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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- main
int zerocnt[1000001];

int main(int argc, char **argv)
{
	int t;
	zerocnt[0] = 1;
	for(int i = 1; i < 1000001; i++)
	{
		int f = zerocnt[i-1];
		int x = i;	
		while(x>0)
		{
			if(x%10 == 0)f++;
			x/=10;		
		}
		zerocnt[i] = f;
	}	

	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",zerocnt[m] - (n==0?0:zerocnt[n-1]));
			
	}
    return 0;
}
