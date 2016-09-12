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

const int N = 51;

vector<int> A;
//ll d[2][ 10 ][ 50002 ]; // sliding
ll d[50002][11];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	A.resize(n);

	forn(i,n)
	{
		cin>>A[i];
	}
	sort(A.begin(), A.end());

	int K;
	cin>>K;
//	cout<<"K:"<<K<<newline;
	if( K < 3 )
	{
		cout<<0<<newline;
		return 0;
	}
	memset(d, 0, sizeof(d));
	d[0][0] = 1;

	ll ans = 0LL;

	for(int i = 0 ; i < n - 1; i++)
	{
//		for(int j = 0 ; j <= 50001; j++)
		for(int k = K - 1 ; k >= 0 ; k--)
		{
			for(int j = 50001 ; j >= A[i] ; j--)
			{
				d[j][k+1] += d[j- A[i]][k];
			}
			for(int j = 50001 - A[i] +1 ; j <= 50001 ;j++)
			{
				d[50001][k+1] += d[j][k];
			}
		}

		for(int j = A[i+1] + 1; j <= 50001; j++)
		{
			if(d[j][K-1])
			{
				ans += d[j][K-1];
			}
		}
//		cout<<i<< ' '<<ans<<newline;
	}
	cout<<ans<<newline;
  return 0;
}
