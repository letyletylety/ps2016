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

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	int n;
	int answer = 0;
	int t;
	int a,b;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin>>n;
	for(int i= 0; i < n;i++)
	{
		cin>>t;
		pq.push(t);
	}
	
	while(pq.size() > 1)
	{
		t =  pq.top();
		pq.pop();
		t += pq.top();
		pq.pop();
		answer += t;
		pq.push(t);
	}
	cout<<answer<<newline;
  return 0;
}
