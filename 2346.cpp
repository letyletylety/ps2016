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
	list<PII> arr;
	for(int i = 0 ;i < n ;i++)
	{
		int temp;
		scanf("%d",&temp);
		arr.push_back({i+1,temp});	
	}
	auto it = arr.begin();
	
	for(int i = 0 ; i < n -1; i++)	
	{
		printf("%d ", it->first);
		int temp = it->second;
		auto jt = it;
		if(temp > 0)
		{
			++jt;
			if(jt == arr.end())
				jt = arr.begin();
			arr.erase(it);
			for(int i= 1 ; i < temp; i++)
			{
				jt++;
				if(jt == arr.end())
					jt = arr.begin();
			}
		}
		else
		{
			temp = -temp;
			if(jt == arr.begin())
				jt = arr.end();
			jt--;
			arr.erase(it);
			for(int i = 1 ; i<temp;i++)
			{
				if(jt == arr.begin())
					jt = arr.end();
				jt--;
			}
		}
		it = jt;
	}
	printf("%d\n",arr.front().first);
}
