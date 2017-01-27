#include <iostream>

using namespace std;

using ll = long long;

ll mod = 1e9+7;
ll cntTree[800000];
ll sumTree[800000];

void update(ll *T, int idx, int val, int node, int nl, int nr)
{
	if(idx < nl || nr < idx) return;

	if(nl == nr)
		T[node] += val;
	else
	{
		int mid = (nl + nr) >>1;
		update(T, idx, val, node+ node, nl, mid);
		update(T, idx, val, node+ node+1, mid+1, nr);
		T[node] = T[node+node] + T[node+node+1];
	}
}

ll query(ll *T, int l, int r, int node, int nl, int nr)
{
	if(r< nl || nr < l) return 0;
	
	if(l <= nl && nr <= r) return T[node];

	int mid = (nl + nr) >>1;
	return query(T, l, r, node+node, nl, mid) + query(T, l, r, 1+node+node, mid+1,nr);
}

int main()
{
	int n;			
	scanf("%d", &n);
	int tt;
	long long answer = 1LL;
	scanf("%d", &tt);
	update(cntTree, tt, 1, 1, 0, 200000);
	update(sumTree, tt, tt, 1, 0, 200000);
	for(int i = 2 ; i <= n; i++)
	{
		scanf("%d", &tt);

		update(cntTree, tt, 1, 1, 0, 200000);
		update(sumTree, tt, tt, 1, 0, 200000);
		long long L = ((tt * query(cntTree, 0, tt-1, 1, 0, 200000)%mod) - (query(sumTree, 0, tt-1, 1, 0, 200000)%mod))%mod;
		long long R = ((query(sumTree, tt+1, 200000, 1, 0, 200000))%mod - (tt * query(cntTree, tt+1, 200000, 1, 0, 200000))%mod) %mod;

		answer = answer * ((L%mod+R%mod)%mod);
		answer %= mod;
//		printf("%lld\n", (L+R));
	}
	printf("%lld", answer);
	return 0;
}
