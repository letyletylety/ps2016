#define _CRT_SECURE_NO_WARNINGS

#include		<cstdio>
#include		<cmath>
#include		<algorithm>
#include		<vector>
#include		<stack>
#include		<queue>
#include		<functional>
#include		<cstring>
#include		<string>
#include		<map>
#include		<set>
#include		<iostream>
#include		<tuple>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair
#define MT			make_tuple

using namespace std;

typedef long long		 ll;
typedef vector	<int>	 VI;

#define MAX_N 3*3*3*3*3*3*3+1

int board[MAX_N][MAX_N];

int isEqual(int y, int x, int n)
{
	int t = board[y][x];
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; ++j)
		{
			if (t != board[i][j])
				return 3;
		}
	}
	return t + 1;
}

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &board[i][j]);			
		}
	}

	int result[3];
	memset(result, 0, sizeof(result));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, n));

	while (!q.empty())
	{
		int y, x, l, t;
		tie(y,x,l)= q.front();
		q.pop();
	//	printf("%d %d %d\n", y, x, l);

		if (l == 1)
		{
			result[board[y][x]+1]++;
		}
		else
		{
			t = isEqual(y, x, l);

			if (t != 3)
			{
				result[t]++;
			}
			else
			{
				l /= 3;
				q.push(MT(y, x, l));
				q.push(MT(y+l, x, l));
				q.push(MT(y+2*l, x, l));
				q.push(MT(y, x+l, l));
				q.push(MT(y+l, x+l, l));
				q.push(MT(y+2*l, x+l, l));
				q.push(MT(y, x+2*l, l));
				q.push(MT(y+l, x+2*l, l));
				q.push(MT(y+2*l, x+2*l, l));
			}
		}
	}

	printf("%d\n%d\n%d\n", result[0], result[1], result[2]);
	return 0;
}

/* memo
*
*
*
*
*
*/