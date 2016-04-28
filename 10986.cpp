/* Lety */

#define _CRT_SECURE_NO_WARNINGS

#include        <cstdio>
#include        <cmath>
#include        <algorithm>
#include        <vector>
#include        <stack>
#include        <queue>
#include        <functional>
#include        <cstring>
#include        <string>
#include        <map>
#include        <set>
#include        <iostream>
#include        <tuple>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair
#define MT      make_tuple
#define PB      push_back

using namespace std;

typedef long long        ll;
typedef vector  <int>  VI;

int main(int argc, char **argv)
{
	int n, m;

	int t;
	int pre;
	int *mod;
	long long int answer = 0;

	pre = 0;

	scanf("%d%d", &n, &m);

	mod = (int *)malloc(sizeof(int) * (m + 1));
	memset(mod, 0, (m + 1) * sizeof(int));
	mod[0] = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		pre = (pre + t) % m;

		if (pre == 0)
		{
			answer += mod[pre]++;
		}
		else
		{
			answer += mod[pre]++;
		}

	}
	printf("%lld", answer);
	return 0;
}

/* memo
*
*
*
*
*
*/