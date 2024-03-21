#include "../s21_string.h"

typedef struct {
  int count;
  int asterisk;
  int width;
  int l_short_int;
  int l_long_int;
  int l_long_double;
} formater;

void s21_skip_space(const char **str_ptr) {
  char *str = (char *)*str_ptr;
  while (*str == ' ') {
    str++;
  }
}

int s21_get_sign(const char **str_ptr) {
  int sign = 1;
  char *str = (char *)*str_ptr;
  if (*str == '-' || *str == '+') {
    if (*str == '-') sign = -1;
    str++;
  }
  return sign;
}

int s21_isnan(const char **str_ptr) {
  int result = 0;
  char *str = (char *)*str_ptr;
  if ((*str == 'n' || *str == 'N') &&
      (*(str + 1) == 'a' || *(str + 1) == 'A') &&
      (*(str + 2) == 'n' || *(str + 2) == 'N')) {
    result = 1;
  }
  return result;
}

int s21_isinf(const char **str_ptr) {
  int result = 0;
  char *str = (char *)*str_ptr;
  if ((*str == 'i' || *str == 'I') &&
      (*(str + 1) == 'n' || *(str + 1) == 'N') &&
      (*(str + 2) == 'f' || *(str + 2) == 'F')) {
    result = 1;
  }
  return result;
}

char *floating_number = "fd";

#define DEFINE_S21_NUMBER(type)                                    \
  type s21_number_##type(char char_type, const char **str_ptr) {   \
    const char *str = *str_ptr;                                    \
    type result = 0;                                               \
    s21_skip_space(&str);                                          \
    int sign = s21_get_sign(&str);                                 \
    if (s21_isinf(&str)) {                                         \
      *str_ptr += 3;                                               \
      return INFINITY * sign;                                      \
    } else if (s21_isnan(&str)) {                                  \
      *str_ptr += 3;                                               \
      return NAN * sign;                                           \
    }                                                              \
    while (*str >= '0' && *str <= '9') {                           \
      result = result * 10 + (*str - '0');                         \
      str++;                                                       \
    }                                                              \
    if (s21_strchr(floating_number, char_type) && (*str == '.')) { \
      type part = 0.1;                                             \
      str++;                                                       \
      while ((*str >= '0' && *str <= '9')) {                       \
        result = result + (*str - '0') * part;                     \
        part *= 0.1;                                               \
        str++;                                                     \
      }                                                            \
    }                                                              \
    if (char_type != 'u') {                                        \
      result *= sign;                                              \
    }                                                              \
    *str_ptr = str;                                                \
    return result;                                                 \
  }

DEFINE_S21_NUMBER(int)
DEFINE_S21_NUMBER(long)
DEFINE_S21_NUMBER(short)
DEFINE_S21_NUMBER(float)
DEFINE_S21_NUMBER(double)
DEFINE_S21_NUMBER(unsigned)

#define DEFINE_S21_NUMBER_LONG_DOUBLE(type)           \
  type s21_number_long_double(const char **str_ptr) { \
    const char *str = *str_ptr;                       \
    type result = 0;                                  \
    s21_skip_space(&str);                             \
    int sign = s21_get_sign(&str);                    \
    if (s21_isinf(&str)) {                            \
      *str_ptr += 3;                                  \
      return INFINITY * sign;                         \
    } else if (s21_isnan(&str)) {                     \
      *str_ptr += 3;                                  \
      return NAN * sign;                              \
    }                                                 \
    while (*str >= '0' && *str <= '9') {              \
      result = result * 10 + (*str - '0');            \
      str++;                                          \
    }                                                 \
    if (*str == '.') {                                \
      type part = 0.1;                                \
      str++;                                          \
      while ((*str >= '0' && *str <= '9')) {          \
        result = result + (*str - '0') * part;        \
        part *= 0.1;                                  \
        str++;                                        \
      }                                               \
    }                                                 \
    *str_ptr = str;                                   \
    result *= sign;                                   \
    return result;                                    \
  }

DEFINE_S21_NUMBER_LONG_DOUBLE(long double)

int s21_int_from_octa(const char **str_ptr) {
  const char *str = *str_ptr;
  int sign = s21_get_sign(&str);
  if (*str == '0') str++;
  int origin_number = s21_number_int('i', &str);
  int result = 0, remainder = 0, i = 0;
  while (origin_number != 0) {
    remainder = origin_number % 10;
    origin_number /= 10;
    result += remainder * pow(8, i++);
  }
  result *= sign;
  return result;
}

int s21_get_hexa_string(const char **str_ptr, char *buf) {
  const char *str = *str_ptr;
  int i = 0;
  char c = 'a';
  char array_hexa[] = {'a', 'b', 'c', 'd', 'e', 'f',
                       'A', 'B', 'C', 'D', 'E', 'F'};
  while (s21_strchr(array_hexa, *str) || (*str >= '0' && *str <= '9')) {
    c = *str++;
    if ('A' <= c && c <= 'Z') {
      c += 'a' - 'A';
    }
    buf[i++] = c;
  }
  *str_ptr = str;
  return s21_strlen(buf);
}

int s21_int_from_hexa(const char **str_ptr) {
  int result = 0;
  const char *str = *str_ptr;
  int sign = s21_get_sign(&str);
  char buf[100];
  if (*str == '0') str++;
  if (*str == 'x' || *str == 'X') str++;
  int length = s21_get_hexa_string(&str, buf);
  for (int i = 0; i < length; i++) {
    int digit = 0;
    if (buf[i] >= '0' && buf[i] <= '9') {
      digit = buf[i] - '0';
    } else if (buf[i] >= 'a' && buf[i] <= 'f') {
      digit = buf[i] - 'a' + 10;
    }
    result += digit * pow(16, length - i - 1);
  }
  *str_ptr = str;
  result *= sign;
  return result;
}

int get_int_from_octa_or_hexa(const char **str_ptr) {
  const char *str = *str_ptr;
  int result = 0;
  if (*str == '0') {
    str++;
    if (*str == 'x' || *str == 'X') {
      str++;
      result = s21_int_from_hexa(&str);
    } else {
      result = s21_int_from_octa(&str);
    }
  } else {
    result = s21_number_int('i', &str);
  }
  *str_ptr = str;
  return result;
}

char *s21_get_string(const char **str_ptr) {
  const char *str = *str_ptr;
  char *result = NULL;
  while (*str != ' ' && *str != '\0') {
    *result++ = *str++;
  }
  *str_ptr = str;
  return result;
}

void s21_get_set_lenght(const char **str_ptr, formater *form1) {
  const char *format = *str_ptr;
  switch (*format) {
    case 'h':
      form1->l_short_int = 1;
      format++;
      break;

    case 'l':
      form1->l_long_int = 1;
      format++;
      break;

    case 'L':
      form1->l_long_double = 1;
      format++;
      break;
  }
  *str_ptr = format;
}

void specific_d(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    s21_number_int('i', &str);
  } else {
    if (form1.l_short_int) {
      short *d = va_arg(va, short *);
      *d = s21_number_short('h', &str);
    } else if (form1.l_long_int) {
      long *d = va_arg(va, long *);
      *d = s21_number_long('l', &str);
    } else {
      int *d = va_arg(va, int *);
      *d = s21_number_int('i', &str);
    }
    (*matched)++;
  }
  *str_ptr = str;
}

void specific_i(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    char buf[100];
    s21_get_hexa_string(str_ptr, buf);
  } else {
    if (form1.l_short_int) {
      short *d = va_arg(va, short *);
      *d = get_int_from_octa_or_hexa(&str);
    } else if (form1.l_long_int) {
      long *d = va_arg(va, long *);
      *d = get_int_from_octa_or_hexa(&str);
    } else {
      int *d = va_arg(va, int *);
      *d = get_int_from_octa_or_hexa(&str);
    }
    (*matched)++;
  }
  *str_ptr = str;
}

void specific_c(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    str++;
  } else {
    int *c = va_arg(va, int *);
    if (*str != '\0') {
      *c = (unsigned char)*str++;
      (*matched)++;
    }
  }
  *str_ptr = str;
}

void specific_f(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    (s21_number_float('f', &str));
  } else {
    if (form1.l_long_double) {
      long double *d = va_arg(va, long double *);
      *d = s21_number_long_double(&str);
    } else if (form1.l_long_int) {
      double *d = va_arg(va, double *);
      *d = s21_number_double('f', &str);
    } else {
      float *d = va_arg(va, float *);
      *d = s21_number_float('f', &str);
    }
    (*matched)++;
  }
  *str_ptr = str;
}

void specific_p(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    get_int_from_octa_or_hexa(&str);
  } else {
    void **p = va_arg(va, void **);
    unsigned long result = (unsigned long)get_int_from_octa_or_hexa(&str);
    if (p != NULL) {
      *p = (void *)result;
    }
    (*matched)++;
    ;
  }
  *str_ptr = str;
}

void specific_o(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    s21_number_int('i', &str);
  } else {
    if (form1.l_short_int) {
      short *d = va_arg(va, short *);
      *d = s21_int_from_octa(&str);
    } else if (form1.l_long_int) {
      long *d = va_arg(va, long *);
      *d = s21_int_from_octa(&str);
    } else {
      int *d = va_arg(va, int *);
      *d = s21_int_from_octa(&str);
    }
    (*matched)++;
    ;
  }
  *str_ptr = str;
}

void specific_x(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    s21_number_int('i', &str);
  } else {
    if (form1.l_short_int) {
      short *d = va_arg(va, short *);
      *d = s21_int_from_hexa(&str);
    } else if (form1.l_long_int) {
      long *d = va_arg(va, long *);
      *d = s21_int_from_hexa(&str);
    } else {
      int *d = va_arg(va, int *);
      *d = s21_int_from_hexa(&str);
    }
    (*matched)++;
  }
  *str_ptr = str;
}

void specific_u(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    s21_number_int('i', &str);
  } else {
    if (form1.l_short_int) {
      short *d = va_arg(va, short *);
      *d = s21_number_int('u', &str);
    } else if (form1.l_long_int) {
      long *d = va_arg(va, long *);
      *d = s21_number_int('u', &str);
    } else {
      int *d = va_arg(va, int *);
      *d = s21_number_int('u', &str);
    }
    (*matched)++;
  }
  *str_ptr = str;
}

void specific_s(formater form1, const char **str_ptr, va_list va,
                int *matched) {
  const char *str = *str_ptr;
  if (form1.asterisk) {
    while (*str != ' ' && *str != '\0') {
      str++;
    }
  } else {
    char *s = va_arg(va, char *);
    while (*str != ' ' && *str != '\0') {
      *s++ = *str++;
    }
    *s = '\0';
    (*matched)++;
  }
  *str_ptr = str;
}

void s21_choose_specific(const char **str_ptr, const char *format,
                         formater *form1, va_list va, int *matched) {
  const char *str = *str_ptr;
  switch (*format) {
    case 'c': {
      specific_c(*form1, &str, va, matched);
      break;
    }
    case 'd': {
      specific_d(*form1, &str, va, matched);
      break;
    }
    case 'i': {
      specific_i(*form1, &str, va, matched);
      break;
    }
    case 'e':
    case 'E': {
      float *f = va_arg(va, float *);
      *f = s21_number_double('f', &str);
      (*matched)++;
      ;
      break;
    }
    case 'f': {
      specific_f(*form1, &str, va, matched);
      break;
    }
    case 'g': {
      float *f = va_arg(va, float *);
      *f = s21_number_double('f', &str);
      (*matched)++;
      ;
      break;
    }
    case 'G': {
      float *f = va_arg(va, float *);
      *f = s21_number_double('f', &str);
      (*matched)++;
      ;
      break;
    }
    case 'o': {
      specific_o(*form1, &str, va, matched);
      break;
    }
    case 's': {
      specific_s(*form1, &str, va, matched);
      break;
    }
    case 'u': {
      specific_u(*form1, &str, va, matched);
      break;
    }
    case 'x':
    case 'X': {
      specific_x(*form1, &str, va, matched);
      break;
    }
    case 'p': {
      specific_p(*form1, &str, va, matched);
      break;
    }
    case 'n': {
      *va_arg(va, int *) = form1->count;
      (*matched)++;
      ;
      break;
    }
    case '%': {
      str++;
      (*matched)++;
      break;
    }
  }
  *str_ptr = str;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  formater form1;
  int matched = 0, error = 0;
  form1.count = 0;
  while (*format && !error) {
    s21_skip_space(&format);
    s21_skip_space(&str);
    form1.asterisk = 0;
    if (*format == '%') {
      format++;
      if (*format == '*') {
        form1.asterisk = 1;
        format++;
      }
      form1.width = s21_number_int('i', &format);
      s21_get_set_lenght(&format, &form1);
      s21_choose_specific(&str, format, &form1, va, &matched);
    } else {
      if (*str == *format) {
        str++;
        form1.count += 1;
      } else {
        error = 1;
      }
    }
    format++;
  }
  va_end(va);
  return matched;
}