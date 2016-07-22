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

int v,e;
int adj[401][401];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin>>v>>e;
	memset(adj, 1, sizeof(adj));

	forn(i,e)
	{
		int a,b,w;
		cin>>a>>b>>w;
		adj[a][b] = w;
	}
	
//	for(int i =1 ; i <=v;i++)
//		adj[i][i] = 0;

	for(int k= 1; k <= v; k++)
	{
		for(int i = 1; i <=v ;i++)
		{
			for(int j =1 ; j<= v; j++)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	int answer = adj[1][1];
//	cout<<adj[1][1]<<newline;
	for(int i = 1; i<=v ;i++)
	{
		answer = min(answer, adj[i][i]);
	}
	if(answer == 16843009)
		cout<<-1<<newline;
	else
		cout<<answer<<newline;
  return 0;
}
