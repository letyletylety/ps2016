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

char str[1000001];
double value[26];
double stack[1000001];
int size = 0;
// -------------------------- main

int main(int argc, char **argv)
{
	int n;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i = 0 ; i <  n; i++)
	{
		scanf("%lf",&value[i]);
	}
	
	int s = strlen(str);
	double result = 0.;
	for(int i= 0 ; i< s; i++)
	{
		if(isalpha(str[i]))
		{
			stack[size++] = value[str[i]-'A'];
		}
	else
	{
		double a,b,c;
		a = b = 0;
		if(size >0)a = stack[--size];
		if(size >0)b = stack[--size];

		if(str[i] == '+')
		{
			c = a+b;
		}
		else if(str[i]=='-')
		{
			c = b-a;
		}
		else if(str[i] == '*')
		{
			c = b*a;
		}else if(str[i] == '/')
		{
			c = b/a;
		}
		stack[size++] = c;
	}
	}
	printf("%.2lf",stack[0]);
    return 0;
}
