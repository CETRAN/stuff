/*
	Zepeda, Bryant
	Lab #2
	Due Date: 3/3/2015
	Description: To gain experience in character processing
*/
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
		{
			if (io == 33 || io == 44 || io == 46 || io == 59 || io == 63)
				io = ' ';
			punc++;
		}
		putchar(io);	
	}
	printf("There are %d words and %d punctuation marks.\n", word, punc);
	system("pause");
	return 0;
}
