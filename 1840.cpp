#include <iostream>

using namespace std;

bool check_row[10][10];
bool check_col[10][10];
bool check_nine[10][10];
int y[81];
int x[81];
int c[81];

int main()
{
	for(int i =  0 ; i <81;i++)
	{
		scanf("%d%d%d",y+i,x+i,c+i);
	}

	for(int i = 1 ; i <= 81; i++)
	{
		int yy, xx, cc;
		yy = y[i];
		xx = x[i];
		yy--;
		xx--;
		cc = c[i];
		int block = (yy/3)*3 + xx/3 + 1;
		
		if(check_row[yy][cc])
		{
			printf("%d\n", i);	
			return 0;
		}
		if(check_col[xx][cc])
		{
			printf("%d\n", i);	
			return 0;
		}
		if(check_nine[block][cc])
		{
			printf("%d\n", i);	
			return 0;
		}
		check_row[yy][cc] = 1;
		check_col[xx][cc] = 1;
		check_nine[block][cc] = 1;
	}
	printf("-1\n");
	return 0;
}
