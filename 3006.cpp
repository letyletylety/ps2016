#include <cstdio>

using namespace std;

int tree[400001]; // (inversion의 개수)
int pos[100001];

void update(int idx, int val, int node, int nl, int nr)
{
	if(idx < nl || nr < idx) return;
	if(nl == nr) 
		tree[node] = val;
	else
	{
		int mid = (nl+nr)>>1;
		update(idx, val, node+node, nl, mid);
		update(idx, val, 1+node+node, mid+1, nr);
		tree[node] = tree[node+node] + tree[node+node+1];
	}
}

int query(int l, int r, int node, int nl, int nr)
{
	if(r < nl || nr < l) return 0LL;

	if(l <= nl && nr <= r) return tree[node];

	int mid = (nl + nr) >> 1;
	return query(l, r, node+node, nl, mid) + query(l, r, 1+node+node, mid+1, nr);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++)
	{
		int tt;
		scanf("%d", &tt);
		pos[tt] = i;
	}
	
	for(int i = 1 ; i < 400001; i++)
	{
		update(i, 1, 1, 1, n); // 모든 리프 노드를 1로 초기화
	}

	int left = 1;
	int right = n;
	bool turn = 1;
	int tt;
	while(left <= right)
	{
		turn = 1 - turn;

		if(turn == 0) // 1 .. 
		{
			tt = pos[left];
			printf("%d\n", query(1, tt-1, 1, 1, n));
			update(tt, 0, 1, 1, n);
			left++;
		}
		else
		{
			tt = pos[right];
			printf("%d\n", query(tt+1, n, 1, 1, n));
			update(tt, 0, 1, 1, n);
			right--;
		}
	}	
	return 0;
}
