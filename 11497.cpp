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
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i = 0 ; i < n ; i++)
		{
			cin>>a[i];				
		}
		sort(a.begin(), a.end());
		deque<int> dq;

		if(n % 2 == 0)
		{
			for(int i = 0 ; i < n ; i+=2)
			{
				dq.push_back(a[i]);
				dq.push_front(a[i+1]);
			}	
		}
		else
		{
			for(int i = 0 ; i < n-2 ; i+=2)
			{
				dq.push_back(a[i]);
				dq.push_front(a[i+1]);
			}	
			dq.push_back(a[n-1]);
		}

		int answer = abs(dq.front() - dq.back());
		for(int i = 1 ; i < n; i++)
		{
			answer = max(answer, abs(dq[i] - dq[i-1]));
		}
		cout<<answer<<newline;
	}
  return 0;
}
