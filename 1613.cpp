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
#define sd(a) scanf("%d",&a);

int test[401][401];
int n,k;
int from, to;

void  input()
{
	sd(n);
	sd(k);
	while(k--)
	{
		sd(from);
		sd(to)
		from--;
		to--;
		test[from][to] = -1;
		test[to][from] = 1;
	}
	
	forn(inter,n)
		forn(i,n)
		{
			if(test[i][inter] == 0) continue;
			forn(j,n)
			{
				if(test[j][inter] != 0 && test[i][inter] == test[inter][j])
				{
					test[i][j] = test[i][inter];	
				}
			}
		}
}

void process()
{
	int s;
	int a,b;
	sd(s);
	while(s--)
	{
		sd(a); sd(b);
		--a;
		--b;
		cout<<test[a][b]<<newline;
	}
}

void output()
{

}

int main(int argc, char **argv)
{
//std::chrono::time_point<std::chrono::system_clock> start, end;
//start = std::chrono::system_clock::now();
	input();
	process();
	output();
/*
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end-start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "finished computation at " << std::ctime(&end_time)
						<< "elapsed time: " << elapsed_seconds.count() << "s\n";
*/
    return 0;
}
