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

const int N = 32;
ll A[N] = {0,1};
/*
 * 2비트씩 묶어서 만들어줘야함....
 *
 */

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;

	for(int i =2 ; i < 32 ;i++)
	{
		A[i] = A[i-1] + 1LL + A[i-1];
	}

	cin>>n;
	while( n--)
	{
		cin>>s;	
		ll ans = 0LL;
		int len = s.size();	

		for(int i = 0 ;;)
		{
			for(; i< len ; i++) if(s[i] == '1') break; // 1번째 1비트 찾기
			
			if( i >= len ) break;
			
			s[i] = '0';
			ans += A[len - i - 1] + 1;
			for( i++ ; i < len ;i++) //  2번째 1비트 찾기
			{
				if(s[i] == '1') break;
				ans += A[len-i - 1] + 1;
			}
			s[i++] = '0';
		}
		cout<<ans<<newline;
	}
  return 0;
}
