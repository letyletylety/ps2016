#include <iostream>

using namespace std;



int ret_size(int n) // IN : a integer, OUT : the length of integer
{
	return to_string(n).size();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin>>n;
	n++;

	int deg[10001];

	for(int i  = 0 ; i < n ; i++)
	{
		cin>>deg[i];
	}	

	int answer = 2; // =  && 최고차항(x)

	for(int i = 1 ; i < n-1 ; i++)
	{
		if(deg[i])
			answer += 1 + ret_size(deg[i]); // +
		answer += 2; // * x
	}
	
	if(deg[n-1])
	answer += 1 + ret_size(deg[n-1]); // +
	cout<<answer<<'\n';	
	return 0;
}
