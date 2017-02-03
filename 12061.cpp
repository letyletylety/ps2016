#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

using ll = long long;

struct Work
{
	ll val;
	int idx;
};

ll tree[400001];

void update(int idx, int val, int node, int nl, int nr)
{
	if(idx < nl || nr < idx) return;

	if(nl == nr)
	{
		tree[node] += val;
	}	
	else
	{
		int nn = node + node;
		int mid = (nl + nr) >> 1;
		update(idx, val, nn , nl, mid);
		update(idx, val, nn+1, mid+1, nr);
		tree[node] = tree[nn] + tree[nn+1];
	}
}

ll query(int l, int r, int node, int nl, int nr)
{
	if(r < nl || nr < l)
		return 0LL;
	if(l <= nl && nr <= r)
		return tree[node];
	
	int nn = node + node;
	int mid = (nl + nr) >> 1;
	return query(l, r, nn, nl, mid) + query(l, r, nn+1, mid+1, nr);
}

int main()
{
	std::ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	Work a[100001];
	ll res[100001];
	cin>>n;

	long long sum = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i].val;
		a[i].idx = i;
		sum += a[i].val;
	}

	sort(a+1, a+1+n, [](const Work &a, const Work &b)
			{
				if(a.val == b.val)
					return a.idx > b.idx;
				return a.val > b.val;
			});

	int diff = 0;
	res[a[1].idx] = sum;
	update(a[1].idx,1, 1, 1, n);

	for(int i = 2 ; i <= n ; i++)
	{
		if((diff = a[i-1].val - a[i].val))
		{
			sum -= query(1, n , 1, 1, n) * diff;
		}
		res[a[i].idx] = sum - query(a[i].idx, n, 1, 1, n);
		update(a[i].idx,1, 1, 1, n);
	}

	for(int i = 1 ; i <= n ;i++)
	{
		cout<<res[i]<<'\n';
	}
	return 0;
}
