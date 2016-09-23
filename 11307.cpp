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

vector<int> getPi(string p)
{
	int m = (int)p.size(), j = 0;
	vector<int> pi(m,0);
	for(int i = 1; i < m ;i++)
	{
		while(j > 0 && p[i] != p[j])
			j= pi[j-1];
		if(p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<bool> kmp(string s, string p)
{
	vector<bool> ret(s.size(), false);
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for(int i = 0 ; i < n ;i++)
	{
		while(j > 0 && s[i] != p[j])
			j = pi[j-1];
		if(s[i] == p[j])
		{
			if(j == m-1)
			{
				ret[i-m+1] = 1;
				j = pi[j];
			}
			else{
				j++;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string init, tar;
		cin>>init>>tar;
		int N = init.size();
		int M = tar.size();

		int play = init.size() - tar.size();
		int bob;
		if(play & 1)
			bob = play/2 + 1;
		else 
			bob = play>>1;

		bool alicewin = true;
		auto matched = kmp(init, tar);

		int cnt = 0;

		int right = N - bob - 1;

		for(int i = 0 ; i <= right ;i++)
		{
			if(matched[i])
			{
				if(i + M - 1 <= right)
					cnt++;
				else break;
			}
		}

		if(cnt == 0) { cout<<"Bob"<<newline; continue; }

		right++;
		for(int left = 1 ; left <= bob; left++, right++)
		{
			if(matched[left-1]) cnt--;
			if(matched[right - M + 1]) cnt++;
			if(cnt == 0){ alicewin = false; break;}
		}

		if(matched.size() == 0 || !alicewin)
			cout<<"Bob"<<newline;
		else
			cout<<"Alice"<<newline;
	}
  return 0;
}
