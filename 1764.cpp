#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	vector<string> a, b;

	cin>>n>>m;

	a.resize(n);
	b.resize(m);

	for(int i = 0 ; i < n; i++)
	{
		cin>>a[i];
	}

	for(int j = 0 ; j < m ; j++)
	{
		cin>>b[j];	
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<string> answer(n+m+1);

	auto it = set_intersection(a.begin(), a.end(), b.begin(), b.end(), answer.begin());

	answer.resize(it - answer.begin());

	sort(answer.begin(), answer.end());

	cout<<answer.size()<<'\n';
	for(string &i : answer)
	{
		cout<<i<<'\n';
	}
	return 0;
}

