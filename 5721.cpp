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

int cache[100001]; //  cache[i][j] : cache[i*m + j]
int board[100001];
int line[100001];
int n,m;

int go(int y, int x)
{		
	if(y >= n ) return 0;
	int &ret = cache[y * m + x];
	if(ret != -1) return ret;
	
	ret = 0;

	return ret = max( go(y+1, x) , go(y+2, x) + line[y]);
}

int go2(int y, int x)
{	
	if(x >= m) return 0;
	int &ret = cache[y * m + x];
	if(ret != -1) return ret;
	ret = 0;

	return ret = max( go2(y, x+1) , go2(y, x+2) + board[y * m + x]);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(true)
	{
		cin>>n>>m;
		if(n == 0 && m == 0) break;

		memset(cache, -1, sizeof(cache));
		for(int i = 0 ; i  < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				cin>>board[i * m + j];
			}
			line[i] = max(go2(i, 0), go2(i, 1));
//			cout<<i<<' ' <<line[i]<<newline;
		}	
		memset(cache, -1, sizeof(cache));
		cout<< max(max(go(1,1), go(0,1)), max( go(0, 0) , go(1, 0)))<<newline;
	}
  return 0;
}
