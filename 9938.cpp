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

const int N = 300000 + 100;
int p[N], c[N]; // parent // charged

int find(int u)
{
	if(p[u] == u) return u;
	return p[u] = find(p[u]);
}

// u를 v의 후손으로 추가
void unite(int u, int v)
{
	p[find(u)] = find(v);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,l;
	cin>>n>>l;
	for(int i = 1 ; i <= l ; i++) p[i] = i;

	for(int i = 1 ; i <= n ; i++)
	{
		int a,b;
		cin>>a>>b;
		// 루트는 항상 먹을수 있게 비워둔다
		// 못먹으면 마셔야지
		if(!c[a])
		{
			c[a] = 1;
			unite(find(a), find(b));
		}
		else if(!c[b])
		{
			c[b] = 1;
			unite(find(b), find(a));
		}
		else if(!c[find(a)])
		{
			c[find(a)] = 1;
			unite(find(a), find(b));
		}
		else if(!c[find(b)])
		{
			c[find(b)] = 1;
			unite(find(b), find(a));
		}
		else
		{
			cout<<"SMECE\n";
			continue;
		}
		cout<<"LADICA\n";
	}	
	
//	for(int i = 1; i <= l ; i++)
//		cout<<find(i)<< ' ';

  return 0;
}
