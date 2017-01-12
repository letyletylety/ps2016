#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int	lanline[10001];

int main()
{
	int k;
	long long n;
	unsigned M = 0;
	scanf("%d%lld",&k,&n);

	for(int i = 0 ; i < k ; i++)
	{
		scanf("%d", lanline+i);
		if( M < lanline[i])
			M = lanline[i];
	}

	unsigned low, high, answer, mid;
	low = 0;
	answer = 0;
	high = M;
	while(low <= high)
	{
		mid = (low+high)>>1;

	  long long int tt = 0;
		for(int i = 0 ; i < k ;i++)
		{
			tt += (long long)(lanline[i] / mid);
		}

		if(tt < n) // 더 짧게 잘라야함
		{
			high = mid-1;	
		}
		else // 더 길게 잘라야함
		{
			low = mid+1;
			if(answer < mid)
				answer = mid;
		}
	}
	printf("%u", answer);
	return 0;
}
