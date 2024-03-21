#include "../s21_tests.h"

/*specifiers s*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %s, Try to do it!", "Bober");
  sprintf(buffer2, "Bye %s, Try to do it!", "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %10s, Try to do it!", "Bober");
  sprintf(buffer2, "Bye %10s, Try to do it!", "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %-10s, Try to do it!", "Bober");
  sprintf(buffer2, "Bye %-10s, Try to do it!", "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %.2s, Try to do it!", "Bober");
  sprintf(buffer2, "Bye %.2s, Try to do it!", "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %10.2s, Try to do it!", "Bober");
  sprintf(buffer2, "Bye %10.2s, Try to do it!", "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %-10.2s, Try to do it!", "Bober");
  sprintf(buffer2, "Bye %-10.2s, Try to do it!", "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test7) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %*s, Try to do it!", 10, "Bober");
  sprintf(buffer2, "Bye %*s, Try to do it!", 10, "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %-*s, Try to do it!", 10, "Bober");
  sprintf(buffer2, "Bye %-*s, Try to do it!", 10, "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %.*s, Try to do it!", 3, "Bober");
  sprintf(buffer2, "Bye %.*s, Try to do it!", 3, "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %*.*s, Try to do it!", 10, 2, "Bober");
  sprintf(buffer2, "Bye %*.*s, Try to do it!", 10, 2, "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %-*.*s, Try to do it!", 10, 2, "Bober");
  sprintf(buffer2, "Bye %-*.*s, Try to do it!", 10, 2, "Bober");
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_s() {
  Suite *s = suite_create("\033[45m| s21_sprintf_test specifier s |\033[0m");
  TCase *t = tcase_create("s21_sprintf_test_x");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  tcase_add_test(t, test7);
  tcase_add_test(t, test8);
  tcase_add_test(t, test9);
  tcase_add_test(t, test10);
  tcase_add_test(t, test11);
  suite_add_tcase(s, t);
  return s;
}