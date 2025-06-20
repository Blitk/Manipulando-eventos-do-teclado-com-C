#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

char getKeyBoard()
{
	struct termios oldt, newt;
	char ch;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}

void imprimir(int *ptr)
{
	for(int i = 0; i <=30; i++)
	{
		for(int d = 0; d<= 50; d++)
		{
			if(ptr[0] == i && ptr[1] == d)
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void alterar(int *ptr, int x, int y)
{
	if(x == 1 && ptr[0] > 0)
	{
		ptr[0] = ptr[0] - 1;
	}
	if(x == 2 && ptr[0] < 30 )
	{
		ptr[0] = ptr[0] + 1;
	}
	if(y == 1 && ptr[1] > 0)
	{
		ptr[1] = ptr[1] - 1;
	}
	if(y == 2 && ptr[1] < 50)
	{
		ptr[1] = ptr[1] + 1;
	}


}

int main()
{
	char c;
	int cordenada[2];
	cordenada[0]= 15;
	cordenada[1] = 15;
	imprimir(cordenada);
	while((c = getKeyBoard()) != 'x')
	{
		switch(c)
		{
		case 'w':
			alterar(cordenada,1,0);
			break;
		case 'a':
			alterar(cordenada,0,1);
			break;
		case 's':
			alterar(cordenada,2,0);
			break;
		case 'd':
			alterar(cordenada,0,2);
			break;
		default:
			break;
		}
		system("clear");
		imprimir(cordenada);

	}
	return 0;
}