#include <cstdio>
#include <map>
#include <memory.h>
using namespace std;

int d[2][1000001];
int a[51];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%d",a+i);
	}

	memset(d, -1, sizeof(d));
	d[0][500000] = 0;

	for(int i = 1; i <= n ;i++)
	{
		int tt = i&1;
		for(int j =0 ; j < 1000001 ;j++)
		{
			if(d[1-tt][j] != -1)
				d[tt][j] = d[1-tt][j];
		}

		for(int j = 1000000 ; j >= a[i]; j--)
		{
			if(d[1-tt][j-a[i]] != -1)
				d[tt][j] = max(d[1-tt][j-a[i]], d[tt][j]);
		}

		for(int j = 0 ; j < 1000001 - a[i] ; j++)
		{
			if(d[1-tt][j+a[i]] != -1)
				d[tt][j] = max(d[tt][j], d[1-tt][j+a[i]]+a[i]);
		}
	}

	printf("%d\n", d[n&1][500000]?:-1);
	
	return 0;
}
