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

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- main

int main(int argc, char **argv)
{
	string n;
	int m;
	cin>>n>>m;
	int s = n.size();
	if(s * stoi(n) > m)
	{
		while(m > s)
		{
			m-=s;
			cout<<n;
		}
		for(int i =0 ; i < m ; i++)
		{
			cout<<n[i];
		}
	}else
	{
		for(int i = 0 ; i< stoi(n) ; i++)
		{
			cout<<n;
		}
	}
    return 0;
}
