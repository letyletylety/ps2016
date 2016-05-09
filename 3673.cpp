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

void work() {
		int N, M;
		scanf("%d %d", &M, &N);

		int A, S = 0;
		int *R = (int *)calloc(M, sizeof(int));
		long long C = 0;
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A);
			S = (S + A) % M;
			C += R[S];
			R[S]++;
			if (!S)
				C++;
		}
		printf("%lld\n", C);
}

int main(int argc, char **argv)
{
	int t;
	scanf("%d", &t);
	while (t--)
		work();

	return 0;
}


/* memo
*
*
*
*
*
*/