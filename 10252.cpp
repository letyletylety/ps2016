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

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		cout<<1<<newline;	
		if(m % 2 == 0)
		{
			for(int i = 0 ; i < m ; i++)
			{
				cout<<'('<<i<<','<<0<<')'<<newline;
			}
			for(int i = m - 1 ; i >= 0 ; i--)
			{
				if(i % 2 == 1)
				{
					for(int j = 1 ; j < n ; j++)
					{
						cout<<'('<<i<<','<<j<<')'<<newline;
					}
				}
				else
				{
					for(int j = n-1 ; j >=1 ; j--)
					{
						cout<<'('<<i<<','<<j<<')'<<newline;
					}
				}
			}
		}
		else if(n % 2 == 0)
		{
			for(int i = 0 ; i < n ; i++)
			{
				cout<<'('<<0<<','<<i<<')'<<newline;
			}
			for(int i = n - 1 ; i >= 0 ; i--)
			{
				if(i % 2 == 1)
				{
					for(int j = 1 ; j < m ; j++)
					{
						cout<<'('<<j<<','<<i<<')'<<newline;
					}
				}
				else
				{
					for(int j = m-1 ; j >=1 ; j--)
					{
						cout<<'('<<j<<','<<i<<')'<<newline;
					}
				}
			}
		}
		else{
			for(int i = 0 ; i < n ; i++)
			{
				if(i % 2 == 0)
				{
					for(int j = 0 ; j < m-1; j++)	
						cout<<'('<<j<<','<<i<<')'<<newline;
				}
				else
				{	
					for(int j = m-2; j >= 0; j--)	
						cout<<'('<<j<<','<<i<<')'<<newline;
				}
			}
			for(int i = n-1; i>= 0 ;i--)
			{	
				cout<<'('<<m-1<<','<<i<<')'<<newline;
			}
		}
	}
  return 0;
}
