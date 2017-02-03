#include <string>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n;
	cin>>n;
	string a,b;
	set<string> company;

	for(int i = 0 ; i < n ; i++)
	{
		cin>>a>>b;
		if(b == "enter")
		{
			company.insert(a);
		}
		else
		{
			company.erase(a);
		}
	}
	
	for(auto it = company.rbegin(); it != company.rend(); it++)
	{
		cout<<*it <<'\n';
	}
	return 0;
}
