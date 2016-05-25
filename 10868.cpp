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


// -------------------------- main
int n,m;
int t1, t2;
int a[100011];
int tree[400010];

void init(int node, int start, int end)
{
	if(start == end) tree[node] = a[start];
	else
	{
		init(node * 2, start, (start+end)/2);
		init(node * 2 + 1, (start+end)/2 + 1, end);
		tree[node] = min(tree[node*2], tree[node*2+1]);
	}	
}

int  query(int node, int start, int end, int i, int j) // i~j 구간의 최소값을 구할 때...
{
	if(i > end || j < start) return -1; // 구간을 벗어나는 쿼리는 바로 리턴
	if(i <= start && end <= j) return tree[node];  // 구간이 쿼리 구간에 완전히 포함

	int m1 = query(2 * node, start, (start+end)/2, i,j);
	int m2 = query(2 * node + 1, (start+end)/2+1, end, i,j);

	if(m1 == -1)return m2;
	else if(m2 == -1) return m1;
	else return min(m1,m2);
}

int main(int argc, char **argv)
{
	scanf("%d%d",&n,&m);
	for(int i = 1; i<=n ;i++)
	{
		scanf("%d",&a[i]);
	}
	init(1, 1, n);
	for(int i = 0; i < m ; i++)
	{
		scanf("%d%d",&t1,&t2);
		printf("%d\n",query(1, 1, n, t1, t2));	
	}
    return 0;
}
