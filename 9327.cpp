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
	int t;
	cin>>t;
	while(t--)
	{
		int n,e;	
		cin>>n>>e;
		vector<int> S(n);
		vector<int> d(200001, 0);
		d[0] = 1;

		if(e % 2 == 1)
		{
			e = e/2 + 1;
		}
		else
		{
			e = e/2;
		}

		for(int i = 0 ; i < n; i++)
		{
			cin>>S[i];
		}

		int answer = 1234567890;
		if(e == 0) answer = 0;

		int lim = 0;
		for(int & s : S)
		{
			for(int i = lim ; i >= 0; i--)
			{
				if(i + s <= 200000)
				{
					d[i+s] += d[i];
					if(d[i+s])
					{
						lim = max(lim, i+s);
						if(i+s >= e && answer > i+s)
							answer = i+s;
					}
				}
			}
		}

		if(answer == 1234567890)
			cout<<"FULL"<<newline;
		else cout<<answer<<newline;
	}
  return 0;
}
