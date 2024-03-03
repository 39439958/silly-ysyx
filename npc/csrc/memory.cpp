#include <common.h>

static const uint32_t img [] = {
    0x00108093,
    0x00108093,
    0x00108093,
    0x00108093,
    0x00100073,
};
struct timeval start, end;
long seconds, microseconds;

void putch();
void difftest_skip_ref();


long load_img(char *img_file) {
    if (img_file == NULL) {
        printf("No image is given. Use the default build-in image.\n");
        return 4096;
    }

    FILE *fp = fopen(img_file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open img file: %s\n", img_file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    int img_size = ftell(fp);

    printf(ANSI_FMT("The image is %s, size = %d\n", ANSI_FG_BLUE), img_file, img_size);

    fseek(fp, 0, SEEK_SET);
    if (fread(pmem, img_size, 1, fp) != 1) {
        fprintf(stderr, "Failed to read img file: %s\n", img_file);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return img_size;
}

void init_mem() {
    memset(pmem, 0, 0x8000000);
    memcpy(pmem, img, sizeof(img));
}

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }

static inline void host_write(void *addr, int len, uint32_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default : return;
  }
}

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: return 0;
  }
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
    // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
    // `wmask`中每比特表示`wdata`中1个字节的掩码,
    // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
    if ((uint32_t)waddr == 0xa00003f8) {
        difftest_skip_ref();
        putchar(wdata);
        fflush(stdout);
        return;
    } 
    else if (waddr == 0xa0000048 || waddr == 0xa000004c){
        difftest_skip_ref();
        gettimeofday(&start, NULL);
    }
    else {
        // plan 1
        uint32_t addr = waddr & ~0x3u;
        // if (wmask == 1 || wmask == 3) {
        //     wdata <<= ((waddr & 0x3u) * 8);
        //     wmask <<= (waddr & 0x3u);
        // }
        // uint32_t *p = (uint32_t *)(pmem + addr - 0x80000000);
        // uint32_t mask = 0; 
        // for (int i = 0; i < 4; i++) {
        //     if (wmask & (1 << i)) {
        //         mask |= 0xff << (i * 8);
        //     }
        // }
        // *p = (*p & ~mask) | (wdata & mask);

        // plan 2
        // if (wmask == 0x1) host_write(guest_to_host(addr), 1, wdata);
        // else if (wmask == 0x3) host_write(guest_to_host(addr), 2, wdata);
        // else if (wmask == 0xf) host_write(guest_to_host(addr), 4, wdata);

        // plan 3
        if (wmask == 0x1) host_write(guest_to_host((uint32_t)waddr), 1, wdata);
        else if (wmask == 0x3) host_write(guest_to_host((uint32_t)waddr), 2, wdata);
        else if (wmask == 0xf) host_write(guest_to_host((uint32_t)waddr), 4, wdata);
    }
}

extern "C" void pmem_read(int raddr, int *rdata) {
    // 总是读取地址为`raddr & ~0x3u`的4字节返回给`rdata`
    if (raddr == 0xa0000048 || raddr == 0xa000004c) {
        difftest_skip_ref();
        gettimeofday(&end, NULL);
        seconds = end.tv_sec - start.tv_sec;
        microseconds = end.tv_usec - start.tv_usec;
        long res = seconds * 1000000 + microseconds;
        *rdata = (raddr == 0xa0000048) ? (res & 0xffffffff) : (res >> 32);
    } else {
        // plan 1
        uint32_t addr = raddr & (~0x3u);
        *rdata = host_read(guest_to_host(addr), 4);
        // plan 2
        // *rdata = host_read(guest_to_host((uint32_t)raddr), 4);
    }
}
