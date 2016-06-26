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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)

int n;
string paper, devil, angel;
int d[2][30][101];

int go(int side, int pi, int bi)
{
	if(pi == n) return 1; // paper end
	if(bi >= devil.size() ) return 0;	

	int &ret = d[side][pi][bi];
	if(ret!=-1)return ret;
	ret = 0;

	if(side == 0)
	{
		for(int i = bi ; i < devil.size() ; i++)
		{
			if(devil[i] == paper[pi]) 
			{
				ret+=go(1, pi+1, i+1);	
			}
		}
	}
	else // side == 1
	{
		for(int i = bi ; i < angel.size() ; i++)
		{
			if(angel[i] == paper[pi])
			{
				ret+=go(0,pi+1, i+1);
			}
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	memset(d, -1,sizeof(d));
	cin>>paper;
	n = paper.size();
	cin>>devil;
	cin>>angel;
	cout<< go(0, 0, 0) + go(1,0,0)<<newline;
  return 0;
}
