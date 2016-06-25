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

int arr[1001];
int d[300001];
const int MAXN(1000);

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	memset(d, -1, sizeof(d));
	int n;
	cin>>n;
	arr[0] = 1;	
	for(int i = 1 ; i <= MAXN ; i++)
	{
		arr[i] = i+1;
	}
	for(int i = 1;  i<= MAXN ;i++)
	{
		arr[i] = arr[i-1] + arr[i];
	}
	for(int i = 1; i <= MAXN ;i++)
	{
		arr[i] = arr[i-1] + arr[i];
	}
	d[0] = 0;
	for(int i = 0 ; i <= MAXN ;i++)
	{
		for(int j = arr[i] ; j <= n ; j++)
		{
			if(d[j] != -1)
				d[j] = min(d[j], d[j-arr[i]] + 1);
			else
				d[j] = d[j-arr[i]]+1;
		}
	}	
	/*
	forn(i,n)
		cout<<d[i]<<' ';
	cout<<newline;
	*/
	cout<<d[n]<<newline;
  return 0;
}
