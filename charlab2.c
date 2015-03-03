#include <stdio.h>
int main(void)
{
	char io;
	int word = 0, punc = 0;

	while ((io = getchar()) != EOF)
	{
		if (io >= 97 || io <= 122)
		{
			if (!((io >= 97 || io <= 122)) || (io >= 65 || io >= 90))
				punc++;
			if (io >= 97)
				io = (io - 32);
			if (io == '\n')
				io = NULL;		
			word++;
		}
		putchar(io);
	}
	return 0;
}

/*This is for counting characters*/
