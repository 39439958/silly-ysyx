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

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define choose(n) rand()%n

// this should be enough
static char buf[65536] = {};
static char code_buf[65536 + 128] = {}; // a little larger than `buf`
static char *code_format =
"#include <stdio.h>\n"
"int main() { "
"  unsigned result = %s; "
"  printf(\"%%u\", result); "
"  return 0; "
"}";
static int buf_index = 0;

int numlen(int num)
{
    if(num == 0) return 1;
    int len = 0;        
    while (num) {
        len++;
        num /= 10;
    }	         
    return len;              
}

void gen_num() {
  int num = choose(1000);
  sprintf(buf+buf_index, "%d", num);
  buf_index += numlen(num);
}

void gen(char c){
    buf[buf_index++] = c;
}

void gen_rand_op() {
    char op[4] = {'+','-','*','/'};
    int op_index = choose(4);
    buf[buf_index++] = op[op_index];
}

void gen_rand_expr() {
    if (buf_index > 60000)
        return;
    switch(choose(3)) {
        case 0: 
            gen_num(); 
            break;
        case 1: 
            gen('(');
            gen_rand_expr();
            gen(')');
            break;
        default:
            gen_rand_expr(); 
            gen_rand_op(); 
            gen_rand_expr(); 
            break;
    }
}

int main(int argc, char *argv[]) {
    int seed = time(0);
    srand(seed);
    int loop = 1;
    if (argc > 1) {
        sscanf(argv[1], "%d", &loop);
    }
    int i;
    for (i = 0; i < loop; i ++) {
        buf_index = 0;
        gen_rand_expr();
        buf[buf_index++]='\0';
        //printf("%s\n",buf);
        sprintf(code_buf, code_format, buf);

        FILE *fp = fopen("/tmp/.code.c", "w");
        assert(fp != NULL);
        fputs(code_buf, fp);
        fclose(fp);

        int ret = system("gcc -O2 -Wall -Werror /tmp/.code.c -o /tmp/.expr");
        if (ret != 0) continue;

        fp = popen("/tmp/.expr", "r");
        assert(fp != NULL);

        int result;
        ret = fscanf(fp, "%d", &result);
        pclose(fp);

        printf("%u %s\n", result, buf);
    }
    return 0;
}
