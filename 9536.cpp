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
#include <sstream>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- global variable
#define ENP printf("--ENTRY--")


// ; »©¸ÔÁö ¾Ê¾Ò´ÂÁö È®ÀÎ ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

char buf[103];
char sss[103];

// -------------------------- main

int main(int argc, char **argv)
{
	vector<string> vs;
	set<string> ssss;
	char buf[12321];
	string s;

	int t; for (scanf("%d ", &t); t--;)
	{
		vs.clear();
		ssss.clear();
		char ch;
		getline(cin, s);
		stringstream ss(s);
		while (getline(ss,s,' '))
		{
			vs.push_back(s);
		}
		//ENP;
		while (true)
		{
			scanf("%*s%s%s", sss, buf);
		//	printf("%s", sss);
			if (sss[0] == 'd')
			{
				scanf("%*s%*s ");
				break;
			}
			ssss.insert(buf);
		}
		//ENP;
		for (int i = 0; (size_t)i < vs.size(); i++)
		{
			if (ssss.find(vs[i]) == ssss.end())
			{
				printf("%s ", vs[i].c_str());
			}
		}
		printf("\n");
	}
	return 0;
}

/* memo
*
*
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
source : http://stackoverflow.com/questions/236129/split-a-string-in-c
*
* getline(cin,s)
* getline(stream , s, token)
* stringstream
*/
