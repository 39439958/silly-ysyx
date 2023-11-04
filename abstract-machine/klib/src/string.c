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
    return NULL;
  char *tmp = (char *)s;
  for (size_t i = 0; i < n; i++) {
    tmp[i] = c;
  }
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  if (dst == NULL || src == NULL)
    return NULL;
  assert(strlen(src) >= n);
  char *tmp_dst = (char *)dst;
  char *tmp_src = (char *)src;

  if (tmp_dst < tmp_src) {
    size_t i = 0;
    while (i < n) {
      tmp_dst[i] = tmp_src[i];
      i++;
    }
  }
  else if (tmp_dst > tmp_src) {
    size_t i = n - 1;
    while (i > 0) {
      tmp_dst[i] = tmp_src[i];
      i--;
    }
  }
  return dst;
}

void *memcpy(void *out, const void *in, size_t n) {
  if (out == NULL || in == NULL)
    return NULL;
  assert(strlen(in) >= n);
  char *tmp_out = (char *)out;
  char *tmp_in = (char *)in;

  size_t i = 0;
  while (i < n) {
    tmp_out[i] = tmp_in[i];
    i++;
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  assert(s1 != NULL && s2 != NULL && n >= 0);
  
  char *tmp_s1 = (char *)s1;
  char *tmp_s2 = (char *)s2;
  return strncmp(tmp_s1, tmp_s2, n);
}

#endif
