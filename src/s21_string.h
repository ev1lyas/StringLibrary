#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef SRC_S21_STRING_H
#define SRC_S21_STRING_H

typedef long unsigned s21_size_t;
#define S21_NULL ((void *)0)

s21_size_t s21_strlen(const char *str);
int s21_strcmp(char *str1, char *str2);
s21_size_t s21_strcspn(const char *str, const char *sym);
s21_size_t s21_strspn(const char *str, const char *sym);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
int s21_memcmp(const void *arr1, const void *arr2, s21_size_t n);
int s21_strncmp(const char *arr1, const char *arr2, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strcpy(char *dest, const char *src);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

int find_ind(const char *src, const char *trim_chars, int index);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strerror(int errnum);
typedef struct {
  int c;
  int d;
  int i;
  int e;
  int E;
  int f;
  int g;
  int G;
  int o;
  int s;
  int u;
  int x;
  int X;
  int p;
  int h;
  int l;
  int L;
  int zero;
  int hash;
  int space;
  int plus;
  int minus;
  int width;
  int accuracy;
  int accuracy_help;
  int percent;
  int error;
} Options;

int s21_sprintf(char *str, const char *format, ...);
void realize_d(long int value, int *point, char *str, Options *options,
               int *hash);
void realize_f(long double value, int *point, char *str, Options *options,
               int *hash);
void check_negative(long int *value, int *point, char *str, Options *options);
int isint(char format);
void realize_width(char *str, Options *options);
const char *check_flags(Options *options, const char *format, char *cur_str,
                        int *cur_point);
const char *check_width(Options *options, const char *format, va_list args);
const char *check_accuracy(Options *options, const char *format, va_list args);
const char *check_length(Options *options, const char *format);
const char *check_specifier(Options *options, const char *format);
void collect_buf(Options *options, char *cur_str, int *cur_point, va_list args);
void check_errors(Options *options);
void realize_g_G(long double value, int *point, char *str, Options *options);
void realize_e_E(long double value, int *point, char *str, Options *options);
void realize_us(short unsigned int value, int *point, char *str,
                Options *options);
void realize_ul(long unsigned int value, int *point, char *str,
                Options *options);
void realize_f0(Options *options, char *cur_str, int *cur_point, va_list args);
void realize_d0(Options *options, char *cur_str, int *cur_point, va_list args);
void realize_s0(Options *options, char *cur_str, int *cur_point, va_list args);
void realize_u0(Options *options, char *cur_str, int *cur_point, va_list args);
void realize_g0(Options *options, char *cur_str, int *cur_point, va_list args);
void check_value_zero(Options *options, int *point, char *str);
void check_value_zero_d(Options *options, int *point, char *str);
void write_exp(int num_digits, char sign, Options *options, int *point,
               char *str);
void realize_g2(int *hash, char *buffer, int *index, int num_digits,
                Options *options, int *point, char *str);
void dynamic_memory_check(char *buffer, int *gg);
int realize_d2(int num_digits, Options *options, int *point, char *str);
void realize_f2(int gg, int zero_count, long double value, int eps,
                int zero_stop, int dot, int curr_accur, int *hash,
                Options *options, int *point, char *str);
void realize_g3(int num_digits, long double temp, Options *options, int *point,
                char *str);
void realize_g4(long double f_part, long double s_part, int *cur_hash,
                Options *options, int *point, char *str);
void realize_g5(long double f_part, int *cur_hash, int *cur_accuracy,
                Options *options, int *point, char *str);
double check_notation(int cur_accuracy);
void realize_e2(long double f_part, long double s_part, int num_digits,
                int cur_accuracy, Options *options, int *point, char *str);
void realize_e2(long double f_part, long double s_part, int num_digits,
                int cur_accuracy, Options *options, int *point, char *str);
void realize_x_X(unsigned value, int *point, char *str, Options *options);
void realize_x0(int *point, char *str, Options *options, va_list args);
void realize_xs(short unsigned int value, int *point, char *str,
                Options *options);
void realize_xl(long unsigned int value, int *point, char *str,
                Options *options);
void realize_o0(int *point, char *str, Options *options, va_list args);
void realize_o1(unsigned value, int *point, char *str, Options *options);
void realize_os(short unsigned int value, int *point, char *str,
                Options *options);
void realize_ol(long unsigned int value, int *point, char *str,
                Options *options);
void realize_p(int *point, char *str, Options *options, va_list args);
#endif