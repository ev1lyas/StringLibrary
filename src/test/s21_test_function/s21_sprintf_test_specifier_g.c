#include "../s21_tests.h"

/*Specifier g*/
START_TEST(test1) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123.312);
  sprintf(buffer2, "I have %g times to go", 123.312);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test2) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123456.312);
  sprintf(buffer2, "I have %g times to go", 123456.312);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test3) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123456.789);
  sprintf(buffer2, "I have %g times to go", 123456.789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test4) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123.);
  sprintf(buffer2, "I have %g times to go", 123.);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test5) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123.456789);
  sprintf(buffer2, "I have %g times to go", 123.456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test6) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123456.456789);
  sprintf(buffer2, "I have %g times to go", 123456.456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test7) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.15g times to go", 123456.456789);
  sprintf(buffer2, "I have %.15g times to go", 123456.456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test8) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.15g times to go", 123.4);
  sprintf(buffer2, "I have %.15g times to go", 123.4);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test9) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123.4);
  sprintf(buffer2, "I have %g times to go", 123.4);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test10) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 0.1234567);
  sprintf(buffer2, "I have %g times to go", 0.1234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test11) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 0.01234567);
  sprintf(buffer2, "I have %g times to go", 0.01234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test12) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 0.001234567);
  sprintf(buffer2, "I have %g times to go", 0.001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test13) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 0.0001234567);
  sprintf(buffer2, "I have %g times to go", 0.0001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test14) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 0.00001234567);
  sprintf(buffer2, "I have %g times to go", 0.00001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test15) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.10g times to go", 0.00000001234567);
  sprintf(buffer2, "I have %.10g times to go", 0.00000001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test16) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 0.00000001234567);
  sprintf(buffer2, "I have %g times to go", 0.00000001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test17) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.3g times to go", 0.00000001234567);
  sprintf(buffer2, "I have %.3g times to go", 0.00000001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test18) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123.312);
  sprintf(buffer2, "I have %g times to go", -123.312);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test19) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123456.312);
  sprintf(buffer2, "I have %g times to go", -123456.312);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test20) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123456.789);
  sprintf(buffer2, "I have %g times to go", -123456.789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test21) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123.);
  sprintf(buffer2, "I have %g times to go", -123.);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test22) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -1234.456789);
  sprintf(buffer2, "I have %g times to go", -1234.456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test23) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123456.456789);
  sprintf(buffer2, "I have %g times to go", -123456.456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test24) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.15g times to go", -123456.456789);
  sprintf(buffer2, "I have %.15g times to go", -123456.456789);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test25) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.15g times to go", -123.4);
  sprintf(buffer2, "I have %.15g times to go", -123.4);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test26) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123.4);
  sprintf(buffer2, "I have %g times to go", -123.4);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test27) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -0.1234567);
  sprintf(buffer2, "I have %g times to go", -0.1234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test28) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -0.01234567);
  sprintf(buffer2, "I have %g times to go", -0.01234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test29) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -0.001234567);
  sprintf(buffer2, "I have %g times to go", -0.001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test30) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -0.0001234567);
  sprintf(buffer2, "I have %g times to go", -0.0001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test31) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -0.00001234567);
  sprintf(buffer2, "I have %g times to go", -0.00001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test32) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.10g times to go", -0.00000001234567);
  sprintf(buffer2, "I have %.10g times to go", -0.00000001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test33) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -0.00000001234567);
  sprintf(buffer2, "I have %g times to go", -0.00000001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test34) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.3g times to go", -0.00000001234567);
  sprintf(buffer2, "I have %.3g times to go", -0.00000001234567);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test35) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 123456789.12345678);
  sprintf(buffer2, "I have %g times to go", 123456789.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test36) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -123456789.12345678);
  sprintf(buffer2, "I have %g times to go", -123456789.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test37) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 12345678.12345678);
  sprintf(buffer2, "I have %g times to go", 12345678.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test38) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", -12345678.12345678);
  sprintf(buffer2, "I have %g times to go", -12345678.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test39) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.15g times to go", 12345678.12345678);
  sprintf(buffer2, "I have %.15g times to go", 12345678.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test40) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.15g times to go", -12345678.12345678);
  sprintf(buffer2, "I have %.15g times to go", -12345678.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test41) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.12g times to go", 12345678.12345678);
  sprintf(buffer2, "I have %.12g times to go", 12345678.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test42) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.12g times to go", -12345678.12345678);
  sprintf(buffer2, "I have %.12g times to go", -12345678.12345678);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test43) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %g times to go", 1.79769e+308);
  sprintf(buffer2, "I have %g times to go", 1.79769e+308);
  ck_assert_str_eq(buffer1, buffer2);
}

START_TEST(test44) {
  char buffer1[8000] = {'\0'};
  char buffer2[8000] = {'\0'};
  s21_sprintf(buffer1, "I have %.3g times to go", 1.79769e+308);
  sprintf(buffer2, "I have %.3g times to go", 1.79769e+308);
  ck_assert_str_eq(buffer1, buffer2);
}

Suite *s21_sprintf_test_suite_specifier_g() {
  Suite *s = suite_create("\033[45m| s21_sprintf_test specifier g |\033[0m");
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
  tcase_add_test(t, test26);
  tcase_add_test(t, test27);
  tcase_add_test(t, test28);
  tcase_add_test(t, test29);
  tcase_add_test(t, test30);
  tcase_add_test(t, test31);
  tcase_add_test(t, test32);
  tcase_add_test(t, test33);
  tcase_add_test(t, test34);
  tcase_add_test(t, test35);
  tcase_add_test(t, test36);
  tcase_add_test(t, test37);
  tcase_add_test(t, test38);
  tcase_add_test(t, test39);
  tcase_add_test(t, test40);
  tcase_add_test(t, test41);
  tcase_add_test(t, test42);
  tcase_add_test(t, test43);
  tcase_add_test(t, test44);
  suite_add_tcase(s, t);
  return s;
}