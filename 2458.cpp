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

int adj[501][501];
int bdj[501][501];

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int m;
	cin>>m;
	
	memset(adj, 1, sizeof(adj));
	memset(bdj,1, sizeof(bdj));
	for(int i = 0 ;i < m  ;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u][v] = 1;
		bdj[v][u] = 1;
	}
	for(int i = 1; i <= n;i++){ adj[i][i] = 0; bdj[i][i] = 0;}

	for(int k = 1; k<=n;k++)
	{
		for(int i = 1;  i<= n ;i++)
		{
			for(int j = 1; j <= n ;j++)
			{
				adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
				bdj[i][j] = min(bdj[i][j] , bdj[i][k] + bdj[k][j]);
			}	
		}
	}
/*	
		for(int i = 1;  i<= n ;i++)
		{
			for(int j = 1; j <= n ;j++)
			{
				cout<<adj[i][j]<<' ';				
			}	
			cout<<newline;
		}

	cout<<newline;
		for(int i = 1;  i<= n ;i++)
		{
			for(int j = 1; j <= n ;j++)
			{
				cout<<bdj[i][j]<<' ';				
			}	
			cout<<newline;
		}
*/


	int answer = 0;
	for(int i =1 ; i <= n ;i++)
	{
		bool noh = true;

		for(int j = 1; j <= n ;j++)
		{
			if(adj[i][j] == 16843009 && bdj[i][j] == 16843009)	
			{
				noh = false;
			}
		}
		if(noh) answer++;
	}
	cout<<answer;
  return 0;
}
