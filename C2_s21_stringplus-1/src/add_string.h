#include "string.h"

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp (const void *str1, const void *str2, size_t n);
void *s21_memmove (void *dest, const void *src, size_t n);
void * s21_memset (void *s, int c, size_t n);
char *s21_strchr (const char *s, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
size_t s21_strlen(const char *str);
char *s21_strrchr(const char *str, int c);
char *s21_strrchr(const char *str, int c) ;

void *s21_memchr(const void *str, int c, size_t n){

	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char*)(str + i) == (unsigned char)c)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {

    int i;
    unsigned char *temps1 = (unsigned char*)str1;
    unsigned char *temps2 = (unsigned char*)str2;    
    i = 0;    

    while (i < n && str1 && str2)
    {
        if (temps1[i] > temps2[i])
            return (1);
        else if (temps1[i] < temps2[i])
            return (-1);
        ++i;
    }
    return (0);
}

void *s21_memmove(void *dest, const void *src, size_t n) {
    
    int i;
    char *tempdest = (char*)dest;
    char *tempsrc = (char*)src;
    if (!dest || !src)
      return(NULL);
    if (dest == src)
        return(dest);
    else if (dest > src)
    {
        i = n - 1;
        while (i >= 0)
        {
            tempdest[i] = tempsrc[i--];
            ++i;
}
    }
    else
    {
        i = 0;
        while (i < n)
        {
           tempdest[i] = tempsrc[i];
           ++i;
        }
    }
    return(dest);
}

void * s21_memset(void *str, int c, size_t n) {
   
    int i = 0;
    if (!srt)
        return (NULL);
    while (i < n)
        *((char*)srt + i++) = c;
    return (srt-i);
}

char *s21_strchr(const char *str, int c) {
    int i;
    char *temps;
    
    temps = str;
    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return(temps + i);
        ++i;
    }
    return(NULL);
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
	size_t i;

	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

size_t s21_strlen(const char *str)
{
	int i = 0;
	while(str[i])
		i++;
    return(i);
}

char *s21_strrchr(const char *str, int c) {
    
    int i;
    char *temps;
    
    temps = str;
    i = ft_strlen(str) - 1;
    while (i >= 0)
    {
        if (str[i] == c)
            return(temps + i);
        --i;
    }
    return(NULL);
}

