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

const int dy[5] = {1,0,0,-1,0};
const int dx[5] = {0,-1,1,0,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)
const int mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

ll dp[5][100001];
vector<pair<int, int> > vp;
int nn;

ll go(int dir, int n)
{
	ll &ret = dp[dir][n];
	if(ret != 0) return ret;
	if(n == nn) return 0;
	ret = 987654321987654321;
		
	int y,x;
	int therey, therex;

	y = vp[n].first;
	x = vp[n].second;
	therey = vp[n+1].first;
	therex = vp[n+1].second;

	y += dy[dir];
	x += dx[dir];

	for(int i = 0 ; i <= 4 ; i++)
	{	
		therey += dy[i];
		therex += dx[i];

		ll temp = abs(therey - y) + abs(therex - x) + go(i, n+1);
		if( ret > temp )
		{
			ret = temp;
		}	
		therey -= dy[i];
		therex -= dx[i];
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>nn;
	vp.resize(nn+1);

	for(int i = 0 ; i <= nn ; i++)
	{
		cin>>vp[i].second>>vp[i].first;
	}

	cout<<go(4, 0)<<newline;
  return 0;
}
