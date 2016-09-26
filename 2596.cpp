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

string encode[8] = 
{
	"000000", "001111","010011", "011100", "100110" , "101001","110101","111010"
};


int find_code(string s)
{
	int ret = 0;
	for(ret = 0; ret <8 ; ret++)
	{
		int cnt = 0;
		for(int i = 0 ; i <6 ; i++)
		{
			if(encode[ret][i] != s[i])
			{
				cnt++;		
			}
		}
		if(cnt <= 1) return ret;
	}
	return 8;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	string s;
	string answer;
	cin>>n;
	cin>>s;

	int start = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int cd = find_code(s.substr(	start, 6 ));
		if(cd == 8)
		{
			cout<<i+1<<newline;
			return 0;
		}
		else
			answer.pb(cd + 'A');
		start += 6;
	}
	cout<<answer<<newline;
  return 0;
}
