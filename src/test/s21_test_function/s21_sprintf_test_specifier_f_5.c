#include "../s21_tests.h"

/*Specifier f Table 5*/
START_TEST(test1) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %+20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %+20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %+20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %+20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % 20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have % 20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % 20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have % 20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test7) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %#20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %#20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test8) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %#20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %#20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % 20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have % 20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % 20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have % 20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %+020.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %+020.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test12) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %+020.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %+020.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test13) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % 020.15f times to go", 26704.45167);
  sprintf(buffer2, "I have % 020.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test14) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % 020.15f times to go", -26704.45167);
  sprintf(buffer2, "I have % 020.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test15) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %+#20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %+#20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test16) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have % #20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have % #20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test17) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %-20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %-20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test18) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %-20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %-20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test19) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %-+20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %-+20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test20) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %-+20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %-+20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test21) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %- 20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %- 20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test22) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %- 20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %- 20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test23) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %-+#20.15f times to go", 26704.45167);
  sprintf(buffer2, "I have %-+#20.15f times to go", 26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test24) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %- #20.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %- #20.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test25) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "I have %+030.15f times to go", -26704.45167);
  sprintf(buffer2, "I have %+030.15f times to go", -26704.45167);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_f_5() {
  Suite *s = suite_create("\033[45m| s21_sprintf_test specifier f 5 |\033[0m");
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
  tcase_add_test(t, test12);
  tcase_add_test(t, test13);
  tcase_add_test(t, test14);
  tcase_add_test(t, test15);
  tcase_add_test(t, test16);
  tcase_add_test(t, test17);
  tcase_add_test(t, test18);
  tcase_add_test(t, test19);
  tcase_add_test(t, test20);
  tcase_add_test(t, test21);
  tcase_add_test(t, test22);
  tcase_add_test(t, test23);
  tcase_add_test(t, test24);
  tcase_add_test(t, test25);

  suite_add_tcase(s, t);
  return s;
}