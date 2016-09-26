#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printfsssss
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef long double ld;

#define mod 1000000007

const char newline = '\n';

ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

long long init(vector<ll> &a , vector<ll> &tree, int node, int start, int end)
{
	if(start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a,tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
}

void update_lazy(vector<ll> &tree, vector<ll> &lazy, int node, int start, int end)
{
	if(lazy[node] != 0)
	{
		tree[node] += (end-start+1)*lazy[node];
		if(start != end) // if not leaf
		{
			lazy[node *2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right, long long diff)
{
	update_lazy(tree, lazy, node, start, end);
	if(left > end || right < start) return;

	if(left <= start && end <= right)
	{
		tree[node] += (end-start+1) * diff;
		if(start != end)
		{
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}	
	update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
	update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
	tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right)
{
	update_lazy(tree, lazy, node, start, end);
	if( left > end || right < start ) return 0;
	if( left <= start && end <= right ) return tree[node];

	return sum(tree, lazy, node*2, start, (start+end)/2, left, right) + sum(tree, lazy, node*2+ 1, (start+end)/2+1, end, left, right);
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m,k;	
	cin>>n>>m>>k;
	vector<long long> a(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1<< (h+1)) - 1;
	vector<long long> tree(tree_size);
	vector<long long> lazy(tree_size);
	m += k;
	for(int i = 0 ; i< n ; i++)
		cin>>a[i];

	init(a, tree, 1, 0, n-1);  // 1번 노드를 0 ~ n-1
	while(m--)
	{
		int t1, t2, t3;
		cin>>t1;
		if(t1 == 1)
		{
			int start, end;
			ll v;
			cin>>start>>end>>v;
			update_range(tree, lazy, 1, 0, n-1, start-1, end-1, v);
		}
		else if(t1 == 2)
		{
			int start, end;
			cin>>start>>end;
			cout<<sum(tree, lazy, 1, 0, n-1, start-1, end-1)<<newline;
		}
	}
  return 0;
}
