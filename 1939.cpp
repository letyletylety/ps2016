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

vector<vector<pair<int, ll> > > adj;
int n,m;
int s, e;

bool bfs(ll muge)
{
	queue<int> q;
	q.push(s);
	vector<int> visited(n+1, 0);
	bool good = false;

	while(!q.empty())
	{
		int here;
		here = q.front();
		q.pop();
		visited[here] = 1;

		if(here == e){ good = true; return good; }

		for(int i  =0 ; i < adj[here].size(); i++)
		{
			if(!visited[adj[here][i].xx] && adj[here][i].yy >= muge)
			{
				q.push(adj[here][i].xx);
			}
		}
	}
	return good;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	adj.resize(n+1);	

	for(int i = 0 ; i<  m; i++)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		adj[u].pb(make_pair(v,w));
		adj[v].pb(make_pair(u,w));
	}
	ll answer;
	cin>>s>>e;

	ll left = 1LL;
	ll right = 1e10;
	while(left <= right)
	{
		ll mid = (left + right) >>1;
		if(bfs(mid))
		{
			left = mid + 1;
			answer = mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout<<answer<<newline;
  return 0;
}
