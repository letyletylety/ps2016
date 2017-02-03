#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int tt[1001];
vector<int> adj[1001];

int main()
{
	int n,p;
	scanf("%d%d",&n,&p);

	for(int i =  0 ; i < p ; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int answer = 1e3+1;

	for(int i  = 0 ; i < n ; i++)
	{
		memset(tt, 0, sizeof(tt));
		int j = i;
		int ss = 0;
		int cnt = 0;
		do
		{
			for(auto &there : adj[j])
			{
				tt[j]++;
				tt[there] -= 2;
			}
			ss += tt[j];
			cnt += ss > 0;
		}while((j = (j+1)%n) != i);
		answer = min(answer,cnt);
	}
	printf("%d", answer);
	return 0;
}
