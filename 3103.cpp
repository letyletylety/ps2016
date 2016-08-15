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

const int N = 300000 + 10;
int k,n, now, i;
int v[N];
int f[N]; // factorial
int A[N]; int B[N]; // offline algorithm
int d1[N], d2[N]; 
int res[N];

VI tn[N];
vector<pii> tf[N];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>k>>n;		
	for(i = 0 ; i < k ; i++) cin>> v[i];
	f[0] = now = 1; 
	for(i = 1; i < k ; i++) f[i] = (ll)f[i-1]*i % mod;
	for(i = 0 ; i < n; i++)
	{
		cin>> A[i] >> B[i]; A[i]--;		B[i]--;
		tn[A[i]].pb(i); tn[B[i]].pb(i);
		tf[A[i]].pb(make_pair(i, v[B[i]]));
		tf[B[i]].pb(make_pair(i, v[A[i]]));
	}

	for(i = 0 ; i < k ; i++)
	{
		int cnt = v[i] - 1;
		int sum = 0;

		// sum 연산
		for(int x = v[i] ; x > 0 ; x -= x&-x) cnt -= d1[x];
		for(int x = k - v[i] + 1 ; x > 0 ; x -= x&-x) sum = (sum + d2[x])% mod;

		now = (now + (ll)cnt * f[k-i-1]) % mod;

		for(auto j : tn[i])
		{
			res[j] = (res[j] - (ll)cnt * f[k-i-1]) % mod;					
			res[j] = (res[j] - sum) % mod;
		}
		for(auto it : tf[i])
		{
			int j = it.first;
			int y = it.second;
			cnt = y-1;
			sum = 0;
			for(int x = y ; x > 0 ; x -= x&-x) cnt -= d1[x];
			for(int x = k - y + 1 ; x > 0 ; x -= x&-x) sum = (sum + d2[x]) % mod;
			res[j] = (res[j] + (ll)cnt * f[k-i-1]) % mod;
			res[j] = (res[j] + sum) % mod;
		}
		for(int x = v[i]; x<= k ; x += x&-x) d1[x] += 1; // update 1
		for(int x = k - v[i] + 1; x <= k ; x += x&-x) d2[x] = (d2[x] + f[k-i-1]) % mod;
	}

	for(int i = 0 ; i < n; i++)
	{
		res[i] = (res[i] + now) % mod;
		if(v[A[i]] < v[B[i]])
		{
			res[i] = (res[i] - f[k-A[i]-1]) % mod;
			res[i] = (res[i] + f[k-B[i]-1]) % mod;
		}
		if(res[i] < 0) res[i] += mod;
		cout<<res[i]<<newline;
	}
  return 0;
}
