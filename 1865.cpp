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
const int INF = 123456789;
const char newline = '\n';

ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

int n;
vector<int> start;

int BellmanFord(vector<tuple<int, int, int> > & E, int start)
{
	// BellmanFord algorithm only for checking the existence of negative
	// weight cycle
	
	// init
	vector<int> dist(n+1, INF); 
	dist[start] = 0; 
	// init end;
	//
	int u,v,w;
	bool negcyc = false;
	for(int i =1; i <= n ;i++)
	{
		for(auto &edge : E) 
		{
			tie(u,v,w) = edge;
			if(dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				if(i == n)
				{
					return -1;
				}
			}
		}
	}
	return 1;
}

bool canTimeLeap(vector<tuple<int,int,int> > & E) 
{
	for(int & t : start)
	{
		if(BellmanFord(E, t) == -1) return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		vector<tuple<int, int, int> > E;
		int m,w;
		cin>>n>>m>>w;
		for(int i = 0 ; i < m ; i++) // road
		{
			int s,e,t;
			cin>>s>>e>>t;
			E.pb(make_tuple(s,e,t));
			E.pb(make_tuple(e,s,t));
		}
		for(int i = 0 ; i < w; i++)
		{
			int s,e,t;
			cin>>s>>e>>t;
			E.pb(make_tuple(s,e,-t));
			start.pb(e);
		}
		cout<<(canTimeLeap(E) ? "YES" : "NO")<<newline;
	}
  return 0;
}
