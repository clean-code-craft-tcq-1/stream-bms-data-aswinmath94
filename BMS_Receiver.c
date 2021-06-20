
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



void readfromConsole(void)
{
	char buffer[200];
	while (scanf("%s",buffer)!=EOF)
	{
		printf(" the value of the buffer is %s\n",buffer);
	}

}

int main()
{
	readfromConsole();
	return 0;
}
