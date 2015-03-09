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
			word++;
		}
		if (!(io >= 'a' && io <= 'z') && !(io >= 'A' && io <= 'Z')) {
			io = '\n';
			reset = 0;
			punc++;
		}
		putchar(io);
	}
	printf("There are %d words and %d punctuation marks.\n", word, punc);
	return 0;
}
