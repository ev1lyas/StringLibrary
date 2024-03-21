#include "../s21_tests.h"

START_TEST(s21_sprintf_test_1) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int x = 1, orig = 0, s21 = 0;
  orig = sprintf(buf, "%d", x);
  s21 = s21_sprintf(buf2, "%d", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_2) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int x = 1, orig = 0, s21 = 0;
  orig = sprintf(buf, "%+.5d", x);
  s21 = s21_sprintf(buf2, "%+.5d", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_3) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int x = 1, orig = 0, s21 = 0;
  orig = sprintf(buf, "% d", x);
  s21 = s21_sprintf(buf2, "% d", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_4) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  long int lx = 1234567890;
  orig = sprintf(buf, "%-9ld", lx);
  s21 = s21_sprintf(buf2, "%-9ld", lx);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_5) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int x = 1, orig = 0, s21 = 0;
  orig = sprintf(buf, "%-6hd", x);
  s21 = s21_sprintf(buf2, "%-6hd", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_6) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0, xm = -678;
  orig = sprintf(buf, "%d", xm);
  s21 = s21_sprintf(buf2, "%d", xm);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_7) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0, xm = -678;
  orig = sprintf(buf, "% d", xm);
  s21 = s21_sprintf(buf2, "% d", xm);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_8) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0, xz = 0;
  orig = sprintf(buf, "%d", xz);
  s21 = s21_sprintf(buf2, "%d", xz);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_9) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0, xz = 0;
  orig = sprintf(buf, "%4.10d", xz);
  s21 = s21_sprintf(buf2, "%4.10d", xz);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_10) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  char x = 'g', orig = 0, s21 = 0;
  orig = sprintf(buf, "%c", x);
  s21 = s21_sprintf(buf2, "%c", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_11) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  char x = 'g', orig = 0, s21 = 0;
  orig = sprintf(buf, "%28c", x);
  s21 = s21_sprintf(buf2, "%28c", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_12) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  float x = 0.000005415;
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%.1f", x);
  s21 = s21_sprintf(buf2, "%.1f", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_13) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  float x = 2.005415;
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%+f-%Lf", x, -0.123L);
  s21 = s21_sprintf(buf2, "%+f-%Lf", x, -0.123L);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_15) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'}, x[10] = "AlWaYs";
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%s", x);
  s21 = s21_sprintf(buf2, "%s", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_16) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'}, x[10] = "AlWaYs";
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%8.4s", x);
  s21 = s21_sprintf(buf2, "%8.4s", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_17) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  unsigned int x = 996677;
  orig = sprintf(buf, "%u", x);
  s21 = s21_sprintf(buf2, "%u", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_18) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  unsigned int x = 996677;
  orig = sprintf(buf, "%8.5hu", x);
  s21 = s21_sprintf(buf2, "%8.5hu", x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_19) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  unsigned long int lx = 9876543210;
  orig = sprintf(buf, "%8.5lu-%.3hu-%.3lu-%hu-%lu", lx, (unsigned short)0, 0ul,
                 (unsigned short)0, 0ul);
  s21 = s21_sprintf(buf2, "%8.5lu-%.3hu-%.3lu-%hu-%lu", lx, (unsigned short)0,
                    0ul, (unsigned short)0, 0ul);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_20) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "1234567890qwe!!-%%");
  s21 = s21_sprintf(buf2, "1234567890qwe!!-%%");
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_21) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int x = 1, orig = 0, s21 = 0;
  orig = sprintf(buf, "%*.*d", 5, 3, x);
  s21 = s21_sprintf(buf2, "%*.*d", 5, 3, x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_22) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  char x = 'g', orig = 0, s21 = 0;
  orig = sprintf(buf, "%*c", 19, x);
  s21 = s21_sprintf(buf2, "%*c", 19, x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_23) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  float x = -2.15;
  long double y = 6.42342335623;
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%*.*f-%#.0f-%#.0Lf", 15, 7, x, x, y);
  s21 = s21_sprintf(buf2, "%*.*f-%#.0f-%#.0Lf", 15, 7, x, x, y);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_24) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'}, x[10] = "AlWaYs";
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%*.*s", 6, 5, x);
  s21 = s21_sprintf(buf2, "%*.*s", 6, 5, x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_25) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  unsigned int x = 996677;
  orig = sprintf(buf, "%*.*hu", 6, 5, x);
  s21 = s21_sprintf(buf2, "%*.*hu", 6, 5, x);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_26) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%Lf", 123.456L);
  s21 = s21_sprintf(buf2, "%Lf", 123.456L);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_27) {
  char buf[2000] = {'\0'}, buf2[2000] = {'\0'};
  double x = 2123.005415;
  long double y = 2123.005415;
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%g-%+g-%-g-%-15g-% 15g-%#15g-%015g-%#15.1g-%015.5Lg-%#g",
                 -15.32, 7e-05, 123332.1, 9.99999, 0.000123, -123.00123,
                 777.00077, x, y, 1.0);
  s21 = s21_sprintf(
      buf2, "%g-%+g-%-g-%-15g-% 15g-%#15g-%015g-%#15.1g-%015.5Lg-%#g", -15.32,
      7e-05, 123332.1, 9.99999, 0.000123, -123.00123, 777.00077, x, y, 1.0);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_28) {
  char buf[2000] = {'\0'}, buf2[2000] = {'\0'};
  double x = 2123.0005415;
  long double y = 2123.005415;
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%G-%+G-%-G-%-15G-% 15G-%#15G-%015G-%#15.1G-%015.6LG",
                 -15.32, 7e-05, 123332.1, 9.99999, 0.000123, -123.00123,
                 -777.00077, x, y);
  s21 = s21_sprintf(buf2, "%G-%+G-%-G-%-15G-% 15G-%#15G-%015G-%#15.1G-%015.6LG",
                    -15.32, 7e-05, 123332.1, 9.99999, 0.000123, -123.00123,
                    -777.00077, x, y);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_29) {
  char buf[200] = {'\0'}, buf2[200] = {'\0'};
  long double x = 200541545671.0;
  int orig = 0, s21 = 0;
  orig = sprintf(buf, "%Lg-%g-%#g-%g-%#g-%g-%#g-%#.0g-%g", x, 0.0523345, 0.0,
                 0.0000052, 1.1, 0.00000000002, 2.0, 0.0, 123432e+87);
  s21 = s21_sprintf(buf2, "%Lg-%g-%#g-%g-%#g-%g-%#g-%#.0g-%g", x, 0.0523345,
                    0.0, 0.0000052, 1.1, 0.00000000002, 2.0, 0.0, 123432e+87);
  ck_assert_int_eq(orig, s21);
  ck_assert_str_eq(buf, buf2);
}
END_TEST
START_TEST(s21_sprintf_test_30) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %s, Go %d times", "Bober", 37);
  sprintf(buffer2, "Bye %s, Go %d times", "Bober", 37);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_31) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %10s, Go %d times", "Bober", 37);
  sprintf(buffer2, "Bye %10s, Go %d times", "Bober", 37);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_32) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %-10s, Go %d times", "Bober", 37);
  sprintf(buffer2, "Bye %-10s, Go %d times", "Bober", 37);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_33) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %%, Are you OK?");
  sprintf(buffer2, "Bye %%, Are you OK?");
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_34) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "%%, Are you OK?");
  sprintf(buffer2, "%%, Are you OK?");
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_35) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %%");
  sprintf(buffer2, "Bye %%");
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_36) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %c, Are you OK?", 'A');
  sprintf(buffer2, "Bye %c, Are you OK?", 'A');
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_37) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %12c, Are you OK?", 'A');
  sprintf(buffer2, "Bye %12c, Are you OK?", 'A');
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_38) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %-12c, Are you OK?", 'A');
  sprintf(buffer2, "Bye %-12c, Are you OK?", 'A');
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_39) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  s21_sprintf(buffer1, "Bye %#Le-%#.4e-%hX-%.4e-%#hX, Are you OK?", 423.55L,
              423.99, 0, 2.45596, (short unsigned)123);
  sprintf(buffer2, "Bye %#Le-%#.4e-%hX-%.4e-%#hX, Are you OK?", 423.55L, 423.99,
          0, 2.45596, (short unsigned)123);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_40) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(buffer1, "Bye %s", " Bober");
  int b = sprintf(buffer2, "Bye %s", " Bober");
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(s21_sprintf_test_41) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(buffer1,
                      "Bye %s your age is %-5d, your wallet have %5.2f dollars",
                      " Bober", 37, 1234.56789);
  int b = sprintf(buffer2,
                  "Bye %s your age is %-5d, your wallet have %5.2f dollars",
                  " Bober", 37, 1234.56789);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_42) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(buffer1, " ");
  int b = sprintf(buffer2, " ");
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
START_TEST(s21_sprintf_test_43) {
  char buffer1[8000] = {0};
  char buffer2[8000] = {0};
  int a = s21_sprintf(buffer1, "%lx-%#lX-%#030lx-%ho-%#ho-%lo-%#lo", 0L, 123L,
                      321L, 0, 321, 0L, 321L);
  int b = sprintf(buffer2, "%lx-%#lX-%#030lx-%ho-%#ho-%lo-%#lo", 0L, 123L, 321L,
                  0, 321, 0L, 321L);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

Suite *s21_sprintf_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_sprintf_test |\033[0m");
  t = tcase_create("s21_sprintf_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_sprintf_test_1);
  tcase_add_test(t, s21_sprintf_test_2);
  tcase_add_test(t, s21_sprintf_test_3);
  tcase_add_test(t, s21_sprintf_test_4);
  tcase_add_test(t, s21_sprintf_test_5);
  tcase_add_test(t, s21_sprintf_test_6);
  tcase_add_test(t, s21_sprintf_test_7);
  tcase_add_test(t, s21_sprintf_test_8);
  tcase_add_test(t, s21_sprintf_test_9);
  tcase_add_test(t, s21_sprintf_test_10);
  tcase_add_test(t, s21_sprintf_test_11);
  tcase_add_test(t, s21_sprintf_test_12);
  tcase_add_test(t, s21_sprintf_test_13);
  tcase_add_test(t, s21_sprintf_test_15);
  tcase_add_test(t, s21_sprintf_test_16);
  tcase_add_test(t, s21_sprintf_test_17);
  tcase_add_test(t, s21_sprintf_test_18);
  tcase_add_test(t, s21_sprintf_test_19);
  tcase_add_test(t, s21_sprintf_test_20);
  tcase_add_test(t, s21_sprintf_test_21);
  tcase_add_test(t, s21_sprintf_test_22);
  tcase_add_test(t, s21_sprintf_test_23);
  tcase_add_test(t, s21_sprintf_test_24);
  tcase_add_test(t, s21_sprintf_test_25);
  tcase_add_test(t, s21_sprintf_test_26);
  tcase_add_test(t, s21_sprintf_test_27);
  tcase_add_test(t, s21_sprintf_test_28);
  tcase_add_test(t, s21_sprintf_test_29);
  tcase_add_test(t, s21_sprintf_test_30);
  tcase_add_test(t, s21_sprintf_test_31);
  tcase_add_test(t, s21_sprintf_test_32);
  tcase_add_test(t, s21_sprintf_test_33);
  tcase_add_test(t, s21_sprintf_test_34);
  tcase_add_test(t, s21_sprintf_test_35);
  tcase_add_test(t, s21_sprintf_test_36);
  tcase_add_test(t, s21_sprintf_test_37);
  tcase_add_test(t, s21_sprintf_test_38);
  tcase_add_test(t, s21_sprintf_test_39);
  tcase_add_test(t, s21_sprintf_test_40);
  tcase_add_test(t, s21_sprintf_test_41);
  tcase_add_test(t, s21_sprintf_test_42);
  tcase_add_test(t, s21_sprintf_test_43);
  suite_add_tcase(s, t);
  return s;
}