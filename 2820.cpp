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

const int NN = 500001;
const int NM = 500001;

vector<vector<int> > adj;

ll salary[NN];
int level[NN];
int endlev[NN];
int lev;

class BIT
{
	public:
		vector<ll> T; // tree 
		int S;  // size

		BIT(const int n)
		{
			S = n;
			T.resize(S+1);
		}
		void Update(int p, int v)
		{
			while(p <= S)
			{
				T[p] += v;
				p+= p & (-p);
			}
		}

		ll Sum(int p){
			ll ret = 0;
			while(p > 0)
			{
				ret += T[p];
				p -= p & (-p);
			}
			return ret;
		}
};

void dfs(int here)
{
	level[here] = ++lev;
	for(auto there : adj[here])
		dfs(there);
	endlev[here] = lev;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	int here;
	cin>>n>>m;
	cin>>salary[1];
	adj.resize(n+1);
	for(int i = 2; i <= n ;i++)
	{
		int tt;
		cin>>salary[i]>>tt;
		adj[tt].pb(i);
	}
	dfs(1);
	BIT tree(n);

	for(int i = 0 ; i< m ; i++)
	{
		char op;
		cin>>op;
		cin>>here;	

		if(op == 'u')
		{
			cout<<salary[here] + tree.Sum(level[here]-1)<<newline;
		}
		else
		{
			int tt;
			cin>>tt;
			tree.Update(level[here], tt);
			tree.Update(endlev[here], -tt);
		}
	}
  return 0;
}
