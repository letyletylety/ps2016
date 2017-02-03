#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
	return !b?a:gcd(b, a%b);
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);

//	if(x < y)
//	{
//		x ^= y;
//		y ^= x;
//		x ^= y;
//	}

	int g = gcd(x,y);
	x /= g;
	y /= g;
	printf("%lld", (long long)g * (x + y - 1));
	return 0;
}
