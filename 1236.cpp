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

const int N =51;
char board[N][N];
bool row[N], col[N];
int r,c;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i =  0; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			cin>>board[i][j];
			if(board[i][j] == 'X'){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i = 0 ; i < n ; i++)
		if(row[i] == 0)
			r++;

	for(int j = 0 ;j < m ;j++)
		if(col[j] == 0)
			c++;

	int answer = max(r,c);
	cout<<answer<<newline;
  return 0;
}
