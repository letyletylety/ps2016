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

int main(int argc, char **argv)
{
	string a, t;
	string ra;

	string left, right;

	cin>>a>>t;
	ra = string(a.rbegin(), a.rend());
	int lsp, rsp;
	int lp, rp;
	lp = 0;
	rp = t.size() - 1;
	
	bool swi = false; // false - left , true - right
	
	while(lp <= rp)
	{
		if(swi == false)
		{
			left.push_back(t[lp++]);

			if(left.size() >= a.size() && (string(left.rbegin(), left.rbegin() + a.size()) == ra))
			{
				for(int i = 0 ; i < a.size(); i++)
				{
					left.pop_back();
				}
				swi = !swi;
			}
		}
		else
		{
			right.push_back(t[rp--]);

			if(right.size() >= a.size() && (string(right.rbegin(), right.rbegin() +a.size()) == a))
			{
				for(int i = 0 ; i < a.size(); i++)
				{
					right.pop_back();
				}
				swi = !swi;
			}
		}
	}

	while(left.size())
	{
		char ch = left.back();
		left.pop_back();
		right.push_back(ch);	
		if(right.size() >= a.size() && (string(right.rbegin(), right.rbegin() +a.size()) == a))
		{
			for(int i = 0 ; i < a.size(); i++)			
			{
				right.pop_back();
			}
		}
	}
	
	cout<<string(right.rbegin(), right.rend());
    return 0;
}


