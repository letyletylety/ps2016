#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int adj[51][51];

int main() {
	int n;
	scanf("%d",&n);
	int u,v;
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= n ;j++)
		{
			adj[i][j] = n;
		}
	}
	
	while(true)
	{
		scanf("%d%d",&u,&v);
		if(u == -1 && v == -1) break;
		adj[u][v] = adj[v][u] = 1;
	}
	
	for(int k = 1; k <= n ; k++)
	{
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j <= n  ;j++)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	

	
	vector<int> answer(n+1);
	vector<int> ghlwkd;
	answer[0] = 123456789;
	int score = 123456789;
	
	for(int i = 1;i<=n;i++)adj[i][i] = 0;
	for(int i= 1; i <=n ;i++)
	{
		answer[i] = 0;
		for(int j = 1; j<=n;j++)
		{
			answer[i] = max(answer[i], adj[i][j]);
		}
		score = min(score, answer[i]);
	}
	
//for(int i= 1; i <=n ;i++)
//{
//	for(int j = 1; j<=n;j++)
//	{
//		printf("%d ",adj[i][j]);
//	}
//	printf("\n");
//}
	
	for(int i = 1; i <=n;i++)
	{
		if(score == answer[i])
		{
			ghlwkd.push_back(i);
		}
	}
	
	printf("%d %d\n",score, ghlwkd.size());
	for(int i = 0 ; i < ghlwkd.size() ;i++)
	{
		printf("%d ",ghlwkd[i]);
	}
	return 0;
}
