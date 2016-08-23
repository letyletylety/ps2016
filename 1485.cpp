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

vector<pair<ll, ll> > vp;

ll distsq(int a, int b)
{
	int ay = vp[a].first;
	int ax = vp[a].second;
	int by = vp[b].first;
	int bx = vp[b].second;
	return (ay-by) * (ay-by) + (ax-bx) * (ax-bx);
}

bool test()
{
	sort(vp.begin(), vp.end());			
	ll temp = distsq(0,1);
	return (temp == distsq(0,2) && temp == distsq(2,3) && temp == distsq(1,3) && distsq(0,3) == distsq(1,2));
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	vp.resize(4);

	while(t--)
	{
		vp.clear();
		for(int i = 0; i < 4; i ++)
		{
			int y,x;
			cin>>y>>x;
			vp.push_back(make_pair(y,x));
		}
		cout<<test()<<newline;
	}
  return 0;
}
