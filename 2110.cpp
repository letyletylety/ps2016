#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printfsssss
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair
#include <map>
#include <list>
#include <stack>
#include <deque>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

bool check(int len, vector<int> a, int c)
{
	int cnt = 1;
	int start = a[0];
	for(int i = 1 ; i < a.size(); i++)
	{
		if(a[i] - start >= len)
		{
			cnt++;
			start = a[i];
		}
	}
	return cnt >= c;
}

// -------------------------- main

int main(int argc, char **argv)
{
	int n,c;
	scanf("%d%d",&n,&c);	
	vector<int> arr(n);
	for(int i= 0 ; i < n ;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr.begin(), arr.end());

	int left = 1;
	int right = arr[n-1] - arr[0];
	int answer = left;
	while(left <= right)
	{
		int mid = (left+right)/2;
		// binary_search .... 
		// mid 개 설치 했을때 c개를 넘어가면 오케이
		// c개가 안되면 길이를 더 줄여야 한다.
		if(check(mid, arr,c))
		{
			answer = max(answer, mid);
			left = mid+1;
		}
		else
		{
			right = mid -1;
		}	
	}
	printf("%d",answer);
    return 0;
}
