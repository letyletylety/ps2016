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

typedef vector<vector<long long> > matrix;
const long long mod = 1000000LL;
matrix operator * (const matrix &a, const matrix &b)
{
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for(int i  =0 ; i < n ; i++)
	{
		for(int j = 0;  j < n ;j++)
		{
			for(int k = 0 ; k < n ;k++)
			{
				c[i][j] +=a[i][k] *b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

// -------------------------- main

int main(int argc, char **argv)
{
	LL n;
	scanf("%lld",&n);
	if(n <= 1) printf("%lld\n",n);
	else
	{
		matrix ans = {{1,0},{0,1}}; // unit matrix
		matrix a = {{1,1},{1,0}};

		while(n > 0){
			if((n & 1) ==1)
			{
				ans = ans * a;
			}
			a = a*a;
			n>>=1;
		}
		printf("%lld\n",ans[0][1]);
	}
    return 0;
}
