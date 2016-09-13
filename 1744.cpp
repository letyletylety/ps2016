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

vector<ll> plu;
vector<ll> minu;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	ll A;
	int onecnt = 0;
	int zerocnt = 0;
	ll ans = 0LL;
	cin>>n;
	for(int i = 0 ; i <  n ; i++)
	{
		cin>>A;			
		if(A >= 2)
			plu.pb(A);
		else if(A <= 0)
			minu.pb(A);
		else
			onecnt++;
	}
	if(minu.size() % 2) minu.pb(1);
	sort(plu.begin(), plu.end());
	sort(minu.begin(), minu.end());

	if(plu.size() %2 )
	{
		ans += plu[0];
		for(int i = 1; i < plu.size() ;i+=2)
		{
			ans += (plu[i] * plu[i+1]);
		}
	}
	else{
		for(int i = 0 ; i < plu.size() ; i+=2)
		{
			ans += (plu[i] * plu[i+1]);
		}
	}

	for(int i = 0 ; i< minu.size(); i+=2)
	{
		ans += (minu[i] *minu[i+1]);
	}
	cout<<ans + onecnt<<newline;
  return 0;
}
