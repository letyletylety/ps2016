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
#include <climits>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef long double ld;

#define mod 1000000007

const char newline = '\n';

ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}


int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	int t;
	int A[300005];
	int S[300005];
	set<int> st;

	vector<int> point;
	vector<pair<int,int> > seg;

	map<int, int> mm;

	cin>>n>>m;
	for(int i = 0 ; i < n ; i++)
	{
		cin>>t;
		st.insert(t);
		point.pb(t);
	}
	for(int i = 0 ; i < m ; i++)
	{
		int a,b;
		cin>>a>>b;
		st.insert(a);
		st.insert(b);
		seg.pb({a,b});
	}

	int idx = 1;
	for(auto i : st)
	{
		mm[i] = idx++;
	}

	for(int i = 0 ; i < n ;i++)
	{
		A[mm[point[i]]] = 1;
	}
	S[0] = 0;
	for(int i = 1 ; i < 300001; i++)
	{
		S[i] = S[i-1] + A[i];
	}
	for(int i = 0 ; i < m ;i++)
	{
		cout<<S[mm[seg[i].se]] - S[mm[seg[i].fi] - 1]<<newline;
	}	
  return 0;
}
