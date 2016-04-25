#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printf
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair
#include <map>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- global variable



// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function


// -------------------------- main

int main(int argc, char **argv)
{
	int dp[10001];
	
	int t;for(scanf("%d",&t);t--;)
	{
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		int n;
		scanf("%d",&n);
		for(int i = 0 ; i < n ;i++)
		{
			int coin;
			scanf("%d",&coin);
			for(int j = coin ; j < 10001; j++)
			{
				dp[j] += dp[j-coin];
			}
		}
		int m;
		scanf("%d",&m);
		printf("%d\n",dp[m]);
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
