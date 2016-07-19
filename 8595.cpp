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

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int n;
	ll answer = 0;
	int temp = 0;
	int cnt = 0;
	char ch;
	cin>>n;
	string s;
	cin>>s;
	for(int i = 0 ; i < n ; i++)
	{
		ch = s[i];
		if( isdigit(ch) )
		{
			if(cnt == 0) // new hidden
			{
				cnt++;
				temp = ch -'0';
			}
			else if(cnt >= 1 && cnt < 6)
			{
				cnt++;
				temp *= 10;
				temp += ch-'0';
			}
			else{// cnt >= 6 
				cnt++;
				temp = 0;
			}
		}
		else
		{
			if(cnt == 0)
			{
				// do nothing	
			}
			else if(cnt >= 1 && cnt <= 6) // good
			{
				cnt = 0;	
				answer += temp;
				temp = 0;
			}
			else{ // cnt >= 6 
				cnt = 0;	
				temp = 0;
			}
		}
	}	

	if(cnt == 0)
	{
		// do nothing	
	}
	else if(cnt >= 1 && cnt <= 6) // good
	{
		cnt = 0;	
		answer += temp;
		temp = 0;
	}
	else{ // cnt >= 6 
		cnt = 0;	
		temp = 0;
	}

	cout<<answer<<newline;
  return 0;
}
