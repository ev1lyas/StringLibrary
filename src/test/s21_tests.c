#include "s21_tests.h"

int main(void) {
  int test_fail = 0;
  int test_successed = 0;
  int gg = 0;
  Suite *s[] = {
      s21_cbonus_test(),
      s21_string_test(),
      s21_sprintf_test(),
      s21_sprintf_test_suite_specifier_s(),
      s21_sprintf_test_suite_specifier_u(),
      s21_sprintf_test_suite_specifier_d_1(),
      s21_sprintf_test_suite_specifier_d_2(),
      s21_sprintf_test_suite_specifier_d_3(),
      s21_sprintf_test_suite_specifier_f_1(),
      s21_sprintf_test_suite_specifier_f_2(),
      s21_sprintf_test_suite_specifier_f_3(),
      s21_sprintf_test_suite_specifier_f_4(),
      s21_sprintf_test_suite_specifier_f_5(),
      s21_sprintf_test_suite_specifier_g(),
      s21_sprintf_test_suite_specifier_g_2(),
      s21_sprintf_test_suite_specifier_g_3(),
      s21_sprintf_test_suite_specifier_g_4(),
      s21_sprintf_test_suite_specifier_g_5(),
      s21_sprintf_test_suite_specifier_g_6(),
      s21_sprintf_test_suite_specifier_g_7(),
      s21_sprintf_test_suite_specifier_e_1(),
      s21_sprintf_test_suite_specifier_e_2(),
      s21_sprintf_test_suite_specifier_e_3(),
      s21_sprintf_test_suite_specifier_e_4(),
      s21_sprintf_test_suite_specifier_e_5(),
      s21_sprintf_test_suite_specifier_e_6(),
      s21_sprintf_test_suite_specifier_e_7(),
      s21_sprintf_test_suite_specifier_e_8(),
      s21_sprintf_test_suite_specifier_e_9(),
      s21_sprintf_test_suite_specifier_x(),
      s21_sprintf_test_suite_specifier_x_2(),
      s21_sprintf_test_suite_specifier_o(),
      s21_sprintf_test_suite_specifier_o_2(),
      s21_sprintf_test_suite_specifier_p(),
      s21_sscanf_test(),
  };  // Добавить свои функции
  for (Suite **cur = s; gg < 35;
       cur++) {  // Изменить размер под количество своих функций
    SRunner *sr;
    sr = srunner_create(*cur);
    srunner_run_all(sr, CK_VERBOSE);
    test_fail += srunner_ntests_failed(sr);
    if (test_fail == 0) test_successed += 1;
    srunner_free(sr);
    gg++;
  }
  printf("\033[43m Tests => \033[42m Success: %d  \033[41m Fail: %d  \033[0m\n",
         test_successed, test_fail);
  return (test_fail == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
