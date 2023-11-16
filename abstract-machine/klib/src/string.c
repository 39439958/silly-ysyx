#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  if (s == NULL) 
    return 0;
  size_t len = 0;
  while (*s++ != '\0') {
    len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  assert(dst != NULL && src != NULL);
  char *res = dst;
  while (*src != '\0') {
    *dst++ = *src++;
  }
  *dst = '\0';
  return res;
}

char *strncpy(char *dst, const char *src, size_t n) {
  assert(dst != NULL && src != NULL && n >= 0);
  if (n == 0)
    return dst;
  char *res = dst;
  while (*src != '\0' && n--) {
    *dst++ = *src++;
  }
  *dst = '\0';
  return res;
}

char *strcat(char *dst, const char *src) {
  assert(dst != NULL && src != NULL);
  char *res = dst;
  while (*dst != '\0') dst++;
  while (*src != '\0') {
    *dst++ = *src++;
  } 
  *dst = '\0';
  return res;
}

int strcmp(const char *s1, const char *s2) {
  assert(s1 != NULL && s2 != NULL);
  while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return *s1 - *s2;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  assert(s1 != NULL && s2 != NULL && n >= 0);
  if (n == 0)
    return 0;
    
  while (n--) {
    if (*s1 == 0 || *s2 == 0 || *s1 != *s2) {
      return *s1 - *s2;
    }
    s1++;
    s2++;
  }
  return 0;
}

void *memset(void *s, int c, size_t n) {
  if (s == NULL || n < 0)
    return s;

  char *tmp = (char *)s;

  for (size_t i = 0; i < n; i++) {
    tmp[i] = c;
  }
  return s;
}

/**
 * 调用时请保证n大于str长度
*/
void *memmove(void *dst, const void *src, size_t n) {
  if (dst == NULL || src == NULL)
    return NULL;

  if (dst > src && dst < (char *)src + n) {
    // 内存重叠,需要从后往前复制
    char *d = (char *)dst + n - 1;
    char *s = (char *)src + n - 1;
    
    while (n--) {
        *d-- = *s--;
    }
  } else {
    // 内存不重叠,从前往后复制
    char *d = (char *)dst;
    char *s = (char *)src;
    
    while (n--) {
        *d++ = *s++;
    }
  }
  return dst;
}

/**
 * 此函数不处理内存重叠，涉及内存重叠使用memmove
 * 调用时请保证n大于str长度
*/
void *memcpy(void *out, const void *in, size_t n) {
  if (out == NULL || in == NULL)
    return NULL;
  
  char *d = (char *)out;
  char *s = (char *)in;

  while (n--) {
    *d++ = *s++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
    if(s1 != NULL && s2 != NULL && n >= 0);

    const unsigned char *p1 = s1;
    const unsigned char *p2 = s2;

    for (size_t i = 0; i < n; i++) {
        if (p1[i] < p2[i]) {
            return -1;
        } else if (p1[i] > p2[i]) {
            return 1;
        }
    }
    return 0;
}

#endif
