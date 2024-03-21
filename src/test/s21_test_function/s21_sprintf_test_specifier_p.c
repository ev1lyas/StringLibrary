#include "../s21_tests.h"

START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = 10;
  s21_sprintf(buffer1, "I have |%p| times to go", &a);
  sprintf(buffer2, "I have |%p| times to go", &a);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = 10;
  s21_sprintf(buffer1, "I have |%30p| times to go", &a);
  sprintf(buffer2, "I have |%30p| times to go", &a);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = 10;
  s21_sprintf(buffer1, "I have |%-30p| times to go", &a);
  sprintf(buffer2, "I have |%-30p| times to go", &a);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_p() {
  Suite *s = suite_create("\033[45m| s21_sprintf_test specifier p |\033[0m");
  TCase *t = tcase_create("s21_sprintf_test_x");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  suite_add_tcase(s, t);
  return s;
}