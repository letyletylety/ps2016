#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	return b?gcd(b, a%b):a;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m,z;
	cin>>n>>m>>z;

	int lcd = n * m / gcd(n,m);

	cout<< z/ lcd<<'\n';
	return 0;
}


