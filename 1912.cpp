#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printf
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- global variable

LL dp[100002]; // dp[i] : index i 까지의 최대 구간합

							 // ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
							 // -------------------------- declare function

							 // -------------------------- main

int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	vector<int> ar(n);
	vector<LL> sr(n, 0);
	vector<int> ir(n);

	int temp;
	LL ret;

	scanf("%d", &ar[0]);
	temp = sr[0] = ar[0];
	ir[0] = 0;

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &ar[i]);
		sr[i] = sr[i - 1] + ar[i];

		if (temp > 0)
		{
			ir[i] = ir[i - 1];
			temp += ar[i];
		}
		else
		{
			ir[i] = i;
			temp = ar[i];
		}
	}

	dp[0] = ar[0];
	for (int i = 1; i < n; i++)
	{
		if (ir[i] == 0)
		{
			dp[i] = max(dp[i - 1], sr[i]);
		}
		else
		{
			dp[i] = max(dp[i - 1], sr[i] - sr[ir[i] - 1]);
		}
	}
	cout << dp[n - 1] << endl;

	return 0;
}

/* memo
*
*
*
*
*
*/