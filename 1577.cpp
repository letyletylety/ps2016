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

ll cache[101][101];
int state[101][101];
int n,m;

ll dp(int y, int x)
{
	if(y == n && x == m)
	{
		return 1;
	}

	if( y > n )
		return 0;
	if(x > m)
		return 0;

	ll &ret = cache[y][x];

	if(ret != -1)return ret;
	ret = 0;

	if( state[y][x] == 1)
	{
		return ret = dp(y, x+1);
	}
	else if(state[y][x] == 2)
	{
		return ret = dp(y+1, x);
	}
	else if(state[y][x] == 0)
	{
		return 0;
	}
	else
	{
		return ret = dp(y+1, x) + dp(y, x+1);
	}
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	int a,b,c,d;

	cin>>n>>m>>k;
	forn(i,101)
		forn(j,101)
		{
			cache[i][j] = -1;
			state[i][j] = 3; // can go anywhere
		}

	forn(i,k)
	{
		cin>>a>>b>>c>>d;
		if(a == c)
		{
			int x = min(b,d);	
			if(state[a][x] == 3)
			{
				state[a][x] = 2;
			}
			else if(state[a][x] == 2)
			{
				// ? 
			}
			else if(state[a][x] == 1)
			{
				state[a][x] = 0; // can not go anywhere
			}
			else{
				// ?
			}
		}
		else if(b == d)
		{
			int y = min(a,c);	
			if(state[y][b] == 3)
			{
				state[y][b] = 1;
			}
			else if(state[y][b] == 2)
			{
				state[y][b] = 0;
			}
			else if(state[y][b] == 1)
			{

			}
			else{
				// ?
			}
		}
	}

	cout<<dp(0,0)<<newline;
  return 0;
}
