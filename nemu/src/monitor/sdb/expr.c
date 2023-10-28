/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>

/* We use the POSIX regex functions to process regular expressions.
 * Type 'man regex' for more information about POSIX regex functions.
 */
#include <regex.h>
#include <memory/vaddr.h>

enum {
  TK_NOTYPE = 256, 
  TK_DEREF, TK_NEG,
  TK_HEXNUM, TK_NUMBER, TK_REG,
  TK_EQ, TK_NOEQ,
  TK_AND, TK_OR, TK_NOT,
};

static struct rule {
  const char *regex;
  int token_type;
} rules[] = {
  {" +", TK_NOTYPE},    // spaces

  {"\\+", '+'},         
  {"\\-", '-'},
  {"\\*", '*'},
  {"\\/", '/'},
  {"\\(", '('},
  {"\\)", ')'},

  {"0x[0-9a-fA-F]+", TK_HEXNUM},
  {"[0-9]+", TK_NUMBER},
  {"\\$[\\$a-z0-9]{2}", TK_REG},

  {"==", TK_EQ},        
  {"!=", TK_NOEQ},

  {"&&", TK_AND},
  {"\\|\\|", TK_OR},
  {"!", TK_NOT},
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex() {
  int i;
  char error_msg[128];
  int ret;

  for (i = 0; i < NR_REGEX; i ++) {
    ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
    if (ret != 0) {
      regerror(ret, &re[i], error_msg, 128);
      panic("regex compilation failed: %s\n%s", error_msg, rules[i].regex);
    }
  }
}

typedef struct token {
  int type;
  char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used))  = 0;

static bool make_token(char *e) {
  int position = 0;
  int i;
  regmatch_t pmatch;

  nr_token = 0;

  while (e[position] != '\0') {
    /* Try all rules one by one. */
    for (i = 0; i < NR_REGEX; i ++) {
      if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0) {
        char *substr_start = e + position;
        int substr_len = pmatch.rm_eo;

        Log("match rules[%d] = \"%s\" at position %d with len %d: %.*s",
            i, rules[i].regex, position, substr_len, substr_len, substr_start);

        position += substr_len;

        if (rules[i].token_type == TK_NOTYPE)
          break;
        
        // put all token to tokens
        tokens[nr_token].type = rules[i].token_type;
        switch (rules[i].token_type) {
          case TK_HEXNUM :
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            break;
          case TK_NUMBER :
            strncpy(tokens[nr_token].str, substr_start, substr_len);
            tokens[nr_token].str[substr_len] = '\0';
            break;
          case TK_REG :
            strncpy(tokens[nr_token].str, substr_start + 1, substr_len - 1);
            tokens[nr_token].str[substr_len - 1] = '\0';
            break;
          default: break;
        }
        nr_token++;

        break;
      }
    }

    if (i == NR_REGEX) {
      printf("no match at position %d\n%s\n%*.s^\n", position, e, position, "");
      return false;
    }
  }

  return true;
}

// 检查括号是否全部匹配成功，且判断第一个'('是否匹配的是最后一个')'
bool check_pt_match(int p, int q) {
  int st[20], sp = 0;
  for (int i = p; i <= q; i++) {
    if (tokens[i].type == '(')
      st[sp++] = i;
    else if (tokens[i].type == ')') {
      if (sp == 0)
        return false;
      sp--;
    }
  }
  if (sp == 0 && st[0] == p)
      return true;
  return false;
}

// 判断括号是否在左右两边，且是对应的括号，且括号匹配正确
bool check_parentheses(int p, int q) {
  if (tokens[p].type == '(' && tokens[q].type == ')') {
    if (check_pt_match(p, q))
      return true;
  }
  return false;
}

// 判断q的左边第一个括号是否为'('
bool check_left(int p, int q) {
  if (p > q)
    return false;
  int i = q;
  while (i >= p) {
    if (tokens[i].type == ')')
      return false;
    if (tokens[i].type == '(')
      return true;
    i--;
  }
  return false;
}

// 判断p的右边第一个括号是否为')'
bool check_right(int p, int q) {
  if (p > q)
    return false;
  int i = p;
  while (i <= q) {
    if (tokens[i].type == '(')
      return false;
    if (tokens[i].type == ')')
      return true;
    i++;
  }
  return false;
}

// if p's priority is less and equal op's priority
// return true, else return false
bool check_priority(int op, int p) {
  if (tokens[p].type == TK_AND || tokens[p].type == TK_OR) {
    return true;
  }
  else if (tokens[p].type == TK_EQ || tokens[p].type == TK_NOEQ) {
    if (tokens[op].type == TK_AND || tokens[op].type == TK_OR) {
      return false;
    } else {
      return true;
    }
  }
  else if (tokens[p].type == '+' || tokens[p].type == '-') {
    if (tokens[op].type == '*' || tokens[op].type == '/' ||
        tokens[op].type == '+' || tokens[op].type == '-') {
      return true;
    } else {
      return false;
    }
  } 
  else {
    if (tokens[op].type == '*' || tokens[op].type == '/') {
      return true; 
    } else {
      return false;
    }
  }
}

// 检查单目运算符时使用
bool check_certain_type(int TK) {
  if (TK == '+' || TK == '-' || TK == '*' || TK == '/' || TK == '(' ||
      TK == TK_AND || TK == TK_OR || TK == TK_EQ || TK == TK_NOEQ)
    return true;
  return false;
}

word_t eval(int p, int q) {
  if (p > q) {
    assert(0);
  } else if (p == q) {
    if (tokens[p].type == TK_NUMBER) {
      word_t val = 0;
      sscanf(tokens[p].str, "%u", &val);
      return val;
    } else if (tokens[p].type == TK_HEXNUM) {
      word_t addr = 0;
      sscanf(tokens[p].str, "%x", &addr);
      return addr;
    } else if (tokens[p].type == TK_REG) {
      bool success = false;
      word_t val = isa_reg_str2val(tokens[p].str, &success);
      if (success) {
        return val;
      } else {
        assert(0);
      }
    }
    return 0;
  } else if (check_parentheses(p, q)) {
      return eval(p + 1, q - 1);
  } else {
    // find the host operator
    int op = -1;
    for (int i = p; i <= q; i++) {
      if (tokens[i].type != '+' && tokens[i].type != '-' &&
          tokens[i].type != '*' && tokens[i].type != '/' &&
          tokens[i].type != TK_EQ && tokens[i].type != TK_NOEQ &&
          tokens[i].type != TK_AND && tokens[i].type != TK_OR )
          continue;
      if (check_left(p, i - 1) && check_right(i + 1, q))
        continue;
      if (op == -1 || check_priority(op, i)) {
        op = i;
      } 
    }
    if (op == -1) {
      if (tokens[p].type == TK_DEREF) {
        word_t tmp_val = vaddr_read(eval(p + 1, q), 4);
        return tmp_val;
      }
      else if (tokens[p].type == TK_NEG) {
        return -1 * eval(p + 1, q);
      }
    }

    word_t val1 = eval(p, op - 1);
    word_t val2 = eval(op + 1, q);

    switch(tokens[op].type) {
      case '+':
        return val1 + val2;
      case '-':
        return val1 - val2;
      case '*':
        return val1 * val2;
      case '/':
        return val1 / val2;
      case TK_EQ:
        if (val1 == val2) {
          return 1;
        } else {
          return 0;
        }
      case TK_NOEQ:
        if (val1 != val2) {
          return 1;
        } else {
          return 0;
        }
      case TK_AND:
        return val1 && val2;
      case TK_OR:
        return val1 || val2;
      default: 
        assert(0);
    }
  }
}

word_t expr(char *e, bool *success) {
  if (!make_token(e)) {
    *success = false;
    return 0;
  }

  for (int i = 0; i < nr_token; i++) {
    if (tokens[i].type == '*' && (i == 0 || check_certain_type(tokens[i - 1].type))) {
      tokens[i].type = TK_DEREF;
    }
    if (tokens[i].type == '-' && (i == 0 || check_certain_type(tokens[i - 1].type))) {
      tokens[i].type = TK_NEG;
    }
  }

  word_t val = eval(0, nr_token - 1);
  return val;
}
