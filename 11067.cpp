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
#define xx first
#define yy second
const int mod = 1000000007;
const int INF = 987654321;
ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

const int N = 100000 + 10;
vector<vector<int> > vv; 
vector<pair<int, int> > mm;
int max_x;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		mm.resize(N);
		vv.resize(N);

		forn(i,N)
			vv[i].clear();
//		max_x = 0;

		forn(i,n)
		{
			int x,y;
			cin>>x>>y;
			vv[x].pb(y);
//		max_x = max(max_x, x);
		}
//		cout<<"yes"<<newline;

//	for(int x = 0 ; x <= max_x; x++)
		for(int x = 0 ; x <= N; x++)
		{
			if(vv[x].size())
			{
				sort(vv[x].begin(), vv[x].end());
			}
		}	

//		cout<<"yes"<<newline;
		int cnt = 1;	
		int here = 0;
		for(int x = 0 ; x <= N ; x++)
		{
			if(vv[x].empty()) continue; // x 좌표 정렬해두고 더 ㅂ빠르게 할수있음
//			cout<<"Y"<<newline;
			if(here == vv[x][0])
			{
//				cout<<"!";
				for(int i = 0 ; i < vv[x].size(); i++)
				{
					here = vv[x][i];
					mm[cnt++] = make_pair(x,here);
//					mm[make_pair(x, here)] = cnt++;
				}
			}
			else
			{
//				cout<<"!";
				for(int i = vv[x].size() - 1 ; i >= 0 ;i--)
				{
					here = vv[x][i];
					mm[cnt++] = make_pair(x, here);
//				mm[make_pair(x, here)] = cnt++;
				}
			}
//			cout<<here<<' ';
		}
//		cout<<"yes"<<newline;
		int m;
		cin>>m;
		forn(i,m)
		{
			int t;
			cin>>t;		
			cout<<mm[t].xx<< ' ' <<mm[t].yy<<newline;
		}
	}
  return 0;
}
