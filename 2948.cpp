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
const string week[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
const int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(int argc, char **argv)
{
	int d,m;
	scanf("%d%d",&d,&m);
	int day = 0;
	for(int i = 0; i < m; i++)
	{
		day += days[i];
	}
	day += d;

	printf("%s",week[(day+2)%7].c_str());
    return 0;
}
