
#include <check.h>
#include <string.h>
#include <stdio.h>
#include "s21_string.h"

START_TEST(SScanTest1) {
    int num1;
    int num2;
    s21_sscanf("123", "%d", &num1);
    sscanf("123", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest2) {
    int num1;
    int num2;
    s21_sscanf("123", "%10d", &num1);
    sscanf("123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest3) {
    int num1;
    int num2;
    s21_sscanf("-123", "%10d", &num1);
    sscanf("-123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest4) {
    int num1;
    int num2;
    s21_sscanf("-123", "%10d", &num1);
    sscanf("-123", "%10d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest5) {
    int num1;
    int num2;
    s21_sscanf("-123", "%d", &num1);
    sscanf("-123", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest6) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("-123", "%1d", &num1);
    sscanf("-123", "%1d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest7) {
    int num1;
    int num2;
    s21_sscanf("123", "%1d", &num1);
    sscanf("123", "%1d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest8) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("||||||123|||---dqwdsc23;;;alq.vmfj", "%d", &num1);
    sscanf("||||||123|||---dqwdsc23;;;alq.vmfj", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST


START_TEST(SScanTest9) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("qwe|||---dqwdsc23;;;alq.vmfj", "%d", &num1);
    sscanf("qwe|||---dqwdsc23;;;alq.vmfj", "%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest10) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("        'ds;fsdlsdfks;df", "%4d", &num1);
    sscanf("        'ds;fsdlsdfks;df", "%4d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest11) {
    int num1;
    int num2;
    char a, b;
    s21_sscanf("123 qwe", "%4d%c", &num1, &a);
    sscanf("123 qwe", "%4d%c", &num2, &b);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest12) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("123 123", "%*d%d", &num1);
    sscanf("123 123", "%*d%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest13) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("as q12", "%*d%d", &num1);
    sscanf("fd qwe", "%*d%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest14) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("as q12", "%*i%i", &num1);
    sscanf("fd qwe", "%*i%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest15) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123214214 q12", "%*i%i", &num1);
    sscanf("123214214 qwe", "%*i%i", &num2);
    ck_assert_int_eq(num1, num2);
}

END_TEST

START_TEST(SScanTest16) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123214214", "%i", &num1);
    sscanf("123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest17) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-123214214", "%i", &num1);
    sscanf("-123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest18) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("-123214214", "%i", &num1);
    sscanf("-123214214", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest19) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("qwdwq wef 123", "%i", &num1);
    sscanf("qwdwq wef 123", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest20) {
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest21) {
    int num1 = 0;
    int num2 = 0;
    int c = s21_sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    int b =  sscanf("13rcsaфыcak jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(c, b);
}
END_TEST

START_TEST(SScanTest22) {
    int num1 = 0;
    int num2 = 0;
    int c = s21_sscanf("  -0124214124 jio1    d  1k=----1-230412-,csdc1", "%i", &num1);
    int b =  sscanf("  -0124214124 jio1    d  1k=----1-230412-,csdc1", "%i", &num2);
    ck_assert_int_eq(c, b);
}
END_TEST

START_TEST(SScanTest23) {
    char a;
    char b;
    s21_sscanf("qwd", "%c", &a);
    sscanf("qwd", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest24) {
    char a;
    char b;
    s21_sscanf("qwd", "%c", &a);
    sscanf("qwd", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest25) {
    char a;
    char b;
    s21_sscanf("f", "%c", &a);
    sscanf("f", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest26) {
    char a;
    char b;
    s21_sscanf(" ", "%c", &a);
    sscanf(" ", "%c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest27) {
    char a;
    char b;
    s21_sscanf("123", "%1c", &a);
    sscanf("123", "%1c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest28) {
    char a;
    char b;
    s21_sscanf(" 1", "%1c", &a);
    sscanf(" 1", "%1c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest29) {
    char a[1024] = "HEllo";
    char b[1024] = "HEllo";
    s21_sscanf("HEllo", "%s", a);
    sscanf("HEllo", "%s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest30) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf("HEllo", "%2s", a);
    sscanf("HEllo", "%2s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest31) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf("123 123", "%2s", a);
    sscanf("123 123", "%2s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest32) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest33) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest34) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest35) {
    char a[1024] = "123";
    char b[1024] = "123";
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10s", b);
    ck_assert_str_eq(a, b);
}
END_TEST

START_TEST(SScanTest36) {
    float a = 0;
    float b = 0;
    s21_sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10f", &a);
    sscanf(";[1;23---30124[''''';.,,m123\\''0__-----12'ł", "%10f", &b);
    ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(SScanTest37) {
    float a = 0;
    float b = 0;
    s21_sscanf("12.213213123", "%1f", &a);
    sscanf("12.213213123", "%1f", &b);
    ck_assert_uint_eq(a, b);
}
END_TEST

START_TEST(SScanTest38) {
    float a = 0;
    float b = 0;
    s21_sscanf("-12.213213123", "%1f", &a);
    sscanf("-12.213213123", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest39) {
    float a = 0;
    float b = 0;
    s21_sscanf("-12.2132131231qwd", "%1f", &a);
    sscanf("-12.2132131231qwd", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest40) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.00000000000001", "%1f", &a);
    sscanf("0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest41) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.00000000000001", "%1f", &a);
    sscanf("0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest42) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000000001", "%1f", &a);
    sscanf("-0.00000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest43) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%1f", &a);
    sscanf("-0.0000000000000000001", "%1f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest44) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%10f", &a);
    sscanf("-0.0000000000000000001", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest45) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000000001", "%10f", &a);
    sscanf("-0.0000000000000000001", "%10f", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest46) {
    float a = 0;
    float b = 0;
    s21_sscanf("1123.2332", "%10e", &a);
    sscanf("1123.2332", "%10e", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest47) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%10e", &a);
    sscanf("-1123.2332", "%10e", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest48) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%E", &a);
    sscanf("-1123.2332", "%E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest49) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000000001", "%15E", &a);
    sscanf("0.0000000000000001", "%15E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest50) {
    float a = 0;
    float b = 0;
    s21_sscanf("1E42", "%E", &a);
    sscanf("1E42", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest51) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%E", &a);
    sscanf("1e42", "%E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest52) {
    float a = 0;
    float b = 0;
    s21_sscanf("1123.2332", "%10E", &a);
    sscanf("1123.2332", "%10E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest53) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%10E", &a);
    sscanf("-1123.2332", "%10E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest54) {
    float a = 0;
    float b = 0;
    s21_sscanf("-1123.2332", "%E", &a);
    sscanf("-1123.2332", "%E", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest55) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000000001", "%15E", &a);
    sscanf("0.0000000000000001", "%15E", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest56) {
    float a = 0;
    float b = 0;
    s21_sscanf("1E42", "%e", &a);
    sscanf("1E42", "%e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest57) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%e", &a);
    sscanf("1e42", "%e", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest58) {
    float a = 0;
    float b = 0;
    s21_sscanf("1e42", "%g", &a);
    sscanf("1e42", "%g", &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(SScanTest59) {
    float a = 0;
    float b = 0;
    s21_sscanf("_+)-=p//./.?>./[p=.['1e42", "%g", &a);
    sscanf("_+)-=p//./.?>./[p=.['1e42", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest60) {
    float a = 0;
    float b = 0;
    s21_sscanf("3.141592653589793238462643383279502 _+)-=p//./.?>./[p=.['1e42", "%g", &a);
    sscanf("3.141592653589793238462643383279502 _+)-=p//./.?>./[p=.['1e42", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest61) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000001", "%g", &a);
    sscanf("0.0000000000001", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest62) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%g", &a);
    sscanf("-0.0000000000000001", "%g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest63) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%15g", &a);
    sscanf("-0.0000000000000001", "%15g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest64) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%1g", &a);
    sscanf("-0.0000000000000001", "%1g", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest65) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000001", "%G", &a);
    sscanf("-0.00000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest66) {
    float a = 0;
    float b = 0;
    s21_sscanf("0.0000000000001", "%G", &a);
    sscanf("0.0000000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest67) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%G", &a);
    sscanf("-0.0000000000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest68) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%15G", &a);
    sscanf("-0.0000000000000001", "%15G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest69) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.0000000000000001", "%1G", &a);
    sscanf("-0.0000000000000001", "%1G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest70) {
    float a = 0;
    float b = 0;
    s21_sscanf("-0.00000000001", "%G", &a);
    sscanf("-0.00000000001", "%G", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest71) {
    int a = 0;
    int b = 0;
    s21_sscanf("124", "%o", &a);
    sscanf("124", "%o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest72) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%o", &a);
    sscanf("-124", "%o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest73) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%10o", &a);
    sscanf("-124", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest74) {
    int a = 0;
    int b = 0;
    s21_sscanf("-124", "%10o", &a);
    sscanf("-124", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest75) {
    int a = 0;
    int b = 0;
    s21_sscanf("1", "%10o", &a);
    sscanf("1", "%10o", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest76) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf("1", "%u", &a);
    sscanf("1", "%u", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest77) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf(" +123", "%u", &a);
    sscanf(" +123", "%u", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest78) {
    unsigned int a = 0;
    unsigned int b = 0;
    s21_sscanf("123", "%n", &a);
    sscanf("123", "%n", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest79) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123", "%x", &num1);
    sscanf("123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest80) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%3x", &num1);
    sscanf("123123", "%3x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest81) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%10x", &num1);
    sscanf("123123", "%10x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest82) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*x%x", &num1);
    sscanf("123 123", "%*x%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest83) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*x%d", &num1);
    sscanf("123 123", "%*x%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest84) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0x123 123", "%x", &num1);
    sscanf("0x123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest85) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0123 123", "%x", &num1);
    sscanf("0123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest86) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0X123 123", "%x", &num1);
    sscanf("0X123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest87) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-0X123 123", "%x", &num1);
    sscanf("-0X123 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest88) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("qwe 123", "%x", &num1);
    sscanf("qwe 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest89) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCDEF 123", "%x", &num1);
    sscanf("ABCDEF 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest90) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCQADEF 123", "%x", &num1);
    sscanf("ABCQADEF 123", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest91) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("ABCDEF -A123", "%x%x", &num1, &num3);
    sscanf("ABCDEF -A123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest92) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("228228228 -A123", "%x%x", &num1, &num3);
    sscanf("228228228 -A123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest93) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+000123ABC -0123", "%x%x", &num1, &num3);
    sscanf("+000123ABC -0123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest94) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+0001§../23ABC -0mxzcmmz123q", "%x%x", &num1, &num3);
    sscanf("+0001§../23ABC -0mxzcmmz123q", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest95) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+123", "%x%x", &num1, &num3);
    sscanf("+123", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest96) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("  000  000   ", "%x%x", &num1, &num3);
    sscanf("  000  000   ", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest97) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("120x211 0x", "%x%x", &num1, &num3);
    sscanf("120x211 0x", "%x%x", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest98) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("120x211 0x", "%x%s", &num1, s1);
    sscanf("120x211 0x", "%x%s", &num2, s2);
    ck_assert_int_eq(num1, num2);
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SScanTest99) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("x120x211 0x", "%x", &num1);
    sscanf("x120x211 0x", "%x", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest100) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x211. 29", "%x%f", &num1, &f1);
    sscanf("x120x211. 29", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest101) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x21.1 2.9", "%x%f", &num1, &f1);
    sscanf("x120x21.1 2.9", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest102) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x-120x.21 12.9", "%x%f", &num1, &f1);
    sscanf("x-120x.21 12.9", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest103) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("2.9 020abxC21.1", "%x%f", &num1, &f1);
    sscanf("2.9 020abxC21.1", "%x%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest104) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123", "%X", &num1);
    sscanf("123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest105) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%3X", &num1);
    sscanf("123123", "%3X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest106) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123123", "%10X", &num1);
    sscanf("123123", "%10X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest107) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*X%X", &num1);
    sscanf("123 123", "%*X%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest108) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("123 123", "%*X%d", &num1);
    sscanf("123 123", "%*X%d", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest109) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0x123 123", "%X", &num1);
    sscanf("0x123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest110) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0123 123", "%X", &num1);
    sscanf("0123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest111) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("0X123 123", "%X", &num1);
    sscanf("0X123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest112) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("-0X123 123", "%X", &num1);
    sscanf("-0X123 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest113) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("qwe 123", "%X", &num1);
    sscanf("qwe 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest114) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCDEF 123", "%X", &num1);
    sscanf("ABCDEF 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest115) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("ABCQADEF 123", "%X", &num1);
    sscanf("ABCQADEF 123", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest116) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("ABCDEF -A123", "%X%X", &num1, &num3);
    sscanf("ABCDEF -A123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest117) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("228228228 -A123", "%X%X", &num1, &num3);
    sscanf("228228228 -A123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest118) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+000123ABC -0123", "%X%X", &num1, &num3);
    sscanf("+000123ABC -0123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest119) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+0001§../23ABC -0mxzcmmz123q", "%X%X", &num1, &num3);
    sscanf("+0001§../23ABC -0mxzcmmz123q", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest120) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("+123", "%X%X", &num1, &num3);
    sscanf("+123", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest121) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("  000  000   ", "%X%X", &num1, &num3);
    sscanf("  000  000   ", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest122) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num3 = 0;
    unsigned int num4 = 0;
    s21_sscanf("120x211 0x", "%X%X", &num1, &num3);
    sscanf("120x211 0x", "%X%X", &num2, &num4);
    ck_assert_int_eq(num1, num2);
    ck_assert_int_eq(num3, num4);
}
END_TEST

START_TEST(SScanTest123) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("120x211 0x", "%X%s", &num1, s1);
    sscanf("120x211 0x", "%X%s", &num2, s2);
    ck_assert_int_eq(num1, num2);
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SScanTest124) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    s21_sscanf("x120x211 0x", "%X", &num1);
    sscanf("x120x211 0x", "%X", &num2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest125) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x211. 29", "%X%f", &num1, &f1);
    sscanf("x120x211. 29", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest126) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x120x21.1 2.9", "%X%f", &num1, &f1);
    sscanf("x120x21.1 2.9", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest127) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("x-120x.21 12.9", "%X%f", &num1, &f1);
    sscanf("x-120x.21 12.9", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest128) {
    unsigned int num1 = 0;
    unsigned int num2 = 0;
    float f1 = 0;
    float f2 = 0;
    s21_sscanf("2.9 020abxC21.1", "%X%f", &num1, &f1);
    sscanf("2.9 020abxC21.1", "%X%f", &num2, &f2);
    ck_assert_int_eq(num1, num2);
    ck_assert_float_eq(f1, f2);
}
END_TEST

START_TEST(SScanTest129) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("123", "%p", &p1);
    sscanf("123", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest130) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%p", &p1);
    sscanf("abc12g3", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest131) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%3p", &p1);
    sscanf("abc12g3", "%3p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest132) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3 abc22", "%*p%p", &p1);
    sscanf("abc12g3 abc22", "%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest133) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf(" abc12g3 abc22", " %*p%p", &p1);
    sscanf(" abc12g3 abc22", " %*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest134) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf(" abc12g3 abc22", "-%*p%p", &p1);
    sscanf(" abc12g3 abc22", "-%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest135) {
    char a, b;
    s21_sscanf("e", "%10c", &a);
    sscanf("e", "%10c", &b);
    ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(SScanTest136) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("+123", "%p", &a);
    sscanf("+123", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SScanTest137) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("0x0X", "%p", &a);
    sscanf("0x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SScanTest138) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("x0X", "%p", &a);
    sscanf("x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST
START_TEST(SScanTest139) {
    void *a = 0;
    void *b = 0;
    s21_sscanf("-x0X", "%p", &a);
    sscanf("-x0X", "%p", &b);
    ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(SScanTest140) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("123", "%p", &p1);
    sscanf("123", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest141) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%p", &p1);
    sscanf("abc12g3", "%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest142) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3", "%3p", &p1);
    sscanf("abc12g3", "%3p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest143) {
    void *p1 = 0;
    void *p2 = 0;
    s21_sscanf("abc12g3 abc22", "%*p%p", &p1);
    sscanf("abc12g3 abc22", "%*p%p", &p2);
    ck_assert_msg(p1 == p2, "sadasd");
}
END_TEST

START_TEST(SScanTest144) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("abc12g3 abc22", "%p%s", &p1, s1);
    sscanf("abc12g3 abc22", "%p%s", &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SScanTest145) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("abc12g3 abc22", "%s%p", s1, &p1);
    sscanf("abc12g3 abc22", "%s%p", s2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SScanTest146) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    s21_sscanf("  abc12g3    abc22  ", "%s%p", s1, &p1);
    sscanf("  abc12g3    abc22  ", "%s%p", s2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
}
END_TEST

START_TEST(SScanTest147) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("abc12g3 0000 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 0000 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest148) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("abc12g3 0x123cc 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 0x123cc 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest149) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("abc12g3 030xcc 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 030xcc 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest150) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("abc12g3 123ab±=-1//a 12", "%s%p%d", s1, &p1, &num1);
    sscanf("abc12g3 123ab±=-1//a 12", "%s%p%d", s2, &p2, &num2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest151) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("abc12g3 123ab±=-1//a 12", "%d%p", &num1, &p1);
    sscanf("abc12g3 123ab±=-1//a 12", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest152) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("abc1 2g3 12 3ab±=-1// a 12", "%d%p", &num1, &p1);
    sscanf("abc1 2g3 12 3ab±=-1// a 12", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest153) {
    void *p1 = 0;
    void *p2 = 0;
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("", "%d%p", &num1, &p1);
    sscanf("", "%d%p", &num2, &p2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest154) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("10 abcdef123 qwe", "%d%4p%s", &num1, &p1, s1);
    sscanf("10 abcdef123 qwe", "%d%4p%s", &num2, &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(SScanTest155) {
    void *p1 = 0;
    void *p2 = 0;
    char s1[1024];
    char s2[1024];
    int num1 = 0;
    int num2 = 0;
    s21_sscanf("10 abcdef123 qwe", "%d%1p%s", &num1, &p1, s1);
    sscanf("10 abcdef123 qwe", "%d%1p%s", &num2, &p2, s2);
    ck_assert_msg(p1 == p2, "sadasd");
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(num1, num2);
}
END_TEST

Suite *sscanf_suite_create() {
    Suite *s1 = suite_create("Test_sscanf");
    TCase *sscanftest = tcase_create("SSCANF1");
    TCase *sscanftest2 = tcase_create("SSCANF2");
    suite_add_tcase(s1, sscanftest);
    suite_add_tcase(s1, sscanftest2);
  tcase_add_test(sscanftest, SScanTest1);
  tcase_add_test(sscanftest, SScanTest2);
  tcase_add_test(sscanftest, SScanTest3);
  tcase_add_test(sscanftest, SScanTest4);
  tcase_add_test(sscanftest, SScanTest5);
  tcase_add_test(sscanftest, SScanTest6);
  tcase_add_test(sscanftest, SScanTest7);
  tcase_add_test(sscanftest, SScanTest8);
  tcase_add_test(sscanftest, SScanTest9);
  tcase_add_test(sscanftest, SScanTest10);
  tcase_add_test(sscanftest, SScanTest11);
  tcase_add_test(sscanftest, SScanTest12);
  tcase_add_test(sscanftest, SScanTest13);
  tcase_add_test(sscanftest, SScanTest14);
  tcase_add_test(sscanftest, SScanTest15);
  tcase_add_test(sscanftest, SScanTest16);
  tcase_add_test(sscanftest, SScanTest17);
  tcase_add_test(sscanftest, SScanTest18);
  tcase_add_test(sscanftest, SScanTest19);
  tcase_add_test(sscanftest, SScanTest20);
  tcase_add_test(sscanftest, SScanTest21);
  tcase_add_test(sscanftest, SScanTest22);
  tcase_add_test(sscanftest, SScanTest23);
  tcase_add_test(sscanftest, SScanTest24);
  tcase_add_test(sscanftest, SScanTest25);
  tcase_add_test(sscanftest, SScanTest26);
  tcase_add_test(sscanftest, SScanTest27);
  tcase_add_test(sscanftest, SScanTest28);
  tcase_add_test(sscanftest, SScanTest29);
  tcase_add_test(sscanftest, SScanTest30);
  tcase_add_test(sscanftest, SScanTest31);
  tcase_add_test(sscanftest, SScanTest32);
  tcase_add_test(sscanftest, SScanTest33);
  tcase_add_test(sscanftest, SScanTest34);
  tcase_add_test(sscanftest, SScanTest35);
  tcase_add_test(sscanftest, SScanTest36);
  tcase_add_test(sscanftest, SScanTest37);
  tcase_add_test(sscanftest, SScanTest38);
  tcase_add_test(sscanftest, SScanTest39);
  tcase_add_test(sscanftest, SScanTest40);
  tcase_add_test(sscanftest, SScanTest41);
  tcase_add_test(sscanftest, SScanTest42);
  tcase_add_test(sscanftest, SScanTest43);
  tcase_add_test(sscanftest, SScanTest44);
  tcase_add_test(sscanftest, SScanTest45);
  tcase_add_test(sscanftest, SScanTest46);
  tcase_add_test(sscanftest, SScanTest47);
  tcase_add_test(sscanftest, SScanTest48);
  tcase_add_test(sscanftest, SScanTest49);
  tcase_add_test(sscanftest, SScanTest50);
  tcase_add_test(sscanftest, SScanTest51);
  tcase_add_test(sscanftest, SScanTest52);
  tcase_add_test(sscanftest, SScanTest53);
  tcase_add_test(sscanftest, SScanTest54);
  tcase_add_test(sscanftest, SScanTest55);
  tcase_add_test(sscanftest, SScanTest56);
  tcase_add_test(sscanftest, SScanTest57);
  tcase_add_test(sscanftest, SScanTest58);
  tcase_add_test(sscanftest, SScanTest59);
  tcase_add_test(sscanftest, SScanTest60);
  tcase_add_test(sscanftest, SScanTest61);
  tcase_add_test(sscanftest, SScanTest62);
  tcase_add_test(sscanftest, SScanTest63);
  tcase_add_test(sscanftest, SScanTest64);
  tcase_add_test(sscanftest, SScanTest65);
  tcase_add_test(sscanftest, SScanTest66);
  tcase_add_test(sscanftest, SScanTest67);
  tcase_add_test(sscanftest, SScanTest68);
  tcase_add_test(sscanftest, SScanTest69);
  tcase_add_test(sscanftest, SScanTest70);
  tcase_add_test(sscanftest, SScanTest71);
  tcase_add_test(sscanftest, SScanTest72);
  tcase_add_test(sscanftest, SScanTest73);
  tcase_add_test(sscanftest, SScanTest74);
  tcase_add_test(sscanftest, SScanTest75);
  tcase_add_test(sscanftest, SScanTest76);
  tcase_add_test(sscanftest, SScanTest77);
  tcase_add_test(sscanftest, SScanTest78);
  tcase_add_test(sscanftest2, SScanTest79);
  tcase_add_test(sscanftest2, SScanTest80);
  tcase_add_test(sscanftest2, SScanTest81);
  tcase_add_test(sscanftest2, SScanTest82);
  tcase_add_test(sscanftest2, SScanTest83);
  tcase_add_test(sscanftest2, SScanTest84);
  tcase_add_test(sscanftest2, SScanTest85);
  tcase_add_test(sscanftest2, SScanTest86);
  tcase_add_test(sscanftest2, SScanTest87);
  tcase_add_test(sscanftest2, SScanTest88);
  tcase_add_test(sscanftest2, SScanTest89);
  tcase_add_test(sscanftest2, SScanTest90);
  tcase_add_test(sscanftest2, SScanTest91);
  tcase_add_test(sscanftest2, SScanTest92);
  tcase_add_test(sscanftest2, SScanTest93);
  tcase_add_test(sscanftest2, SScanTest94);
  tcase_add_test(sscanftest2, SScanTest95);
  tcase_add_test(sscanftest2, SScanTest96);
  tcase_add_test(sscanftest2, SScanTest97);
  tcase_add_test(sscanftest2, SScanTest98);
  tcase_add_test(sscanftest2, SScanTest99);
  tcase_add_test(sscanftest2, SScanTest100);
  tcase_add_test(sscanftest2, SScanTest101);
  tcase_add_test(sscanftest2, SScanTest102);
  tcase_add_test(sscanftest2, SScanTest103);
  tcase_add_test(sscanftest2, SScanTest104);
  tcase_add_test(sscanftest2, SScanTest105);
  tcase_add_test(sscanftest2, SScanTest106);
  tcase_add_test(sscanftest2, SScanTest107);
  tcase_add_test(sscanftest2, SScanTest108);
  tcase_add_test(sscanftest2, SScanTest109);
  tcase_add_test(sscanftest2, SScanTest110);
  tcase_add_test(sscanftest2, SScanTest111);
  tcase_add_test(sscanftest2, SScanTest112);
  tcase_add_test(sscanftest2, SScanTest113);
  tcase_add_test(sscanftest2, SScanTest114);
  tcase_add_test(sscanftest2, SScanTest115);
  tcase_add_test(sscanftest2, SScanTest116);
  tcase_add_test(sscanftest2, SScanTest117);
  tcase_add_test(sscanftest2, SScanTest118);
  tcase_add_test(sscanftest2, SScanTest119);
  tcase_add_test(sscanftest2, SScanTest120);
  tcase_add_test(sscanftest2, SScanTest121);
  tcase_add_test(sscanftest2, SScanTest122);
  tcase_add_test(sscanftest2, SScanTest123);
  tcase_add_test(sscanftest2, SScanTest124);
  tcase_add_test(sscanftest2, SScanTest125);
  tcase_add_test(sscanftest2, SScanTest126);
  tcase_add_test(sscanftest2, SScanTest127);
  tcase_add_test(sscanftest2, SScanTest128);
  tcase_add_test(sscanftest2, SScanTest129);
  tcase_add_test(sscanftest2, SScanTest130);
  tcase_add_test(sscanftest2, SScanTest131);
  tcase_add_test(sscanftest2, SScanTest132);
  tcase_add_test(sscanftest2, SScanTest133);
  tcase_add_test(sscanftest2, SScanTest134);
  tcase_add_test(sscanftest2, SScanTest135);
  tcase_add_test(sscanftest2, SScanTest136);
  tcase_add_test(sscanftest2, SScanTest137);
  tcase_add_test(sscanftest2, SScanTest138);
  tcase_add_test(sscanftest2, SScanTest139);
  tcase_add_test(sscanftest2, SScanTest140);
  tcase_add_test(sscanftest2, SScanTest141);
  tcase_add_test(sscanftest2, SScanTest142);
  tcase_add_test(sscanftest2, SScanTest143);
  tcase_add_test(sscanftest2, SScanTest144);
  tcase_add_test(sscanftest2, SScanTest145);
  tcase_add_test(sscanftest2, SScanTest146);
  tcase_add_test(sscanftest2, SScanTest147);
  tcase_add_test(sscanftest2, SScanTest148);
  tcase_add_test(sscanftest2, SScanTest149);
  tcase_add_test(sscanftest2, SScanTest150);
  tcase_add_test(sscanftest2, SScanTest151);
  tcase_add_test(sscanftest2, SScanTest152);
  tcase_add_test(sscanftest2, SScanTest153);
  tcase_add_test(sscanftest2, SScanTest154);
  tcase_add_test(sscanftest2, SScanTest155);
    return s1;
}
