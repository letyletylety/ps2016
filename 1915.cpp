/* Lety */

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
#include		<numeric>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair
#define MT      make_tuple
#define PB      push_back

using namespace std;

typedef long long		 ll;
typedef vector	<int>	 VI;

int board[1001][1001];
int dp[1001][1001];
int a, b;

int main(int argc, char **argv)
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		dp[i][0] = board[i][0];
		answer = max(answer, dp[i][0]);
	}
	for (int i = 0; i < m;i++)
	{
		dp[0][i] = board[0][i];
		answer = max(answer, dp[0][i]);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (board[i][j] == 1)
			{
				dp[i][j] = board[i][j];

				a = dp[i - 1][j];
				b = dp[i][j - 1];

				if (a == b)
				{
					if (board[i - a][j - a] == 1)
					{
						dp[i][j] = max(dp[i][j], a + 1);
					}
					else
					{
						dp[i][j] = max(dp[i][j], a);
					}
				}
				else
				{
					dp[i][j] = max(dp[i][j], min(a, b) + 1);
				}
			}
			else
			{
				dp[i][j] = 0;
			}

			answer = max(answer, dp[i][j]);
		}
	}
	printf("%d", answer*answer);
	return 0;
}

/* memo
* ...... 입력 n by n 으로 받아서 시간초과 10번 넘게 남....
*
*
*
*
*/