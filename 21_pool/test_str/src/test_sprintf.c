#include <stdio.h>
#include "s21_string.h"

START_TEST(SFTest1) {
    char data[100];
    char data1[100];
    sprintf(data, "|%32s|\n", "111");
    s21_sprintf(data1, "|%32s|\n", "111");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest2) {
    char data[100];
    char data1[100];
    sprintf(data, "|%32s|\n", "abc");
    s21_sprintf(data1, "|%32s|\n", "abc");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest3) {
    char data[100];
    char data1[100];
    sprintf(data, "|%-32s|\n", "abc");
    s21_sprintf(data1, "|%-32s|\n", "abc");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest4) {
    char data[100];
    char data1[100];
    sprintf(data, "|%16s|\n", "nark nark");
    s21_sprintf(data1, "|%16s|\n", "nark nark");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest5) {
    char data[100];
    char data1[100];
    sprintf(data, "|%16s|\n", "nark nark");
    s21_sprintf(data1, "|%16s|\n", "nark nark");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest6) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%.03s|\n", "hello");
    int d = sprintf(data1, "|%.03s|\n", "hello");
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest7) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%.3s| kushat nado |%20s|\n", "MneEEEEEEEEE", "arbuz");
    int d = sprintf(data1, "|%.3s| kushat nado |%20s|\n", "MneEEEEEEEEE", "arbuz");
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest8) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%-20.18u|\n", -345);
    int d = sprintf(data1, "|%-20.18u|\n", -345);
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest9) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%-20.18d|\n", -345);
    int d = sprintf(data1, "|%-20.18d|\n", -345);
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest10) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%020d|\n", -345);
    int d = sprintf(data1, "|%020d|\n", -345);
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest11) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|%%|\n");
    int d = sprintf(data1, "|%%|\n");
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest12) {
    char data[100];
    char data1[100];
    int c = s21_sprintf(data, "|test %-12i et %24s !|\n", 0, "coco");
    int d = sprintf(data1, "|test %-12i et %24s !|\n", 0, "coco");
    ck_assert_int_eq(c, d);
}
END_TEST

START_TEST(SFTest13) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%c|\n", 'a');
    sprintf(data1, "01)SPRINTF : |%c|\n", 'a');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest14) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-c|\n", 'z');
    sprintf(data1, "01)SPRINTF : |%-c|\n", 'z');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest15) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%5c|\n", 'R');
    sprintf(data1, "01)SPRINTF : |%5c|\n", 'R');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest16) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-5c|\n", 'R');
    sprintf(data1, "01)SPRINTF : |%-5c|\n", 'R');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest17) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%1c|\n", '3');
    sprintf(data1, "01)SPRINTF : |%1c|\n", '3');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest18) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%c|\n", '\0');
    sprintf(data1, "01)SPRINTF : |%c|\n", '\0');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest19) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%5c|\n", '\0');
    sprintf(data1, "01)SPRINTF : |%5c|\n", '\0');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest20) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-5c|\n", '\0');
    sprintf(data1, "01)SPRINTF : |%-5c|\n", '\0');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest21) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%1c|\n", '\0');
    sprintf(data1, "01)SPRINTF : |%1c|\n", '\0');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest22) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%s|\n", "salut");
    sprintf(data1, "01)SPRINTF : |%s|\n", "salut");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest23) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-s|\n", "test");
    sprintf(data1, "01)SPRINTF : |%-s|\n", "test");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest24) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%10s|\n", "42");
    sprintf(data1, "01)SPRINTF : |%10s|\n", "42");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest25) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-10s|\n", "42");
    sprintf(data1, "01)SPRINTF : |%-10s|\n", "42");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest26) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%2s|\n", "string");
    sprintf(data1, "01)SPRINTF : |%2s|\n", "string");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest27) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-2s|\n", "string");
    sprintf(data1, "01)SPRINTF : |%-2s|\n", "string");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest28) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%.15s|\n", "precision");
    sprintf(data1, "01)SPRINTF : |%.15s|\n", "precision");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest29) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%.4s|\n", "precision");
    sprintf(data1, "01)SPRINTF : |%.4s|\n", "precision");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest30) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%.0s|\n", "precision");
    sprintf(data1, "01)SPRINTF : |%.0s|\n", "precision");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest31) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%s|\n", "\0\0\0\0\0");
    sprintf(data1, "01)SPRINTF : |%s|\n", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest32) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%10s|\n", "\0\0\0\0\0");
    sprintf(data1, "01)SPRINTF : |%10s|\n", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest33) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%s|\n", "");
    sprintf(data1, "01)SPRINTF : |%s|\n", "");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest34) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-.2s|\n", "boom");
    sprintf(data1, "01)SPRINTF : |%-.2s|\n", "boom");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest35) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%10.8s|\n", "google");
    sprintf(data1, "01)SPRINTF : |%10.8s|\n", "google");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest36) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%10.2s|\n", "twitter");
    sprintf(data1, "01)SPRINTF : |%10.2s|\n", "twitter");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest37) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%2.10s|\n", "samsung");
    sprintf(data1, "01)SPRINTF : |%2.10s|\n", "samsung");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest38) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%2.5s|\n", "sprintf");
    sprintf(data1, "01)SPRINTF : |%2.5s|\n", "sprintf");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest39) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-10.2s|\n", "424242424242");
    sprintf(data1, "01)SPRINTF : |%-10.2s|\n", "424242424242");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest40) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%1.0s|\n", "123456789");
    sprintf(data1, "01)SPRINTF : |%1.0s|\n", "123456789");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest41) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-1.0s|\n", "123456789");
    sprintf(data1, "01)SPRINTF : |%-1.0s|\n", "123456789");
    ck_assert_str_eq(data, data1);
}
END_TEST


START_TEST(SFTest42) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%.1s|\n", "covid-19");
    sprintf(data1, "01)SPRINTF : |%.1s|\n", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest43) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%10.2s|\n", "covid-19");
    sprintf(data1, "01)SPRINTF : |%10.2s|\n", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest44) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%2.5s|\n", "covid-19");
    sprintf(data1, "01)SPRINTF : |%2.5s|\n", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest45) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%-10.2s|\n", "covid-19");
    sprintf(data1, "01)SPRINTF : |%-10.2s|\n", "covid-19");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest46) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01)SPRINTF : |%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
    sprintf(data1, "01)SPRINTF : |%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest47) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "01) standart PRINTF : |%p|\n", "salut");
    sprintf(data1, "01) standart PRINTF : |%p|\n", "salut");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest48) {
    char data[100];
    char data1[100];
    int num1 = 0;
    s21_sprintf(data, "02) standart PRINTF : |%-p|\n", &num1);
    sprintf(data1, "02) standart PRINTF : |%-p|\n", &num1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest49) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10p|\n", "21");
    sprintf(data1, "02) standart PRINTF : |%10p|\n", "21");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest50) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-10p|\n", "21");
    sprintf(data1, "02) standart PRINTF : |%-10p|\n", "21");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest51) {
    char data[100];
    char data1[100];
    int num1;
    s21_sprintf(data, "02) standart PRINTF : |%2p|\n", &num1);
    sprintf(data1, "02) standart PRINTF : |%2p|\n", &num1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest52) {
    char data[100];
    char data1[100];
    int num1;
    s21_sprintf(data, "02) standart PRINTF : |%-2p|\n", &num1);
    sprintf(data1, "02) standart PRINTF : |%-2p|\n", &num1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest53) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%p|\n", "\0\0\0\0\0");
    sprintf(data1, "02) standart PRINTF : |%p|\n", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest54) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%20p|\n", "\0\0\0\0\0");
    sprintf(data1, "02) standart PRINTF :|%20p|\n", "\0\0\0\0\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest55) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%p|\n", "");
    sprintf(data1, "02) standart PRINTF :|%p|\n", "");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest56) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%p|\n", NULL);
    sprintf(data1, "02) standart PRINTF :|%p|\n", NULL);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest57) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%10p|\n", NULL);
    sprintf(data1, "02) standart PRINTF :|%10p|\n", NULL);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest58) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%-10p|\n", NULL);
    sprintf(data1, "02) standart PRINTF :|%-10p|\n", NULL);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest59) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%1.1d|\n", -20);
    sprintf(data1, "02) standart PRINTF :|%1.1d|\n", -20);
}
END_TEST

START_TEST(SFTest60) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%-10d|\n", -50);
    sprintf(data1, "02) standart PRINTF :|%-10d|\n", -50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest61) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%2d|\n", -20);
    sprintf(data1, "02) standart PRINTF :|%2d|\n", -20);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest62) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%.2d|\n", -20);
    sprintf(data1, "02) standart PRINTF :|%.2d|\n", -20);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest63) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%d|\n", 42);
    sprintf(data1, "02) standart PRINTF :|%d|\n", 42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest64) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%i|\n", 42);
    sprintf(data1, "02) standart PRINTF :|%i|\n", 42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest65) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%-d|\n", 42);
    sprintf(data1, "02) standart PRINTF :|%-d|\n", 42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest66) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%10d|\n", 100);
    sprintf(data1, "02) standart PRINTF :|%10d|\n", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest67) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%-10d|\n", 100);
    sprintf(data1, "02) standart PRINTF :|%-10d|\n", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest68) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%.10d|\n", 100);
    sprintf(data1, "02) standart PRINTF :|%.10d|\n", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest69) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%10.5d|\n", 100);
    sprintf(data1, "02) standart PRINTF :|%10.5d|\n", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest70) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%5.10d|\n", 64);
    sprintf(data1, "02) standart PRINTF :|%5.10d|\n", 64);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest71) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%1.1d|\n", 16);
    sprintf(data1, "02) standart PRINTF :|%1.1d|\n", 16);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest72) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%d|\n", -42);
    sprintf(data1, "02) standart PRINTF :|%d|\n", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest73) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%10d|\n", -42);
    sprintf(data1, "02) standart PRINTF :|%10d|\n", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest74) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%.10d|\n", -42);
    sprintf(data1, "02) standart PRINTF :|%.10d|\n", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest75) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%10.5d|\n", -16);
    sprintf(data1, "02) standart PRINTF :|%10.5d|\n", -16);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest76) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%5.10d|\n", -16);
    sprintf(data1, "02) standart PRINTF :|%5.10d|\n", -16);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest77) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.2d|\n", -1);
    sprintf(data1, "02) standart PRINTF : |%.2d|\n", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest78) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-10d|\n", -80);
    sprintf(data1, "02) standart PRINTF : |%-10d|\n", -80);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest79) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-.10d|\n", -80);
    sprintf(data1, "02) standart PRINTF : |%-.10d|\n", -80);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest80) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%06d|\n", 35);
    sprintf(data1, "02) standart PRINTF : |%06d|\n", 35);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest81) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%06d|\n", -35);
    sprintf(data1, "02) standart PRINTF : |%06d|\n", -35);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest82) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.d|\n", 0);
    sprintf(data1, "02) standart PRINTF : |%.d|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest83) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.d|\n", 100);
    sprintf(data1, "02) standart PRINTF : |%.d|\n", 100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest84) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%x|\n", 34);
    sprintf(data1, "02) standart PRINTF : |%x|\n", 34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest85) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%x|\n", -34);
    sprintf(data1, "02) standart PRINTF : |%x|\n", -34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest86) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-x|\n", 50);
    sprintf(data1, "02) standart PRINTF : |%-x|\n", 50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest87) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10x|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%10x|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest88) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.10x|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%.10x|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest89) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15x|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%15x|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest90) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.15x|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%.15x|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest91) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10.5x|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%10.5x|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest92) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%5.10x|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%5.10x|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest93) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%20.15x|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%20.15x|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest94) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15.20x|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%15.20x|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest95) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-10x|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-10x|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest96) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-.10x|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-.10x|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest97) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-20x|\n", -20000000);
    sprintf(data1, "02) standart PRINTF : |%-20x|\n", -20000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest98) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%08x|\n", 64);
    sprintf(data1, "02) standart PRINTF : |%08x|\n", 64);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest99) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.x|\n", 0);
    sprintf(data1, "02) standart PRINTF : |%.x|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest100) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.x|\n", 88);
    sprintf(data1, "02) standart PRINTF : |%.x|\n", 88);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest101) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%x| |%x|\n", (unsigned int)-1,  1);
    sprintf(data1, "02) standart PRINTF : |%x| |%x|\n", (unsigned int)-1, 1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest102) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%X|\n", 34);
    sprintf(data1, "02) standart PRINTF : |%X|\n", 34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest103) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%X|\n", 34);
    sprintf(data1, "02) standart PRINTF : |%X|\n", 34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest104) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%X|\n", -34);
    sprintf(data1, "02) standart PRINTF : |%X|\n", -34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest105) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-X|\n", 50);
    sprintf(data1, "02) standart PRINTF : |%-X|\n", 50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest106) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10X|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%10X|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest107) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.10X|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%.10X|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest108) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15X|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%15X|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest109) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.15X|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%.15X|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest110) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10.5X|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%10.5X|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest111) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%5.10X|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%5.10X|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest112) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%20.15X|\n", 10000);
    sprintf(data1, "02) standart PRINTF : |%20.15X|\n", 10000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest113) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15.20X|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%15.20X|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest114) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-10X|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-10X|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest115) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-.10X|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-.10X|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest116) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-20X|\n", -20000000);
    sprintf(data1, "02) standart PRINTF : |%-20X|\n", -20000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest117) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%08X|\n", 64);
    sprintf(data1, "02) standart PRINTF : |%08X|\n", 64);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest118) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.X|\n", 0);
    sprintf(data1, "02) standart PRINTF : |%.X|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest119) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.X|\n", 88);
    sprintf(data1, "02) standart PRINTF : |%.X|\n", 88);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest120) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%X|\n", 2147483647);
    sprintf(data1, "02) standart PRINTF : |%X|\n", 2147483647);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest121) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%u|\n", 34);
    sprintf(data1, "02) standart PRINTF : |%u|\n", 34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest122) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%u|\n", -34);
    sprintf(data1, "02) standart PRINTF : |%u|\n", -34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest123) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-u|\n", 50);
    sprintf(data1, "02) standart PRINTF : |%-u|\n", 50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest124) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10u|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%10u|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest125) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.10u|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%.10u|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest126) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15u|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%15u|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest127) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10.5u|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%10.5u|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest128) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%5.10u|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%5.10u|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest129) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%20.15u|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%20.15u|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest130) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15.20u|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%15.20u|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest131) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-10u|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-10u|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest132) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-.10u|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-.10u|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest133) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-20u|\n", -20000000);
    sprintf(data1, "02) standart PRINTF : |%-20u|\n", -20000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest134) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%08u|\n", 64);
    sprintf(data1, "02) standart PRINTF : |%08u|\n", 64);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest135) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF :|%u|\n", 0);
    sprintf(data1, "02) standart PRINTF :|%u|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest136) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.u|\n", 0);
    sprintf(data1, "02) standart PRINTF : |%.u|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest137) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10u|\n", 0);
    sprintf(data1, "02) standart PRINTF : |%10u|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest138) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.u|\n", 88);
    sprintf(data1, "02) standart PRINTF : |%.u|\n", 88);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest139) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.*s|\n", 5, "bratok");
    sprintf(data1, "02) standart PRINTF : |%.*s|\n", 5, "bratok");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest140) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.*d|\n", 5, 5);
    sprintf(data1, "02) standart PRINTF : |%.*d|\n", 5, 5);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest141) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.*d|\n", 5, 0);
    sprintf(data1, "02) standart PRINTF : |%.*d|\n", 5, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest142) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.3s|\n", "21");
    sprintf(data1, "02) standart PRINTF : |%.3s|\n", "21");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest143) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.3X|\n", 17);
    sprintf(data1, "02) standart PRINTF : |%.3X|\n", 17);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest144) {
    char data[100];
    char data1[100];
    char c;
    s21_sprintf(data, "|%s%d%p%%%i%u%x%X%c|\n", "bonjour", 42, &c, 42, 42, 42, 42, 'c');
    sprintf(data1, "|%s%d%p%%%i%u%x%X%c|\n", "bonjour", 42, &c, 42, 42, 42, 42, 'c');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest145) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%x|\n", -42);
    sprintf(data1, "|%x|\n", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest146) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%X|\n", -42);
    sprintf(data1, "|%X|\n", -42);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest147) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%lx|\n", 4294967296);
    sprintf(data1, "|%lx|\n", 4294967296);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest148) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%u|\n", -1);
    sprintf(data1, "|%u|\n", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest149) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%u|\n", -1);
    sprintf(data1, "|%u|\n", -1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest150) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%f|\n", 324.34);
    sprintf(data1, "|%f|\n", 324.34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest151) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10f|\n", 324.343);
    sprintf(data1, "|%10f|\n", 324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest152) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.3f|\n", 324.343);
    sprintf(data1, "|%10.3f|\n", 324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest153) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%1.30f|\n", 324.343);
    sprintf(data1, "|%1.30f|\n", 324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest154) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-1.10f|\n", 324.343);
    sprintf(data1, "|%-1.10f|\n", 324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest155) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-1.10f|\n", -324.343);
    sprintf(data1, "|%-1.10f|\n", -324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest156) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%.10f|\n", -324.343);
    sprintf(data1, "|%.10f|\n", -324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest157) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%.10f|\n", 324.343);
    sprintf(data1, "|%.10f|\n", 324.343);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest158) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% 10f|\n", 324.1);
    sprintf(data1, "|% 10f|\n", 324.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest159) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+10f|\n", 324.1);
    sprintf(data1, "|%+10f|\n", 324.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest160) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#10f|\n", 324.1);
    sprintf(data1, "|%#10f|\n", 324.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest161) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#10f|\n", 324.1123132);
    sprintf(data1, "|%#10f|\n", 324.1123132);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest162) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#10.15f|\n", 324.1123132);
    sprintf(data1, "|%#10.15f|\n", 324.1123132);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest163) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%.0f|\n", 324.1123132);
    sprintf(data1, "|%.0f|\n", 324.1123132);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest164) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#10.0f|\n", 3.14);
    sprintf(data1, "|%#10.0f|\n", 3.14);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest165) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.10f|\n", 320.3);
    sprintf(data1, "|%10.10f|\n", 320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest166) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-10.10f|\n", 320.3);
    sprintf(data1, "|%-10.10f|\n", 320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest167) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-10.10f|\n", 320.3);
    sprintf(data1, "|%-10.10f|\n", 320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest168) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-10.10f|\n", -320.3);
    sprintf(data1, "|%-10.10f|\n", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest169) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%.0f|\n", -320.3);
    sprintf(data1, "|%.0f|\n", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest170) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%.0f|\n", -320.3);
    sprintf(data1, "|%.0f|\n", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest171) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%05.0f|\n", -320.3);
    sprintf(data1, "|%05.0f|\n", -320.3);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest172) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%05.0f|\n", 3.141592653589793);
    sprintf(data1, "|%05.0f|\n", 3.141592653589793);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest173) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%05.0f|\n", 3.141592653589793);
    sprintf(data1, "|%05.0f|\n", 3.141592653589793);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest174) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% -5.1f|\n", 0.001);
    sprintf(data1, "|% -5.1f|\n", 0.001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest175) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%5.1f|\n", 324.324);
    sprintf(data1, "|%5.1f|\n", 324.324);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest176) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%5.3f|\n", 0.0001);
    sprintf(data1, "|%5.3f|\n", 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest177) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%5.*f|\n", 10 , 0.0001);
    sprintf(data1, "|%5.*f|\n", 10, 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest178) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%5.*f|\n", -10 , 0.0001);
    sprintf(data1, "|%5.*f|\n", -10, 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest179) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*f|\n", 23, -10 , 0.0001);
    sprintf(data1, "|%*.*f|\n", 23, -10, 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest180) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*f|\n", -23, -10 , 0.0001);
    sprintf(data1, "|%*.*f|\n", -23, -10, 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest181) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*f|\n", 0, -10 , 0.0001);
    sprintf(data1, "|%*.*f|\n", 0, -10, 0.0001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest182) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#x|\n", 123);
    sprintf(data1, "|%#x|\n", 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest183) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*x|\n", 10, 123);
    sprintf(data1, "|%#*x|\n", 10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest184) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*x|\n", 10, -123);
    sprintf(data1, "|%#*x|\n", 10, -123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest185) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*x|\n", -10, 123);
    sprintf(data1, "|%#*x|\n", -10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest186) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.10x|\n", 10, 123);
    sprintf(data1, "|%#*.10x|\n", 10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest187) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*x|\n", 10, -10, 123);
    sprintf(data1, "|%#*.*x|\n", 10, -10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest188) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*x|\n", 10, -10, 123);
    sprintf(data1, "|%*.*x|\n", 10, -10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest189) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-*.*x|\n", 10, -10, 123);
    sprintf(data1, "|%-*.*x|\n", 10, -10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest190) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*x|\n", 10, -10, 123);
    sprintf(data1, "|%#*.*x|\n", 10, -10, 123);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest191) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*x|\n", 10, -10, 0);
    sprintf(data1, "|%*.*x|\n", 10, -10, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest192) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*x|\n", 10, -10, 0);
    sprintf(data1, "|%#*.*x|\n", 10, -10, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest193) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%g|\n", 10.1);
    sprintf(data1, "|%g|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest194) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%g|\n", 0.001);
    sprintf(data1, "|%g|\n", 0.001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest195) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10g|\n", 10.1);
    sprintf(data1, "|%10g|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest196) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.5g|\n", 10.1);
    sprintf(data1, "|%10.5g|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest197) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.5g|\n", 10.1);
    sprintf(data1, "|%10.5g|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest198) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#10.5g|\n", 10.1123213);
    sprintf(data1, "|%#10.5g|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest199) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% 10.5g|\n", 10.1123213);
    sprintf(data1, "|% 10.5g|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest200) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-10.5g|\n", 10.1123213);
    sprintf(data1, "|%-10.5g|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest201) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+10.5g|\n", 10.1123213);
    sprintf(data1, "|%+10.5g|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest202) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%010.5g|\n", 10.1123213);
    sprintf(data1, "|%010.5g|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest203) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%0*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%0*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest204) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%#*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest205) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% *.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|% *.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest206) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%-*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest207) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%+*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest208) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+*.*g|\n", 10, 10, 0.0000001);
    sprintf(data1, "|%+*.*g|\n", 10, 10, 0.0000001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest209) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+#*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%+#*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest210) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%+*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest211) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*g|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%*.*g|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest212) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*o|\n", 10, -10, 0);
    sprintf(data1, "|%#*.*o|\n", 10, -10, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest213) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*o|\n", -10, -10, 0);
    sprintf(data1, "|%#*.*o|\n", -10, -10, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest214) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*o|\n", -10, -10, 0);
    sprintf(data1, "|%*.*o|\n", -10, -10, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest215) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*o|\n", -10, -10, -10);
    sprintf(data1, "|%*.*o|\n", -10, -10, -10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest216) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*o|\n", 10, 10, -10);
    sprintf(data1, "|%*.*o|\n", 10, 10, -10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest217) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*o|\n", 0, 0, 0);
    sprintf(data1, "|%*.*o|\n", 0, 0, 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest218) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*o|\n", 0, 0, -10);
    sprintf(data1, "|%*.*o|\n", 0, 0, -10);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest219) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%G|\n", 10.1);
    sprintf(data1, "|%G|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest220) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%G|\n", 0.001);
    sprintf(data1, "|%G|\n", 0.001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest221) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10G|\n", 10.1);
    sprintf(data1, "|%10G|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest222) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.5G|\n", 10.1);
    sprintf(data1, "|%10.5G|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest223) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%10.5G|\n", 10.1);
    sprintf(data1, "|%10.5G|\n", 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest224) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#10.5G|\n", 10.1123213);
    sprintf(data1, "|%#10.5G|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest225) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% 10.5G|\n", 10.1123213);
    sprintf(data1, "|% 10.5G|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest226) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-10.5G|\n", 10.1123213);
    sprintf(data1, "|%-10.5G|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest227) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+10.5G|\n", 10.1123213);
    sprintf(data1, "|%+10.5G|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest228) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%010.5G|\n", 10.1123213);
    sprintf(data1, "|%010.5G|\n", 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest229) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%0*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%0*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest230) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%#*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%#*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest231) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|% *.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|% *.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest232) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%-*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%-*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest233) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%+*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest234) {
        char data[100];
        char data1[100];
        s21_sprintf(data, "|%+*.*G|\n", 10, 10, 0.0000001);
        sprintf(data1, "|%+*.*G|\n", 10, 10, 0.0000001);
        ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest235) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+#*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%+#*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest236) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%+*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%+*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest237) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "|%*.*G|\n", -10, -10, 10.1123213);
    sprintf(data1, "|%*.*G|\n", -10, -10, 10.1123213);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest238) {
    char data[100];
    char data1[100];
    int num;
    s21_sprintf(data, "%n", &num);
    sprintf(data1, "%n", &num);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest239) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%e", -0.1);
    sprintf(data1, "%e", -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest240) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10e", 332.34);
    sprintf(data1, "%#10e", 332.34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest241) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10.5e", 332.34);
    sprintf(data1, "%#10.5e", 332.34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest242) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", 10, 10, 10.1);
    sprintf(data1, "%#*.*e", 10, 10, 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest243) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", -10, -10, -10.1);
    sprintf(data1, "%#*.*e", -10, -10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest244) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", -10, 10, 10.1);
    sprintf(data1, "%#*.*e", -10, 10, 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest245) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", 10, -10, 10.1);
    sprintf(data1, "%#*.*e", 10, -10, 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest246) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", 10, 10, -10.1);
    sprintf(data1, "%#*.*e", 10, 10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest247) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", 10, -10, -10.1);
    sprintf(data1, "%#*.*e", 10, -10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest248) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", -10, 10, -10.1);
    sprintf(data1, "%#*.*e", -10, 10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest249) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*e", 0, 0, -0.1);
    sprintf(data1, "%#*.*e", 0, 0, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest250) {
    char data[100];
    char data1[100];
    float a = -0.1;
    s21_sprintf(data, "%#*.*e", 10, 10, a);
    sprintf(data1, "%+*.*e", 10, 10, a);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest251) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "% *.*e", 10, 10, -0.1);
    sprintf(data1, "% *.*e", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest252) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%+*.*e", 10, 10, -0.1);
    sprintf(data1, "%+*.*e", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest253) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-*.*e", 10, 10, -0.1);
    sprintf(data1, "%-*.*e", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest254) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%0*.*e", 10, 10, -0.1);
    sprintf(data1, "%0*.*e", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest255) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%*.*e", 0, 0, -0.1);
    sprintf(data1, "%*.*e", 0, 0, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest256) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%E", 0.1);
    sprintf(data1, "%E", 0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest257) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10E", 332.34);
    sprintf(data1, "%#10E", 332.34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest258) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10.5E", 332.34);
    sprintf(data1, "%#10.5E", 332.34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest259) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 10, 10, 10.1);
    sprintf(data1, "%#*.*E", 10, 10, 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest260) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", -10, -10, -10.1);
    sprintf(data1, "%#*.*E", -10, -10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest261) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", -10, 10, 10.1);
    sprintf(data1, "%#*.*E", -10, 10, 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest262) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 10, -10, 10.1);
    sprintf(data1, "%#*.*E", 10, -10, 10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest263) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 10, 10, -10.1);
    sprintf(data1, "%#*.*E", 10, 10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest264) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 10, -10, -10.1);
    sprintf(data1, "%#*.*E", 10, -10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest265) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", -10, 10, -10.1);
    sprintf(data1, "%#*.*E", -10, 10, -10.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest266) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 0, 0, -0.1);
    sprintf(data1, "%#*.*E", 0, 0, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest267) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 10, 10, -0.1);
    sprintf(data1, "%+*.*E", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest268) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "% *.*E", 10, 10, -0.1);
    sprintf(data1, "% *.*E", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest269) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%+*.*E", 10, 10, -0.1);
    sprintf(data1, "%+*.*E", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest270) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-*.*E", 10, 10, -0.1);
    sprintf(data1, "%-*.*E", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest271) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%0*.*E", 10, 10, -0.1);
    sprintf(data1, "%0*.*E", 10, 10, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest272) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%*.*E", 0, 0, -0.1);
    sprintf(data1, "%*.*E", 0, 0, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest273) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", 0, 0, -0.1);
    sprintf(data1, "%#*.*E", 0, 0, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest274) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%*.*E", 0, 4, -0.1);
    sprintf(data1, "%*.*E", 0, 4, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest275) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%*.*E", -7, 0, -0.1);
    sprintf(data1, "%*.*E", -7, 0, -0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest276) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%E", 1234.323);
    sprintf(data1, "%E", 1234.323);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest277) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10E", 1234.323);
    sprintf(data1, "%#10E", 1234.323);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest278) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10.3E", 1234.32333);
    sprintf(data1, "%#10.3E", 1234.32333);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest279) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10.2E", 1234.0000);
    sprintf(data1, "%#10.2E", 1234.0000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest280) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#10.*E", -5, 0.00001);
    sprintf(data1, "%#10.*E", -5, 0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest281) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", -5, -5, 0.00001);
    sprintf(data1, "%#*.*E", -5, -5, 0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest282) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#*.*E", -5, -5, -0.00001);
    sprintf(data1, "%#*.*E", -5, -5, -0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest283) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%0*.*E", -5, -5, -0.00001);
    sprintf(data1, "%0*.*E", -5, -5, -0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest284) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "% *.*E", -5, -5, -0.00001);
    sprintf(data1, "% *.*E", -5, -5, -0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest285) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%+#*.*E", -5, -5, -0.00001);
    sprintf(data1, "%+#*.*E", -5, -5, -0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest286) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "% #*.*E", -5, -5, 0.00001);
    sprintf(data1, "% #*.*E", -5, -5, 0.00001);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest287) {
    char str[100];
    char str1[100];
    int a = 10, b = 20, c;
    c = a + b;
    sprintf(str, "Sum of %d and %d is %d", a, b, c);
    s21_sprintf(str1, "Sum of %d and %d is %d", a, b, c);
    ck_assert_str_eq(str, str1);
    sprintf(str, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u|\n",
            "abra", 'e', 56, -43);
    s21_sprintf(str1, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u|\n",
                "abra", 'e', 56, -43);
    ck_assert_str_eq(str, str1);
    sprintf(str, "Sum of %d and %d is %d", a, b, c);
    s21_sprintf(str1, "Sum of %d and %d is %d", a, b, c);
}
END_TEST

START_TEST(SFTest288) {
    char str[100];
    char str1[100];
    sprintf(str, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u|\n",
            "abra", 'e', 56, -43);
    s21_sprintf(str1, "Chislo:|%-5s|kust and |%9c|. This sum is |%i|. This is |%%|. And now unsigned: |%u|\n",
                "abra", 'e', 56, -43);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest289) {
    char str[100];
    char str1[100];
    sprintf(str, "and now heximal: |%8x|, |%X|\n", 5554645, -123);
    s21_sprintf(str1, "and now heximal: |%8x|, |%X|\n", 5554645, -123);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest290) {
    char str[100];
    char str1[100];
    sprintf(str, "%p", NULL);
    s21_sprintf(str1, "%p", NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest291) {
    char str[100];
    char str1[100];
    char *ptr = NULL;
    sprintf(str, "%p", ptr);
    s21_sprintf(str1, "%p", ptr);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest292) {
    char str[100];
    char str1[100];
    sprintf(str, "|%i|\n",   10);
    s21_sprintf(str1, "|%i|\n",   10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest293) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", 8, 5, 15);
    s21_sprintf(str1, "|%*.*i|\n", 8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest294) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", 8, 5, 152352352);
    s21_sprintf(str1, "|%*.*i|\n", 8, 5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest295) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*i|\n", 18, 152352352);
    s21_sprintf(str1, "|%0*i|\n", 18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest296) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*i|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest297) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*i|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%-*.*i|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest298) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*i|", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest299) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*i|\n", 3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*i|\n", 3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest300) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*i|\n", -10, -5, 10);
    s21_sprintf(str1, "|%-*.*i|\n", -10, -5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest301) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", -8, -5, 15);
    s21_sprintf(str1, "|%*.*i|\n", -8, -5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest302) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", -8, -5, 152352352);
    s21_sprintf(str1, "|%*.*i|\n", -8, -5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest303) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*i|\n", -18, 152352352);
    s21_sprintf(str1, "|%0*i|\n", -18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest304) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", -18, -10, 152352352);
    s21_sprintf(str1, "|%*.*i|\n", -18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST
START_TEST(SFTest305) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*i|\n", -18, -10, 152352352);
    s21_sprintf(str1, "|%-*.*i|\n", -18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest306) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", -18, -15, -152352352);
    s21_sprintf(str1, "|%*.*i|\n", -18, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest307) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", -18, 10, 152352352);
    s21_sprintf(str1, "|%*.*i|\n", -18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest308) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*i|\n", 18, -15, -152352352);
    s21_sprintf(str1, "|%*.*i|\n", 18, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest309) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*i|\n", -3, -15, -152352352);
    s21_sprintf(str1, "|%-*.*i|\n", -3, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// D

START_TEST(SFTest310) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", 10, 5, 10);
    s21_sprintf(str1, "|%-*.*d|\n", 10, 5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest311) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", 8, 5, 15);
    s21_sprintf(str1, "|%*.*d|\n", 8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest312) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", 8, 5, 152352352);
    s21_sprintf(str1, "|%*.*d|\n", 8, 5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest313) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*d|\n", 18, 152352352);
    s21_sprintf(str1, "|%0*d|\n", 18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest314) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*d|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest315) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%-*.*d|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest316) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*d|\n", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest317) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", 3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*d|\n", 3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest318) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", 15, 3, -152352352);
    s21_sprintf(str1, "|%-*.*d|\n", 15, 3, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// Width and accuracy for D

START_TEST(SFTest319) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", -10, -5, 10);
    s21_sprintf(str1, "|%-*.*d|\n", -10, -5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest320) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", -8, 5, 15);
    s21_sprintf(str1, "|%*.*d|\n", -8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest321) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", 8, -5, 152352352);
    s21_sprintf(str1, "|%*.*d|\n", 8, -5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest322) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*d|\n", -18, 152352352);
    s21_sprintf(str1, "|%0*d|\n", -18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest323) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", -18, 10, 152352352);
    s21_sprintf(str1, "|%*.*d|\n", -18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest324) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", 18, -10, 152352352);
    s21_sprintf(str1, "|%-*.*d|\n", 18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest325) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", -18, -15, -152352352);
    s21_sprintf(str1, "|%*.*d|\n", -18, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest326) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", 18, -10, 152352352);
    s21_sprintf(str1, "|%*.*d|\n", 18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest327) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", -18, 15, -152352352);
    s21_sprintf(str1, "|%*.*d|\n", -18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest328) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", 3, -15, -152352352);
    s21_sprintf(str1, "|%-*.*d|\n", 3, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest329) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*d|\n", -15, 3, -152352352);
    s21_sprintf(str1, "|%-*.*d|\n", -15, 3, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// Some interesting for D

START_TEST(SFTest330) {
    char str[100];
    char str1[100];
    sprintf(str, "|%.d|\n", 0);
    s21_sprintf(str1, "|%.d|\n", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest331) {
    char str[100];
    char str1[100];
    sprintf(str, "|%5.d|\n", 0);
    s21_sprintf(str1, "|%5.d|\n", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest332) {
    char str[100];
    char str1[100];
    sprintf(str, "|%5.0d|\n", 0);
    s21_sprintf(str1, "|%5.0d|\n", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest333) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-5.d|\n", 0);
    s21_sprintf(str1, "|%-5.d|\n", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest334) {
    char str[100];
    char str1[100];
    sprintf(str, "|%.0d|\n", 0);
    s21_sprintf(str1, "|%.0d|\n", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

// U

START_TEST(SFTest335) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 10, 5, 10);
    s21_sprintf(str1, "|%-*.*u|\n", 10, 5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest336) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 8, 5, 15);
    s21_sprintf(str1, "|%*.*u|\n", 8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest337) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 8, 5, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", 8, 5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest338) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*u|\n", 18, 152352352);
    s21_sprintf(str1, "|%0*u|\n", 18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest339) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest340) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%-*.*u|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest341) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*u|\n", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest342) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest343) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*u|\n", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest344) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*u|\n", 3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest345) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-20.18u|\n", -345);
    s21_sprintf(str1, "|%-20.18u|\n", -345);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest346) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-20.*u|\n", -18, -345);
    s21_sprintf(str1, "|%-20.*u|\n", -18, -345);
    ck_assert_str_eq(str, str1);
}
END_TEST

// Width and accuracy U

START_TEST(SFTest347) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, -10, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", -18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest348) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 18, -10, 152352352);
    s21_sprintf(str1, "|%-*.*u|\n", 18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest349) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, 15, -152352352);
    s21_sprintf(str1, "|%*.*u|\n", -18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest350) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", -3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*u|\n", -3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest351) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, -10, 0);
    s21_sprintf(str1, "|%*.*u|\n", -18, -10, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest352) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 18, -10, 0);
    s21_sprintf(str1, "|%-*.*u|\n", 18, -10, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest353) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, 15, -0);
    s21_sprintf(str1, "|%*.*u|\n", -18, 15, -0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest354) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", -3, 15, -0);
    s21_sprintf(str1, "|%-*.*u|\n", -3, 15, -0);
    ck_assert_str_eq(str, str1);
}
END_TEST

// X

START_TEST(SFTest355) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 10, 5, 10);
    s21_sprintf(str1, "|%-*.*x|\n", 10, 5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest356) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 5, 15);
    s21_sprintf(str1, "|%*.*x|\n", 8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest357) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 5, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", 8, 5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest358) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*x|\n", 18, 152352352);
    s21_sprintf(str1, "|%0*x|\n", 18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest359) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 10, 0, 0);
    s21_sprintf(str1, "|%-*.*x|\n", 10, 0, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest360) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 0, 0);
    s21_sprintf(str1, "|%*.*x|\n", 8, 0, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest361) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 5, 0);
    s21_sprintf(str1, "|%*.*x|\n", 8, 5, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest362) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*x|\n", 18, 0);
    s21_sprintf(str1, "|%0*x|\n", 18, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest363) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest364) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%-*.*x|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest365) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*x|\n", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest366) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest367) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*x|\n", 3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// Width and accuracy X

START_TEST(SFTest368) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", -18, -10, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", -18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest369) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 18, -10, 152352352);
    s21_sprintf(str1, "|%-*.*x|\n", 18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest370) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", -18, 15, -152352352);
    s21_sprintf(str1, "|%*.*x|\n", -18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest371) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", -3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*x|\n", -3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest372) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", -18, -10, 0);
    s21_sprintf(str1, "|%*.*x|\n", -18, -10, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest373) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 18, -10, 0);
    s21_sprintf(str1, "|%-*.*x|\n", 18, -10, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest374) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", -18, 15, -0);
    s21_sprintf(str1, "|%*.*x|\n", -18, 15, -0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest375) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", -3, 15, -0);
    s21_sprintf(str1, "|%-*.*x|\n", -3, 15, -0);
    ck_assert_str_eq(str, str1);
}
END_TEST

// X

START_TEST(SFTest376) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 10, 5, 10);
    s21_sprintf(str1, "|%-*.*x|\n", 10, 5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest377) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 5, 15);
    s21_sprintf(str1, "|%*.*x|\n", 8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest378) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 5, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", 8, 5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest379) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*x|\n", 18, 152352352);
    s21_sprintf(str1, "|%0*x|\n", 18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest380) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 10, 0, 0);
    s21_sprintf(str1, "|%-*.*x|\n", 10, 0, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest381) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 0, 0);
    s21_sprintf(str1, "|%*.*x|\n", 8, 0, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest382) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 8, 5, 0);
    s21_sprintf(str1, "|%*.*x|\n", 8, 5, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest383) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*x|\n", 18, 0);
    s21_sprintf(str1, "|%0*x|\n", 18, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest384) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest385) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%-*.*x|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest386) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*x|\n", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest387) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*x|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*x|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest388) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*x|\n", 3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*x|\n", 3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// S

START_TEST(SFTest389) {
    char str[100];
    char str1[100];
    sprintf(str, "|%8s|\n", "abra");
    s21_sprintf(str1, "|%8s|\n", "abra");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest390) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-8s|\n", "abrafdefgbr");
    s21_sprintf(str1, "|%-8s|\n", "abrafdefgbr");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest391) {
    char str[100];
    char str1[100];
    sprintf(str, "|%8s|\n", "abra");
    s21_sprintf(str1, "|%8s|\n", "abra");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest392) {
    char str[100];
    char str1[100];
    sprintf(str, "|%8s|\n", "abrafdefgbr");
    s21_sprintf(str1, "|%8s|\n", "abrafdefgbr");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest393) {
    char str[100];
    char str1[100];
    sprintf(str, "|%8s|\n", "abra");
    s21_sprintf(str1, "|%8s|\n", "abra");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest394) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest395) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%-*.*s|\n", 20, 5, "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest396) {
    char str[100];
    char str1[100];
    sprintf(str, "|%.*s|\n",  5, "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%.*s|\n",  5, "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest397) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.s|\n", 20, "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%*.s|\n", 20, "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest398) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest399) {
    char str[100];
    char str1[100];
    sprintf(str, "|%.s|\n",  "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%.s|\n",  "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest400) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*s|\n",  40, "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%*s|\n",  40, "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest401) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%-*.s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest402) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%-*.0s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest403) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.1s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%*.1s|\n", 20,  "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest404) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
    s21_sprintf(str1, "|%-*.*s|\n", 2, 20, "1234567890123fsfbdfbdfvbbdvbvb");
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest405) {
    char p[100];
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*s|\n",  20, 2, p);
    s21_sprintf(str1, "|%*.*s|\n",  20, 2, p);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest406) {
    char p[100];
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*s|\n",  20, 6, p);
    s21_sprintf(str1, "|%*.*s|\n",  20, 6, p);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest407) {
    char p[100];
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*s|\n",  20, 2, p);
    s21_sprintf(str1, "|%*.*s|\n",  20, 2, p);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest408) {
    char p[100];
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*s|\n",  20, 3, p);
    s21_sprintf(str1, "|%-*.*s|\n",  20, 3, p);
    ck_assert_str_eq(str, str1);
}
END_TEST

// P

START_TEST(SFTest409) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  20, NULL);
    s21_sprintf(str1, "|%-*p|\n",  20, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest410) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  20, NULL);
    s21_sprintf(str1, "|%-*p|\n",  20, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest411) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  20, NULL);
    s21_sprintf(str1, "|%*p|\n",  20, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest412) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  1, NULL);
    s21_sprintf(str1, "|%*p|\n",  1, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest413) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  1, NULL);
    s21_sprintf(str1, "|%-*p|\n",  1, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest414) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  0, NULL);
    s21_sprintf(str1, "|%-*p|\n",  0, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest415) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  16, NULL);
    s21_sprintf(str1, "|%*p|\n",  16, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest416) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  -20, NULL);
    s21_sprintf(str1, "|%-*p|\n",  -20, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest417) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  -20, NULL);
    s21_sprintf(str1, "|%*p|\n",  -20, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest418) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  -1, NULL);
    s21_sprintf(str1, "|%*p|\n",  -1, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest419) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  -1, NULL);
    s21_sprintf(str1, "|%-*p|\n",  -1, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest420) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*d|\n", -18, -10, 0);
    s21_sprintf(str1, "|%*.*d|\n", -18, -10, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest421) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  -16, NULL);
    s21_sprintf(str1, "|%*p|\n",  -16, NULL);
    ck_assert_str_eq(str, str1);
}
END_TEST

// P.

START_TEST(SFTest422) {
    int a = 23;
    char *str2 = "aa";
    char str[100];
    char str1[100];
    sprintf(str, "And now address: |%p| |%p|\n", &a, str2);
    s21_sprintf(str1, "And now address: |%p| |%p|\n", &a, str2);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest423) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  20, &a);
    s21_sprintf(str1, "|%-*p|\n",  20, &a);
    ck_assert_str_eq(str, str1);;
}
END_TEST

START_TEST(SFTest424) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  20, &a);
    s21_sprintf(str1, "|%*p|\n",  20, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest425) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  1, &a);
    s21_sprintf(str1, "|%*p|\n",  1, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest426) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  -1, &a);
    s21_sprintf(str1, "|%*p|\n",  -1, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest427) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  1, &a);
    s21_sprintf(str1, "|%-*p|\n",  1, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest428) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  0, &a);
    s21_sprintf(str1, "|%-*p|\n",  0, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest429) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  16, &a);
    s21_sprintf(str1, "|%*p|\n",  16, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest430) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  -20, &a);
    s21_sprintf(str1, "|%*p|\n",  -20, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest431) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  -20, &a);
    s21_sprintf(str1, "|%-*p|\n",  -20, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest432) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%-*p|\n",  -1, &a);
    s21_sprintf(str1, "|%-*p|\n",  -1, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest433) {
    int a = 23;
    char str[100];
    char str1[100];
    sprintf(str, "|%*p|\n",  -16, &a);
    s21_sprintf(str1, "|%*p|\n",  -16, &a);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest434) {
    char str[100];
    char str1[100];
    sprintf(str, "%i", 0);
    s21_sprintf(str1, "%i", 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

// С

START_TEST(SFTest435) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n", 40, 'a');
    s21_sprintf(str1, "|%*c|\n", 40, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest436) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  0, 'a');
    s21_sprintf(str1, "|%*c|\n",  0, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest437) {
    char str[100];
    char str1[100];
    sprintf(str, "|%c|\n", 'a');
    s21_sprintf(str1, "|%c|\n", 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest438) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 0,   'a');
    s21_sprintf(str1, "|%-*c|\n", 0,   'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest439) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n",  40, 'a');
    s21_sprintf(str1, "|%-*c|\n",  40, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest440) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  5, 'a');
    s21_sprintf(str1, "|%*c|\n",  5, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest441) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 5,   'a');
    s21_sprintf(str1, "|%-*c|\n", 5,   'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest442) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 1, 'a');
    s21_sprintf(str1, "|%-*c|\n", 1, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest443) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 0,   'a');
    s21_sprintf(str1, "|%-*c|\n", 0,   'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

// Negative C

START_TEST(SFTest444) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  -40, 'a');
    s21_sprintf(str1, "|%*c|\n",  -40, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest445) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  -1, 'a');
    s21_sprintf(str1, "|%*c|\n",  -1, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest446) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 0,   'a');
    s21_sprintf(str1, "|%-*c|\n", 0,   'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest447) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n",  -40, 'a');
    s21_sprintf(str1, "|%-*c|\n",  -40, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest448) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  -5, 'a');
    s21_sprintf(str1, "|%*c|\n",  -5, 'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest449) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", -5,   'a');
    s21_sprintf(str1, "|%-*c|\n", -5,   'a');
    ck_assert_str_eq(str, str1);
}
END_TEST

// Empty C

START_TEST(SFTest450) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  40, '\0');
    s21_sprintf(str1, "|%*c|\n",  40, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest451) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  0, '\0');
    s21_sprintf(str1, "|%*c|\n",  0, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest452) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 0,  '\0');
    s21_sprintf(str1, "|%-*c|\n", 0,  '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest453) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n",  40, '\0');
    s21_sprintf(str1, "|%-*c|\n",  40, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest454) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 5,   '\0');
    s21_sprintf(str1, "|%-*c|\n", 5,   '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest455) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  1, '\0');
    s21_sprintf(str1, "|%*c|\n",  1, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest456) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", 1,   '\0');
    s21_sprintf(str1, "|%-*c|\n", 1,   '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

// Negative empty C

START_TEST(SFTest457) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  -40, '\0');
    s21_sprintf(str1, "|%*c|\n",  -40, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest458) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  -1, '\0');
    s21_sprintf(str1, "|%*c|\n",  -1, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest459) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", -1,  '\0');
    s21_sprintf(str1, "|%-*c|\n", -1,  '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest460) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n",  -40, '\0');
    s21_sprintf(str1, "|%-*c|\n",  -40, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest461) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*c|\n",  -5, '\0');
    s21_sprintf(str1, "|%*c|\n",  -5, '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest462) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*c|\n", -5,   '\0');
    s21_sprintf(str1, "|%-*c|\n", -5,   '\0');
    ck_assert_str_eq(str, str1);
}
END_TEST

// +

START_TEST(SFTest463) {
    char str[100];
    char str1[100];
    for (int i = -101; i <= 101; i++) {
        sprintf(str, "%+i", i);
        s21_sprintf(str1, "%+i", i);
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(SFTest464) {
    char str[100];
    char str1[100];
    for (int i = -101; i <= 101; i++) {
        sprintf(str, "%+d", i);
        s21_sprintf(str1, "%+d", i);
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(SFTest465) {
    char str[100];
    char str1[100];
    sprintf(str, " %+d %+i %+d %+d", 2147483647, -2147483647, 21, 0);
    s21_sprintf(str1, " %+d %+i %+d %+d", 2147483647, -2147483647, 21, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest466) {
    char str[100];
    char str1[100];
    sprintf(str, " %+li ", 9223372036854775807);
    s21_sprintf(str1, " %+li ", 9223372036854775807);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest467) {
    char str[100];
    char str1[100];
    sprintf(str, " %+ld ", 9223372036854775807);
    s21_sprintf(str1, " %+ld ", 9223372036854775807);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest468) {
    char str[100];
    char str1[100];
    sprintf(str, " %+-5d %+-5i", -7, 0);
    s21_sprintf(str1, " %+-5d %+-5i", -7, 0);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest469) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%lo\n", 100000000000000000);
    sprintf(data1, "%lo\n", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

// U

START_TEST(SFTest470) {
    char str[100];
    char str1[100];
    sprintf(str, "|%u|\n",   10);
    s21_sprintf(str1, "|%u|\n",   10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest471) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 8, 5, 15);
    s21_sprintf(str1, "|%*.*u|\n", 8, 5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest472) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 8, 5, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", 8, 5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest473) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*u|\n", 18, 152352352);
    s21_sprintf(str1, "|%0*u|\n", 18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest474) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest475) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 18, 10, 152352352);
    s21_sprintf(str1, "|%-*.*u|\n", 18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest476) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|", 18, 15, -152352352);
    s21_sprintf(str1, "|%*.*u|", 18, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest477) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", 3, 15, -152352352);
    s21_sprintf(str1, "|%-*.*u|\n", 3, 15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// Negative and accuracy U

START_TEST(SFTest478) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", -10, -5, 10);
    s21_sprintf(str1, "|%-*.*u|\n", -10, -5, 10);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest479) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -8, -5, 15);
    s21_sprintf(str1, "|%*.*u|\n", -8, -5, 15);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest480) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -8, -5, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", -8, -5, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest481) {
    char str[100];
    char str1[100];
    sprintf(str, "|%0*u|\n", -18, 152352352);
    s21_sprintf(str1, "|%0*u|\n", -18, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest482) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, -10, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", -18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest483) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", -18, -10, 152352352);
    s21_sprintf(str1, "|%-*.*u|\n", -18, -10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest484) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, -15, -152352352);
    s21_sprintf(str1, "|%*.*u|\n", -18, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest485) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", -18, 10, 152352352);
    s21_sprintf(str1, "|%*.*u|\n", -18, 10, 152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest486) {
    char str[100];
    char str1[100];
    sprintf(str, "|%*.*u|\n", 18, -15, -152352352);
    s21_sprintf(str1, "|%*.*u|\n", 18, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest487) {
    char str[100];
    char str1[100];
    sprintf(str, "|%-*.*u|\n", -3, -15, -152352352);
    s21_sprintf(str1, "|%-*.*u|\n", -3, -15, -152352352);
    ck_assert_str_eq(str, str1);
}
END_TEST

// Space

START_TEST(SFTest488) {
    char str[100];
    char str1[100];
    for (int i = -101; i <= 101;) {
        sprintf(str, "% d", i);
        s21_sprintf(str1, "% d", i);
        i = i+7;
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(SFTest489) {
        char str[100];
        char str1[100];
            sprintf(str, " %#x ", 0);
            s21_sprintf(str1, " %#x ", 0);
            ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest490) {
    char str[100];
    char str1[100];
    for (int i = -101; i <= 101;) {
        sprintf(str, "% -i % -d % -5d", i, i+1, 143646235);
        s21_sprintf(str1, "% -i % -d % -5d", i, i+1, 143646235);
        i = i+7;
        ck_assert_str_eq(str, str1);
    }
}
END_TEST

START_TEST(SFTest491) {
    char str[100];
    char str1[100];
        sprintf(str, "%#o", 143646235);
        s21_sprintf(str1, "%#o", 143646235);
        ck_assert_str_eq(str, str1);
}
END_TEST

START_TEST(SFTest492) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%o|\n", 34);
    sprintf(data1, "02) standart PRINTF : |%o|\n", 34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest493) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%o|\n", -34);
    sprintf(data1, "02) standart PRINTF : |%o|\n", -34);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest494) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-o|\n", 50);
    sprintf(data1, "02) standart PRINTF : |%-o|\n", 50);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest495) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10o|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%10o|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest496) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.10o|\n", 90);
    sprintf(data1, "02) standart PRINTF : |%.10o|\n", 90);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest497) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15o|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%15o|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest498) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.15o|\n", -100);
    sprintf(data1, "02) standart PRINTF : |%.15o|\n", -100);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest499) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%10.5o|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%10.5o|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest500) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%5.10o|\n", 52);
    sprintf(data1, "02) standart PRINTF : |%5.10o|\n", 52);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest501) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%20.15o|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%20.15o|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest502) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%15.20o|\n", -100000);
    sprintf(data1, "02) standart PRINTF : |%15.20o|\n", -100000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest503) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-10o|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-10o|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest504) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-.10o|\n", 144);
    sprintf(data1, "02) standart PRINTF : |%-.10o|\n", 144);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest505) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%-20o|\n", -20000000);
    sprintf(data1, "02) standart PRINTF : |%-20o|\n", -20000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest506) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%08o|\n", 64);
    sprintf(data1, "02) standart PRINTF : |%08o|\n", 64);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest507) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.o|\n", 0);
    sprintf(data1, "02) standart PRINTF : |%.o|\n", 0);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest508) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%.o|\n", 88);
    sprintf(data1, "02) standart PRINTF : |%.o|\n", 88);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest509) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "02) standart PRINTF : |%o| |%o|\n", (unsigned int)-1,  1);
    sprintf(data1, "02) standart PRINTF : |%o| |%o|\n", (unsigned int)-1, 1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest510) {
    char data[100];
    char data1[100];
    int t = 50;
    s21_sprintf(data, "%s %n", "hello world", &t);
    sprintf(data1, "%s %n", "hello world", &t);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest511) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%-3.1s", "\0");
    sprintf(data1, "%-3.1s", "\0");
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest512) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "this -%g scientific notation", -1.5);
    sprintf(data1, "this -%g scientific notation", -1.5);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest513) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%.0g", 0.1);
    sprintf(data1, "%.0g", 0.1);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest514) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%g", 9999999999.9);
    sprintf(data1, "%g", 9999999999.9);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest515) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%e", 9999999999.9);
    sprintf(data1, "%e", 9999999999.9);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest516) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%0*.e", 10, 0.9);
    sprintf(data1, "%0*.e", 10, 0.9);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest517) {
    char data[100];
    char data1[100];
    s21_sprintf(data, "%#05x", 21);
    sprintf(data1, "%#05x", 21);
    ck_assert_str_eq(data, data1);
}
END_TEST

// Sprintf

START_TEST(SFTest518) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%li", 100000000000000000);
    sprintf(data1, "%li", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest519) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%lo", 100000000000000000);
    sprintf(data1, "%lo", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest520) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%lu", 100000000000000000);
    sprintf(data1, "%lu", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest521) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%lx", 100000000000000000);
    sprintf(data1, "%lx", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest522) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%lX", 100000000000000000);
    sprintf(data1, "%lX", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest523) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%ld", 100000000000000000);
    sprintf(data1, "%ld", 100000000000000000);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest524) {
    char data[200];
    char data1[200];
    short int i = -30000;
    s21_sprintf(data, "%hi", i);
    sprintf(data1, "%hi", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest525) {
    char data[200];
    char data1[200];
    short int i = -30000;
    s21_sprintf(data, "%ho", i);
    sprintf(data1, "%ho", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest526) {
    char data[200];
    char data1[200];
    short int i = -30000;
    s21_sprintf(data, "%hu", i);
    sprintf(data1, "%hu", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest527) {
    char data[200];
    char data1[200];
    short int i = -30000;
    s21_sprintf(data, "%hx", i);
    sprintf(data1, "%hx", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest528) {
    char data[200];
    char data1[200];
    short int i = -30000;
    s21_sprintf(data, "%hX", i);
    sprintf(data1, "%hX", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest529) {
    char data[200];
    char data1[200];
    short int i = -30000;
    s21_sprintf(data, "%hd", i);
    sprintf(data1, "%hd", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest530) {
    char data[200];
    char data1[200];
    s21_sprintf(data, "%lc", 'c');
    sprintf(data1, "%lc", 'c');
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest531) {
    char data[200];
    char data1[200];
    long double i = 0.00000000000000000000000000000000000000000000000001;
    s21_sprintf(data, "%Lf", i);
    sprintf(data1, "%LF", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest532) {
    char data[200];
    char data1[200];
    long double i = 1.1e+49;
    s21_sprintf(data, "%Le", i);
    sprintf(data1, "%Le", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest533) {
    char data[200];
    char data1[200];
    long double i = 1.1e+49;
    s21_sprintf(data, "%LE", i);
    sprintf(data1, "%LE", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest534) {
    char data[200];
    char data1[200];
    long double i = 0.00000000000000000000000000000000000000000000000001;
    s21_sprintf(data, "%Lg", i);
    sprintf(data1, "%Lg", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(SFTest535) {
    char data[200];
    char data1[200];
    long double i = 0.00000000000000000000000000000000000000000000000001;
    s21_sprintf(data, "%LG", i);
    sprintf(data1, "%LG", i);
    ck_assert_str_eq(data, data1);
}
END_TEST

Suite *example_suite_create() {
    Suite *s1 = suite_create("Test_sprintf");
    TCase *sprintftest = tcase_create("SPRINTF2");
    suite_add_tcase(s1, sprintftest);
    tcase_add_test(sprintftest, SFTest1);
    tcase_add_test(sprintftest, SFTest2);
    tcase_add_test(sprintftest, SFTest3);
    tcase_add_test(sprintftest, SFTest4);
    tcase_add_test(sprintftest, SFTest5);
    tcase_add_test(sprintftest, SFTest6);
    tcase_add_test(sprintftest, SFTest7);
    tcase_add_test(sprintftest, SFTest8);
    tcase_add_test(sprintftest, SFTest9);
    tcase_add_test(sprintftest, SFTest10);
    tcase_add_test(sprintftest, SFTest11);
    tcase_add_test(sprintftest, SFTest12);
    tcase_add_test(sprintftest, SFTest13);
    tcase_add_test(sprintftest, SFTest14);
    tcase_add_test(sprintftest, SFTest15);
    tcase_add_test(sprintftest, SFTest16);
    tcase_add_test(sprintftest, SFTest17);
    tcase_add_test(sprintftest, SFTest18);
    tcase_add_test(sprintftest, SFTest19);
    tcase_add_test(sprintftest, SFTest20);
    tcase_add_test(sprintftest, SFTest21);
    tcase_add_test(sprintftest, SFTest22);
    tcase_add_test(sprintftest, SFTest23);
    tcase_add_test(sprintftest, SFTest24);
    tcase_add_test(sprintftest, SFTest25);
    tcase_add_test(sprintftest, SFTest26);
    tcase_add_test(sprintftest, SFTest27);
    tcase_add_test(sprintftest, SFTest28);
    tcase_add_test(sprintftest, SFTest29);
    tcase_add_test(sprintftest, SFTest30);
    tcase_add_test(sprintftest, SFTest31);
    tcase_add_test(sprintftest, SFTest32);
    tcase_add_test(sprintftest, SFTest33);
    tcase_add_test(sprintftest, SFTest34);
    tcase_add_test(sprintftest, SFTest35);
    tcase_add_test(sprintftest, SFTest36);
    tcase_add_test(sprintftest, SFTest37);
    tcase_add_test(sprintftest, SFTest38);
    tcase_add_test(sprintftest, SFTest39);
    tcase_add_test(sprintftest, SFTest40);
    tcase_add_test(sprintftest, SFTest41);
    tcase_add_test(sprintftest, SFTest42);
    tcase_add_test(sprintftest, SFTest43);
    tcase_add_test(sprintftest, SFTest44);
    tcase_add_test(sprintftest, SFTest45);
    tcase_add_test(sprintftest, SFTest46);
    tcase_add_test(sprintftest, SFTest47);
    tcase_add_test(sprintftest, SFTest48);
    tcase_add_test(sprintftest, SFTest49);
    tcase_add_test(sprintftest, SFTest50);
    tcase_add_test(sprintftest, SFTest51);
    tcase_add_test(sprintftest, SFTest52);
    tcase_add_test(sprintftest, SFTest53);
    tcase_add_test(sprintftest, SFTest54);
    tcase_add_test(sprintftest, SFTest55);
    tcase_add_test(sprintftest, SFTest56);
    tcase_add_test(sprintftest, SFTest57);
    tcase_add_test(sprintftest, SFTest58);
    tcase_add_test(sprintftest, SFTest59);
    tcase_add_test(sprintftest, SFTest60);
    tcase_add_test(sprintftest, SFTest61);
    tcase_add_test(sprintftest, SFTest62);
    tcase_add_test(sprintftest, SFTest63);
    tcase_add_test(sprintftest, SFTest64);
    tcase_add_test(sprintftest, SFTest65);
    tcase_add_test(sprintftest, SFTest66);
    tcase_add_test(sprintftest, SFTest67);
    tcase_add_test(sprintftest, SFTest68);
    tcase_add_test(sprintftest, SFTest69);
    tcase_add_test(sprintftest, SFTest70);
    tcase_add_test(sprintftest, SFTest71);
    tcase_add_test(sprintftest, SFTest72);
    tcase_add_test(sprintftest, SFTest73);
    tcase_add_test(sprintftest, SFTest74);
    tcase_add_test(sprintftest, SFTest75);
    tcase_add_test(sprintftest, SFTest76);
  tcase_add_test(sprintftest, SFTest77);
tcase_add_test(sprintftest, SFTest78);
tcase_add_test(sprintftest, SFTest79);
tcase_add_test(sprintftest, SFTest80);
tcase_add_test(sprintftest, SFTest81);
tcase_add_test(sprintftest, SFTest82);
tcase_add_test(sprintftest, SFTest83);
tcase_add_test(sprintftest, SFTest84);
tcase_add_test(sprintftest, SFTest85);
tcase_add_test(sprintftest, SFTest86);
tcase_add_test(sprintftest, SFTest87);
tcase_add_test(sprintftest, SFTest88);
tcase_add_test(sprintftest, SFTest89);
tcase_add_test(sprintftest, SFTest90);
tcase_add_test(sprintftest, SFTest91);
tcase_add_test(sprintftest, SFTest92);
tcase_add_test(sprintftest, SFTest93);
tcase_add_test(sprintftest, SFTest94);
tcase_add_test(sprintftest, SFTest95);
tcase_add_test(sprintftest, SFTest96);
tcase_add_test(sprintftest, SFTest97);
tcase_add_test(sprintftest, SFTest98);
tcase_add_test(sprintftest, SFTest99);
tcase_add_test(sprintftest, SFTest100);
tcase_add_test(sprintftest, SFTest101);
tcase_add_test(sprintftest, SFTest102);
tcase_add_test(sprintftest, SFTest103);
tcase_add_test(sprintftest, SFTest104);
tcase_add_test(sprintftest, SFTest105);
tcase_add_test(sprintftest, SFTest106);
tcase_add_test(sprintftest, SFTest107);
tcase_add_test(sprintftest, SFTest108);
tcase_add_test(sprintftest, SFTest109);
tcase_add_test(sprintftest, SFTest110);
tcase_add_test(sprintftest, SFTest111);
tcase_add_test(sprintftest, SFTest112);
tcase_add_test(sprintftest, SFTest113);
tcase_add_test(sprintftest, SFTest114);
tcase_add_test(sprintftest, SFTest115);
tcase_add_test(sprintftest, SFTest116);
tcase_add_test(sprintftest, SFTest117);
tcase_add_test(sprintftest, SFTest118);
tcase_add_test(sprintftest, SFTest119);
tcase_add_test(sprintftest, SFTest120);
tcase_add_test(sprintftest, SFTest121);
tcase_add_test(sprintftest, SFTest122);
tcase_add_test(sprintftest, SFTest123);
tcase_add_test(sprintftest, SFTest124);
tcase_add_test(sprintftest, SFTest125);
tcase_add_test(sprintftest, SFTest126);
tcase_add_test(sprintftest, SFTest127);
tcase_add_test(sprintftest, SFTest128);
tcase_add_test(sprintftest, SFTest129);
tcase_add_test(sprintftest, SFTest130);
tcase_add_test(sprintftest, SFTest131);
tcase_add_test(sprintftest, SFTest132);
tcase_add_test(sprintftest, SFTest133);
tcase_add_test(sprintftest, SFTest134);
tcase_add_test(sprintftest, SFTest135);
tcase_add_test(sprintftest, SFTest136);
tcase_add_test(sprintftest, SFTest137);
tcase_add_test(sprintftest, SFTest138);
tcase_add_test(sprintftest, SFTest139);
tcase_add_test(sprintftest, SFTest140);
tcase_add_test(sprintftest, SFTest141);
tcase_add_test(sprintftest, SFTest142);
tcase_add_test(sprintftest, SFTest143);
tcase_add_test(sprintftest, SFTest144);
tcase_add_test(sprintftest, SFTest145);
tcase_add_test(sprintftest, SFTest146);
tcase_add_test(sprintftest, SFTest147);
tcase_add_test(sprintftest, SFTest148);
tcase_add_test(sprintftest, SFTest149);
tcase_add_test(sprintftest, SFTest150);
tcase_add_test(sprintftest, SFTest151);
tcase_add_test(sprintftest, SFTest152);
tcase_add_test(sprintftest, SFTest153);
tcase_add_test(sprintftest, SFTest154);
tcase_add_test(sprintftest, SFTest155);
tcase_add_test(sprintftest, SFTest156);
tcase_add_test(sprintftest, SFTest157);
tcase_add_test(sprintftest, SFTest158);
tcase_add_test(sprintftest, SFTest159);
tcase_add_test(sprintftest, SFTest160);
tcase_add_test(sprintftest, SFTest161);
tcase_add_test(sprintftest, SFTest162);
tcase_add_test(sprintftest, SFTest163);
tcase_add_test(sprintftest, SFTest164);
tcase_add_test(sprintftest, SFTest165);
tcase_add_test(sprintftest, SFTest166);
tcase_add_test(sprintftest, SFTest167);
tcase_add_test(sprintftest, SFTest168);
tcase_add_test(sprintftest, SFTest169);
tcase_add_test(sprintftest, SFTest170);
tcase_add_test(sprintftest, SFTest171);
tcase_add_test(sprintftest, SFTest172);
tcase_add_test(sprintftest, SFTest173);
tcase_add_test(sprintftest, SFTest174);
tcase_add_test(sprintftest, SFTest175);
tcase_add_test(sprintftest, SFTest176);
tcase_add_test(sprintftest, SFTest177);
tcase_add_test(sprintftest, SFTest178);
tcase_add_test(sprintftest, SFTest179);
tcase_add_test(sprintftest, SFTest180);
tcase_add_test(sprintftest, SFTest181);
tcase_add_test(sprintftest, SFTest182);
tcase_add_test(sprintftest, SFTest183);
tcase_add_test(sprintftest, SFTest184);
tcase_add_test(sprintftest, SFTest185);
tcase_add_test(sprintftest, SFTest186);
tcase_add_test(sprintftest, SFTest187);
tcase_add_test(sprintftest, SFTest188);
tcase_add_test(sprintftest, SFTest189);
tcase_add_test(sprintftest, SFTest190);
tcase_add_test(sprintftest, SFTest191);
tcase_add_test(sprintftest, SFTest192);
tcase_add_test(sprintftest, SFTest193);
tcase_add_test(sprintftest, SFTest194);
tcase_add_test(sprintftest, SFTest195);
tcase_add_test(sprintftest, SFTest196);
tcase_add_test(sprintftest, SFTest197);
tcase_add_test(sprintftest, SFTest198);
tcase_add_test(sprintftest, SFTest199);
tcase_add_test(sprintftest, SFTest200);
tcase_add_test(sprintftest, SFTest201);
tcase_add_test(sprintftest, SFTest202);
tcase_add_test(sprintftest, SFTest203);
tcase_add_test(sprintftest, SFTest204);
tcase_add_test(sprintftest, SFTest205);
tcase_add_test(sprintftest, SFTest206);
tcase_add_test(sprintftest, SFTest207);
tcase_add_test(sprintftest, SFTest208);
tcase_add_test(sprintftest, SFTest209);
tcase_add_test(sprintftest, SFTest210);
tcase_add_test(sprintftest, SFTest211);
tcase_add_test(sprintftest, SFTest212);
tcase_add_test(sprintftest, SFTest213);
tcase_add_test(sprintftest, SFTest214);
tcase_add_test(sprintftest, SFTest215);
tcase_add_test(sprintftest, SFTest216);
tcase_add_test(sprintftest, SFTest217);
tcase_add_test(sprintftest, SFTest218);
tcase_add_test(sprintftest, SFTest219);
tcase_add_test(sprintftest, SFTest220);
tcase_add_test(sprintftest, SFTest221);
tcase_add_test(sprintftest, SFTest222);
tcase_add_test(sprintftest, SFTest223);
tcase_add_test(sprintftest, SFTest224);
tcase_add_test(sprintftest, SFTest225);
tcase_add_test(sprintftest, SFTest226);
tcase_add_test(sprintftest, SFTest227);
tcase_add_test(sprintftest, SFTest228);
tcase_add_test(sprintftest, SFTest229);
tcase_add_test(sprintftest, SFTest230);
tcase_add_test(sprintftest, SFTest231);
tcase_add_test(sprintftest, SFTest232);
tcase_add_test(sprintftest, SFTest233);
tcase_add_test(sprintftest, SFTest234);
tcase_add_test(sprintftest, SFTest235);
tcase_add_test(sprintftest, SFTest236);
tcase_add_test(sprintftest, SFTest237);
tcase_add_test(sprintftest, SFTest238);
tcase_add_test(sprintftest, SFTest239);
tcase_add_test(sprintftest, SFTest240);
tcase_add_test(sprintftest, SFTest241);
tcase_add_test(sprintftest, SFTest242);
tcase_add_test(sprintftest, SFTest243);
tcase_add_test(sprintftest, SFTest244);
tcase_add_test(sprintftest, SFTest245);
tcase_add_test(sprintftest, SFTest246);
tcase_add_test(sprintftest, SFTest247);
tcase_add_test(sprintftest, SFTest248);
tcase_add_test(sprintftest, SFTest249);
tcase_add_test(sprintftest, SFTest250);
tcase_add_test(sprintftest, SFTest251);
tcase_add_test(sprintftest, SFTest252);
tcase_add_test(sprintftest, SFTest253);
tcase_add_test(sprintftest, SFTest254);
tcase_add_test(sprintftest, SFTest255);
tcase_add_test(sprintftest, SFTest256);
tcase_add_test(sprintftest, SFTest257);
tcase_add_test(sprintftest, SFTest258);
tcase_add_test(sprintftest, SFTest259);
tcase_add_test(sprintftest, SFTest260);
tcase_add_test(sprintftest, SFTest261);
tcase_add_test(sprintftest, SFTest262);
tcase_add_test(sprintftest, SFTest263);
tcase_add_test(sprintftest, SFTest264);
tcase_add_test(sprintftest, SFTest265);
tcase_add_test(sprintftest, SFTest266);
tcase_add_test(sprintftest, SFTest267);
tcase_add_test(sprintftest, SFTest268);
tcase_add_test(sprintftest, SFTest269);
tcase_add_test(sprintftest, SFTest270);
tcase_add_test(sprintftest, SFTest271);
tcase_add_test(sprintftest, SFTest272);
tcase_add_test(sprintftest, SFTest273);
tcase_add_test(sprintftest, SFTest274);
tcase_add_test(sprintftest, SFTest275);
tcase_add_test(sprintftest, SFTest276);
tcase_add_test(sprintftest, SFTest277);
tcase_add_test(sprintftest, SFTest278);
tcase_add_test(sprintftest, SFTest279);
tcase_add_test(sprintftest, SFTest280);
tcase_add_test(sprintftest, SFTest281);
tcase_add_test(sprintftest, SFTest282);
tcase_add_test(sprintftest, SFTest283);
tcase_add_test(sprintftest, SFTest284);
tcase_add_test(sprintftest, SFTest285);
tcase_add_test(sprintftest, SFTest286);
    return s1;
}

Suite *example_suite_create2() {
    Suite *s1 = suite_create("Test_sprintf_part2");
    TCase *sprintftest1 = tcase_create("SPRINTF1");
    TCase *sprintftest3 = tcase_create("SPRINTF3");
    suite_add_tcase(s1, sprintftest1);
     tcase_add_test(sprintftest1, SFTest287);
  tcase_add_test(sprintftest1, SFTest288);
  tcase_add_test(sprintftest1, SFTest289);
  tcase_add_test(sprintftest1, SFTest290);
  tcase_add_test(sprintftest1, SFTest291);
  tcase_add_test(sprintftest1, SFTest292);
  tcase_add_test(sprintftest1, SFTest293);
  tcase_add_test(sprintftest1, SFTest294);
  tcase_add_test(sprintftest1, SFTest295);
  tcase_add_test(sprintftest1, SFTest296);
  tcase_add_test(sprintftest1, SFTest297);
  tcase_add_test(sprintftest1, SFTest298);
  tcase_add_test(sprintftest1, SFTest299);
  tcase_add_test(sprintftest1, SFTest300);
  tcase_add_test(sprintftest1, SFTest301);
  tcase_add_test(sprintftest1, SFTest302);
  tcase_add_test(sprintftest1, SFTest303);
  tcase_add_test(sprintftest1, SFTest304);
  tcase_add_test(sprintftest1, SFTest305);
  tcase_add_test(sprintftest1, SFTest306);
  tcase_add_test(sprintftest1, SFTest307);
  tcase_add_test(sprintftest1, SFTest308);
  tcase_add_test(sprintftest1, SFTest309);
  tcase_add_test(sprintftest1, SFTest310);
  tcase_add_test(sprintftest1, SFTest311);
  tcase_add_test(sprintftest1, SFTest312);
  tcase_add_test(sprintftest1, SFTest313);
  tcase_add_test(sprintftest1, SFTest314);
  tcase_add_test(sprintftest1, SFTest315);
  tcase_add_test(sprintftest1, SFTest316);
  tcase_add_test(sprintftest1, SFTest317);
  tcase_add_test(sprintftest1, SFTest318);
  tcase_add_test(sprintftest1, SFTest319);
  tcase_add_test(sprintftest1, SFTest320);
  tcase_add_test(sprintftest1, SFTest321);
  tcase_add_test(sprintftest1, SFTest322);
  tcase_add_test(sprintftest1, SFTest323);
  tcase_add_test(sprintftest1, SFTest324);
  tcase_add_test(sprintftest1, SFTest325);
  tcase_add_test(sprintftest1, SFTest326);
  tcase_add_test(sprintftest1, SFTest327);
  tcase_add_test(sprintftest1, SFTest328);
  tcase_add_test(sprintftest1, SFTest329);
  tcase_add_test(sprintftest1, SFTest330);
  tcase_add_test(sprintftest1, SFTest331);
  tcase_add_test(sprintftest1, SFTest332);
  tcase_add_test(sprintftest1, SFTest333);
  tcase_add_test(sprintftest1, SFTest334);
  tcase_add_test(sprintftest1, SFTest335);
  tcase_add_test(sprintftest1, SFTest336);
  tcase_add_test(sprintftest1, SFTest337);
  tcase_add_test(sprintftest1, SFTest338);
  tcase_add_test(sprintftest1, SFTest339);
  tcase_add_test(sprintftest1, SFTest340);
  tcase_add_test(sprintftest1, SFTest341);
  tcase_add_test(sprintftest1, SFTest342);
  tcase_add_test(sprintftest1, SFTest343);
  tcase_add_test(sprintftest1, SFTest344);
  tcase_add_test(sprintftest1, SFTest345);
  tcase_add_test(sprintftest1, SFTest346);
  tcase_add_test(sprintftest1, SFTest347);
  tcase_add_test(sprintftest1, SFTest348);
  tcase_add_test(sprintftest1, SFTest349);
  tcase_add_test(sprintftest1, SFTest350);
  tcase_add_test(sprintftest1, SFTest351);
  tcase_add_test(sprintftest1, SFTest352);
  tcase_add_test(sprintftest1, SFTest353);
  tcase_add_test(sprintftest1, SFTest354);
  tcase_add_test(sprintftest1, SFTest355);
  tcase_add_test(sprintftest1, SFTest356);
  tcase_add_test(sprintftest1, SFTest357);
  tcase_add_test(sprintftest1, SFTest358);
  tcase_add_test(sprintftest1, SFTest359);
  tcase_add_test(sprintftest1, SFTest360);
  tcase_add_test(sprintftest1, SFTest361);
  tcase_add_test(sprintftest1, SFTest362);
  tcase_add_test(sprintftest1, SFTest363);
  tcase_add_test(sprintftest1, SFTest364);
  tcase_add_test(sprintftest1, SFTest365);
  tcase_add_test(sprintftest1, SFTest366);
  tcase_add_test(sprintftest1, SFTest367);
  tcase_add_test(sprintftest1, SFTest368);
  tcase_add_test(sprintftest1, SFTest369);
  tcase_add_test(sprintftest1, SFTest370);
  tcase_add_test(sprintftest1, SFTest371);
  tcase_add_test(sprintftest1, SFTest372);
  tcase_add_test(sprintftest1, SFTest373);
  tcase_add_test(sprintftest1, SFTest374);
  tcase_add_test(sprintftest1, SFTest375);
  tcase_add_test(sprintftest1, SFTest376);
  tcase_add_test(sprintftest1, SFTest377);
  tcase_add_test(sprintftest1, SFTest378);
  tcase_add_test(sprintftest1, SFTest379);
  tcase_add_test(sprintftest1, SFTest380);
  tcase_add_test(sprintftest1, SFTest381);
  tcase_add_test(sprintftest1, SFTest382);
  tcase_add_test(sprintftest1, SFTest383);
  tcase_add_test(sprintftest1, SFTest384);
  tcase_add_test(sprintftest1, SFTest385);
  tcase_add_test(sprintftest1, SFTest386);
  tcase_add_test(sprintftest1, SFTest387);
  tcase_add_test(sprintftest1, SFTest388);
  tcase_add_test(sprintftest1, SFTest389);
  tcase_add_test(sprintftest1, SFTest390);
  tcase_add_test(sprintftest1, SFTest391);
  tcase_add_test(sprintftest1, SFTest392);
  tcase_add_test(sprintftest1, SFTest393);
  tcase_add_test(sprintftest1, SFTest394);
  tcase_add_test(sprintftest1, SFTest395);
  tcase_add_test(sprintftest1, SFTest396);
  tcase_add_test(sprintftest1, SFTest397);
  tcase_add_test(sprintftest1, SFTest398);
  tcase_add_test(sprintftest1, SFTest399);
  tcase_add_test(sprintftest1, SFTest400);
  tcase_add_test(sprintftest1, SFTest401);
  tcase_add_test(sprintftest1, SFTest402);
  tcase_add_test(sprintftest1, SFTest403);
  tcase_add_test(sprintftest1, SFTest404);
  tcase_add_test(sprintftest1, SFTest405);
  tcase_add_test(sprintftest1, SFTest406);
  tcase_add_test(sprintftest1, SFTest407);
  tcase_add_test(sprintftest1, SFTest408);
  tcase_add_test(sprintftest1, SFTest409);
  tcase_add_test(sprintftest1, SFTest410);
  tcase_add_test(sprintftest1, SFTest411);
  tcase_add_test(sprintftest1, SFTest412);
  tcase_add_test(sprintftest1, SFTest413);
  tcase_add_test(sprintftest1, SFTest414);
  tcase_add_test(sprintftest1, SFTest415);
  tcase_add_test(sprintftest1, SFTest416);
  tcase_add_test(sprintftest1, SFTest417);
  tcase_add_test(sprintftest1, SFTest418);
  tcase_add_test(sprintftest1, SFTest419);
  tcase_add_test(sprintftest1, SFTest420);
  tcase_add_test(sprintftest1, SFTest421);
  tcase_add_test(sprintftest1, SFTest422);
  tcase_add_test(sprintftest1, SFTest423);
  tcase_add_test(sprintftest1, SFTest424);
  tcase_add_test(sprintftest1, SFTest425);
  tcase_add_test(sprintftest1, SFTest426);
  tcase_add_test(sprintftest1, SFTest427);
  tcase_add_test(sprintftest1, SFTest428);
  tcase_add_test(sprintftest1, SFTest429);
  tcase_add_test(sprintftest1, SFTest430);
  tcase_add_test(sprintftest1, SFTest431);
  tcase_add_test(sprintftest1, SFTest432);
  tcase_add_test(sprintftest1, SFTest433);
  tcase_add_test(sprintftest1, SFTest434);
  tcase_add_test(sprintftest1, SFTest435);
  tcase_add_test(sprintftest1, SFTest436);
  tcase_add_test(sprintftest1, SFTest437);
  tcase_add_test(sprintftest1, SFTest438);
  tcase_add_test(sprintftest1, SFTest439);
  tcase_add_test(sprintftest1, SFTest440);
  tcase_add_test(sprintftest1, SFTest441);
  tcase_add_test(sprintftest1, SFTest442);
  tcase_add_test(sprintftest1, SFTest443);
  tcase_add_test(sprintftest1, SFTest444);
  tcase_add_test(sprintftest1, SFTest445);
  tcase_add_test(sprintftest1, SFTest446);
  tcase_add_test(sprintftest1, SFTest447);
  tcase_add_test(sprintftest1, SFTest448);
  tcase_add_test(sprintftest1, SFTest449);
  tcase_add_test(sprintftest1, SFTest450);
  tcase_add_test(sprintftest1, SFTest451);
  tcase_add_test(sprintftest1, SFTest452);
  tcase_add_test(sprintftest1, SFTest453);
  tcase_add_test(sprintftest1, SFTest454);
  tcase_add_test(sprintftest1, SFTest455);
  tcase_add_test(sprintftest1, SFTest456);
  tcase_add_test(sprintftest1, SFTest457);
  tcase_add_test(sprintftest1, SFTest458);
  tcase_add_test(sprintftest1, SFTest459);
  tcase_add_test(sprintftest1, SFTest460);
  tcase_add_test(sprintftest1, SFTest461);
  tcase_add_test(sprintftest1, SFTest462);
  tcase_add_test(sprintftest1, SFTest463);
  tcase_add_test(sprintftest1, SFTest464);
  tcase_add_test(sprintftest1, SFTest465);
  tcase_add_test(sprintftest1, SFTest466);
  tcase_add_test(sprintftest1, SFTest467);
  tcase_add_test(sprintftest1, SFTest468);
  tcase_add_test(sprintftest1, SFTest469);
  tcase_add_test(sprintftest1, SFTest470);
  tcase_add_test(sprintftest1, SFTest471);
  tcase_add_test(sprintftest1, SFTest472);
  tcase_add_test(sprintftest1, SFTest473);
  tcase_add_test(sprintftest1, SFTest474);
  tcase_add_test(sprintftest1, SFTest475);
  tcase_add_test(sprintftest1, SFTest476);
  tcase_add_test(sprintftest1, SFTest477);
  tcase_add_test(sprintftest1, SFTest478);
  tcase_add_test(sprintftest1, SFTest479);
  tcase_add_test(sprintftest1, SFTest480);
  tcase_add_test(sprintftest1, SFTest481);
  tcase_add_test(sprintftest1, SFTest482);
  tcase_add_test(sprintftest1, SFTest483);
  tcase_add_test(sprintftest1, SFTest484);
  tcase_add_test(sprintftest1, SFTest485);
  tcase_add_test(sprintftest1, SFTest486);
  tcase_add_test(sprintftest1, SFTest487);
  tcase_add_test(sprintftest1, SFTest488);
  tcase_add_test(sprintftest1, SFTest489);
  tcase_add_test(sprintftest1, SFTest490);
  tcase_add_test(sprintftest1, SFTest491);
  tcase_add_test(sprintftest1, SFTest492);
  tcase_add_test(sprintftest1, SFTest493);
  tcase_add_test(sprintftest1, SFTest494);
  tcase_add_test(sprintftest1, SFTest495);
  tcase_add_test(sprintftest1, SFTest496);
  tcase_add_test(sprintftest1, SFTest497);
  tcase_add_test(sprintftest1, SFTest498);
  tcase_add_test(sprintftest1, SFTest499);
  tcase_add_test(sprintftest1, SFTest500);
  tcase_add_test(sprintftest1, SFTest501);
  tcase_add_test(sprintftest1, SFTest502);
  tcase_add_test(sprintftest1, SFTest503);
  tcase_add_test(sprintftest1, SFTest504);
  tcase_add_test(sprintftest1, SFTest505);
  tcase_add_test(sprintftest1, SFTest506);
  tcase_add_test(sprintftest1, SFTest507);
  tcase_add_test(sprintftest1, SFTest508);
  tcase_add_test(sprintftest1, SFTest509);
  tcase_add_test(sprintftest1, SFTest510);
  tcase_add_test(sprintftest1, SFTest511);
  tcase_add_test(sprintftest1, SFTest512);
  tcase_add_test(sprintftest1, SFTest513);
  tcase_add_test(sprintftest1, SFTest514);
  tcase_add_test(sprintftest1, SFTest515);
  tcase_add_test(sprintftest1, SFTest516);
  tcase_add_test(sprintftest1, SFTest517);
    suite_add_tcase(s1, sprintftest3);
    tcase_add_test(sprintftest3, SFTest518);
    tcase_add_test(sprintftest3, SFTest519);
    tcase_add_test(sprintftest3, SFTest520);
    tcase_add_test(sprintftest3, SFTest521);
    tcase_add_test(sprintftest3, SFTest522);
    tcase_add_test(sprintftest3, SFTest523);
    tcase_add_test(sprintftest3, SFTest524);
    tcase_add_test(sprintftest3, SFTest525);
    tcase_add_test(sprintftest3, SFTest526);
    tcase_add_test(sprintftest3, SFTest527);
    tcase_add_test(sprintftest3, SFTest528);
    tcase_add_test(sprintftest3, SFTest529);
    tcase_add_test(sprintftest3, SFTest530);
    tcase_add_test(sprintftest3, SFTest531);
    tcase_add_test(sprintftest3, SFTest532);
    tcase_add_test(sprintftest3, SFTest533);
    tcase_add_test(sprintftest3, SFTest534);
    tcase_add_test(sprintftest3, SFTest535);
    return s1;
}
