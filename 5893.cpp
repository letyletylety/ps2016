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

string s1, s2;

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	cin>>s1;	
	s2 = "0000";
	
	s2.append(s1);
	s1.append("0000");

	int carry = 0;
	int sum;
	
//	cout<<' '<<s1<<"\n "<<s2<<newline;
	for(int i = s1.size()-1 ; i >= 0 ; i--)
	{
		int a = s1[i]-'0';
		int b = s2[i]-'0';
		sum = a + b + carry;
		if(sum >= 2)
		{
			carry = 1;
			sum -= 2;
		}
		else
		{
			carry = 0;
		}
		s1[i] = sum + '0';
	}
	if(carry)
	{
		cout<<1;
	}
	cout<<s1<<newline;
  return 0;
}
