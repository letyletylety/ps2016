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
	cin>>n>>m;
	vector<vector<int> > adj(n+1);
	vector<int> answer;
	vector<bool> visited(n+1, false);
	vector<int> indegree(n+1, 0);
	priority_queue<int, vector<int>, greater<int>> pq;

	// indegree small , number small
	for(int i = 0 ; i < m ; i++)
	{
		int from, to;
		cin>>from>>to;
		adj[from].pb(to);
		indegree[to]++;
	}

//	int f = 0;

	for(int i = 1; i <= n ; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		if(!indegree[i]) pq.push(i);
	}

	while(!pq.empty())
	{
		int here = pq.top(); pq.pop();
		answer.pb(here);	
		visited[here] = true;
		for(const int & there : adj[here])
		{
			if(visited[there]) continue;			

			indegree[there]--;

			if(!indegree[there])
			{
				pq.push(there);
			}
		}
	}
	
	for(int &ans : answer)
	{
		cout<<ans<<' ';
	}
	cout<<newline;
	return 0;
}
