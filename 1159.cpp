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


// -------------------------- main
int name[26];

int main(int argc, char **argv)
{
	int n;
	char buf[50];
	scanf("%d",&n);
	for(int i= 0 ; i < n ;i++)
	{
		scanf("%s",buf);
		name[buf[0]-'a']++;
	}
	bool checked = false;
	for(int i = 0; i < 26;i++)
	{
		if(name[i] >= 5)
		{
			checked = true;
			printf("%c",i+'a');
		}
	}
	if(checked == false) printf("PREDAJA");
    return 0;
}
