#include <cstdio>
#include <algorithm>

using namespace std;

int a[51];
int c[51];

int main()
{
	int n,m;
	scanf("%d",&n);

	for(int i = 0 ; i <  n ;i++)
	{
		scanf("%d", a+ i);
	}
	sort(a, a+n);
	scanf("%d",&m);
	for(int i = 0 ; i < m ;i++)
	{
		int tt;
		scanf("%d", &tt);
		int j;
		for(j = 0; j < n ; j++)
		{
			if(a[j] >= tt)
			{
				c[j]++;
				break;
			}
		}
		if(j == n)
		{
			puts("-1");
			return 0;
		}
	}

	int answer = 1;

	while(1)
	{
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = i; j>=0 ;j--)
			{
				if(c[j])
				{
					c[j]--;
					break;
				}
			}
		}

		bool ok = true;
		for(int i = 0 ; i < n ;i++)
		{
			if(c[i]) {ok = false; break;}
		}
		if(ok)
		{
			break;
		}

		answer++;	
	}
	printf("%d\n", answer);
	return 0;
}

