#include "../s21_tests.h"

START_TEST(s21_memcmp_test_1) {
  char str1[] = "qwerty";
  char str2[] = "qwerty";
  int n = 0;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_2) {
  char str1[] = "qwerty";
  char str2[] = "qwerty";
  int n = 3;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_3) {
  char str1[] = "qwerty";
  char str2[] = "Qwerty";
  int n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_4) {
  char str1[] = "1234";
  char str2[] = "1234";
  int n = 2;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_5) {
  char str1[] = "1234567890 qwertyuiopasdfghjklzxcvbnm ASDFG";
  char str2[] = "1234567890 qwertyuiopasdfghjklzxcvbnm ASDFG";
  int n = 43;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(s21_memcmp_test_6) {
  char str1[] = "1234567890 qwertyuiopasdfghjklzxcvbnm ASDFG";
  char str2[] = "1234567890 qwertyuiopasdfghjklzxcvbnm ASDFg";
  int n = 43;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

// s21_strchr
START_TEST(s21_strchr_test_1) {
  char str[] = "0123456789";
  int c = '5';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test_2) {
  char str[] = "hello world";
  int c = 'z';
  ck_assert_ptr_eq(s21_strchr(str, c), S21_NULL);
}
END_TEST

START_TEST(s21_strchr_test_3) {
  char str[] = "hello world";
  int c = 'o';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

// s21_strncmp
START_TEST(s21_strncmp_test_1) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n_byte = 0;

  int s21 = s21_strncmp(str1, str2, n_byte);
  int ori = strncmp(str1, str2, n_byte);

  if (s21 > 1) s21 = 1;
  if (ori > 1) ori = 1;

  if (s21 < -1) s21 = -1;
  if (ori < -1) ori = -1;

  ck_assert_int_eq(s21, ori);
}
END_TEST

START_TEST(s21_strncmp_test_2) {
  char str1[] = "qwerty";
  char str2[] = "";
  s21_size_t n_byte = 6;

  int s21 = s21_strncmp(str1, str2, n_byte);
  int ori = strncmp(str1, str2, n_byte);

  if (s21 > 1) s21 = 1;
  if (ori > 1) ori = 1;

  if (s21 < -1) s21 = -1;
  if (ori < -1) ori = -1;

  ck_assert_int_eq(s21, ori);
}
END_TEST

START_TEST(s21_strncmp_test_3) {
  char str1[] = "";
  char str2[] = "qwerty";
  s21_size_t n_byte = 6;

  int s21 = s21_strncmp(str1, str2, n_byte);
  int ori = strncmp(str1, str2, n_byte);

  if (s21 > 1) s21 = 1;
  if (ori > 1) ori = 1;

  if (s21 < -1) s21 = -1;
  if (ori < -1) ori = -1;

  ck_assert_int_eq(s21, ori);
}
END_TEST

// s21_strncpy
START_TEST(s21_strncpy_test_1) {
  char src[] = "";
  char res[] = "";
  char exp[] = "";
  s21_size_t n = 0;

  s21_strncpy(res, src, n);
  strncpy(exp, src, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_test_2) {
  char src[] = "qwe";
  char res[] = "qwe";
  char exp[] = "qwe";
  s21_size_t n = 0;

  s21_strncpy(res, src, n);
  strncpy(exp, src, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_test_3) {
  char src[] = "world";
  char res[] = "Hello";
  char exp[] = "Hello";
  s21_size_t n = 0;

  s21_strncpy(res, src, n);
  strncpy(exp, src, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_test_4) {
  char src[] = "123";
  char res[5] = "123";
  char exp[5] = "123";
  s21_size_t n = 1;

  s21_strncpy(res, src, n);
  strncpy(exp, src, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_test_5) {
  char src[] = "123";
  char res[7] = "123";
  char exp[7] = "123";
  s21_size_t n = 2;

  s21_strncpy(res, src, n);
  strncpy(exp, src, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

START_TEST(s21_strncpy_test_6) {
  char src[] = "Str1ng";
  char res[14] = "Str1ng";
  char exp[14] = "Str1ng";
  s21_size_t n = 7;

  s21_strncpy(res, src, n);
  strncpy(exp, src, n);

  ck_assert_str_eq(res, exp);
}
END_TEST

// s21_strcspn
START_TEST(s21_strcspn_test_1) {
  char src[] = "";
  char res[] = "";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_test_2) {
  char src[] = "123";
  char res[] = "123";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_test_3) {
  char src[] = "qwe";
  char res[] = "qwe";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_test_4) {
  char src[] = "qwe23";
  char res[] = "qwe23";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

START_TEST(s21_strcspn_test_5) {
  char src[] = "123QWe";
  char res[] = "123QWe";

  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST

// s21_strlen
START_TEST(s21_strlen_test_1) {
  char src[] = "";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_2) {
  char src[] = "hafafdhgsjsg";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_3) {
  char src[] = "987623456124678";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_strlen_test_4) {
  char src[] = "12345645qwefsfdfWERWR....asdDSqw";

  ck_assert_int_eq(s21_strlen(src), strlen(src));
}
END_TEST

START_TEST(s21_memset_test_1) {
  char str1[10] = "abcdefghi";
  ck_assert_ptr_eq(s21_memset(str1, 'A', 5), memset(str1, 'A', 5));
}
END_TEST

START_TEST(s21_memset_test_2) {
  char str2[10] = "abcdefghi";
  ck_assert_ptr_eq(s21_memset(str2, '\0', 4), memset(str2, '\0', 4));
}
END_TEST

START_TEST(s21_strchr_test_4) {
  char str[] = "0123456789";
  int c = '5';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test_5) {
  char str[] = "hello world";
  int c = 'z';
  ck_assert_ptr_eq(s21_strchr(str, c), S21_NULL);
}
END_TEST

START_TEST(s21_strchr_test_6) {
  char str[] = "hello world";
  int c = 'o';
  ck_assert_ptr_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strlen_test1) {
  // Тест 1: пустая строка
  const char *str1 = "";
  s21_size_t result1 = s21_strlen(str1);
  ck_assert_int_eq(result1, 0);
}
END_TEST

START_TEST(s21_strlen_test2) {
  const char *str2 = "a";
  s21_size_t result2 = s21_strlen(str2);
  ck_assert_int_eq(result2, 1);
}
END_TEST

START_TEST(s21_strlen_test3) {
  // Тест 3: строка из нескольких символов
  const char *str3 = "Hello";
  s21_size_t result3 = s21_strlen(str3);
  ck_assert_int_eq(result3, 5);
}
END_TEST

START_TEST(s21_strncat_test_1) {
  char *src = "world!";
  s21_size_t n = 0;
  char dest[20] = "Hello, ";
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(s21_strncat_test_2) {
  char *src = "";
  s21_size_t n = 7;
  char dest[20] = "Hello, ";
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(s21_strncat_test_3) {
  char *src = "world!";
  s21_size_t n = 7;
  char dest[20] = "";
  ck_assert_ptr_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(s21_strpbrk_test_1) {
  ck_assert_int_eq(
      strcmp(s21_strpbrk("this is", "abs"), strpbrk("this is", "abs")), 0);
  ck_assert_int_eq(
      strcmp(s21_strpbrk("this is", "th"), strpbrk("this is", "th")), 0);
  ck_assert_int_eq(
      strcmp(s21_strpbrk("this is", "hi"), strpbrk("this is", "hi")), 0);
  ck_assert_ptr_eq(s21_strpbrk("this is", ""), strpbrk("this is", ""));
  ck_assert_ptr_eq(s21_strpbrk("this is", "dplf"), strpbrk("this is", "dplf"));
}
END_TEST

START_TEST(s21_strpbrk_test_2) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == S21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(s21_strrchr_test_1) {
  char msg[50] = "Hello, World!";
  ck_assert_ptr_eq(s21_strrchr(msg, ','), strrchr(msg, ','));
  ck_assert_ptr_eq(s21_strrchr(msg, 'h'), strrchr(msg, 'h'));
  ck_assert_ptr_eq(s21_strrchr(msg, ' '), strrchr(msg, ' '));
}
END_TEST

START_TEST(s21_strrchr_test_2) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
}
END_TEST

START_TEST(s21_strstr_test_1) {
  ck_assert_ptr_eq(s21_strstr("abc", ""), strstr("abc", ""));
  ck_assert_ptr_eq(s21_strstr("abc", "a"), strstr("abc", "a"));
  ck_assert_ptr_eq(s21_strstr("hello", "el"), strstr("hello", "el"));
  char msg[50] = "abcdef";
  ck_assert_ptr_eq(s21_strstr(msg, "ab"), strstr(msg, "ab"));
  ck_assert_ptr_eq(s21_strstr(msg, "1"), strstr(msg, "1"));
}
END_TEST

START_TEST(s21_strstr_test_2) {
  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(s21_strtok_test_1) {
  char str[30] = "abc cde,llf.ggg";
  char str2[30] = "abc cde,llf.ggg";
  ck_assert_int_eq(strcmp(s21_strtok(str, " .,"), strtok(str2, " .,")), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, " .,"), strtok(NULL, " .,")), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, " .,"), strtok(NULL, " .,")), 0);
  ck_assert_int_eq(strcmp(s21_strtok(NULL, " .,"), strtok(NULL, " .,")), 0);
  ck_assert_ptr_eq(s21_strtok(NULL, " .,"), strtok(NULL, " .,"));
}
END_TEST

START_TEST(s21_strtok_test_2) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";

  char str_strtok2[] = "one/two/three(four)five";
  char delim2[] = "/()";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim1);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

// louellat
START_TEST(S21_MEMCHR) {
  char *src_msg = "abcd e f g";
  ck_assert_ptr_eq(s21_memchr(src_msg, 'f', 4), memchr(src_msg, 'f', 4));
  ck_assert_str_eq(s21_memchr(src_msg, 'f', 8), memchr(src_msg, 'f', 8));

  // null
  ck_assert_ptr_eq(s21_memchr(src_msg, 's', 5), memchr(src_msg, 's', 5));
  ck_assert_ptr_eq(s21_memchr(src_msg, 'z', 11), memchr(src_msg, 'z', 11));

  // not equal
  ck_assert_ptr_ne(s21_memchr(src_msg, 's', 5), memchr(src_msg, 'd', 5));
}
END_TEST

START_TEST(S21_MEMCPY) {
  char *src_msg = "Everything we hear is an opinion, not a fact.";
  char dst_string[100];
  int n = 10;
  ck_assert_str_eq((s21_memcpy(&dst_string, src_msg, n)),
                   memcpy(&dst_string, src_msg, n));
  n = 5;
  ck_assert_str_eq((s21_memcpy(&dst_string, src_msg, n)),
                   memcpy(&dst_string, src_msg, n));
  n = 10;
  ck_assert_str_eq((s21_memcpy(&dst_string, src_msg, n)),
                   memcpy(&dst_string, src_msg, n));
  n = 0;
  ck_assert_ptr_eq((s21_memcpy(&dst_string, src_msg, n)),
                   memcpy(&dst_string, src_msg, n));
  n = 46;
  ck_assert_str_eq((s21_memcpy(&dst_string, src_msg, n)),
                   memcpy(&dst_string, src_msg, n));
}
END_TEST

START_TEST(S21_MEMCPY_2) {
  char *src_msg = "Everything we hear is an opinion";
  char dst_string[100];
  int n = 0;
  ck_assert_ptr_eq((s21_memcpy(&dst_string, src_msg, n)),
                   memcpy(&dst_string, src_msg, n));
}
END_TEST

START_TEST(S21_STRERROR) {
  int nums_error[5] = {1, 15, 110, 60, 210};
  for (int i = 0; i < 5; i++) {
    ck_assert_str_eq(s21_strerror(nums_error[i]), strerror(nums_error[i]));
  }
}
END_TEST

START_TEST(test1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  int n = sizeof(str1);

  for (int i = 0; i < n; i++) {
    int result = s21_strncmp(str1, str2, i);
    int expected = strncmp(str1, str2, i);
    ck_assert_int_eq(result > 0    ? 1
                     : result == 0 ? 0
                                   : -1,
                     expected > 0    ? 1
                     : expected == 0 ? 0
                                     : -1);
  }
}
END_TEST
START_TEST(test2) {
  char str[] = "Hello world";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

Suite *s21_string_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_string_test |\033[0m");
  t = tcase_create("s21_string_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_memcmp_test_1);
  tcase_add_test(t, s21_memcmp_test_2);
  tcase_add_test(t, s21_memcmp_test_3);
  tcase_add_test(t, s21_memcmp_test_4);
  tcase_add_test(t, s21_memcmp_test_5);
  tcase_add_test(t, s21_memcmp_test_6);
  tcase_add_test(t, s21_strchr_test_1);
  tcase_add_test(t, s21_strchr_test_2);
  tcase_add_test(t, s21_strchr_test_3);
  tcase_add_test(t, s21_strchr_test_4);
  tcase_add_test(t, s21_strchr_test_5);
  tcase_add_test(t, s21_strchr_test_6);
  tcase_add_test(t, s21_strncmp_test_1);
  tcase_add_test(t, s21_strncmp_test_2);
  tcase_add_test(t, s21_strncmp_test_3);
  tcase_add_test(t, s21_strncpy_test_1);
  tcase_add_test(t, s21_strncpy_test_2);
  tcase_add_test(t, s21_strncpy_test_3);
  tcase_add_test(t, s21_strncpy_test_4);
  tcase_add_test(t, s21_strncpy_test_5);
  tcase_add_test(t, s21_strncpy_test_6);
  tcase_add_test(t, s21_strcspn_test_1);
  tcase_add_test(t, s21_strcspn_test_2);
  tcase_add_test(t, s21_strcspn_test_3);
  tcase_add_test(t, s21_strcspn_test_4);
  tcase_add_test(t, s21_strcspn_test_5);
  tcase_add_test(t, s21_strlen_test_1);
  tcase_add_test(t, s21_strlen_test_2);
  tcase_add_test(t, s21_strlen_test_3);
  tcase_add_test(t, s21_strlen_test_4);
  tcase_add_test(t, s21_memset_test_1);
  tcase_add_test(t, s21_memset_test_2);
  tcase_add_test(t, s21_strlen_test1);
  tcase_add_test(t, s21_strlen_test2);
  tcase_add_test(t, s21_strlen_test3);
  tcase_add_test(t, s21_strncat_test_1);
  tcase_add_test(t, s21_strncat_test_2);
  tcase_add_test(t, s21_strncat_test_3);
  tcase_add_test(t, s21_strpbrk_test_1);
  tcase_add_test(t, s21_strpbrk_test_2);
  tcase_add_test(t, s21_strrchr_test_1);
  tcase_add_test(t, s21_strrchr_test_2);
  tcase_add_test(t, s21_strstr_test_1);
  tcase_add_test(t, s21_strstr_test_2);
  tcase_add_test(t, s21_strtok_test_1);
  tcase_add_test(t, s21_strtok_test_2);

  tcase_add_test(t, S21_MEMCHR);
  tcase_add_test(t, S21_MEMCPY);
  tcase_add_test(t, S21_MEMCPY_2);
  tcase_add_test(t, S21_STRERROR);
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);

  suite_add_tcase(s, t);
  return s;
}
