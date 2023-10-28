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

#include "sdb.h"

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].expr = malloc(sizeof(char *) * 64);
  }

  head = NULL;
  free_ = wp_pool;
}

// get a new wp in free wp_pool
WP* new_wp(char *expr, word_t val) {
  if (!free_)
    assert(0);
  // get free wp
  WP *wp = free_;
  free_ = free_->next;
  // insert in head
  wp->next = head;
  head = wp;
  wp->val = val;
  memmove(wp->expr, expr, strlen(expr));
  wp->expr[strlen(expr)] = '\0';
  return wp;
}

void free_wp(WP *wp) {
  WP *p = head, *q = head;
  while (p != NULL) {
    if (p->NO == wp->NO)
      break;
    q = p;
    p = p->next;
    q = q->next;
  }
  if (p->NO == head->NO) {
    p->val = 0;
    head = head->next;
    p->next = free_;
    free_ = p;
    wp->expr[0] = '\0';
  } else {
    p->val = 0;
    q->next = p->next;
    p->next = free_;
    free_ = p;
    wp->expr[0] = '\0';
  }
}

bool examine_watchpoint(word_t pc) {
  WP *p = head;
  if (!head) {
    return false;
  }
  bool flag2 = false, flag1 = true;
  while (p != NULL) {
    uint32_t val = expr(p->expr, &flag1);
    if (flag1 && val != p->val) {
      printf("watchpoint NO:%d change in pc:%08x\n", p->NO, pc);
      printf("old value = %d\n", p->val);
      printf("new value = %d\n", val);
      p->val = val;
      flag2 = true;
    }
    p = p->next;
  }
  return flag2;
}

int delete_watchpoint(int n) {
  WP *p = head;
  while (p != NULL) {
    if (p->NO == n) {
      free_wp(p);
      return 1;
    }
  }
  return 0;
}

void show_watchpoint() {
  WP *p = head;
  while (p != NULL) {
    printf("watch point:%d , expr:%s\n", p->NO, p->expr);
    p = p->next;
  }
}