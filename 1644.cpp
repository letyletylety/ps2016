#define _CRT_SECURE_NO_WARNINGS

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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

bool isPrime[4000010];
int canMake[4000010];
int primes[4000000];
int psize = 0;

void eratos()
{
	for(int i = 0 ; i <= 4000000 ;i++)
	{
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;
	for(int i = 2 ; i <= 4000000; i++)
	{
		if(isPrime[i] == true)
		{
			primes[psize++] = i;
			for(int j = i+i ; j <= 4000000 ;j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

// -------------------------- main

int main(int argc, char **argv)
{
	LL N;
	scanf("%lld",&N);
	eratos();
	
	int head = 0;
	int tail = 0;
	LL sum = primes[0];
	LL cnt = 0;
	
	while(tail <= head && head < psize)
	{
		if(N > sum)
		{
			sum += primes[++head];
		}
		else if(N < sum)
		{
			sum -= primes[tail++];
		}
		else
		{
			cnt++;
			sum -= primes[tail++];
		}
	}
	printf("%lld\n",cnt);

    return 0;
}
