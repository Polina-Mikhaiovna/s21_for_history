#include<stdio.h>
#include <stdlib.h>

int input(char *str);

int main(){

	char* str = malloc(sizeof(char*));
    int len = input(str);
    printf(".%d.\n", len);
    int count = 0;
    int i = len-1;
    for (*(str+i); *(str+i) != ' '; i--) {
    	count += 1;
    }
    printf(".%d.\n", i);
    str[i] = '\0';
    
    printf("%s\n", str);

    for (i = 0; i < (len - count - 1); i++) {
    	for (i = 0; i < (len-count - 1); i++) 
    		if (str[len - count + i] == str[i])
    			continue;
    		else break;
    }
   
    printf(".%d.\n", count);
    
    char* new_str;
    new_str = (char*)calloc(len-count, sizeof(char));
    
    int dif = len - count;

    for (int j = 0; j < count; j++) {
    	new_str[j] = str[len - j - 1];       //*(str + (len - n));
    }

    printf(".%s.\n", new_str);

    free(str);
    free(new_str);
    return 0;
    
}

int input(char *str) {
    int i=0;
    do {
        scanf("%c", (str + i));
        i++;
    } while (str[i-1] != '\n');
    
    int len = i;
    return len;
}
