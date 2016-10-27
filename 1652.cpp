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

const char newline = '\n';

ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	int hori, verti;
	char board[111][111];
	bool visited[111][111];
	vector<vector<int>> row(111);
	vector<vector<int>> col(111);

	memset(visited, false, sizeof(visited));
	hori = 0, verti = 0;
	cin>>n;
	
	for(int i = 0; i < 111; i++)
	{	
		row[i].pb(0);
		col[i].pb(0);
	}
	
	for(int i = 1 ;i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
		{
			cin>>board[i][j];
			if(board[i][j] == 'X')
			{
				row[i].pb(j);
				col[j].pb(i);
			}
		}

	for(int i = 0; i < 111; i++)
	{	
		row[i].pb(n+1);
		col[i].pb(n+1);
	}

	for(int i = 1 ; i <= n ;i++)
	{
		for(int j = 1; j < row[i].size() ; j++)
		{
			if(row[i][j] - row[i][j-1] > 2) hori++;
		}
	}

	for(int i = 1 ; i <= n ;i++)
	{
		for(int j = 1; j <col[i].size() ; j++)
		{
			if(col[i][j] - col[i][j-1] > 2) verti++;
		}
	}
	cout<<hori<<' '<<verti<<newline;
  return 0;
}
