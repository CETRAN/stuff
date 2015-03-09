#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	char io;
	int word = 0, punc = 0, reset = 0;

	while ((io = getchar()) != EOF) {
		if (reset == 0 && (io >= 'a' && io <= 'z')) {
			io = (io - 32);
			reset = 1;
		}
		if (!(io >= 'a' && io <= 'z') && !(io >= 'A' && io <= 'Z')) {
			io = '\n';
			reset = 0;
			punc++;
		}
		putchar(io);
	}
	return 0;
}
