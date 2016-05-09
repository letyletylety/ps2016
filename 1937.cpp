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

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
// -------------------------- global variable

// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

int board[501][501];
int cache[501][501];
const int dy[4] = {-1,0,0,1};
const int dx[4] = {0,-1,1,0};
int n;	

// -------------------------- main

bool isRange(int y, int x)
{
	return y>=0 && y< n && x>=0 && x < n;
}

int dp(int y, int x)
{
	int &ret = cache[y][x];
	
	if(ret != -1) return ret;
	
	int ny,nx;
	ret = 1;
	for(int dir = 0 ; dir <4 ;dir++)
	{
		ny = y + dy[dir];
		nx = x + dx[dir];
		if(isRange(ny, nx) && board[ny][nx] > board[y][x])
		{
			ret = max(ret, dp(ny,nx)+1);
		}
	}
	return ret;
}

int main(int argc, char **argv)
{	
	scanf("%d",&n);
	for(int i = 0; i <  n;i++)
	{
		for(int j = 0 ; j <n ;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	
	
	memset(cache, -1, sizeof(cache));
	
	for(int i = 0 ; i < n ;i ++)
	{
		for(int j = 0 ; j < n ;j++)
		{
			if(cache[i][j] == -1)dp(i,j);
		}
	}
	
	int answer = 0;
		
	for(int i = 0 ; i<  n ;i ++)
	{
		for(int j = 0 ; j < n ;j++)
		{
			answer = max(answer, cache[i][j]);
		}
	}
	
	printf("%d",answer);		
	
	return 0;
}

/* memo
*
*
*
*
*
*/
