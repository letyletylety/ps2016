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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)
int n,m;
int board[1001][1001];
int d[1001][1001][4];
int visited[1001][1001][4];

int go(int y,int x, int pd)
{
	if(y == n-1 && x == m-1)
		return board[y][x];
	
	int &ret = d[y][x][pd];
	if(visited[y][x][pd] == 1) return ret;
	visited[y][x][pd] = 1;
	ret = -123456789;
	for(int d = 1 ; d< 4; d++)
	{
		int ny = dy[d] + y;
		int nx = dx[d] + x;
		if(ny >= 0 && ny < n && nx >= 0 && nx < m && 3-pd != d)
		{
			ret = max(ret, go(ny, nx, d) + board[y][x]);
		}		
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(d, -1, sizeof(d));
	forn(i,n)
		forn(j,m)
			cin>>board[i][j];
	cout<<go(0,0,3);
  return 0;
}
