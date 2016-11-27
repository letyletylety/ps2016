#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,m,k;
	cin>>n>>m>>k;

	if( n > m*k || n < m+k-1 )
		return printf("%d",-1), 0;

	vector<int> ans(n);
	vector<int> group(m, 1);
	int sum = m;	
	for(int i = 1; i <= n ;i++) ans[i-1] = i;

	for(int i = m-1 ; i >= 0 ;i --)
	{
		if(sum + k - 1 == n)
		{
			group[i] = k;
			break;
		}
		else if(sum + k - 1 > n)
		{
			group[i] += n-sum;
			break;
		}
		else{
			group[i] = k;
			sum += k-1;
		}
	}

	int tt = 0;

	for(int i = 0 ; i < m ; i++)
	{
		reverse(ans.begin() + tt, ans.begin() + tt + group[i]);
		tt += group[i];
	}

	for(int a : ans)
	{
		cout<<a<<' ';	
	}	

	return 0;
}
