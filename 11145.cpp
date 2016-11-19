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

void F()
{
	puts("invalid input");
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	char s[200];	
	int i,j,t;	
	fgets(s, 200, stdin);
	sscanf(s, "%d", &t);
	while(t--)
	{
		bool f = false;
		fgets(s, 200, stdin);
		i = 0;
		j = strlen(s);
		while( i < j && isspace(s[i])) i++; // delete leading space
		while( j > i && isspace(s[j-1])) s[--j] = 0; // delete following space
		for(int k = i ; k < j ; k++)
		{
			if(!isdigit(s[k])) //  if there is any char except digit -> F
			{
				f = 1;
				break;
			}
		}
		if(i == j)  // if string empty --> F
		{	
			f = 1;
		}

		if(f) 
		{
			F();
			continue;
		}

		while(i<j-1 && s[i] =='0') i++;
		puts((s+i));
	}
  return 0;
}
