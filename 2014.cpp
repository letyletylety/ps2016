#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <climits>
#include <utility>
#include <tuple>
#include <algorithm>

typedef long long ll;
using namespace std;

int a[101];

int main()
{
	int k,n;
	scanf("%d%d",&k,&n);

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;

	for(int i  = 0; i < k ; i++)
	{
		scanf("%d", a+i);
	}

	sort(a, a+k);

	for(int i = 0 ; i < k ; i++)
	{
		min_heap.push({a[i], i});
	}

	int max = a[0];
	int value, idx;

	for(int i = 0 ; i < n-1 ; i++)
	{
		tie(value, idx) = min_heap.top(); min_heap.pop();

		for(int j = idx; j < k ; j++)
		{
			ll new_val = (ll)value * a[j];
			if(new_val > INT_MAX) break;

			if(max > new_val)
			{
				min_heap.push({value * a[j], j});
			}
			else{	
				if(min_heap.size() > (n-i))
					break;
				else
				{
					max = new_val;
					min_heap.push({value * a[j], j});
				}
			}
		}
	}
	printf("%d\n", min_heap.top().first);
	return 0;
}
