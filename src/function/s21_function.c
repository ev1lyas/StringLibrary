#include "../s21_error.h"
#include "../s21_string.h"

// num 1 Artur
void *s21_memchr(const void *str, int c, s21_size_t n) {
  int is_find = 0;
  const unsigned char *p = (const unsigned char *)str;
  while (n-- && *p != '\0' && !is_find) {
    if (*p == (unsigned char)c) {
      is_find = 1;
    } else {
      p++;
    }
  }
  if (!is_find) {
    p = S21_NULL;
  }
  return (void *)p;
}

// No 2 Rayf
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  int flag = 0;
  unsigned char *cs = (unsigned char *)str1;
  unsigned char *ct = (unsigned char *)str2;
  for (s21_size_t i = 0; i < n && flag == 0; i++, cs++, ct++) {
    if (*cs != *ct) {
      res = *cs - *ct;
      flag = 1;
    }
  }
  return res;
}

// num 3 Artur
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  const char *s = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

// number 4 Ilyas
void *s21_memset(void *str, int c, s21_size_t n) {
  char *path = str;
  for (s21_size_t i = 0; i < n; i++) {
    path[i] = c;
  }
  return path;
}

// number 5 Ilyas
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *path = dest;
  while (*path) path++;
  for (; n > 0; n--, path++, src++) {
    *path = *src;
  }
  *path = '\0';
  return dest;
}

// number 6 Ilyas
char *s21_strchr(const char *str, int c) {
  int i = 0;
  while (str[i] && str[i] != c) ++i;
  return c == str[i] ? (char *)str + i : S21_NULL;
}

//  No 7 Rayf
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  while (n > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
    n--;
  }
  if (n == 0) {
    res = 0;
  } else {
    res = *(unsigned char *)str1 - *(unsigned char *)str2;
  }
  return res;
}

// No 8 Rayf
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int flag = 0;
  for (s21_size_t i = 0; i < n && flag == 0; i++) {
    if (src[i] == '\0') flag = 1;
    if (flag == 1) {
      dest[i] = '\0';
    } else {
      dest[i] = src[i];
    }
  }
  return dest;
}

// No 9 Rayf
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  int i = 0;
  int j = 0;
  int flag = 0;
  for (i = 0; str1[i] != '\0' && flag == 0; i++) {
    for (j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
        i--;
      }
    }
  }
  return i;
}

// number 10 Artur
char *s21_strerror(int errnum) {
  char *s21_error = S21_NULL;
  if (errnum > MIN_ERRLIST && errnum < MAX_ERRLIST) {
    s21_error = (char *)maserror[errnum];
  } else {
    s21_error = malloc(sizeof(ERROR) + sizeof(errnum) + 1);
    if (s21_error != S21_NULL) {
      s21_sprintf(s21_error, "%s%d", ERROR, errnum);
    }
  }
  return s21_error;
}

// No 11 Rayf
s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  for (; *(str + length); length++)
    ;
  // while (str[lenght] != '\0') {
  //   lenght++;
  // }
  return length;
}

// number 12 Ahror
char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  for (s21_size_t i = 0; i < len1; i++) {
    for (s21_size_t j = 0; j < len2; j++) {
      if (str1[i] == str2[j]) {
        return (char *)(str1 + i);
      }
    }
  }
  return S21_NULL;
}

// number 13 Ahror

char *s21_strrchr(const char *str, int c) {
  const char *res = S21_NULL;
  while (*str) {
    if (*str == c) {
      res = str;
    }
    str++;
  }
  if (c == '\0') {
    res = (char *)str;
  }
  return (char *)res;
}
// number 14 Ahror

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == S21_NULL || needle == S21_NULL) return S21_NULL;
  while (*haystack != '\0') {
    const char *a = haystack;
    const char *b = needle;
    while (*b != '\0' && *a == *b) {
      a++;
      b++;
    }
    if (*b == '\0') return (char *)haystack;
    haystack++;
  }
  return S21_NULL;
}

// num 15 Ahror
char *s21_strtok(char *str, const char *delim) {
  static char *last;
  char *res;

  if (str == S21_NULL) {
    str = last;
  }

  while (*str && s21_strchr(delim, *str)) str++;

  if (*str == '\0') {
    last = str;
    return S21_NULL;
  }

  res = str;
  while (*str && !s21_strchr(delim, *str)) str++;

  if (*str == '\0')
    last = str;
  else {
    *str = '\0';
    last = str + 1;
  }

  return res;
}

char *s21_strcpy(char *restrict dst, const char *restrict src) {
  if (dst == S21_NULL) {
    return S21_NULL;
  }

  int i = 0;
  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }
  dst[i] = '\0';
  return dst;
}