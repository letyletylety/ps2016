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


int cache[2510];
int cache2[2510][2510];
string s;

int isPal(int i, int j)
{
	if(i == j) return 1;
	if(j == i+1)
	{
		if(s[i] == s[j]) return 1;
	}
	
	int  &ret = cache2[i][j];
	if(ret != -1)return ret;
	
	if(s[i] != s[j]) return ret = 0; 
	else
	{
		return ret = isPal(i+1,j-1);
	}
}
int dp(int i)
{
	if(i < 0)return 0;
	if(i == 0) return 1;
	int &ret = cache[i];
	if(ret != -1)return ret;
	ret = 123456789;
	for(int j = 0; j<= i;j++)
	{
		if(isPal(j,i))
		{
			ret = min(1+dp(j-1), ret);
		}
	}
	return ret;
}
// -------------------------- main

int main(int argc, char **argv)
{
	memset(cache, -1,sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin>>s;
	printf("%d\n",dp(s.size()-1));
    return 0;
}
