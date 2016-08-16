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

char board[6][100];
string s;

void deco(int i, char ch)
{
	int ceny = 2;	
	int cenx = 4*i + 2;
	
	board[ceny][cenx] = s[i];

	board[ceny-2][cenx] = board[ceny+2][cenx] = board[ceny-1][cenx-1] = board[ceny-1][cenx+1] = ch;
	board[ceny][cenx-2] = board[ceny][cenx+2] = ch;
	board[ceny+1][cenx+1] = board[ceny+1][cenx-1] = ch;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>s;
	for(int i = 0 ; i < 6; i ++)
	{
		forn(j, 100)
			board[i][j] = '.';
	}

	for(int i = 0 ; i< s.size() ; i++)
	{
		// Peter #
		deco(i, '#');
	}

	for(int i = 2 ; i < s.size() ; i+= 3)
	{
		deco(i, '*');
	}

	forn(i,5)
	{
		forn(j, 4*s.size() + 1)
		{
			cout<<board[i][j];
		}cout<<newline;
	}
  return 0;
}
