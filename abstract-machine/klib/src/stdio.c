#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...) {
  panic("Not implemented");
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);

  while (*fmt != '\0') {
    if (*fmt == '%') {
      fmt++;
      if (*fmt == 's') {
        char *tmp_s = va_arg(ap, char*);
        while (*tmp_s != '\0') {
          *out++ = *tmp_s++;
        }
      }
      else if (*fmt == 'd') {
        int tmp_int = va_arg(ap, int);
        int number = tmp_int;

        int len  = 0;
        do {
          number /= 10;
          len++;
        } while (number);

        out = out + len - 1;
        int tmp_len = len;
        while (tmp_len--) {
          int tmp = tmp_int % 10;
          *out-- = tmp + 48;
          tmp_int /= 10;
        }
        out += len;
      }
      else {
        return -1;
      }
    }
    else {
      *out++ = *fmt;
    }
    fmt++;
  }
  return 0;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
