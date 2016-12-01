#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const char newline = '\n';

int main()
{
	int n;
	cin>>n;
	vector<int> chu(n);
	for(int i = 0 ; i < n ;i++)
	{
		cin>>chu[i];
	}

	sort(chu.begin(), chu.end());

	long long sum = 0;
	long long answer = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(sum + 1 < chu[i])
		{
			cout<<sum+1<<newline;
			return 0;
		}
		else
		{
			sum += chu[i];
		}
	}	
	cout<<sum+1<<newline;
	return 0;
}
