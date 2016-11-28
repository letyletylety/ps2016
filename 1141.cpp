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
#define FOR(i,n) for(int i = 0 ; i < (n) ; ++i)
#define SORT(v) sort((v).begin(), (v).end());
const char newline = '\n';

ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

bool isPrefix(string &a, string &b)
{
	if(a.size() > b.size())
	{
		return false;
	}

	assert(a.size() <= b.size());

	if(string(b.begin(), b.begin() + a.size()) == a)
	{
		return true;
	}
	return false;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	vector<string> a(n);
	vector<vector<int> > adj(n);
	for(int i = 0 ; i < n ; i++)
	{
		cin>>a[i];
	}

	sort(a.begin(), a.end());
	auto w = unique(a.begin(), a.end());

	n = w - a.begin();
//	cout<<n<<newline;
	for(int i = 0 ; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j) continue;
			if(isPrefix(a[i] , a[j]))
			{
				adj[i].push_back(j);	
//			cout<<i<< ' '<<j<<newline;
			}
		}
	}

	int answer = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(adj[i].size() == 0)
		{
			answer++;
		}
	}
	cout<<answer<<newline;
	return 0;
}
