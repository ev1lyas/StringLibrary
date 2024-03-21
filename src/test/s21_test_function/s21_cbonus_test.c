#include "../s21_tests.h"

// s21_to_upper
START_TEST(s21_to_upper_test_1) {
  char str[] = "hello world";
  char expected[] = "HELLO WORLD";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

// s21_to_lower
START_TEST(s21_to_lower_test_1) {
  char str[] = "HELLO WORLD";
  char expected[] = "hello world";
  char *got = s21_to_lower(str);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

// s21_insert
START_TEST(s21_insert_test_1) {
  char src[] = "Hello";
  char str[] = "";
  s21_size_t index = 7;
  char *got = s21_insert(src, str, index);

  ck_assert_pstr_eq(got, S21_NULL);

  free(got);
}
END_TEST

START_TEST(s21_insert_test_2) {
  char src[] = "Hello world";
  char str[] = "my ";
  s21_size_t index = 6;
  char *got = s21_insert(src, str, index);

  ck_assert_pstr_eq(got, "Hello my world");

  free(got);
}
END_TEST

START_TEST(s21_insert_test_3) {
  char src[] = "";
  char str[] = "qwe";
  s21_size_t index = 0;
  char *got = s21_insert(src, str, index);

  ck_assert_pstr_eq(got, "qwe");

  free(got);
}
END_TEST

START_TEST(s21_insert_test_4) {
  char src[] = "Hello";
  char str[] = " world";
  s21_size_t index = 5;
  char *got = s21_insert(src, str, index);

  ck_assert_pstr_eq(got, "Hello world");

  free(got);
}
END_TEST

START_TEST(s21_insert_test_5) {
  char src[] = "check";
  char str[] = "Please";
  s21_size_t index = 0;
  char *got = s21_insert(src, str, index);

  ck_assert_pstr_eq(got, "Pleasecheck");

  free(got);
}
END_TEST

START_TEST(s21_insert_test_6) {
  char src[] = "aaaaaaooooo";
  char str[] = "qwe";
  s21_size_t index = 6;
  char *got = s21_insert(src, str, index);

  ck_assert_pstr_eq(got, "aaaaaaqweooooo");

  free(got);
}
END_TEST

// s21_trim
START_TEST(s21_trim_test_1) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_2) {
  char str[] = "";
  char trim_ch[] = "qwerty123";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_3) {
  char str[] = "qwerty123";
  char trim_ch[] = "";
  char expected[] = "qwerty123";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_4) {
  char str[] = "qwerty123";
  char trim_ch[] = "qwerty123";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_5) {
  char str[] = "!@qwe@ty@!";
  char trim_ch[] = "!@";
  char expected[] = "qwe@ty";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_6) {
  char str[] = " qwerty    ";
  char trim_ch[] = " ";
  char expected[] = "qwerty";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_7) {
  char str[] = "        qwer         ";
  char trim_ch[] = "";
  char expected[] = "qwer";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

START_TEST(s21_trim_test_8) {
  char str[] = "        qwer         ";
  char *trim_ch = NULL;
  char expected[] = "qwer";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);

  free(got);
}
END_TEST

Suite *s21_cbonus_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_cbonus_test |\033[0m");
  t = tcase_create("s21_cbonus_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_to_upper_test_1);
  tcase_add_test(t, s21_to_lower_test_1);
  tcase_add_test(t, s21_insert_test_1);
  tcase_add_test(t, s21_insert_test_2);
  tcase_add_test(t, s21_insert_test_3);
  tcase_add_test(t, s21_insert_test_4);
  tcase_add_test(t, s21_insert_test_5);
  tcase_add_test(t, s21_insert_test_6);
  tcase_add_test(t, s21_trim_test_1);
  tcase_add_test(t, s21_trim_test_2);
  tcase_add_test(t, s21_trim_test_3);
  tcase_add_test(t, s21_trim_test_4);
  tcase_add_test(t, s21_trim_test_5);
  tcase_add_test(t, s21_trim_test_6);
  tcase_add_test(t, s21_trim_test_7);
  tcase_add_test(t, s21_trim_test_8);
  suite_add_tcase(s, t);
  return s;
}
