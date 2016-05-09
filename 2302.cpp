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

int dp[41];
int D[41]; // i 개의 자리가 있을때 앉는 방법의 수
// -------------------------- main

int main(int argc, char **argv)
{
	int n,m;
	vector<int> vip;
	scanf("%d%d",&n,&m);
	
	for(int i = 0 ; i < m;i++)
	{
		int t;
		scanf("%d",&t);
		vip.push_back(t);
	}
	
	int pre = 1;
	dp[0] = 1;
	D[0] = 1;
	D[1] = 1;
	for(int i = 2; i <= n ;i++)
	{
		D[i] = D[i-1] + D[i-2];
	}
	
	for(int i = 1; i <= m ;i++)
	{
		int here = vip[i-1];
		dp[i] = dp[i-1] * D[here-pre];
		pre = here +1;
	}
	printf("%d", dp[m]*D[n+1-pre]);
	return 0;
}

/* memo
* vip석 사이에 있는 것들이 피보나치임을 찾아내는것이 핵심
*
*
*
*
*/

