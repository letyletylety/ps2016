#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printf
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair
#include <map>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

// -------------------------- global variable


// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

long long lineLength(long long num, vector<long long>& arr)
{
	long long ret = 0;
	for(int i = 0 ; (size_t)i< arr.size();i++)
	{
		ret += arr[i]/num;
	}
	return ret;
}

// -------------------------- main

int main(int argc, char **argv)
{
	int n;
	long long k;
	scanf("%d%lld",&n,&k);
	vector<long long> lanline(n);
	for(int i =0 ; i<n;i++)
	{
		scanf("%lld",&lanline[i]);
	}
	long long left = 0;
	long long right = *max_element(lanline.begin(), lanline.end());
	long long mid;
	long long int ans = 0;
	while(left <= right)
	{
	//	printf("%lld %lld\n",left, right);

		mid = (left + right)/2;
		long long temp = lineLength(mid, lanline);

		if(k > temp)
		{
			right = mid-1;
		}
		else
		{
			if(ans < mid)
			{
				ans = mid;
			}
			left = mid+1;			
		}
	}
	printf("%lld",ans);
	return 0;
}

/* memo
*  드디어 풀었다,,
* long long 으로 해야하는 것과 최대값 들고있기
*그리고 디버깅용 프린트 지우기
*
*
*/
