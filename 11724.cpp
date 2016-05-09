/* Lety */

#define _CRT_SECURE_NO_WARNINGS

#include		<cstdio>
#include		<cmath>
#include		<algorithm>
#include		<vector>
#include		<stack>
#include		<queue>
#include		<functional>
#include		<cstring>
#include		<string>
#include		<map>
#include		<set>
#include		<iostream>
#include		<tuple>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair
#define MT 		make_tuple
#define PB      push_back


using namespace std;

typedef long long		 ll;
typedef vector	<int>	 VI;


void bfs(vector<vector<int>> & adj, vector<bool> & checked, int i)
{
	queue<int> q;
	q.push(i);
	checked[i] = true;

	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int i = 0; i < adj[t].size(); i++)
		{
			int next = adj[t][i];
			if (!checked[next])
			{
				checked[next] = true;
				q.push(next);
			}
		}
	}	
}

int CountCC(vector<vector<int>> & adj)
{
	int n = adj.size();
	vector<bool> checked(n, false);
	int ret = 0;

	for (int i = 1; i < n ; i++)
	{
		if (!checked[i])
		{
			bfs(adj, checked, i);
			ret++;
		}
	}
	return ret;
}

int main(int argc, char **argv)
{
	/*int t;	for (scanf("%d", &t); t--;)
	{

	}*/
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> adj(n+1);
	int u, v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	printf("%d",CountCC(adj));


	return 0;
}

/* memo
*
*
*
*
*
*/