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
#include <cctype>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- main
char stack[1000001];
char buf[1000001];
int size = 0;

int main(int argc, char **argv)
{
	buf[0] = '(';
   	scanf("%s",buf+1);
	char *bp = buf + strlen(buf);
	char ch;
	*bp++ = ')';
	*bp++ = '\0';
	stack[1000000] = 0;
	// stack<char> st;   - C++ STL stack	
	//printf("%s\n",buf);	
	for(char *p = buf; *p ; p++) 	
	{
		ch = *p;
		if(ch >= 'A' && ch <= 'Z')
		{
			printf("%c",ch);
		}
		else
		{
			if(ch == '+' || ch == '-')
			{
				while(size > 0 && stack[size-1] != '(')
				{
					printf("%c",stack[--size]);
				}
				stack[size++] = ch;
			}
			else if(ch == '*' || ch == '/')
			{
				while(size > 0 && stack[size-1] != '+' && stack[size-1] != '-' && stack[size-1] != '(')
				{
					printf("%c",stack[--size]);
				}
				stack[size++] = ch;
			}
			else if(ch == '(')
			{
				stack[size++] = ch;
			}
			else if(ch == ')')
			{
				while(size>0 && stack[size-1] != '(')
				{
					printf("%c",stack[--size]);
				}
				if(stack[size-1] == '(')
				size--;
			}
		}
		//printf("%s\n",stack);
	}

	while(size > 0)
	{
		printf("%c",stack[--size]);
	}
    // printf("%s",stack);
	return 0;
}
