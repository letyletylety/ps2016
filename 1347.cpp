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
const int INF = 987654321;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

char board[200][200];
bool row[200];
bool col[200];

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int sy; int sx;
	int dir = 3;
	sy = sx = 100;
	board[sy][sx] = '.';	
	row[sy] = 1;
	col[sx] = 1;

	forn(i,s.size())
	{
		if(s[i] == 'R')
		{
			if(dir == 0) dir = 2;	
			else if(dir == 2) dir = 3;
			else if(dir == 3) dir = 1;
			else if(dir == 1) dir = 0;
		}
		else if(s[i] == 'L')
		{
			if(dir == 0) dir = 1;	
			else if(dir == 2) dir = 0;
			else if(dir == 3) dir = 2;
			else if(dir == 1) dir = 3;
		}
		else
		{
			sy += dy[dir];
			sx += dx[dir];
			board[sy][sx] = '.';
			row[sy] = 1;
			col[sx] = 1;
		}
	}

	int ssy, ssx; 
	for(int i = 0 ; i < 200; i++)
	{
		for(int j = 0 ; j < 200 ;j++)
		{
			if(row[i] && col[j])
			{
				if(board[i][j])
				cout<<board[i][j];
				else cout<<'#';
			}
		}
		if(row[i])
			cout<<newline;
	}
  return 0;
}
