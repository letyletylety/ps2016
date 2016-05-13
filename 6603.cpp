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

void comb(vector<int> &arr, int idx, vector<int> &selected, int t = 6)
{
	if(arr.size() - idx + selected.size() < t) 
		return;

	if(selected.size() == t)
	{
		for(int i = 0; i <selected.size(); i++)
		{
			printf("%d ",selected[i]);
		}
		printf("\n");
		return;
	}
	else
	{
		for(int i = idx ; i < arr.size(); i++)
		{
			selected.push_back(arr[i]);
			comb(arr,i+1,selected);
			selected.pop_back();
		}
	}
}
// -------------------------- main

int main(int argc, char **argv)
{
	int n;
	vector<int> arr;
	vector<int> sel;
	while(true)
	{
		scanf("%d",&n);
		if(n == 0)break;
		arr.clear();
		for(int i= 0 ; i < n ;i++)
		{
			int temp;
			scanf("%d",&temp);
			arr.push_back(temp);
		}
		sel.clear();
		comb(arr,0,sel);
		printf("\n");
	}
    return 0;
}
