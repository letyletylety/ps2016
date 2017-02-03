#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int used[10];
	int N;
	int hello;
	int	world; 
	int d,e,h,l,o,r,w;
	cin>>N;

	for(int i = 0 ; i < 10000000; i++)
	{
		memset(used, 0, sizeof(used));
		d = i;
		w = d%10;  // w
		if(!w) continue;
		used[w] = 1;
		d/= 10;
		h = d % 10; // h
		if(!h || used[h]) continue;
		used[h] = 1;
		d /= 10;
		r = d % 10; // r
		if(used[r]) continue;
		used[r] = 1;
		d /= 10;
		o = d%10; // o 
		if(used[o]) continue;
		used[o] = 1;
		d /= 10;
		l = d%10; // l
		if(used[l]) continue;
		used[l] = 1;
		d /= 10;
		e = d %10;
		if(used[e]) continue;
		used[e] = 1;
		d /= 10;
		if(used[d]) continue;
		hello = ((((10*h + e) * 10 + l) * 10 + l) * 10) + o;
		world = ((((10*w + o) * 10 + r) * 10 + l) * 10) + d;
		if(hello + world == N)
		{
			printf("%7d\n",hello);
			printf("+%6d\n",world);
			puts("-------");
			printf("%7d\n", N);
			return 0;
		}
	}

	puts("No Answer");

	return 0;
}
