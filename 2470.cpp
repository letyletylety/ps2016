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
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- main

int main(int argc, char **argv)
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n);	
	for(int i = 0 ; i <  n ;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr.begin(), arr.end());

	int cur_a, cur_b;
	int cur_c, cur_d;
	int temp = 1234567890;
	cur_c = cur_a = 0;
	cur_d = cur_b = arr.size() -1;

	while(cur_a < cur_b)
	{
		temp = arr[cur_a] + arr[cur_b];
		int tt = arr[cur_c] + arr[cur_d];
		if(abs(tt) < abs(temp))
		{
			cur_a = cur_c;
			cur_b = cur_d;
		}
		
		if(tt < 0)
		{
			// if tt < 0, cur_c++;
			cur_c++;
		}
		else if(tt > 0)
		{
			// if tt > 0 , cur_d--;
			cur_d--;
		}
		else
		{
			break;	
		}
		
		if(cur_c >= cur_d) break;
	}
	printf("%d %d",arr[cur_a], arr[cur_b]);
	return 0;
}
