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

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair
#define MT      make_tuple
#define PB      push_back

using namespace std;

typedef long long		 ll;
typedef vector	<int>	 VI;

int main(int argc, char **argv)
{
	int n, m;
	int arr[110];
	int srr[110]; // srr[i] : arr[j] �� �� (j : 0~ i-1)

	scanf("%d%d", &n, &m);
	srr[0] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		srr[i + 1] = srr[i] + arr[i];
	//	printf("%d\n", srr[i + 1]);
	}
	
	int dp[110][110]; // dp[i][j] : i��° ���ڱ��� ������ ������ j�� �϶� � ���� ���� �ִ�
	
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = -123456789;
		for (int here = 0; here < i; here++)
		{
			dp[i][1] = max(dp[i][1], srr[i] - srr[here]);
		}
	}

	for (int j = 2; j <= m; j++)
	{
		for (int i = 2 * j - 1; i <= n; i++) // TODO: ���� ���� ����
		{
			dp[i][j] = -123456789;
			for (int before = j * 2 - 3; before < i - 1; before++)
			{
				int t = -123456789;
				for (int here = before + 1; here < i; here++)
				{
					t = max(t, srr[i] - srr[here]);
				}
				dp[i][j] = max(dp[i][j], dp[before][j - 1] + t);
			}
		//	printf("%d %d : %d\n", i, j, dp[i][j]);
		}
	}

	int answer = -123456789;
	for (int i = 2*m-1; i <= n; i++)
	{
		answer = max(answer, dp[i][m]);
	}
//	printf("%d\n", dp[2][1]);
	//printf("%d\n", dp[5][2]);
	printf("%d", answer);
	return 0;
}

/* memo
* �� ���� ������ ���� ��ġ�ų� "�پ�" �־�� �� �ȴ�.
* ..������ ���� 0���� �������� �ִ�
* ����üũ
*
*
*/