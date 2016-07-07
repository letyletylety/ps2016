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

using namespace std;

typedef unsigned ULL;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)

int n;
int m;

int d[10001]; // d[i] : i 원을 가지고 얻을 수 있는 최대 칼로리
int cal[5001];
int	mon[5001]; 
int td, ts;

int main(int argc, char **argv)
{
	while(true)
	{
		scanf("%d %d.%d", &n, &td, &ts);
		m = 100 * td + ts;
		if( n == 0 ) break;

		for(int i = 0 ; i< n  ;i++)
		{
			scanf("%d %d.%d", &cal[i], &td, &ts);
			mon[i] = td * 100 + ts;
		}

		memset(d, -1, sizeof(d));	
		d[0] = 0;

		for(int i = 0 ; i< n ; i++)
		{
			for(int j = mon[i] ; j <= m; j++)
			{
				if(d[j-mon[i]] != -1)	
					d[j] = max(d[j], d[j-mon[i]] + cal[i]);
			}
		}
		int answer = 0;
		for(int i = 0 ; i <= m ; i++)
		{
			answer = max(answer, d[i]);
		}
		cout<<answer<<newline;
	}
  return 0;
}
