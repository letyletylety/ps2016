/* Lety */

#define _CRT_SECURE_NO_WARNINGS

#include		<cstdio>
#include		<cmath>
#include		<algorithm>
#include		<vector>
#include		<stack>
#include		<queue>
#include		<functional>
#include		<cstring>
#include		<string>
#include		<map>
#include		<set>
#include		<iostream>
#include		<tuple>
#include		<numeric>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair
#define MT      make_tuple
#define PB      push_back

using namespace std;

typedef long long		 ll;
typedef vector	<int>	 VI;

int main(int argc, char **argv)
{
	int n, m;
	deque<int> dq;

	scanf("%d%d", &n, &m);

	int ptr = 0;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	int answer = 0;

	for (int i = 0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		
		int s = dq.size();
		int it = find(dq.begin(), dq.end(), t) - dq.begin();
			
		rotate(dq.begin(), dq.begin() + it, dq.end());
		if (it < s - it) // <<
		{
			answer += it;
		}
		else // >> 
		{
			answer += (s - it);
		}
		dq.pop_front();
	}
	printf("%d", answer);

	return 0;
}

/* memo
*
*
*
*
*
*/