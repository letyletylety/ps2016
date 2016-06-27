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

int d[100001][5][5];
int v[100001];
int n;
int go(int idx, int l, int r)
{
	//cout<<idx<<  ' ' <<l << ' ' <<r <<newline;
	if(idx == n) return 0;
	int &ret = d[idx][l][r];
	if( ret != -1) return ret;

	ret = 123456789;
	// 발 밑에 있는 것들은 무조건 눌러야함
	if(v[idx] == l)
	{
		return ret = min(go( idx + 1, l, r) + 1, ret);
	}
	else	
	if(v[idx] == r)
	{
		return ret = min(ret, go(idx+1, l,r) +1);
	}

	//  v[idx] != l && v[idx] != r	
	if(l == 0)
	{
		ret = min(ret, go(idx+1, v[idx], r) + 2);
	}
	else
	if( abs(v[idx] - l) == 2 ) // opposite side
	{
		ret = min(ret, go(idx+1, v[idx], r) + 4);
	}
	else if(abs(v[idx] - l) == 1 || ( v[idx] == 4 && l == 1) || (v[idx] == 1 && l == 4)) // adjacent
	{
		ret = min(ret, go(idx+1, v[idx], r) + 3);
	}

	if(r == 0)
	{
		ret = min(ret, go(idx+1, l,v[idx]) + 2);
	}
	else
 	if(abs(v[idx] -r) == 2) // opposite
		ret = min(ret, go(idx+1, l, v[idx]) + 4);
	else if(abs(v[idx]-r) == 1 || ( v[idx] == 4 && r == 1) || ( v[idx] == 1 && r == 4))
		ret = min(ret, go(idx+1, l , v[idx]) + 3);

	return ret;
}
int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int *ptr = v;
	memset(d, -1, sizeof(d));
	int t;
	while(true)
	{
		cin>>t;
		if(t == 0) break;
		*ptr++ = t;
	}
	n = ptr - v;
	cout<<go(0,0,0)<<newline;
  return 0;
}
