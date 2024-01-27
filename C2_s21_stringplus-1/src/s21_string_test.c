#include<stdlib.h>
#include"./s21_string.h"
#include<check.h>

START_TEST(strlen_null) {
    char * str = s21_NULL;
    unsigned long result = s21_strlen(str);
    ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(strlen_one) {
    char * str = "a";
    unsigned long result = s21_strlen(str);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(strlen_ten) {
    char * str = "0123456789";
    unsigned long result = s21_strlen(str);
    ck_assert_int_eq(result, 10);
}
END_TEST

Suite *len_suite(void) {
    Suite *s;
    TCase *tc_null, *tc_one, *tc_ten;
    s = suite_create("Strlen");
    
    tc_null = tcase_create("Null");
    tcase_add_test(tc_null, strlen_null);
    suite_add_tcase(s, tc_null);
    
    tc_one = tcase_create("One");
    tcase_add_test(tc_one, strlen_one);
    suite_add_tcase(s, tc_one);
    
    tc_ten = tcase_create("Ten");
    tcase_add_test(tc_ten, strlen_ten);
    suite_add_tcase(s, tc_ten);

    return s;
}

int main(void) {
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    
    s = len_suite();
    runner = srunner_create(s);
    
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
