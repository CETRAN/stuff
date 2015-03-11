/*Zepeda, Bryant
  Lab #2
  Due Date: 3/10/2015
  Description: Exercise to improve character handling*/
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	char io;
	int word = 0, punc = 0, reset = 0, cap = 0, newline = 0;
	while ((io = getchar()) != EOF) {
		if (newline == 1 && reset == 0 && (io >= 'a' && io <= 'z')) {
			io = (io - 32); /*Setting to capital*/
			reset = 1; /*Flag*/
			word++;
			cap = 1; /*If already capitalized then don't do it again in second conditional*/
		}
		if (cap == 1 && ((io >= 'A' && io <= 'Z') && (io >= 'a' && io <= 'z'))) {
			cap = 0;
		}
		else if (!(io >= 'a' && io <= 'z') && !(io >= 'A' && io <= 'Z')) {
			io = '\n';
			reset = 0;/*First character that is not capitalized*/
			punc++;
			newline = 1;
		}
		putchar(io);
	}
	printf("There are %d words and %d punctuation marks.\n", word, punc);
	system("pause");
	return 0;
}
