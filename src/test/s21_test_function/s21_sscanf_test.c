#include "../s21_tests.h"

START_TEST(test1) {
  char str[8000] = "120.10 12.34 16.34 20.45 40.2";
  char *format = "%f %e %E %g %G";
  float d21 = 0, d22 = 0, i21 = 0;
  float g1 = {0}, g2 = {0};
  s21_sscanf(str, format, &d21, &i21, &d22, &g1, &g2);

  float orig_d21 = 0, orig_d22 = 0, orig_i21 = 0;
  float orig_g1, orig_g2;
  sscanf(str, format, &orig_d21, &orig_i21, &orig_d22, &orig_g1, &orig_g2);
  ck_assert_float_eq(d21, orig_d21);
  ck_assert_float_eq(d22, orig_d22);
  ck_assert_float_eq(i21, orig_i21);
  ck_assert_float_eq(g1, orig_g1);
  ck_assert_float_eq(g2, orig_g2);
}

START_TEST(test2) {
  char str[8000] = "120 0x16dc прощай 170 0x16dc прощай";
  char *format = "%d %i %s %d %i %s";
  int d21 = 0, d22 = 0, i21 = 0, i22 = 0;
  char str21[100] = {0}, str22[100] = {0};
  s21_sscanf(str, format, &d21, &i21, str21, &d22, &i22, str22);

  int orig_d21 = 0, orig_d22 = 0, orig_i21 = 0, orig_i22 = 0;
  char orig_str21[100] = {0}, orig_str22[100] = {0};
  sscanf(str, format, &orig_d21, &orig_i21, orig_str21, &orig_d22, &orig_i22,
         orig_str22);
  ck_assert_int_eq(d21, orig_d21);
  ck_assert_int_eq(d22, orig_d22);
  ck_assert_int_eq(i21, orig_i21);
  ck_assert_int_eq(i22, orig_i22);
  ck_assert_str_eq(str21, orig_str21);
  ck_assert_str_eq(str22, orig_str22);
}

START_TEST(test3) {
  char str[8000] = "120 прощай 170 0x16dc прощай 0x16dc";
  char *format = "%*d %p";
  void *p = 0;
  s21_sscanf(str, format, &p);

  void *orig_p = 0;
  sscanf(str, format, &orig_p);
  ck_assert_ptr_eq(p, orig_p);
}

START_TEST(test4) {
  char str[8000] = "120 прощай 170 0x16dc прощай 0x16dc";
  char *format = "%*s";
  char s[100] = {0};
  s21_sscanf(str, format, &s);

  char orig_s[100] = {0};
  sscanf(str, format, &s);
  ck_assert_str_eq(s, orig_s);
}

START_TEST(test5) {
  char str[8000] = "прощай 170 0x16dc прощай 0x16dc";
  char *format = "%s";
  char s[100] = {0};
  s21_sscanf(str, format, &s);

  char orig_s[100] = {0};
  sscanf(str, format, &orig_s);
  ck_assert_str_eq(s, orig_s);
}

START_TEST(test7) {
  char str[8000] = "0x16dc";
  char *format = "%ld %Lf";
  long d21 = 0;
  long double i22 = 0;
  s21_sscanf(str, format, &d21, &i22);

  int orig_d21 = 0;
  long orig_i22 = 0;
  sscanf(str, format, &orig_d21, &orig_i22);
  ck_assert_int_eq(d21, orig_d21);
  ck_assert_int_eq(i22, orig_i22);
}

START_TEST(test6) {
  char str[8000] = "A";
  char *format = "%c";
  char i22 = 0;
  s21_sscanf(str, format, &i22);

  long orig_i22 = 0;
  s21_sscanf(str, format, &orig_i22);
  ck_assert_int_eq(i22, orig_i22);
}

START_TEST(test8) {
  char str[8000] = "1000";
  char *format = "%u";
  unsigned i22 = 0;
  s21_sscanf(str, format, &i22);

  unsigned orig_i22 = 0;
  s21_sscanf(str, format, &orig_i22);
  ck_assert_int_eq(i22, orig_i22);
}

START_TEST(test9) {
  char str[8000] = "176";
  char *format = "%o";
  int i22 = 0;
  s21_sscanf(str, format, &i22);

  int orig_i22 = 0;
  s21_sscanf(str, format, &orig_i22);
  ck_assert_int_eq(i22, orig_i22);
}

START_TEST(test_c_1) {
  char *str = "Hello my dear friend, how are you?";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_2) {
  char *str = "walderhu";
  char buff1, buff2, buff1_s21, buff2_s21;
  sscanf(str, "%c%c", &buff1, &buff2);
  s21_sscanf(str, "%c%c", &buff1_s21, &buff2_s21);
  ck_assert_int_eq(buff1, buff1_s21);
  ck_assert_int_eq(buff2, buff2_s21);
}
END_TEST

START_TEST(test_c_3) {
  char *str = "163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_4) {
  char *str = "   163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_5) {
  char *str = "?163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_6) {
  char *str = "___163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_7) {
  char *str = "\t163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_8) {
  char *str = "\r163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_9) {
  char *str = "f163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_c_10) {
  char *str = "\n163";
  char original, replica;
  sscanf(str, "%c", &original);
  s21_sscanf(str, "%c", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_2) {
  char *str = "walderhu 163";
  int original = 0, replica = 0;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_d_6) {
  char *str = "       my16 3";
  int original = 0, replica = 0;
  sscanf(str, "%d", &original);
  s21_sscanf(str, "%d", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_u_4) {
  char *str = "walderhu 163";
  unsigned int original = 0, replica = 0;
  sscanf(str, "%u", &original);
  s21_sscanf(str, "%u", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_i_4) {
  char *str = "walderhu 163";
  int original = 0, replica = 0;
  sscanf(str, "%i", &original);
  s21_sscanf(str, "%i", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_s_1) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_s_3) {
  char *str = "walderhu\tworld";
  char original[strlen(str)];
  char replica[strlen(str)];
  sscanf(str, "%10s", original);
  s21_sscanf(str, "%10s", replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_f_1) {
  char *str = "3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_7) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_f_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_e_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_E_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_g_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_G_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_1) {
  char *str = "163.5";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_2) {
  char *str = "walderhu 163";
  short original = 0, replica = 0;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_3) {
  char *str = "16 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_4) {
  char *str = "16.3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_6) {
  char *str = "       my16 3";
  short original = 0, replica = 0;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_8) {
  char *str = "0x16 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_9) {
  char *str = "432416 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hd_10) {
  char *str = "136 3";
  short original, replica;
  sscanf(str, "%hd", &original);
  s21_sscanf(str, "%hd", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_1) {
  char *str = "1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_3) {
  char *str = "1abc3";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_4) {
  char *str = "0";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_5) {
  char *str = "01ab";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_6) {
  char *str = "0x1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hx_8) {
  char *str = "0x1a";
  short unsigned int original, replica;
  sscanf(str, "%hx", &original);
  s21_sscanf(str, "%hx", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_1) {
  char *str = "1A";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_3) {
  char *str = "1ABC3";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_4) {
  char *str = "0";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_5) {
  char *str = "01AB";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hX_6) {
  char *str = "0x1A";
  short unsigned int original, replica;
  sscanf(str, "%hX", &original);
  s21_sscanf(str, "%hX", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_1) {
  char *str = "0123";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_2) {
  char *str = "123";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_4) {
  char *str = "\t0";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_5) {
  char *str = "01AB";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_6) {
  char *str = "0x1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_7) {
  char *str = "\n0x1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_8) {
  char *str = "     \t0x1a";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ho_10) {
  char *str = "\t0X1A";
  short unsigned int original, replica;
  sscanf(str, "%ho", &original);
  s21_sscanf(str, "%ho", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_1) {
  char *str = "0123";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_3) {
  char *str = "01239.3";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_4) {
  char *str = "walderhu 163";
  short unsigned int original = 0, replica = 0;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_5) {
  char *str = "16 3";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_6) {
  char *str = "1a";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_7) {
  char *str = "0x1a";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_8) {
  char *str = "0x1ABC";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hu_9) {
  char *str = "01239.3";
  short unsigned int original, replica;
  sscanf(str, "%hu", &original);
  s21_sscanf(str, "%hu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_4) {
  char *str = "walderhu 163";
  short int original = 0, replica = 0;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_5) {
  char *str = "16 3";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_hi_6) {
  char *str = "1a";
  short int original, replica;
  sscanf(str, "%hi", &original);
  s21_sscanf(str, "%hi", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_2) {
  char *str = "walderlu 163";
  long original = 0, replica = 0;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_ld_6) {
  char *str = "       my16 3";
  long original = 0, replica = 0;
  sscanf(str, "%ld", &original);
  s21_sscanf(str, "%ld", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_lu_4) {
  char *str = "walderlu 163";
  long unsigned int original = 0, replica = 0;
  sscanf(str, "%lu", &original);
  s21_sscanf(str, "%lu", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_li_4) {
  char *str = "walderlu 163";
  long original = 0, replica = 0;
  sscanf(str, "%li", &original);
  s21_sscanf(str, "%li", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_1) {
  char *str = "3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_7) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lf_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%f", &original);
  s21_sscanf(str, "%f", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Le_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%e", &original);
  s21_sscanf(str, "%e", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LE_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%E", &original);
  s21_sscanf(str, "%E", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_Lg_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%g", &original);
  s21_sscanf(str, "%g", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_6) {
  char *str = "hell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_8) {
  char *str = "0xhell\r-3.1451";
  float original = 0, replica = 0;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_9) {
  char *str = "1hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_LG_10) {
  char *str = "1,33333 hell\r-3.1451";
  float original, replica;
  sscanf(str, "%G", &original);
  s21_sscanf(str, "%G", &replica);
  ck_assert_int_eq(original, replica);
}
END_TEST

START_TEST(test_star_5) {
  char *str = "\f   \t163";
  char original1[strlen(str)];
  char replica1[strlen(str)];

  char original2[strlen(str)];
  char replica2[strlen(str)];

  memset(original1, '\0', sizeof(original1));
  memset(replica1, '\0', sizeof(replica1));

  memset(original2, '\0', sizeof(original2));
  memset(replica2, '\0', sizeof(replica2));

  char specifier[] = "%*s%s";

  sscanf(str, specifier, original1, original2);
  s21_sscanf(str, specifier, replica1, replica2);

  ck_assert_int_eq(strcmp(original1, replica1), 0);
  ck_assert_int_eq(strcmp(original2, replica2), 0);
  for (s21_size_t i = 0; i < strlen(original1); i++)
    ck_assert_int_eq(original1[i], replica1[i]);
  for (s21_size_t i = 0; i < strlen(original2); i++)
    ck_assert_int_eq(original2[i], replica2[i]);
}
END_TEST

START_TEST(test_width_3) {
  char *str = "16313";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%123d";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_4) {
  char *str = "hello 163131234";
  int buffer1 = 0, buffer2 = 0;
  char specifier[] = "%123d";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_16) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2e";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_19) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1g";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_20) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2g";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_23) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1E";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_24) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2E";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_27) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1G";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_28) {
  char *str = "1.234e+4";
  float buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%2G";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_33) {
  char *str = "hello";
  char buffer1 = 0, buffer2 = 0;
  buffer1 = buffer2;
  char specifier[] = "%1c";
  sscanf(str, specifier, &buffer1);
  s21_sscanf(str, specifier, &buffer2);
  ck_assert_int_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_width_36) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%10s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_width_37) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%1s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST
START_TEST(test_width_38) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%2s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST
START_TEST(test_width_39) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%10s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST
START_TEST(test_width_40) {
  char *str = "hello world";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%0s";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

START_TEST(test_percent_1) {
  char str[] = "Привет!%";
  char original[strlen(str)];
  char replica[strlen(str)];
  char specifier[] = "%s%d";
  sscanf(str, specifier, original);
  s21_sscanf(str, specifier, replica);
  for (s21_size_t i = 0; i < strlen(original); i++)
    ck_assert_int_eq(original[i], replica[i]);
}
END_TEST

Suite *s21_sscanf_test() {
  Suite *s = suite_create("\033[45m| s21_sscanf |\033[0m");
  TCase *t = tcase_create("s21_sscanf");

  tcase_add_test(t, test1);
  tcase_add_test(t, test2);
  tcase_add_test(t, test3);
  tcase_add_test(t, test4);
  tcase_add_test(t, test5);
  tcase_add_test(t, test6);
  tcase_add_test(t, test7);
  tcase_add_test(t, test8);
  tcase_add_test(t, test9);
  tcase_add_test(t, test_c_1);
  tcase_add_test(t, test_c_2);
  tcase_add_test(t, test_c_3);
  tcase_add_test(t, test_c_4);
  tcase_add_test(t, test_c_5);
  tcase_add_test(t, test_c_6);
  tcase_add_test(t, test_c_7);
  tcase_add_test(t, test_c_8);
  tcase_add_test(t, test_c_9);
  tcase_add_test(t, test_c_10);

  tcase_add_test(t, test_d_2);
  tcase_add_test(t, test_d_6);

  tcase_add_test(t, test_u_4);

  tcase_add_test(t, test_i_4);

  tcase_add_test(t, test_s_1);
  tcase_add_test(t, test_s_3);

  tcase_add_test(t, test_f_1);
  tcase_add_test(t, test_f_6);
  tcase_add_test(t, test_f_7);
  tcase_add_test(t, test_f_8);
  tcase_add_test(t, test_f_9);
  tcase_add_test(t, test_f_10);

  tcase_add_test(t, test_e_6);
  tcase_add_test(t, test_e_8);
  tcase_add_test(t, test_e_9);
  tcase_add_test(t, test_e_10);

  tcase_add_test(t, test_E_6);
  tcase_add_test(t, test_E_8);
  tcase_add_test(t, test_E_9);
  tcase_add_test(t, test_E_10);

  tcase_add_test(t, test_g_6);
  tcase_add_test(t, test_g_8);
  tcase_add_test(t, test_g_9);
  tcase_add_test(t, test_g_10);

  tcase_add_test(t, test_G_6);
  tcase_add_test(t, test_G_8);
  tcase_add_test(t, test_G_9);
  tcase_add_test(t, test_G_10);

  tcase_add_test(t, test_hd_1);
  tcase_add_test(t, test_hd_2);
  tcase_add_test(t, test_hd_3);
  tcase_add_test(t, test_hd_4);
  tcase_add_test(t, test_hd_6);
  tcase_add_test(t, test_hd_8);
  tcase_add_test(t, test_hd_9);
  tcase_add_test(t, test_hd_10);

  tcase_add_test(t, test_hX_1);
  tcase_add_test(t, test_hX_3);
  tcase_add_test(t, test_hX_4);
  tcase_add_test(t, test_hX_5);
  tcase_add_test(t, test_hX_6);

  tcase_add_test(t, test_hx_1);
  tcase_add_test(t, test_hx_3);
  tcase_add_test(t, test_hx_4);
  tcase_add_test(t, test_hx_5);
  tcase_add_test(t, test_hx_6);
  tcase_add_test(t, test_hx_8);

  tcase_add_test(t, test_ho_1);
  tcase_add_test(t, test_ho_2);
  tcase_add_test(t, test_ho_4);
  tcase_add_test(t, test_ho_5);
  tcase_add_test(t, test_ho_6);
  tcase_add_test(t, test_ho_7);
  tcase_add_test(t, test_ho_8);
  tcase_add_test(t, test_ho_10);

  tcase_add_test(t, test_hu_1);
  tcase_add_test(t, test_hu_3);
  tcase_add_test(t, test_hu_4);
  tcase_add_test(t, test_hu_5);
  tcase_add_test(t, test_hu_6);
  tcase_add_test(t, test_hu_7);
  tcase_add_test(t, test_hu_8);
  tcase_add_test(t, test_hu_9);

  tcase_add_test(t, test_hi_4);
  tcase_add_test(t, test_hi_5);
  tcase_add_test(t, test_hi_6);

  tcase_add_test(t, test_ld_2);
  tcase_add_test(t, test_ld_6);

  tcase_add_test(t, test_lu_4);

  tcase_add_test(t, test_li_4);

  tcase_add_test(t, test_Lf_1);
  tcase_add_test(t, test_Lf_6);
  tcase_add_test(t, test_Lf_7);
  tcase_add_test(t, test_Lf_8);
  tcase_add_test(t, test_Lf_9);
  tcase_add_test(t, test_Lf_10);

  tcase_add_test(t, test_Le_6);
  tcase_add_test(t, test_Le_8);
  tcase_add_test(t, test_Le_9);
  tcase_add_test(t, test_Le_10);

  tcase_add_test(t, test_LE_6);
  tcase_add_test(t, test_LE_8);
  tcase_add_test(t, test_LE_9);
  tcase_add_test(t, test_LE_10);

  tcase_add_test(t, test_Lg_6);
  tcase_add_test(t, test_Lg_8);
  tcase_add_test(t, test_Lg_9);
  tcase_add_test(t, test_Lg_10);

  tcase_add_test(t, test_LG_6);
  tcase_add_test(t, test_LG_8);
  tcase_add_test(t, test_LG_9);
  tcase_add_test(t, test_LG_10);

  tcase_add_test(t, test_star_5);
  tcase_add_test(t, test_width_3);
  tcase_add_test(t, test_width_4);
  tcase_add_test(t, test_width_16);
  tcase_add_test(t, test_width_19);
  tcase_add_test(t, test_width_20);
  tcase_add_test(t, test_width_23);
  tcase_add_test(t, test_width_24);
  tcase_add_test(t, test_width_27);
  tcase_add_test(t, test_width_28);
  tcase_add_test(t, test_width_33);
  tcase_add_test(t, test_width_36);
  tcase_add_test(t, test_width_37);
  tcase_add_test(t, test_width_38);
  tcase_add_test(t, test_width_39);
  tcase_add_test(t, test_width_40);

  tcase_add_test(t, test_percent_1);

  suite_add_tcase(s, t);
  return s;
}
