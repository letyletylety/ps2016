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
#define xx first
#define yy second
const int mod = 1000000007;
const int INF = 987654321;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

const int N = 16;

int n;
char board[N][N];
int d[1<<16][N][10];
int answer = -1;

int dp( unsigned mask, int here, int price)
{
	int & ret = d[mask][here][price]; 
	if(ret != -1) return ret;

	ret = 1;
	for(int i = 0 ; i < n ; i++)
	{
		if( (mask & (1 << i)) ) continue;

		int t = board[here][i];			
		if(t >= price)
		{
			ret = max(ret , dp((mask | (1 << i)), i, t) + 1);
		}
	}
	return ret;	
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	forn(i,n)
		forn(j,n)
			cin>>board[i][j];		
	memset(d, -1, sizeof(d));	

	cout<<	dp( (1<<0) , 0, 0 ) << newline;

  return 0;
}
