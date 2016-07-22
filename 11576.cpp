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

int a,b;
int m;
VI v;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin>>a>>b;
	cin>>m;
	int t;
	int su = 0;
	forn(i,m)
	{
		cin>>t;
		su *= a;
		su += t;
	}

	while(su)
	{
		v.pb(su % b);
		su /= b;
	}

	for(auto it = v.rbegin(); it!= v.rend(); it++)
	{
		cout<<*it<<' ';
	}
	cout<<newline;
  return 0;
}
