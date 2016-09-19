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

#define mod 100000007
#define newline '\n'
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	deque<char> dq;
	dq.push_back(s[0]);

	for(int i = 1 ; i < n ; i++)
	{
		while(!dq.empty() && (dq.back() < s[i]) && k)
		{
			dq.pop_back();
			k--;
		}
		dq.push_back(s[i]);
	}

	while(!dq.empty() && k)
	{
		dq.pop_back();
		k--;
	}	

	while(!dq.empty())
	{
		cout<<dq.front();
		dq.pop_front();
	}
	cout<<newline;
  return 0;
}
