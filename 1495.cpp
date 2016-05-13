#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printfsssss
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair
#include <map>
#include <list>
#include <stack>
#include <deque>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

int n,s,m;
int arr[101];
int cache[101][1001];

// -------------------------- main

int dp(int idx, int volume) //  dp(i,j) : 현재 i번째 곡을 선택하고 현재 볼륨은 j일때 볼륨 시작점 까지 감소할 수 있는지 여부
{
	if(idx == -1) return volume == s;
	if(volume < 0 || volume > m) return 0;

	int &ret = cache[idx][volume];
	if(ret != -1) return ret;
	
	ret = 0;
	ret |= dp(idx-1,volume+arr[idx])|dp(idx-1, volume-arr[idx]);
	return ret;
}


int main(int argc, char **argv)
{
	scanf("%d%d%d",&n,&s,&m);
	memset(cache,-1,sizeof(cache));
	for(int i = 0 ; i < n ;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int ans = -1;
	for(int i = 0 ; i <= m ;i++)
	{
		if(dp(n-1,i))ans = i;
	}
	printf("%d\n",ans);
    return 0;
}
