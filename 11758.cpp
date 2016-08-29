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


void getpoint(pair<int, int> &p)
{
	cin>>p.first>>p.second;
}

int crossproduct(pair<int, int> a, pair<int, int> b)
{
	int x1,y1, x2, y2;
	tie(x1,y1) = a;
	tie(x2, y2) = b;
//	cout<<x1<< ' '<<y1<< ' '<<x2<<' ' <<y2<<newline;
	return x1*y2 - x2*y1;
}

pii v2_sub(pii a, pii b)
{
	return make_pair(b.first - a.first , b.second - a.second);
}

void ccw(pair<int, int> a, pair<int, int> b)
{
	int t = crossproduct(a,b);	
	if(t > 0)
	{
		cout<< 1<<newline;
	}
	else
	{
		cout<< -(t < 0)<<newline;
	}
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<pii> points;
	points.resize(3);
	for(int i = 0 ; i < 3; i++)
	{
		getpoint(points[i]);
	}

	ccw(v2_sub(points[0], points[1]), v2_sub(points[0], points[2]));
  return 0;
}
