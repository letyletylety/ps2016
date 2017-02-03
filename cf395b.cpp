#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	int a[200001];
	cin>>n;

	for(int i = 1  ; i <= n ;i++)
	{
		cin>>a[i];
	}	

	if(n&1)
	{
		for(int i = 1; i <= n ; i++)
		{
			if(i&1)
			{
				cout<<a[n-i+1]<<' ';
			}
			else
			{
				cout<<a[i]<<' ';
			}
		}	
	}
	else{
		for(int i = 1; i <= n/2 ; i++)
		{
			if(i&1)
			{
				cout<<a[n-i+1]<<' ';
			}
			else
			{
				cout<<a[i]<<' ';
			}
		}	

		for(int i = n/2+1; i <= n ; i++)
		{
			if(!(i&1))
			{
				cout<<a[n-i+1]<<' ';
			}
			else
			{
				cout<<a[i]<<' ';
			}
		}	
	}
	
	return 0;
}

