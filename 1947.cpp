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
int d[1000001];
int main(int argc, char **argv)
{
	const int DIV = 1000000000;
	ios::sync_with_stdio(false);
	cin>>n;
	d[0] = 0;
	d[1] = 0;
	d[2] = 1;
	for(int i = 3; i<= n;i++)
	{
		d[i] = ((i-1) * (d[i-1] + d[i-2]) % DIV) %DIV;
	}
	cout<<d[n]<<newline;
  return 0;
}
