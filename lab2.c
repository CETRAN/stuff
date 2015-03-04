#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	char io; 
	int word = 1, punc = 0;

	while ((io = getchar()) != EOF)
	{
		if (io >= 97 && io <= 122)
			io = (io - 32);
		if (io == 32)
		{
			word++;
			putchar('\n');
		}
		if (io >= 33 && io <= 64)
			io = ' ';
		putchar(io);	
	}
	printf("There are %d words and %d punctuation marks.\n", word, punc);

	system("pause");
	return 0;
}
