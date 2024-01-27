#include <stdio.h>
//#include "cat.h"

struct cat_option
{
	int opt_b; //нумерует только непустые
	int opt_e; //отображает /0 как $(код 36)
	int opt_n; //нумерует все строки
	int opt_s; //сжимает смежные пустые строки
	int opt_t; //отображает табы(код 9) как ^|(коды 94, 124)

};

int main(const int const argc, char const *argv[]) {
	
	const char * const allowedFlags[] = { "-b", "-e", "-n", "s", "-t"};
	const unsigned int const numberOfAllowedFlags = sizeof allowedFlags /
	sizeof allowedFlags[0];
	struct cat_option opt;
	opt.opt_b = 0;
	opt.opt_e = 0;
	opt.opt_n = 0;
	opt.opt_s = 0;
	opt.opt_t = 0;
	
	printf("%d\n", numberOfAllowedFlags);
	printf("%d, %d, %d, %d, %d\n", opt.opt_b, opt.opt_e, opt.opt_n, opt.opt_s, opt.opt_t);
	printf("%d, %s\n", argc, argv[1]);
	return 0;
}
