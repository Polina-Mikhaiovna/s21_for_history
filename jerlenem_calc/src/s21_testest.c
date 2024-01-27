#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./S21_Smart_calc_v1.h"

/*===============================================================/
/                                                                /
/                S21_CALCULATOR PROJECT SCHOOL 21                /
/                                                                /
/===============================================================*/

#define C_STRING_SIZE 255

START_TEST(syntax_test) {
  char str1[C_STRING_SIZE] = "sin()";  // f_result = ERROR
  char str11[C_STRING_SIZE] =
      "sin(x)-acos(2)*asin(atan(9))";              // f_result = OK; x = 30;
  char str2[C_STRING_SIZE] = "sin(1)^2+cos(1)^2";  // f_result = OK
  char str3[C_STRING_SIZE] = "tan(1)/(cos(1)/sin(1))";  // f_result = OK

  int result = 0;
  int count = 0;
  printf("------------------Systax-test-begin------------------\n");
  expression_to_polish_notation(str1, 3.0, &result);
  if (result == 1) printf("Success!\n"), count++;
  expression_to_polish_notation(str2, 3.0, &result);
  if (result == 0) printf("Success!\n"), count++;
  expression_to_polish_notation(str3, 3.0, &result);
  if (result == 0) printf("Success!\n"), count++;
  expression_to_polish_notation(str11, 30.0, &result);
  if (result == 0) printf("Success!\n"), count++;

  if (count == 4)
    printf("----------------Systax-test-completed----------------\n\n");
}
END_TEST

START_TEST(result_test) {
  char str1[C_STRING_SIZE] = "sin(1)^2+cos(1)^2";       // result = 1
  char str2[C_STRING_SIZE] = "tan(1)*(cos(1)/sin(1))";  // result = 1
  char str3[C_STRING_SIZE] = "2^2^3";                   // result = 64
  char str4[C_STRING_SIZE] = "2^(2^3)";                 // result = 256

  int error = 0;
  double result = 0.0;
  int count = 0;
  printf("------------------Result-test-begin------------------\n");
  result = expression_to_polish_notation(str1, 3.0, &error);
  if (error == 0) {
    if (result == 1.0) {
      printf("Success!\n"), count++;
    }
  }
  result = 0;
  result = expression_to_polish_notation(str2, 3.0, &error);
  if (error == 0) {
    if (result == 1.0) {
      printf("Success!\n"), count++;
    }
  }
  result = 0;
  result = expression_to_polish_notation(str3, 3.0, &error);
  if (error == 0) {
    if (result == 64.0) {
      printf("Success!\n"), count++;
    }
  }
  result = 0;
  result = expression_to_polish_notation(str4, 3.0, &error);
  if (error == 0) {
    if (result == 256.0) {
      printf("Success!\n"), count++;
    }
  }

  if (count == 4)
    printf("----------------Result-test-completed----------------\n\n");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, syntax_test);
  tcase_add_test(tc1_1, result_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
