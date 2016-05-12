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

int a[500001];
int b[500001];
int pa[500001];
int pb[500001];

// -------------------------- main

int main(int argc, char **argv)
{
	int n,h;
	scanf("%d%d",&n,&h);
	for(int i = 0 ; i < n/2; i++)
	{
		int ta, tb;
		scanf("%d%d",&ta,&tb);
		a[ta]++;
		b[h-tb]++;	
	}	
	pa[h] = a[h];
	for(int i = h-1 ; i >= 1 ; i--)
	{
		pa[i] = pa[i+1] + a[i];	
	}
	pb[0] = b[0];
	for(int i = 1; i < h ;i++)
	{
		pb[i] = pb[i-1] + b[i];
    }
	for(int i = 1 ; i <= h ;i++)
	{
		pb[i-1] += pa[i];
		//printf("%d//",pb[i-1]);
	}
	sort(pb, pb+h);

	int me = *min_element(pb, pb+h);
	int answer = count(pb, pb+h, me);
	printf("%d %d",me,answer);
	return 0;
}
