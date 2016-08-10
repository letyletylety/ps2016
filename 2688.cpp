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
#include <cmath>
#include <ctime>
#include <chrono>
#include <climits>
#include <cassert>
using namespace std;

typedef unsigned ull;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)
const int mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

ll dp[10][65];

ll go(int here, int n) 
{
	if(n == 1) return 1;
	if(dp[here][n] != -1) return dp[here][n];

	ll &ret = dp[here][n];
	ret = 0;
	for(int there = here ; there <= 9 ;there++)
	{
		ret += go(there, n-1);
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp, -1, sizeof(dp));
		ll answer = 0;
		for(int i = 0 ; i < 10 ; i++)
		{
			answer += go(i, n);
		}
		cout<<answer<<newline;
	}
	return 0;
}
