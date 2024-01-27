#include"./s21_string.h"

unsigned long s21_strlen(char *str) {
    unsigned long i = 0;
    if(str != s21_NULL) {while (str[i++] != '\0');}
    else i = 1;
    return i-1;
}
/*void *memcpy(void *dest, const void *src, size_t n) {
  if (NULL == dest || NULL == src) {
  return NULL;
}
  void *ret = dest;
  if (dest <= src || (char *)dest >= (char *)src + n) {
  while (n--) {
  *(char *)dest = *(char *)src;
  dest = (char *)dest + 1;
  src = (char *)src + 1;
}
} else {
  src = (char *)src + n - 1;
  dest = (char *)dest + n - 1;
  while (n--) {
  *(char *)dest = *(char *)src;
  dest = (char *)dest - 1;
  src = (char *)src - 1;
}
}
  return ret;
}

void *memmove(void *dest, const void *src, size_t n) {
  char *p1 = dest;
  const char *p2 = src;
  if (p2 < p1 && p1 < p2 + n) {
  p2 += n;
  p1 += n;
  while (n-- != 0)
  *--p1 = *--p2;
  } else
  while (n-- != 0)
  *p1++ = *p2++;
  return dest;
}

void *memset(void *str, int c, size_t n) {
  char *p = (char*)str;
  for (size_t i = 0; i != n; ++i) {
  p[i] = c;
}
  return str;
}

size_t strspn(const char *str1, const char *str2) {
  size_t i, j;
  for (i = 0; str1[i] != '\0'; i++) {
  for (j = 0; str2[j] != str1[i]; j++) {
  if (str2[j] == '\0')
  return i;
}
}
  return i;
}

size_t strcspn(const char *str1, const char *str2) {
  while(*str1 && (*s1 == *str2)) {
  str1++;
  str2++;
}
  return *str1 - *str2;
}
*/

/*
unsigned long strxlen(char *s, char *exclude) {
  int i = 0, n = 0, a = 0;
  while (s[i] != '\0') {
  for (int j = 0; j < strlen(exclude); j++) {
  if (s[i] == exclude[j]) {
  a = 0;
}
}
  if (a == 1) {
  n++;
  } else {
  a = 1;
  }
  i++;
  }
  return n;
}

char *strtok(char *str, char *tok) {
  int i = 0;
  while (str[i] != '\0') {
  for (int j = 0; j < strlen(tok); j++) {
  if (str[i] == tok[j]) {
  str[i] = '\0';
  return str;
}
}
  i++;
}
  return NULL;
}

int strcmp(char *s1, char *s2) {
  while(*s1 != '\0' && *s2 != '\0') {
  if(*s1++ != *s2++) {
  return 0;
}
}
  return 1;
}

int strncmp(char *s1, char *s2, unsigned long count) {
  for (int i = 0; i < count; i++) {
  if (s1[i] != s2[i]) {
  return i;
}
}
  return 0;
}

int strstr(char *str, char *find) {
  int n = strlen(find);
  for (int i = 0; i < strlen(str); i++) {
  if (!strncmp(str + i, find, n)) {
  return i;
}
}
  return -1;
}

char *strlower(char *s) {
  for (int i = 0; i < strlen(s); i++) {
  if (s[i] >= 'A' && s[i] <= 'Z') {
  s[i] += 32;
}
}
}

char *strupper(char *s) {
  for (int i = 0; i < strlen(s); i++) {
  if (s[i] >= 'a' && s[i] <= 'z') {
  s[i] -= 32;
}
}
}

char *strcat(char s1[], char s2[]) {
  int i;
  unsigned long n = strlen(s1); 
  while (s1[i] != 0) {
  s1[i + n] = s2[i];
  i++;
}
  return s1;
}

char *strcpy(char *dest, char *src) {
  while (*src != '\0') {
  *dest++ = *src++;
}
  return dest;
}

char *strncpy(char *dest, char *src, unsigned long count) {
  while (*src != '\0' && *dest < count) {
  *dest++ = *src++;
}
  return dest;
}
*/
