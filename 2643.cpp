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

const int N = 120;

int n;
vector<pair<int, int> > paper;
vector<vector<int> > g;
int memo[N];

int dfs(int here)
{
	if(memo[here] != -1) return memo[here];

	int &ret = memo[here];
	ret = 1;

	for(int i = 0 ; i < g[here].size() ; i++)
	{
		ret = max(ret , dfs(g[here][i]) + 1);
	}	
	return ret;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	g.resize(n);

	for(int i = 0 ; i < n ;i++)
	{
		int a,b;
		cin>>a>>b;
		paper.pb({min(a,b), max(a,b)});
	}
	sort(paper.begin(), paper.end());

//	for(auto i : paper) 
//		cout<<i.fi<< ' '<<i.se<<newline;
//	cout<<newline;
	for(int i = 0 ; i <n  ;i++)
	{
		for(int j = i+1 ; j< n ;j++)
		{
			if( paper[i].se <= paper[j].se)
				g[i].pb(j);	
		}
	}
//	cout<<"YES"<<newline;
	int answer = 0;
	memset( memo, -1, sizeof(memo));
	for(int i = 0 ; i < n ;i++)
	{
//	memset(chk, 0, sizeof(chk));
		int t;
		t = dfs(i);
//		cout<<i<< ' ' <<t<<newline;
		answer = max(answer, t);
	}	
	cout<<answer<<newline;
  return 0;
}
