#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

vector<long long> factorSimple(long long int n)
{
	vector<long long> ret;

	for(long long div = 2; div*div <= n ; ++div)
	{
		if(!(n % div))
		{
			while(n % div == 0) {
				n/= div;
			}
			ret.push_back(div);
		}
	}
	if(n > 1) ret.push_back(n);
	return ret;
}

int main()
{
	long long int n;
	scanf("%lld",&n);

	vector<long long int> factor = factorSimple(n);

	queue<long long> q;
	queue<int> currentidx;

	for(int i = 0; i< factor.size() ;i++)
	{
		q.push(factor[i]);
		currentidx.push(i);
	}

	long long answer = n;

	while(!q.empty())
	{
		long long tt = q.front(); q.pop();
		int idx = currentidx.front(); currentidx.pop();	
		int ss = (tt > 0);

//		printf("%lld ", tt);
		if(ss)
			answer -= n / tt;
		else
		{
			tt = -tt;
			answer += n / tt;
		}

		for(int i = idx + 1 ; i< factor.size() ; i++)
		{
			long long tti = tt * factor[i];
			if(tti <= n)
			{
				q.push((ss?-tti:tti));
				currentidx.push(i);	
			}
			else break;
		}
	}

	printf("%lld", answer);
	return 0;
}
