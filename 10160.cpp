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
typedef pair<int, int> PII;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)
const int mod = 1000000009;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

ll d[7];
ll e[7];

// 길이가 i인 유효한 암호문이며 현재 상태가 state 인 문자열의 개수
int n ,k;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin>>n>>k;	
	e[0] = 1;

	for(int i = 1; i <= n ; i++)
	{
		d[0] = (k-1) * e[0];
		for(int j = 1 ; j < 7; j++)
			d[0] = (d[0] % mod + ( (k-2) * e[j] ) % mod) % mod;

		d[1] = (e[0] + e[1] + e[3] + e[5] + e[6]) % mod;
		d[2] = e[1];
		d[3] = (e[2] + e[4]) % mod;
		d[4] = e[3];
		d[5] = e[2];
		d[6] = e[5];

		for(int j = 0 ; j< 7 ;j++) e[j] = d[j];
	}

	ll answer = 0;
	for(int i  = 0; i<7 ; i++)
	{
		answer = (answer % mod + e[i] % mod) % mod;
	}
	cout<<answer<<newline;
  return 0;
}
