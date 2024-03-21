#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int point = 0;
  va_list args = {0};
  va_start(args, format);
  while (*format) {
    Options options = {0};
    options.accuracy = -1;
    options.accuracy_help = -1;
    if (*format == '%') {
      char cur_str[2048] = "";
      int cur_point = 0;
      format++;
      format = check_flags(&options, format, cur_str, &cur_point);
      format = check_width(&options, format, args);
      format = check_accuracy(&options, format, args);
      format = check_length(&options, format);
      format = check_specifier(&options, format);
      check_errors(&options);
      collect_buf(&options, cur_str, &cur_point, args);
      realize_width(cur_str, &options);
      cur_point = 0;
      while (cur_str[cur_point]) {
        str[point++] = cur_str[cur_point++];
      }
    } else {
      str[point++] = *format++;
    }
  }

  va_end(args);

  str[point] = '\0';

  return (int)s21_strlen(str);  // to do s21
}

const char *check_flags(Options *options, const char *format, char *cur_str,
                        int *cur_point) {
  if (*format == '+') {
    cur_str[*cur_point] = *format;
    *cur_point += 1;
    options->plus = 1;
    format++;
  } else if (*format == ' ') {
    cur_str[*cur_point] = *format;
    *cur_point += 1;
    options->space = 1;
    format++;
  } else if (*format == '-') {
    options->minus = 1;
    format++;
  } else if (*format == '#') {
    options->hash = 1;
    format++;
  } else if (*format == '0') {
    options->zero = 1;
    format++;
  }
  while (*format == '+' || *format == ' ' || *format == '-' || *format == '#') {
    if (*format == '+') {
      cur_str[*cur_point] = *format;
      *cur_point += 1;
      options->plus = 1;
      format++;
    } else if (*format == ' ') {
      cur_str[*cur_point] = *format;
      *cur_point += 1;
      options->space = 1;
      format++;
    } else if (*format == '-') {
      options->minus = 1;
      format++;
    } else if (*format == '#') {
      options->hash = 1;
      format++;
    }
  }
  return format;
}

const char *check_width(Options *options, const char *format, va_list args) {
  if (*format == '*') {
    options->width = va_arg(args, int);
    format++;
  } else if (isint(*format)) {
    int result = 0;
    if (*format == '0') options->zero = 1;
    result = result * 10 + (*format - '0');
    format++;
    while (isint(*format)) {
      result = result * 10 + (*format - '0');
      format++;
    }
    options->width = result;
  }
  return format;
}

const char *check_accuracy(Options *options, const char *format, va_list args) {
  if (*format == '.') {
    format++;
    if (*format == '*') {
      options->accuracy = va_arg(args, int);
      format++;
    } else if (isint(*format)) {
      int result = 0;
      result = result * 10 + (*format - '0');
      format++;
      while (isint(*format)) {
        result = result * 10 + (*format - '0');
        format++;
      }
      options->accuracy = result;
      options->accuracy_help = result;
    } else {
      options->accuracy = 0;
    }
  }
  return format;
}

const char *check_length(Options *options, const char *format) {
  if (*format == 'l') {
    options->l = 1;
    format++;
  } else if (*format == 'h') {
    options->h = 1;
    format++;
  } else if (*format == 'L') {
    options->L = 1;
    format++;
  }
  return format;
}

const char *check_specifier(Options *options, const char *format) {
  switch (*format) {
    case 'c':
      options->c = 1;
      break;
    case 'd':
      options->d = 1;
      break;
    case 'f':
      options->f = 1;
      break;
    case 's':
      options->s = 1;
      break;
    case 'u':
      options->u = 1;
      break;
    case '%':
      options->percent = 1;
      break;
    case 'g':
      options->g = 1;
      break;
    case 'G':
      options->G = 1;
      break;
    case 'e':
      options->e = 1;
      break;
    case 'E':
      options->E = 1;
      break;
    case 'x':
      options->x = 1;
      break;
    case 'X':
      options->X = 1;
      break;
    case 'o':
      options->o = 1;
      break;
    case 'p':
      options->p = 1;
      break;
    default:
      options->error = 1;
      break;
  }
  format++;
  return format;
}

void collect_buf(Options *options, char *cur_str, int *cur_point,
                 va_list args) {
  if (options->c == 1) {
    cur_str[*cur_point] = va_arg(args, int);
    *cur_point += 1;
  } else if (options->d == 1) {
    realize_d0(options, cur_str, cur_point, args);
  } else if (options->f == 1) {
    realize_f0(options, cur_str, cur_point, args);
  } else if (options->s == 1) {
    realize_s0(options, cur_str, cur_point, args);
  } else if (options->u == 1) {
    realize_u0(options, cur_str, cur_point, args);
  } else if (options->percent == 1) {
    cur_str[*cur_point] = '%';
    *cur_point += 1;
  } else if (options->g == 1 || options->G == 1) {
    realize_g0(options, cur_str, cur_point, args);
  } else if (options->e == 1 || options->E == 1) {
    if (options->L == 1) {
      realize_e_E(va_arg(args, long double), cur_point, cur_str, options);
    } else {
      realize_e_E(va_arg(args, double), cur_point, cur_str, options);
    }
  } else if (options->x == 1 || options->X == 1) {
    realize_x0(cur_point, cur_str, options, args);
  } else if (options->o == 1) {
    realize_o0(cur_point, cur_str, options, args);
  } else if (options->p == 1) {
    realize_p(cur_point, cur_str, options, args);
  }
}

void check_errors(Options *options) {
  if (options->plus == 1 &&
      (options->c == 1 || options->s == 1 || options->u == 1))
    options->error = 1;
  if (options->space == 1 &&
      (options->c == 1 || options->s == 1 || options->u == 1))
    options->error = 1;
  if (options->h == 1 &&
      (options->c == 1 || options->s == 1 || options->f == 1))
    options->error = 1;
  if (options->l == 1 &&
      (options->c == 1 || options->s == 1 || options->f == 1))
    options->error = 1;
  if (options->plus == 1 && options->space == 1) options->error = 1;
  if (options->error == 1) {
    fprintf(stderr, "n/a");
    exit(0);
  }
}

void realize_g0(Options *options, char *cur_str, int *cur_point, va_list args) {
  if (options->L == 1) {
    realize_g_G(va_arg(args, long double), cur_point, cur_str, options);
  } else {
    realize_g_G(va_arg(args, double), cur_point, cur_str, options);
  }
}

void realize_u0(Options *options, char *cur_str, int *cur_point, va_list args) {
  if (options->u == 1 && options->l != 1 && options->h != 1) {
    realize_d(va_arg(args, unsigned), cur_point, cur_str, options, S21_NULL);
  } else if (options->u == 1 && options->l == 1) {
    realize_ul(va_arg(args, long unsigned), cur_point, cur_str, options);
  } else if (options->u == 1 && options->h == 1) {
    realize_us((short)va_arg(args, unsigned), cur_point, cur_str, options);
  }
  cur_str[*cur_point] = '\0';
  *cur_point += 1;
}

void realize_s0(Options *options, char *cur_str, int *cur_point, va_list args) {
  char *ch_long = va_arg(args, char *);
  int curr_accur = options->accuracy;
  while (*ch_long != '\0' && curr_accur != 0) {
    cur_str[*cur_point] = *ch_long;
    *cur_point += 1;
    ch_long++;
    curr_accur--;
  }
}

void realize_d0(Options *options, char *cur_str, int *cur_point, va_list args) {
  if (options->d == 1 && options->l != 1 && options->h != 1) {
    int value = va_arg(args, int);
    realize_d(value, cur_point, cur_str, options, S21_NULL);
  } else if (options->d == 1 && options->l == 1) {
    long int value = va_arg(args, long);
    realize_d(value, cur_point, cur_str, options, S21_NULL);
  } else if (options->d == 1 && options->h == 1) {
    short int value = (short)va_arg(args, int);
    realize_d(value, cur_point, cur_str, options, S21_NULL);
  }
  cur_str[*cur_point] = '\0';
  *cur_point += 1;
}

void realize_f0(Options *options, char *cur_str, int *cur_point, va_list args) {
  if (options->f == 1 && options->L == 1) {
    long double value = va_arg(args, long double);
    long double f_part = 0.0, s_part = modfl(value, &f_part);
    if (signbit(value) && f_part == 0) {
      long int f = -1;
      check_negative(&f, cur_point, cur_str, options);
    }
    realize_d(f_part, cur_point, cur_str, options, S21_NULL);
    if (options->accuracy == 0 && options->hash == 1) {
      cur_str[*cur_point] = '.';
      *cur_point += 1;
    } else if (options->accuracy != 0) {
      cur_str[*cur_point] = '.';
      *cur_point += 1;
      s_part = signbit(value) ? s_part * -1 : s_part;
      realize_f(s_part, cur_point, cur_str, options, S21_NULL);
    }
  } else if (options->f == 1 && options->L != 1) {
    double value = va_arg(args, double);
    int int_part = (int)value;
    double fractional_part = value - int_part;
    if (signbit(value) && int_part == 0) {
      long int f = -1;
      check_negative(&f, cur_point, cur_str, options);
    }
    realize_d(int_part, cur_point, cur_str, options, S21_NULL);
    if (options->accuracy == 0 && options->hash == 1) {
      cur_str[*cur_point] = '.';
      *cur_point += 1;
    } else if (options->accuracy != 0) {
      cur_str[*cur_point] = '.';
      *cur_point += 1;
      fractional_part = signbit(value) ? fractional_part * -1 : fractional_part;
      realize_f(fractional_part, cur_point, cur_str, options, S21_NULL);
    }
  }
}

void check_value_zero(Options *options, int *point, char *str) {
  if (options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  }
  int count_accur = 1;
  if (options->accuracy > 0) {
    while (count_accur < options->accuracy) {
      str[*point] = '0';
      *point += 1;
      count_accur++;
    }
  }
}
void check_value_zero_d(Options *options, int *point, char *str) {
  if (options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  }
  if (options->accuracy == 0 && options->f == 1) {
    str[*point] = '0';
    *point += 1;
  }
  int count_accur = 1;
  if (options->accuracy > 0 && options->f == 0 && options->g == 0 &&
      options->G == 0) {
    while (count_accur < options->accuracy) {
      str[*point] = '0';
      *point += 1;
      count_accur++;
    }
  }
}

void write_exp(int num_digits, char sign, Options *options, int *point,
               char *str) {
  if (options->G == 1) str[*point] = 'E';
  if (options->g == 1) str[*point] = 'e';
  *point += 1;
  str[*point] = sign;
  *point += 1;
  num_digits = (sign == '+') ? num_digits - 1 : num_digits;
  if (num_digits > 9 && num_digits < 100) {
    int second = (num_digits) % 10;
    int first = ((num_digits) / 10) % 10;
    str[*point] = '0' + first;
    *point += 1;
    str[*point] = '0' + second;
    *point += 1;
  } else if (num_digits < 9) {
    str[*point] = '0';
    *point += 1;
    int first = (num_digits) % 10;
    str[*point] = '0' + first;
    *point += 1;
  } else if (num_digits < 1000) {
    int third = (num_digits) % 10;
    int second = ((num_digits) / 10) % 10;
    int first = ((num_digits) / 100) % 10;
    str[*point] = '0' + first;
    *point += 1;
    str[*point] = '0' + second;
    *point += 1;
    str[*point] = '0' + third;
    *point += 1;
  }
}

void realize_g2(int *hash, char *buffer, int *index, int num_digits,
                Options *options, int *point, char *str) {
  for (int i = 0; i < options->accuracy + 2; i++) {
    if (i == 1) {
      str[*point] = '.';
      *hash = 1;
      *point += 1;
    } else if (options->accuracy > i) {
      str[*point] = buffer[*index];
      *point += 1;
      *index += 1;
    } else if (options->accuracy == i) {
      int hope = (int)buffer[*index - 1];
      str[*point] = (hope > 9) ? buffer[*index] + 1 : buffer[*index];
      *point += 1;
      *index += 1;
    } else {
      write_exp(num_digits, '+', options, point, str);
    }
  }
}

void dynamic_memory_check(char *buffer, int *gg) {
  if (buffer == S21_NULL) {
    fprintf(stderr, "Error memory");
    *gg = 1;
    exit(0);
  }
}

int realize_d2(int num_digits, Options *options, int *point, char *str) {
  if (options->accuracy > 0 && options->f == 0 && options->g == 0 &&
      options->G == 0) {
    while (num_digits < options->accuracy) {
      str[*point] = '0';
      *point += 1;
      num_digits++;
    }
  }
  return num_digits;
}

void realize_f2(int gg, int zero_count, long double value, int eps,
                int zero_stop, int dot, int curr_accur, int *hash,
                Options *options, int *point, char *str) {
  double g = check_notation(curr_accur);
  while (curr_accur > 0 && value > 1e-13 &&
         (options->g == 1 || options->G == 1) && gg < 14) {
    if (zero_count == 5) eps = 1;
    gg++;
    value = value * 10;
    if ((int)value == 0 && zero_stop != -1) {
      zero_count++;
      continue;
    } else
      zero_stop = -1;
    if (zero_count >= 1 && zero_count < 5) {
      str[*point] = '0';
      *point += 1;
      str[*point] = '.';
      *hash = 1;
      *point += 1;
      dot = 1;
      while (zero_count > 1) {
        str[*point] = '0';
        *point += 1;
        zero_count--;
      }
      zero_count--;
    }
    str[*point] = (curr_accur == 1 || gg == 14) ? ((int)(value + 0.5) + '0')
                                                : ((int)(value + g) + '0');
    *point += 1;
    value -= (int)(value + g);
    g *= 10;
    if (dot == 0 && curr_accur > 1 && value > 1e-15) {
      str[*point] = '.';
      *hash = 1;
      *point += 1;
      dot = 1;
    } else if (dot == 1 && value < 1e-15 && options->hash == 1 && eps == 0) {
      while (curr_accur > 1) {
        str[*point] = '0';
        *point += 1;
        curr_accur -= 1;
      }
    }
    curr_accur -= 1;
    if ((curr_accur == 0 || value <= 1e-13 || gg == 14) && eps == 1) {
      write_exp(zero_count, '-', options, point, str);
    }
  }
}

void realize_g3(int num_digits, long double temp, Options *options, int *point,
                char *str) {
  int curr_accur = (options->accuracy == -1) ? 6 : options->accuracy, dot = 0,
      num_check = num_digits;
  if (curr_accur == 0) {
    curr_accur = 1;
    dot = (options->hash == 1) ? 0 : 1;
  }
  double g = check_notation(curr_accur);
  while (curr_accur > 0 && num_check > 0) {
    temp = temp * 10;
    if ((int)temp == 9 && curr_accur == 1) {
      if ((int)(temp + 0.5) == 10) {
        str[*point - 1] = (int)str[*point - 1] + 1;
        str[*point] = '0';
      } else
        str[*point] = '9';
    } else {
      str[*point] = (curr_accur == 1) ? ((int)(temp + 0.5) + '0')
                                      : ((int)(temp + g) + '0');
    }
    *point += 1;
    temp -= (int)(temp + g);
    g *= 10;
    if (dot == 0) {
      str[*point] = '.';
      *point += 1;
      dot = 1;
    }
    curr_accur--;
    if (curr_accur == 0) {
      int check = 0, zero = 0, i = 0;
      for (i = *point; i > check; i--) {
        if (str[i - 1] == '0') zero++;
        if (str[i - 1] != '0') check = 3000;
      }
      if (zero == *point - i - 1) {
        while (*point > i + 1) {
          *point -= 1;
          str[*point] = '\0';
        }
      }
      write_exp(num_digits, '+', options, point, str);
    }
    num_check--;
  }
}
void realize_g4(long double f_part, long double s_part, int *cur_hash,
                Options *options, int *point, char *str) {
  s_part = signbit(f_part) ? s_part * -1 : s_part;
  str[*point] = '.';
  *cur_hash = 1;
  *point += 1;
  realize_f(s_part, point, str, options, cur_hash);
  int dot = 0, zero = 0, i = 0;
  for (i = *point; i > dot; i--) {
    if (str[i - 1] == '0') zero++;
    if (str[i - 1] == '.') dot = 3000;
  }
  i++;
  if (zero == *point - i) {
    while (*point >= i) {
      *point -= 1;
      str[*point] = '\0';
    }
  }
  dot = 0;
  zero = 0;
  for (i = *point; i > dot; i--) {
    if (str[i - 1] == '0') zero++;
    if (str[i - 1] != '0') dot = 3000;
  }
  if (zero == *point - i - 1 && options->hash == 0) {
    while (*point > i + 1) {
      *point -= 1;
      str[*point] = '\0';
    }
  }
}

void realize_g5(long double f_part, int *cur_hash, int *cur_accuracy,
                Options *options, int *point, char *str) {
  long int f = signbit(f_part) ? -1 : 1;
  check_negative(&f, point, str, options);
  str[*point] = '0';
  *point += 1;
  if (options->hash == 1 && options->accuracy == -1) {
    *cur_hash = 1;
    str[*point] = '.';
    *point += 1;
    while (*cur_accuracy > 1 && options->hash == 1) {
      str[*point] = '0';
      *point += 1;
      *cur_accuracy -= 1;
    }
  }
}

double check_notation(int cur_accuracy) {
  double g = 1.0;
  while (cur_accuracy > 0) {
    g /= 10;
    cur_accuracy--;
  }
  return g;
}

void realize_e2(long double f_part, long double s_part, int num_digits,
                int cur_accuracy, Options *options, int *point, char *str) {
  s_part = signbit(f_part) ? s_part * -1 : s_part;
  double g = check_notation(cur_accuracy);
  while (cur_accuracy > 0) {
    s_part = s_part * 10;
    if ((int)s_part == 9 && cur_accuracy == 1) {
      if ((int)(s_part + 0.5) == 10) {
        str[*point - 1] = (int)str[*point - 1] + 1;
        str[*point] = '0';
      } else
        str[*point] = '9';
    } else {
      if (cur_accuracy == 1) {
        str[*point] = (int)(s_part + 0.5) + '0';
      } else {
        str[*point] = (int)(s_part + g) + '0';
      }
    }
    *point += 1;
    s_part -= (int)(s_part + g);
    g *= 10;
    cur_accuracy--;
    if (options->e == 1)
      options->g = 1;
    else
      options->G = 1;
  }
  write_exp(num_digits, '+', options, point, str);
}

void realize_e3(long double f_part, long double s_part, int cur_accuracy,
                Options *options, int *point, char *str) {
  int zero_count = 1, zero_stop = 0, dot = 0;
  s_part = signbit(f_part) ? s_part * -1 : s_part;
  double g = check_notation(cur_accuracy);
  while (cur_accuracy > 0) {
    s_part = s_part * 10;
    if ((int)s_part == 0 && zero_stop != -1) {
      zero_count++;
      continue;
    } else
      zero_stop = -1;
    if (cur_accuracy == 1) {
      str[*point] = (int)(s_part + 0.5) + '0';
    } else {
      str[*point] = (int)(s_part + g) + '0';
    }
    *point += 1;
    s_part -= (int)(s_part + g);
    g *= 10;
    if (dot == 0) {
      str[*point] = '.';
      *point += 1;
      dot = 1;
    }
    cur_accuracy -= 1;
    if (cur_accuracy == 0) {
      write_exp(zero_count, '-', options, point, str);
    }
  }
}

void realize_us(short unsigned int value, int *point, char *str,
                Options *options) {
  short unsigned int temp = value;
  int num_digits = 0, gg = 0;
  if (value == 0) {
    check_value_zero(options, point, str);
  } else {
    while (temp != 0) {
      temp /= 10;
      num_digits++;
    }
    char *buffer = (char *)malloc(sizeof(char) * (num_digits + 1));
    dynamic_memory_check(buffer, &gg);
    if (gg != 1) {
      int index = num_digits - 1;
      buffer[num_digits] = '\0';
      while (value != 0 && index >= 0) {
        int digit = value % 10;
        buffer[index] = '0' + digit;
        value /= 10;
        index--;
      }
      index++;
      num_digits = realize_d2(num_digits, options, point, str);
      while (buffer[index] != '\0') {
        str[*point] = buffer[index];
        *point += 1;
        index++;
      }
    }
    free(buffer);
  }
}

void realize_ul(long unsigned int value, int *point, char *str,
                Options *options) {
  long unsigned int temp = value;
  int num_digits = 0, gg = 0;
  if (value == 0) {
    check_value_zero(options, point, str);
  } else {
    while (temp != 0) {
      temp /= 10;
      num_digits++;
    }
    char *buffer = (char *)malloc(sizeof(char) * (num_digits + 1));
    dynamic_memory_check(buffer, &gg);
    if (gg != 1) {
      int index = num_digits - 1;
      buffer[num_digits] = '\0';
      while (value != 0 && index >= 0) {
        int digit = value % 10;
        buffer[index] = '0' + digit;
        value /= 10;
        index--;
      }
      index++;
      num_digits = realize_d2(num_digits, options, point, str);
      while (buffer[index] != '\0') {
        str[*point] = buffer[index];
        *point += 1;
        index++;
      }
    }
    free(buffer);
  }
}

void realize_d(long int value, int *point, char *str, Options *options,
               int *hash) {
  int num_digits = 0, gg = 0;
  check_negative(&value, point, str, options);
  long int temp = value;
  if (value == 0) {
    check_value_zero_d(options, point, str);
  } else {
    while (temp != 0) {
      temp /= 10;
      num_digits++;
    }
    char *buffer = (char *)malloc(sizeof(char) * (num_digits + 1));
    dynamic_memory_check(buffer, &gg);
    if (gg != 1) {
      int index = num_digits - 1;
      buffer[num_digits] = '\0';
      while (value != 0 && index >= 0) {
        int digit = value % 10;
        buffer[index] = '0' + digit;
        value /= 10;
        index--;
      }
      index++;
      num_digits = realize_d2(num_digits, options, point, str);
      options->accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
      if ((options->g == 1 || options->G == 1) &&
          options->accuracy < num_digits) {
        realize_g2(hash, buffer, &index, num_digits, options, point, str);
      } else if ((options->g == 1 || options->G == 1) &&
                 num_digits <=
                     ((options->accuracy == -1) ? 6 : options->accuracy)) {
        options->accuracy = options->accuracy - num_digits + 1000;
        while (buffer[index] != '\0') {
          str[*point] = buffer[index];
          *point += 1;
          index++;
        }
      }
      while (buffer[index] != '\0' && options->g == 0 && options->G == 0) {
        str[*point] = buffer[index];
        *point += 1;
        index++;
      }
    }
    free(buffer);
  }
}

void realize_f(long double value, int *point, char *str, Options *options,
               int *hash) {
  int curr_accur = 6;
  int zero_count = 1, eps = 0, dot = 0, zero_stop = 0;
  if (options->accuracy > 1000) {
    curr_accur = options->accuracy - 1000;
    options->accuracy -= 1000;
    dot = 1;
    zero_stop = -1;
    zero_count = 0;
  }
  if (options->accuracy > -1) curr_accur = options->accuracy;
  if (options->g == 1 || options->G == 1)
    curr_accur = (curr_accur == 0) ? 6 : curr_accur;
  double g = check_notation(curr_accur);
  while (curr_accur > 0 && options->f == 1) {
    value = value * 10.0;
    str[*point] = (curr_accur == 1) ? ((int)(value + 0.5) + '0')
                                    : ((int)(value + g) + '0');
    *point += 1;
    value -= (int)(value + g);
    curr_accur--;
    g *= 10;
  }
  int gg = 0;
  realize_f2(gg, zero_count, value, eps, zero_stop, dot, curr_accur, hash,
             options, point, str);
}

void realize_g_G(long double value, int *point, char *str, Options *options) {
  int cur_hash = 0, cur_accuracy = 6, num_digits = 0;
  long double f_part = 0.0, s_part = modfl(value, &f_part),
              temp = (f_part > 0) ? f_part : -f_part;
  while (temp >= 1) {
    temp /= 10;
    num_digits++;
  }
  if (num_digits > 35) {
    realize_g3(num_digits, temp, options, point, str);
  } else if (f_part != 0) {
    realize_d(f_part, point, str, options, &cur_hash);
  } else if (f_part == 0.0 && s_part == 0.0) {
    realize_g5(f_part, &cur_hash, &cur_accuracy, options, point, str);
  } else if (f_part == 0.0 && s_part != 0.0) {
    long int f = signbit(f_part) ? -1 : 1;
    check_negative(&f, point, str, options);
    s_part = signbit(f_part) ? s_part * -1 : s_part;
    realize_f(s_part, point, str, options, &cur_hash);
  }
  if (options->accuracy > 1000 && s_part != 0) {
    realize_g4(f_part, s_part, &cur_hash, options, point, str);
  } else if (options->accuracy > 1000 && s_part == 0 && options->hash == 1) {
    s_part = signbit(f_part) ? s_part * -1 : s_part;
    str[*point] = '.';
    cur_hash = 1;
    *point += 1;
    while (options->accuracy - 1000 >= 1) {
      str[*point] = '0';
      *point += 1;
      options->accuracy--;
    }
  } else if (options->accuracy == 1000) {
    s_part = signbit(f_part) ? s_part * -1 : s_part;
    int check = (int)(s_part + 0.5);
    if (check > 0) {
      *point -= 1;
      str[*point] = (int)str[*point] + 1;
      *point += 1;
    }
  }
  if (cur_hash == 0 && options->hash == 1) {
    str[*point] = '.';
    *point += 1;
  }
}

void realize_e_E(long double value, int *point, char *str, Options *options) {
  int num_digits = 0, cur_accuracy = 0;
  long double f_part = 0.0, s_part = modfl(value, &f_part),
              temp = (f_part > 0) ? f_part : -f_part;
  while (temp >= 1) {
    temp /= 10;
    num_digits++;
  }
  long int f = signbit(f_part) ? -1 : 1;
  check_negative(&f, point, str, options);
  if (options->e == 1)
    options->g = 1;
  else
    options->G = 1;
  cur_accuracy = (options->accuracy == -1) ? 6 - num_digits + 1
                                           : options->accuracy - num_digits + 1;
  if (num_digits != 0) {
    realize_g3(num_digits, temp, options, point, str);
  }
  if (f_part == 0.0) {
    realize_e3(f_part, s_part, cur_accuracy, options, point, str);
  } else if (s_part == 0.0 && cur_accuracy > 0) {
    while (cur_accuracy > 0) {
      str[*point] = '0';
      *point += 1;
      cur_accuracy--;
    }
    if (options->e == 1)
      options->g = 1;
    else
      options->G = 1;
    write_exp(num_digits, '+', options, point, str);
  } else if (s_part != 0.0 && cur_accuracy > 0) {
    realize_e2(f_part, s_part, num_digits, cur_accuracy, options, point, str);
  }
}

void realize_x_X(unsigned value, int *point, char *str, Options *options) {
  char hex_digits[] = "0123456789abcdef";
  if (options->X == 1) {
    hex_digits[10] = 'A';
    hex_digits[11] = 'B';
    hex_digits[12] = 'C';
    hex_digits[13] = 'D';
    hex_digits[14] = 'E';
    hex_digits[15] = 'F';
  }
  unsigned int remainder = 0, hash = (value == 0) ? 1 : 0;
  if (value == 0 && options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  } else {
    int cur_accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
    while (value > 0) {
      remainder = value % 16;
      str[*point] = hex_digits[remainder];
      *point += 1;
      value = value / 16;
      cur_accuracy--;
    }
    if (cur_accuracy > 0 && options->accuracy != -1)
      while (cur_accuracy > 0) {
        str[*point] = '0';
        *point += 1;
        cur_accuracy--;
      }
  }
  if (options->hash == 1 && hash == 0) {
    if (options->x == 1)
      str[*point] = 'x';
    else if (options->X == 1)
      str[*point] = 'X';
    *point += 1;
    str[*point] = '0';
    *point += 1;
  }
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}

void realize_xs(short unsigned int value, int *point, char *str,
                Options *options) {
  char hex_digits[] = "0123456789abcdef";
  if (options->X == 1) {
    hex_digits[10] = 'A';
    hex_digits[11] = 'B';
    hex_digits[12] = 'C';
    hex_digits[13] = 'D';
    hex_digits[14] = 'E';
    hex_digits[15] = 'F';
  }
  short unsigned int remainder = 0, hash = (value == 0) ? 1 : 0;
  if (value == 0 && options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  } else {
    int cur_accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
    while (value > 0) {
      remainder = value % 16;
      str[*point] = hex_digits[remainder];
      *point += 1;
      value = value / 16;
      cur_accuracy--;
    }
    if (cur_accuracy > 0 && options->accuracy != -1)
      while (cur_accuracy > 0) {
        str[*point] = '0';
        *point += 1;
        cur_accuracy--;
      }
  }
  if (options->hash == 1 && hash == 0) {
    if (options->x == 1)
      str[*point] = 'x';
    else if (options->X == 1)
      str[*point] = 'X';
    *point += 1;
    str[*point] = '0';
    *point += 1;
  }
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}

void realize_xl(long unsigned int value, int *point, char *str,
                Options *options) {
  char hex_digits[] = "0123456789abcdef";
  if (options->X == 1) {
    hex_digits[10] = 'A';
    hex_digits[11] = 'B';
    hex_digits[12] = 'C';
    hex_digits[13] = 'D';
    hex_digits[14] = 'E';
    hex_digits[15] = 'F';
  }
  long unsigned int remainder = 0, hash = (value == 0) ? 1 : 0;
  if (value == 0 && options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  } else {
    int cur_accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
    while (value > 0) {
      remainder = value % 16;
      str[*point] = hex_digits[remainder];
      *point += 1;
      value = value / 16;
      cur_accuracy--;
    }
    if (cur_accuracy > 0 && options->accuracy != -1)
      while (cur_accuracy > 0) {
        str[*point] = '0';
        *point += 1;
        cur_accuracy--;
      }
  }
  if (options->hash == 1 && hash == 0) {
    if (options->x == 1)
      str[*point] = 'x';
    else if (options->X == 1)
      str[*point] = 'X';
    *point += 1;
    str[*point] = '0';
    *point += 1;
  }
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}

void realize_x0(int *point, char *str, Options *options, va_list args) {
  if (options->l != 1 && options->h != 1) {
    realize_x_X(va_arg(args, unsigned), point, str, options);
  } else if (options->l == 1) {
    realize_xl(va_arg(args, long unsigned), point, str, options);
  } else if (options->h == 1) {
    realize_xs((short)va_arg(args, unsigned), point, str, options);
  }
  str[*point] = '\0';
  *point += 1;
}

void realize_o0(int *point, char *str, Options *options, va_list args) {
  if (options->l != 1 && options->h != 1) {
    realize_o1(va_arg(args, unsigned), point, str, options);
  } else if (options->l == 1) {
    realize_ol(va_arg(args, long unsigned), point, str, options);
  } else if (options->h == 1) {
    realize_os((short)va_arg(args, unsigned), point, str, options);
  }
  str[*point] = '\0';
  *point += 1;
}

void realize_o1(unsigned value, int *point, char *str, Options *options) {
  char hex_digits[] = "012345678";
  unsigned int remainder = 0, hash = (value == 0) ? 1 : 0;
  if (value == 0 && options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  } else {
    int cur_accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
    while (value > 0) {
      remainder = value % 8;
      str[*point] = hex_digits[remainder];
      *point += 1;
      value = value / 8;
      cur_accuracy--;
    }
    if (cur_accuracy > 0 && options->accuracy != -1)
      while (cur_accuracy > 0) {
        str[*point] = '0';
        *point += 1;
        cur_accuracy--;
      }
  }
  if (options->hash == 1 && hash == 0) {
    str[*point] = '0';
    *point += 1;
  }
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}
void realize_os(short unsigned int value, int *point, char *str,
                Options *options) {
  char hex_digits[] = "012345678";
  short unsigned int remainder = 0, hash = (value == 0) ? 1 : 0;
  if (value == 0 && options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  } else {
    int cur_accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
    while (value > 0) {
      remainder = value % 8;
      str[*point] = hex_digits[remainder];
      *point += 1;
      value = value / 8;
      cur_accuracy--;
    }
    if (cur_accuracy > 0 && options->accuracy != -1)
      while (cur_accuracy > 0) {
        str[*point] = '0';
        *point += 1;
        cur_accuracy--;
      }
  }
  if (options->hash == 1 && hash == 0) {
    str[*point] = '0';
    *point += 1;
  }
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}
void realize_ol(long unsigned int value, int *point, char *str,
                Options *options) {
  char hex_digits[] = "012345678";
  long unsigned int remainder = 0, hash = (value == 0) ? 1 : 0;
  if (value == 0 && options->accuracy != 0) {
    str[*point] = '0';
    *point += 1;
  } else {
    int cur_accuracy = (options->accuracy == -1) ? 6 : options->accuracy;
    while (value > 0) {
      remainder = value % 8;
      str[*point] = hex_digits[remainder];
      *point += 1;
      value = value / 8;
      cur_accuracy--;
    }
    if (cur_accuracy > 0 && options->accuracy != -1)
      while (cur_accuracy > 0) {
        str[*point] = '0';
        *point += 1;
        cur_accuracy--;
      }
  }
  if (options->hash == 1 && hash == 0) {
    str[*point] = '0';
    *point += 1;
  }
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}

void realize_p(int *point, char *str, Options *options, va_list args) {
  options->p = options->p;
  void *ptr = va_arg(args, void *);
  const char hex_digits[] = "0123456789abcdef";
  unsigned long address = (unsigned long)ptr;
  while (address > 0) {
    int digit = address % 16;
    str[*point] = hex_digits[digit];
    *point += 1;
    address /= 16;
  }
  str[*point] = 'x';
  *point += 1;
  str[*point] = '0';
  *point += 1;
  int length = *point;
  char temp = '0';
  for (int j = 0; j < length / 2; j++) {
    temp = str[j];
    str[j] = str[length - j - 1];
    str[length - j - 1] = temp;
  }
}

void check_negative(long int *value, int *point, char *str, Options *options) {
  if (*value < 0 && (options->space == 1 || options->plus == 1) &&
      options->u != 1) {
    *point -= 1;
    str[*point] = '-';
    *point += 1;
    *value = *value * -1;
  } else if (*value < 0 && options->space == 0 && options->plus == 0 &&
             options->u != 1) {
    str[*point] = '-';
    *point += 1;
    *value = *value * -1;
  }
}

int isint(char format) {
  int choise = 0;
  switch (format) {
    case '1':
      choise = 1;
      break;
    case '2':
      choise = 1;
      break;
    case '3':
      choise = 1;
      break;
    case '4':
      choise = 1;
      break;
    case '5':
      choise = 1;
      break;
    case '6':
      choise = 1;
      break;
    case '7':
      choise = 1;
      break;
    case '8':
      choise = 1;
      break;
    case '9':
      choise = 1;
      break;
    case '0':
      choise = 1;
      break;
    default:
      choise = 0;
      break;
  }
  return choise;
}

void realize_width(char *str, Options *options) {
  if (options->width > (int)s21_strlen(str)) {  // todo s21
    if (options->minus == 1) {
      while (options->width > (int)s21_strlen(str))
        str[s21_strlen(str)] = ' ';  // todo s21
    } else {
      char extra_str[2048];
      for (int i = 0; i < (int)s21_strlen(str); i++) {  // todo s21
        extra_str[i] = str[i];
      }
      int diff = options->width - (int)s21_strlen(str);  // todo s21
      for (int i = 0; i < options->width; i++) {
        if (i < diff &&
            (extra_str[i] == '-' || extra_str[i] == '+' ||
             extra_str[i] == ' ' ||
             (extra_str[i] == '0' &&
              (extra_str[i + 1] == 'x' || extra_str[i + 1] == 'X'))) &&
            i == 0 && options->zero == 1) {
          if (extra_str[i] == '-')
            str[i] = '-';
          else if (extra_str[i] == '+')
            str[i] = '+';
          else if (extra_str[i] == ' ')
            str[i] = ' ';
          else if (extra_str[i] == '0') {
            str[i] = '0';
            if (extra_str[i + 1] == 'x')
              str[++i] = 'x';
            else if (extra_str[i + 1] == 'X')
              str[++i] = 'X';
            extra_str[1] = (options->zero == 1) ? '0' : ' ';
          }
          extra_str[0] = (options->zero == 1) ? '0' : ' ';
        } else if (i < diff) {
          if (options->zero == 1)
            str[i] = '0';
          else
            str[i] = ' ';
        } else {
          str[i] = extra_str[i - diff];
        }
      }
    }
  }
}

// int main() {
//   char buffer1[8000] = {'\0'};
//   char buffer2[8000] = {'\0'};
//   int a = 10;
//   s21_sprintf(buffer1, "I have |%-30p| times to go", &a);
//   sprintf(buffer2, "I have |%-30p| times to go", &a);
//   printf("Orig format: %s\n", buffer2);
//   printf("s21s format: %s\n", buffer1);

//   // char buf[200] = {'\0'}, buf2[200] = {'\0'};
//   // long double x = 200541545671.0;
//   // int orig = 0, s21 = 0;
//   // orig = sprintf(buf, "%#g", 1.1);
//   // s21 = s21_sprintf(buf2, "%#g", 1.1);
//   // printf("Orig format: %s\n", buf);
//   // printf("s21s format: %s\n", buf2);
//   return 0;
// }