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

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll x;
	while(cin>>x)
	{
		x *= 10000000LL;
		int n;
		cin>>n;
		if(n == 0)
		{
			cout<<"danger"<<newline;
			continue;
		}
		vector<ll> A(n);
		forn(i,n)
		{
			cin>>A[i];
		}
		sort(A.begin(), A.end());
		bool good = false;
		for(int i = 0 ; i < n ; i++)
		{
			ll t = x - A[i];	

			if( binary_search(A.begin() + i + 1, A.end(), t) )
			{
				cout<<"yes "<<A[i]<<' '<<t<<newline;
				good = true;
				break;
			}
		}
		if(!good)
			cout<<"danger"<<newline;
	}
  return 0;
}