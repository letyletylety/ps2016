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

const int MAX_N = 1001;

int n = 1001;
bool isPrime[MAX_N];

void eratosthenes()
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(n));
	for(int i = 2; i <= sqrtn; i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i ; j <= n ;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	vector<int> primes;
	eratosthenes();
	for(int i = 0 ; i < MAX_N ; i++)
	{
		if(isPrime[i])
		primes.pb(i);
	}

	cin>>t;
	while(t--)
	{
		int K;
		int done = 0;
		cin>>K;
		for(int i = 0; i<primes.size() ;i++)
		{
			if(done) break;
			for(int j = i ; j < primes.size() ;j++)
			{
			if(done) break;
				for(int k = j ; k < primes.size(); k++)
				{
			if(done) break;
					if(primes[i] + primes[j] + primes[k] == K)
					{
						cout<<primes[i]<<' '<<primes[j]<<' '<<primes[k]<<newline;
						done = 1;
					}
				}
			}
		}

	}
  return 0;
}
