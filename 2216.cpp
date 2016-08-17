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

string x,y;
int a,b,c;	
int d[3001][3001];

int go(int xx, int yy)
{
	if(xx == x.size() && yy == y.size() )
	{
		return 0;
	}	
	else if(xx == x.size() && yy != y.size())
	{
		return b * (y.size() - yy);
	}
	else if(xx != x.size() && yy == y.size())
	{
		return b * (x.size() - xx);
	}

	int &ret = d[xx][yy];
	if(ret != -1) return ret;

	if(x[xx] == y[yy]) 
		ret = a + go(xx+1, yy+1);
	else
	{
		ret = c + go(xx+1, yy+1);
	}

	ret = max( ret, b + go(xx+1, yy) );
	ret = max( ret, b + go(xx, yy+1) );
	return ret;
}
int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	memset(d, -1, sizeof(d));
	cin>>a>>b>>c;
	cin>>x>>y;
	cout<<go(0,0)<<newline;
  return 0;
}
