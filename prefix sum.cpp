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
	int n;						// the # of element
	int m;						// the # of query
	int t;						// temp variable
	int psum[100001]; // prefix sum
	int a, b;					// range : [a,b]
	scanf("%d", &n);
	scanf("%d", &psum[0]);
	for (int i = 1; i < n; i++)
	{
		scanf("%d", &t);
		psum[i] = psum[i - 1] + t; // calculate prefix sum
	}
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		a--;						// starting index is 0
		b--;

		printf("%d\n", psum[b] - (a==0?0:psum[a - 1])); // !
	}
	return 0;
}

/* memo
*
*
*
*
*
*/