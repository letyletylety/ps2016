#define _CRT_SECURE_NO_WARNINGS

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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const char newline = '\n';

#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)

int v,e;
vector<vector<int> > adj;
int depth[20001];

void dfs(int node, int d)
{
	if(depth[node] != -1)
	{
		return;
	}

	depth[node] = d;
	for(int i = 0 ; i < adj[node].size() ;i++)
	{
		int there = adj[node][i];
		dfs(there, d+1);
	}
}

void  input()
{
	adj.clear();
	cin>>v>>e;
	adj.clear();
	adj.resize(v+1);
	forn(i,e)
	{
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}			
}

void process()
{
	memset(depth, -1, sizeof(depth));
	for(int i = 1; i <= v; i++)
		dfs(i, 0);	
}

void output()
{
	bool result = true;
	for(int i =1 ; i <= v; i++)
	{
		for(int j = 0 ; j < adj[i].size() ; j++)
		{
			if(depth[i]%2 == depth[adj[i][j]]%2)
			{
				result = false;
			//	break;
			}
		}
	}
	cout<<(result?"YES":"NO")<<newline;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		input();
		process();
		output();
	}
  return 0;
}
