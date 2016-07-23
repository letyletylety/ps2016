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

int sudoku[10][10];
vector<pii> toFill;

bool fitrow(int r, int c, int n)
{
	for(int i = 0; i < 9 ;i++)
	{
		if(	sudoku[r][i] == n )
			return false;
	}
	return true;
}

bool fitcol(int r, int c, int n )
{
	for(int i = 0; i < 9 ;i++)
	{
		if(	sudoku[i][c] == n )
			return false;
	}
	return true;
}

bool fitblock(int r, int c, int n)
{
	int sy = r/3 * 3;
	int sx = c/3 * 3;

	for(int i = sy; i < sy+3; i ++)
	{
		for(int j = sx ;j < sx+3 ; j++)
		{
			if(sudoku[i][j] == n)		
				return false;
		}
	}
	return true;
}

bool isfit(int r, int c, int n)
{	
	return fitblock(r,c,n) && fitcol(r,c,n) && fitrow(r,c,n);
}

void fill(int idx)
{	
	if(idx == toFill.size()) // done
	{
		forn(i,9)
		{
			forn(j,9)
			{
				cout<<sudoku[i][j] <<' ';
			}
			cout<<newline;
		}
		return;
	}	

	int y,x;
	y = toFill[idx].first;
	x = toFill[idx].second;
	for(int i = 1; i <= 9; i++)
	{
		if(isfit(y,x,i))
		{
			//cout<<y<<' '<<x<<' ' <<i<<newline;
			sudoku[y][x] = i;
			fill(idx+1);
			sudoku[y][x] = 0;
		}
	}
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);

	forn(i,9) forn(j,9) {cin>>sudoku[i][j]; if(!sudoku[i][j]) toFill.pb(make_pair(i,j));}

 // backtracking!!	
	fill(0);	

  return 0;
}
