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

int main(int argc, char **argv)
{
	int n, s;
	int arr[100001];
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int answer = 123456789;
	int begin = 0, end = 0;
	int temp = 0;

	for (end = 0; end < n; end++)
	{
		temp += arr[end];
		while (temp >= s)
		{
			answer = min(answer, end - begin + 1);

			if (begin == end)
			{
				break;
			}
			else
			{
				temp -= arr[begin];
				begin++;
			}
		}
	}
	printf("%d", answer==123456789?0:answer);

	return 0;
}

/* memo
*
*
*
*
*
*/