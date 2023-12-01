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

#include <common.h>

void init_monitor(int, char *[]);
void am_init_monitor();
void engine_start();
int is_exit_status_bad();
void iringbuf_display();

// for test
word_t expr(char *e, bool *success);
void test_expr();

int main(int argc, char *argv[]) {
  /* Initialize the monitor. */
#ifdef CONFIG_TARGET_AM
  am_init_monitor();
  printf("AM started\n");
#else
  init_monitor(argc, argv);
#endif

  /* Start engine. */
  engine_start();

  /* test expr */
    // test_expr();
  
  iringbuf_display();

  return is_exit_status_bad();
}

void test_expr(){
    char buf[65535];
    FILE *fptr;
    if ((fptr = fopen("/home/silly/ysyx-workbench/nemu/tools/gen-expr/input", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);         
    }
    int cnt = 1;
    bool flag = false;
     while (fgets(buf, sizeof(buf), fptr) != NULL) {
         bool *success = false;
         char *param = strtok(buf, " ");
         word_t res = expr(param, success);
         word_t res1 = atoi(buf);
         if (res != res1) {
         printf("%d: %dfalse\n",cnt, res1);
            flag = true;
            break;
        }
        cnt++;
    }
    if (!flag) printf("ALL test accept![%d]\n",cnt - 1);
    fclose(fptr);
	exit(0);
}
