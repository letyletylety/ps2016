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
#define xx first
#define yy second
const int mod = 1000000007;
const int INF = 987654321;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

// parametric!

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> vv(n);
	forn(i,n)
	{
		cin>>vv[i];	
	}
	ll left = 0LL;
	ll right = 1e15;
	ll answer = 0;

	while(left <= right)
	{
		ll mid = (left + right)>>1;
	
		ll people = 0;
		bool good = true;

		for(int i = 0 ; i < n ; i++)
		{
			people += mid / vv[i];
		}
		if(people >= m)
		{
			right = mid-1;	
			answer = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout<<answer<<newline;
  return 0;
}
