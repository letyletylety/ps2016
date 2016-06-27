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
#include <cmath>
#include <ctime>
#include <chrono>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const char newline = '\n';

const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
#define pb(x) push_back(x)
#define forn(i,n) for(int i = 0 ; i < int(n); ++i)

// N에서 자기 자신의 찾으면서 나타나는 부분 일치를 이용해
// pi[]를 계산한다.
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이
vector<int> getPartialMatch(const string & N)
{
	int m = N.size(); 
	vector<int> pi(m,0);
	// KMP로 자기 자신을 찾는다/
	// N을 N에서 찾는다 begin = 0 이면 자기 자신을 찾아버리니까 안됨
	int begin = 1, matched = 0;
	// 비교할 문자가 N의 끝에 도달할 때 까지 찾으면서 부분 일치를 모두
	// 기록한다.
	while(begin + matched < m)
	{
		if(N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin+matched-1] = matched;
		}
		else
		{
			if(matched == 0)++begin;
			else
			{
				begin+= matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

// a 의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다
int maxOverlap(const string &a, const string &b)
{
	int n = a.size(), m = b.size();
	VI pi = getPartialMatch(b);
	//begin = matched = 0 에서 부터 시작하자
	int begin = 0, matched = 0;
	while(begin < n)
	{
		// 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if(matched < m && a[begin + matched] == b[matched])
		{
			++matched;
			if(begin + matched == n)
			{
				return matched;
			}

		}	
		else
		{
			if(matched == 0)
			{
				++begin;
			}
			else
			{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}	
	return 0;
}

int main(int argc, char **argv)
{
	ios::sync_with_stdio(false);
	//int t;
	//cin>>t;
	//while(t--)
//	{
	string a,b;
	cin>>a;
	b = string(a.rbegin(), a.rend());
	int n = maxOverlap(a,b)	;
	cout<<a.size() + b.size() - n<<newline;
//	}
  return 0;
}
