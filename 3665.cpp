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
const int mod = 1000000007;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

int n;
VI past;
int m;
int adj[510][510]; // adj[u][v] = 1   ==>   u->v 인 edge가 존재

int fg; // back edge cycle;
int v[510];
int p;
int od[510];

void dfs(int a)
{
	if(v[a] == 1) fg = 1;
	if(v[a])return;

	v[a] = 1; // gray

	for(int i = 1; i <= n ; i++)
	{
		if(adj[a][i])
			dfs(i);
	}
	
	v[a] = 2; // black
	od[p] = a; p--;
}

void work()
{
	cin>>n;		
	past.resize(n);

	for(int i = 0 ; i < n ;i++)
	{
		cin>>past[i];
	}

	memset(adj, 0, sizeof(adj));

	for(int i = 0; i < n ; i++)
	{
		for(int j = i+1 ; j < n ;j++)
		{
			adj[past[i]][past[j]] = 1; // past[i] 가 past[j] 보다 앞섬
		}
	}

	cin>>m;
	forn(i,m)
	{
		int a,b;
		cin>>a>>b;
		adj[a][b] = 1 - adj[a][b];
		adj[b][a] = 1 - adj[b][a];
	}

	for(int i = 1 ; i <= n ; i++) v[i] = 0; // white;
	fg = 0; p = n-1;

	for(int i = 1 ; i <= n ;i++)
	{
		if(!v[i]) dfs(i);
	} 

	if(fg) // cycle
	{
		cout<<"IMPOSSIBLE"<<newline;
	}
	else
	{	
		for(int i = 0 ; i < n ; i++)
		{
			cout<<	od[i] <<' ';
		}
		cout<<newline;
	}
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		work();
  return 0;
}
