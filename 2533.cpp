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

using namespace std;

typedef unsigned ULL;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)

vector<VI> adj;
int cache[2][1000001];
int level[1000001];
int leaves[1000001];

int d(int early, int here)
{
	if(leaves[here] == true) return 0;
	int &ret = cache[early][here];
	if(ret != -1)return ret;
	ret = 0;
	if(early)
	{
		for(int i = 0 ; i < adj[here].size() ; i++)
		{
			int there = adj[here][i];
			if(level[there] > level[here])
			{
				ret += min(d(0, there), d(1, there) + 1); 
			}
		}
	}
	else
	{
		for(int i = 0 ; i < adj[here].size() ; i++)
		{
			int there = adj[here][i];
			if(level[there] > level[here])
			{
				ret += ( d(1, there) + 1 );
			}
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	adj.resize(n+1);
	memset(cache, -1, sizeof(cache));

	for(int i= 0 ; i< n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	// make tree
	level[1] = 1;
	queue<int> q;
	q.push(1);	

	while(!q.empty())
	{
		int here = q.front(); q.pop();
		int isLeaf = true;
		for(int i = 0 ; i < adj[here].size() ; i++)
		{
			int there = adj[here][i];
			if(level[there] == 0)
			{
				level[there] = level[here]+1;
				q.push(there);
				isLeaf = false;
			}
		}
		leaves[here] = isLeaf;
	}
	// done.
	cout<< min( d(0, 1), d(1, 1) + 1)<<newline;
  return 0;
}
