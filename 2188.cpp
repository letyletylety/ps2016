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
#define first xx
#define second yy
const int mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

const int MAX_V = 1000;
const int INF = 987654321;
int V;

int capacity[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int networkFlow(int source, int sink)
{
	memset(flow, 0, sizeof(flow) );
	int totalFlow= 0;
	while(true)
	{
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1)
		{
			int here = q.front(); q.pop();
			for(int there = 0; there < V; ++there)
			{
				if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1)
				{
					q.push(there);
					parent[there] = here;
				}
			}
		}
		if(parent[sink] == -1) break;
		int amount = INF;
		for(int p = sink ; p != source ; p = parent[p])
		{
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		}
		for(int p = sink ; p != source ; p = parent[p])
		{
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin>>n>>m;
	V = n+ m + 2;
	for(int i = 1; i <= n ;i++)
	{
		capacity[0][i] = 1;
	}
	for(int i = n + 1	; i <= n+m; i++)
	{
		capacity[i][n+m+1] = 1;
	}

	for(int i = 1; i <= n ;i++)
	{
		int t;	
		cin>>t;
		while(t--)
		{
			int tt;
			cin>>tt;
			capacity[i][n + tt] = 1234;
		}
	}	
	cout<<networkFlow(0, n+m+1)<<newline;
  return 0	;
}
