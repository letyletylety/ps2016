#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory.h>
#include <map>
using namespace std;

int pos[75001];
int tree[300001];

void update(int idx, int val, int node, int nl, int nr)
{
	if(idx < nl || nr < idx) return;

	if(nl == nr)
	{
		tree[node] += val;
	}
	else
	{
		int mid = (nl + nr) >>1;
		int nn = node + node;
		update(idx, val, nn, nl, mid);
		update(idx, val, 1+nn, mid+1, nr);
		tree[node] = tree[nn] + tree[nn+1];
	}
}

int query(int l, int r, int node, int nl, int nr)
{
	if(r < nl || nr < l) return 0;

	if(l <= nl && nr <= r) return tree[node];

	int mid = (nl + nr) >>1;
	int nn = node + node;
	return query(l, r, nn, nl, mid) + query(l, r, nn+1, mid+1, nr);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		vector<pair<int, int> > P;
		scanf("%d",&n);
		P.resize(n);
		memset(pos, 0, sizeof(pos));
		memset(tree, 0, sizeof(tree));

		for(int i = 0 ; i < n ;i++)
		{
			scanf("%d%d", &P[i].first, &P[i].second);
			P[i].second *= -1;
			pos[i] = P[i].second;
		}

		sort(P.begin(), P.end());

		int answer = 0;
		for(int i=  0 ; i < n ; i++)
		{
			int yy = lower_bound(pos, pos+n, P[i].second) - pos;
			answer += query(0, yy, 1, 0, n-1);	
			update(yy, 1, 1, 0, n-1);
		}
		printf("%d\n", answer);
	}
	return 0;
}

