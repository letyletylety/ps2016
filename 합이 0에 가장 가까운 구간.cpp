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

typedef struct
{
	int idx;
	int element;
} PAIR;

bool comp(const PAIR &x, const PAIR &y)
{
	return x.element < y.element;
}

int main(int argc, char **argv)
{
	int a[] = { -14,7,2,3,-8,4,-6,8,9,11 };
	const int len = sizeof(a) / sizeof(int);
	PAIR result[len];

	result[0].idx = 0;
	result[0].element = a[0];

	for (int i = 1; i < len; i++)
	{
		result[i].element = result[i - 1].element + a[i];
		result[i].idx = i;
	}
		
	sort(result, result + len, comp);
	
	for (int i = 0; i < len; i++)
	{
		printf("%d ", result[i].idx);
	}
	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d ", result[i].element);
	}

	// 0에 가장 가까운 구간 하나만 구함

	int min_ = result[1].element - result[0].element;  // large stuff
	int ra = result[1].idx , rb = result[0].idx;			 // range

	for (int i = 2; i < len; i++)
	{
		int t = abs(result[i].element - result[i - 1].element);
		if (min_ > t)
		{
			ra = result[i].idx;
			rb = result[i-1].idx;
			printf("%d %d\n", ra, rb);
			min_ = t;
		}
	}

	if (rb < ra) swap(ra, rb);
	printf("합이 0에 가장 가까운 구간은 [%d, %d] 입니다.\n", ra+1, rb); // ra+1 !!
	
	return 0;
}

/* memo
*
*
*
*
*
*/