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

const int N = 10000 + 123;

vector<vector<pair<int, int>>> graph;
int parent[N];
vector<pair<int, int> > d;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	int root;
	cin>>n;
	graph.resize(n+1);
	memset(parent, -1, sizeof(parent));
	for(int i = 0 ;i< n-1; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		parent[v] = u;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

	for(int i = 0 ;i < n ; i++)
		if(parent[i] == -1)
			root = i;

	int here = root;
	
	queue<pair<int, int> > pq;
	pq.emplace(0, here);

	pair<int, int> tt;
	while(!pq.empty())
	{
		tt = pq.front(); pq.pop();
		here = tt.yy;
		d.emplace_back(tt.xx, tt.yy);
		for(int i = 0 ; i < graph[here].size(); i++)
		{
			int there = graph[here][i].yy;
			int dist = graph[here][i].xx;
			if(parent[there] == here)
			{
				pq.push(make_pair(tt.xx + dist, there));
			}
		}
	}
//	cout<<"-------"<<newline;
	sort(d.rbegin(), d.rend());
//	for(auto it : d)
//		cout<<it.xx<< ' ' <<it.yy<<newline;
	root = d[0].yy;
//	cout<<root<<newline;
	d.clear();

	vector<int> visited(n + 1, -1);

	pq.push(make_pair(0, root));
	
	while(!pq.empty())
	{
		tt = pq.front(); pq.pop();
//		cout<<tt.xx<< ' '<<tt.yy<<newline;
		here = tt.yy;
		visited[here] = 1;
		d.emplace_back(tt.xx, tt.yy);
		for(int i = 0 ; i < graph[here].size(); i++)
		{
			int there = graph[here][i].yy;
			int dist = graph[here][i].xx;
			if(visited[there] == -1) 
			{
				pq.push(make_pair(tt.xx + dist, there));
			}
		}
	}
	sort(d.rbegin(), d.rend());
	cout<< d[0].xx<<newline;
  return 0;
}
