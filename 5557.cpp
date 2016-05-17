#include <iostream>
#include <queue>
#include <utility>

typedef long long LL;
using namespace std;
int arr[102];
LL dp[102][21]; // dp[i][j] : i번째 수부터 이용해서 x를 만드는 방법의 수
int n;


int main()
{
	scanf("%d",&n);

	for(int  i  = 1; i<=  n;i++)
	{
		scanf("%d",arr+i);
	}
	
	dp[1][arr[1]] = 1;
	for(int i = 1; i <= n-2 ;i++)
	{
		for(int j = 0 ; j <= 20; j++)
		{
			if(dp[i][j] == 0) continue;

			if(j+arr[i+1]<=20){dp[i+1][j+arr[i+1]] += dp[i][j];}
			if(j-arr[i+1]>=0){dp[i+1][j-arr[i+1]] += dp[i][j];}
		}
	}
	printf("%lld",dp[n-1][arr[n]]);
	return 0;
}

