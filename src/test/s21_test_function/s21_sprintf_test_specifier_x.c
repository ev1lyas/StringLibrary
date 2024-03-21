#include "../s21_tests.h"

/*specifiers x*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have |%x| times to go", 16384);
  sprintf(buffer2, "I have |%x| times to go", 16384);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have |%x| times to go", 123456789);
  sprintf(buffer2, "I have |%x| times to go", 123456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have |%lx| times to go", 5124095576030430L);
  sprintf(buffer2, "I have |%lx| times to go", 5124095576030430L);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have |%lX| times to go", 5124095576030430L);
  sprintf(buffer2, "I have |%lX| times to go", 5124095576030430L);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_x() {
  Suite *s = suite_create("\033[45m| s21_sprintf_test specifier x |\033[0m");
  TCase *t = tcase_create("s21_sprintf_test_x");
  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  suite_add_tcase(s, t);
  return s;
}