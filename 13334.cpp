#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct rail
{
	int h;
	int o;
};

rail R[100001];

int main()
{
	int n;
	int L;
	scanf("%d",&n);
	for(int i = 0;i< n ; i++)
	{
		scanf("%d%d", &R[i].h,&R[i].o);	
		if(R[i].h > R[i].o) swap(R[i].h, R[i].o);
	}
	scanf("%d",&L);

	sort(R, R+n, [](const rail & a, const rail &b){return a.o < b.o;});

	priority_queue<int, vector<int> , greater<int> > max_heap;
	int answer = 0;

	for(int i = 0 ; i < n ; i++)
	{
		max_heap.push(R[i].h);
		while(!max_heap.empty() && max_heap.top() < R[i].o - L) max_heap.pop();
		answer = max(answer, (int)max_heap.size());
	}
	printf("%d\n", answer);
	return 0;
}
