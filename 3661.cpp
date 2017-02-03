#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
using namespace std;

struct Man
{
	int money;
	int idx;
};

Man a[101];
int res[101];

int main()
{
	int t;
	scanf("%d", &t); // ~100

	while(t--)
	{
		memset(res, 0, sizeof(res));
		long long p;
		int n;
		long long sum = 0;
		scanf("%lld%d", &p,&n);

		for(int i = 0 ; i < n ; i++)
		{	
			scanf("%d",&a[i].money);

			sum += a[i].money;
			a[i].idx = i;
		}
	
		if(sum < p)
		{
			puts("IMPOSSIBLE");
			continue;
		}

		sort(a, a+n, [](const Man &a, const Man &b)
				{
					if(a.money == b.money)
					{
						return a.idx > b.idx;
					}
					return a.money < b.money;
				});

//		for(int i = 0 ; i < n ; i++)
//		{
//			printf("%d %d\n", a[i].money, a[i].idx);
//		}

		for(int i = 0 ; i < n && p ; i++)
		{
			int nqnsdml1 = p/(n-i);
			int tt = min(a[i].money, nqnsdml1);

//			printf("%d %d\n", nqnsdml1, tt);

			if(!tt) continue;

			for(int j = i ; j < n ;j++)
			{
				a[j].money -= tt;
				res[a[j].idx] += tt;
			}
			p = p - tt * (n-i);	
		}

		for(int i = 0 ; i < n ; i++)
		{
			printf("%d", res[i]);
			if(i == n-1)
				puts("");
			else printf(" ");
		}
	}
	return 0;
}
