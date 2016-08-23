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

const int INF = 123456789;

int n;
int board[20][20]; // i 번째에서 j번째를 가동하는 비용
int p;
unsigned state;

int d[100000];

int go(unsigned cur)
{
	int cnt = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if((cur & (1<<i)))
		{
			cnt++;	
		}
	}

//	cout<<"hey"<<' '<<cur<<' ' <<cnt<<newline;

	if(cnt >= p){
//		cout<<"escape"<<newline;
		return 0;
	}

	int &ret = d[cur];
	if( ret != -1 ) return ret;

	ret = INF;	

	forn(i,n)
	{
		if(cur & (1<<i))
		{
//			cout<<i<<'!'<<newline;
			forn(j,n)
			{
				if((cur & (1<<j)) == 0)
				{
//					cout<< i << ' ' << j <<newline;
					ret = min(ret, go( cur | (1<<j) ) + board[i][j] );
				}
			}
//			cout<<ret<<newline;
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;
	cin>>n;

	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n ; j++)
		{
			cin>>board[i][j];
		}
	}
	cin>>s;
	cin>>p;
	state = 0;
	
	for(int i = 0; i < s.size() ; i++)
	{
		if(s[i] == 'Y')
		{
			state |= (1<<(i));		
		}
	}

	memset(d, -1, sizeof(d));
	int answer = go(state);	

	if(state == 0u)
	{
		cout<<-1<<newline;
	}
	else cout<<answer<<newline;

  return 0;
}
