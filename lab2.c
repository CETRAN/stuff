#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	char io;
	int word = -1, punc = 0; /*the variable 'word' is -1 to offset the end of the character*/

	while ((io = getchar()) != EOF)
	{
		if (io >= 97 && io <= 122)
		{
			io = (io - 32);
			word++;
		}
		if (io >= 65 && io <= 90); /*A precursor for else statement and not changing capitalized characters*/
		else
		{
			io = ' ';
			punc++;
			putchar('\n');
		}
			
		putchar(io);
	}
	printf("There are %d words and %d punctuation marks.\n", word, punc);
	return 0;
}
