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


// -------------------------- main
int n;
int arr[2010];
int isPal[2010][2010]; // isPal[i][j] : i~j 까지 구간이 팰린드롬인지 여부

int dp(int i,int j)
{
	if(i == j)return 1;
	if(j == i+1)
	{
		if(arr[i] == arr[j]) return 1;
		return 0;
	}
	
	int &ret = isPal[i][j];
	if(ret != -1) return ret;
	if(arr[i] != arr[j]) return ret = 0;
	else return ret = dp(i+1,j-1);
}
int main(int argc, char **argv)
{
	scanf("%d",&n);
	memset(isPal, -1, sizeof(isPal));
	for(int i=1 ; i <= n ;i++)
	{
		scanf("%d",&arr[i]);
	}
	int m;
	scanf("%d",&m);
	for(int i  = 0;  i< m; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp(a,b));
	}
    return 0;
}
