#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[1001];

int main() {
	int n,k;
	int cnt = 0;

	scanf("%d%d",&n,&k);

	for(int i =2 ; i <=n ;i++)
	{
		isPrime[i] = true;
	}
	
	for(int  i = 2; i <= n ;i++)
	{
		if(isPrime[i])
		{
			cnt++;
			if(cnt == k) {printf("%d",i);return 0;}
			isPrime[i] = false;
			//printf("%d ",i);
			for(int j = i*i;j<=n;j+=i)
			{
				if(isPrime[j])
				{
					cnt++;
					if(cnt == k) {printf("%d",j);return 0;}
					isPrime[j] = false;	
					//printf("%d ",j);
				}
			}
		}
	}
	
	return 0;
}
