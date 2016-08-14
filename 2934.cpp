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

const int N = 100000 + 10;
int d[N];

int sum(int i)
{	
	int ans = 0;
	while(i)
	{
		ans += d[i];		
		i -= (i&-i);
	}
	return ans;
}

void add(int i, int num)
{
	while(i <= N)
	{
		d[i] += num;	
		i += (i&-i);
	}
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;

	for(int i = 1; i <= n ;i++)
	{
		int l,r,ql,qr;
		cin>>l>>r;
		ql = sum(l);
		qr = sum(r);
		cout<<ql+qr<<newline;
		add(l, -ql); add(l+1, ql);
		add(r, -qr); add(r+1, qr);
		add(l+1, 1);
		add(r, -1);

//		for(int j = 1 ; j < 10 ; j++)
//		{
//			cout<<d[j]<<' ';
//		}
//		cout<<newline;
	}	
  return 0;
}
