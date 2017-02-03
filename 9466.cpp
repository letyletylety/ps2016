#include <iostream>
#include <memory.h>

using namespace std;

int a[100001];
bool visited[100001];
int indegree[100001];

int main()
{
	int tt;

	scanf("%d",&tt);

	while(tt--)
	{
		memset(visited, 0, sizeof(visited));
		memset(indegree, 0, sizeof(indegree));

		int n;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ;i++)
		{
			scanf("%d", a+i);
			indegree[a[i]]++;
		}

		int res = 0;
		int here = 0;
		for(int i = 1; i <= n ;i++)
		{
			here = i;	
			while(!indegree[here] && !visited[here])
			{
				visited[here] = true;
				here = a[here];
				indegree[here]--;
				res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
