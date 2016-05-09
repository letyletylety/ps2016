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

int a[1000001];
int b[1000002];
int main()
{
	int n;
	int answer = 0;
	scanf("%d", &n);
	int i, j, k;
	for (i = 0; i<n; i++)
	{
		scanf("%d", a + i);
		b[a[i]] = i;
	}
	b[n + 1] = 0;
	int s;
	for (i = 0; i<n; i++)
	{
		s = b[a[i]];
		for (j = a[i] + 1; b[j] > s; j++)s = b[j]; // a[i] 보다 번호가 크면서 크면서 가장 멀리 떨어진 학생의 번호의 학생을 찾는다
		
		answer = max(answer, j - a[i]);
	}
	printf("%d", n - answer);
	return 0;
}