#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  if (s == NULL) 
    return 0;
  size_t i = 0;
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

char *strcpy(char *dst, const char *src) {
  if (src == NULL || dst == NULL)
    return NULL;
  size_t i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
  }
  dst[i] = '\0';
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  if (src == NULL || dst == NULL)
    return NULL;
  assert(strlen(src) >= n);
  size_t i = 0;
  while (src[i] != '\0' && i < n) {
    dst[i] = src[i];
  }
  dst[i] = '\0';
  return dst;
}

char *strcat(char *dst, const char *src) {
  if (src == NULL || dst == NULL)
    return NULL;
  char *res = dst;
  while (*dst != '\0') dst++;
  while (*src != '\0') {
    *dst = *src;
    dst++;
    src++;
  } 
  *dst = '\0';
  return res;
}

int strcmp(const char *s1, const char *s2) {
  if (s1 == NULL && s2 == NULL)
    return 0;
  else if (s1 == NULL)
    return -1;
  else if (s2 == NULL)
    return 1;
  
  size_t i = 0;
  while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
    i++;
  }
  if (s1[i] == '\0' && s2[i] == '\0')
    return 0;
  else if (s1[i] == '\0')
    return -1;
  else
    return 1;
}

int strncmp(const char *s1, const char *s2, size_t n) {
  assert(n > 0);
  if (n == 0) 
    return 0;
  if (s1 == NULL && s2 == NULL)
    return 0;
  else if (s1 == NULL)
    return -1;
  else if (s2 == NULL)
    return 1;
  
  size_t i = 0;
  while (i < n && s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
    i++;
  }

  if (i < n) {
    return 0;
  }

  if (s1[i] == '\0' && s2[i] == '\0')
    return 0;
  else if (s1[i] == '\0')
    return -1;
  else
    return 1;
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
    }
  }
  else if (tmp_dst > tmp_src) {
    size_t i = n - 1;
    while (i > 0) {
      tmp_dst[i] = tmp_src[i];
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
  }
  return out;
}

int memcmp(const void *s1, const void *s2, size_t n) {
  char *tmp_s1 = (char *)s1;
  char *tmp_s2 = (char *)s2;
  return strncmp(tmp_s1, tmp_s2, n);
}

#endif
