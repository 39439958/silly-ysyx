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
#include <memory/vaddr.h>
#include <memory/paddr.h>

#define SATP_MASK 0X3fffff
#define PG_SHIFT 12
#define PGT1_ID(val) (val >> 22)
#define PGT2_ID(val) ((val & 0x3fffff) >> 12)
#define OFFSET(val) (val & 0xfff)
paddr_t isa_mmu_translate(vaddr_t vaddr, int len, int type) {
  word_t va_raw = (uint32_t)vaddr;
  paddr_t *pt_1 = (paddr_t *)guest_to_host((paddr_t)(cpu.csrs.satp << PG_SHIFT));
  assert(pt_1 != NULL);
  word_t *pt_2 = (word_t *)guest_to_host(pt_1[PGT1_ID(va_raw)]);

  assert(pt_2 != NULL);
  paddr_t paddr = (paddr_t)((pt_2[PGT2_ID(va_raw)] & (~0xfff)) | OFFSET(va_raw));

  assert(vaddr >= 0x40000000 && vaddr <= 0xa1200000);
  return paddr;

}
