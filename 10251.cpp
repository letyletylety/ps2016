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

const int N = 101;
int d[N][N][N+N][2];
int garo[N][N];
int sero[N][N];

int m,n,l,g;

int dp(int y, int x, int cnt, int dir)
{
	if(y == m-1 && x == n-1)
	{
		return 0;
	}

	int &ret = d[y][x][cnt][dir];
	if(ret != -1) return ret;

	ret = INF;
	if(y == m-1)
	{
		// 0 				
		if(dir == 0)
		{
			if(cnt)
				ret = min(ret, dp( y , x + 1 , cnt-1, 1) + garo[y][x]);
			else
				ret = INF;
		}	
		else
		{
			ret = min(ret, dp(y, x+ 1, cnt, 1) + garo[y][x]);	
		}
	}
	else if(x == n-1)
	{
		// 1
		if(dir == 1)
		{
			if(cnt)
				ret = min(ret, dp( y + 1, x , cnt-1 , 0) + sero[y][x]);	
			else
				ret = INF;
		}
		else
		{
			ret = min(ret, dp(y+1, x, cnt, 0) + sero[y][x]);
		}
	}
	else
	{
		if(dir == 1)
		{
			if(cnt)
				ret = min(ret, dp(y+1, x, cnt - 1, 0) + sero[y][x]);
			ret = min(ret, dp(y, x+1, cnt, 1) + garo[y][x]);
		}
		else{
			if(cnt)
				ret =  min(ret, dp(y, x+1, cnt-1, 1)  + garo[y][x]);
			ret = min(ret, dp(y+1, x, cnt, 0) + sero[y][x]);
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(d, -1, sizeof(d));
		cin>>m>>n>>l>>g;
		for(int i = 0 ; i < m ; i++)
		{
			for(int j = 0; j < n -1 ; j++)
			{
				cin>>garo[i][j];
			}
		}
		for(int i = 0 ; i < m - 1; i++)
		{
			for(int j = 0 ; j < n ; j++)
			{
				cin>>sero[i][j];
			}
		}

		bool solve = false;
		for(int i = 1; i <= m + n - 1; i++)
		{
			dp(1,0,i,0);
			dp(0,1,i,1);
			if( g >= min(d[1][0][i][0] + sero[0][0] , d[0][1][i][1] + garo[0][0]))
			{
				solve = 1;	
				cout<<((m+n-2) * l + i)<<newline;
				break;
			}
		}
		if(!solve) cout<<-1<<newline;
	}
  return 0;
}
