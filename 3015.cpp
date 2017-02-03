#include <cstdio>
#include <stack>
using namespace std;

int st[500001];
int st2[500001];
int sz = 0;

int main()
{
	int n;
	scanf("%d", &n);

	long long answer = 0LL;

	for(int i = 0 ; i < n ; i++)
	{
		int x;
		int t = 1;
		scanf("%d", &x);

		while(sz > 0 && st[sz-1] <= x) // empty아닐때
		{
			answer += (long long)st2[sz-1];	 // top <= x
			if(st[sz-1] == x) // top == x
			{
				t += st2[sz-1];
			}
			sz--; //pop
		}

		if(sz > 0) // empty 아닐때
			answer += 1LL;

		//push
		st[sz] = x;
		st2[sz++] = t;
	}
	printf("%lld", answer);
	return 0;
}
