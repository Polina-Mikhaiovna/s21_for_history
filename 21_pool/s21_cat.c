#include <stdio.h>
#include <string.h>
//#include "cat.h"

struct cat_opt {
	int b; //нумерует только непустые
	int e; //отображает /0 как $(код 36)
	int n; //нумерует все строки
	int s; //сжимает смежные пустые строки
	int t; //отображает табы(код 9) как ^|(коды 94, 124)

};
	

int main(const int argc, char const *argv[]) {
	
	unsigned int count = 1;
	unsigned int errorFlag = 0;
	long unsigned int i = 1;
	struct cat_opt opt;
	opt.b = 0;
	opt.e = 0;
	opt.n = 0;
	opt.s = 0;
	opt.t = 0;
	
	if (argc > 1 && argv[count][0] == '-') {
		
		while(argv) {
			if (errorFlag > 0) break;
			
			while (i < strlen(argv[count])) {
				switch (argv[count][i]) {
				case 'b' : opt.b = 1; break;
				case 'e' : opt.e = 1; break;
				case 'n' : opt.n = 1; break;
				case 's' : opt.s = 1; break;
				case 't' : opt.t = 1; break;
			} if (argv[count][i] != ('b' || 'e' || 'n' || 's' || 't')) {
					errorFlag++;
					break;
			} i += 1;
			} memset(argv[count], '\0', strlen(argv[count]));
		}
	}
	/*if (argc > 1 && argv[count][0] != '-') {

		FILE *cat_file = fopen(argv[count], "");
		cat_file = ;

	}*/


	printf("%d, %d, %d, %d, %d\n", opt.b, opt.e, opt.n, opt.s, opt.t);
	printf("%d, %s\n", argc, argv[count]);
	printf("%d\n", errorFlag);
	printf("%ld\n", strlen(argv[count]) - 1);
	return 0;

}
