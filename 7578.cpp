#include <cstdio>
#include <map>
using namespace std;

using ll = long long;

int a[500001];
int pos[1000001];
ll tree[4000001];

void update(int idx, int val, int node, int nl, int nr)
{
	if(idx < nl || nr < idx) return;

	if(nl == nr)
	{
		tree[node] += val;
	}	
	else
	{
		int nn = node <<1;
		update(idx, val, nn, nl, (nl+nr)>>1);
		update(idx, val, 1+nn, 1+((nl+nr)>>1), nr);
		tree[node] = tree[nn] + tree[nn+1];
	}	
}

ll query(int l, int r, int node, int nl, int nr)
{
	if(r < nl || nr < l) return 0LL;

	if(l <= nl && nr <= r)
	{
		return tree[node];
	}

	int nn = node<<1;
	int mid = (nl + nr) >>1;
	return query(l, r, nn, nl, mid) + query(l, r, nn+1, mid+1, nr);
}

int main()
{
	int n;
	scanf("%d",&n);

	for(int i = 1 ; i <= n  ;i++)
	{
		scanf("%d", a+i);
	}

	int tt;
	for(int i = 1 ; i <= n  ;i++)
	{
		scanf("%d", &tt);
		pos[tt] = i;	
	}

	ll answer =0;

	for(int i = 1 ; i <= n ; i++)
	{
		answer += query(pos[a[i]], n,  1, 1, n);
		update(pos[a[i]], 1, 1, 1, n);
	}
	printf("%lld", answer);
	return 0;
}
