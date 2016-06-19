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

int n;
int v[100001];
vector<pair<int, LL>> adj[100001];
int answer;

void dfs(int node, LL d)
{
	if(d > v[node])
		return;
	answer++;
	for(int i =0 ; i < adj[node].size() ;i++)
	{
		dfs(adj[node][i].first, max(d + adj[node][i].second, 0LL));
	}
}

void  input()
{
	for(int i = 1; i <= n ; i++)
	{
		cin>>v[i];	
	}
	for(int i = 2; i <= n ;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].pb(make_pair(i,b));
	}	
}

void process()
{
	dfs(1,0LL);
}

void output()
{
	cout<<n-answer<<newline;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		input();
		process();
		output();
	}
	return 0;
}
