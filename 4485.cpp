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
typedef pair<int, int> PII;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)


// -------------------------- global variable

const int dy[4] = {-1,0,0,1};  // up and right and down and left
const int dx[4] = {0,-1,1,0};

// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

int board[126][126];
int dist[126][126];

// -------------------------- main

int main(int argc, char **argv)
{
	int n;
	int cnt = 0;
	while(true)
	{
		cnt++;
		scanf("%d",&n);
		if( n == 0 ) break;
		
		for(int i = 0 ; i < n ; i++)
		{
			for(int j = 0 ; j < n ;j++)
			{
				scanf("%d",&board[i][j]);
			}
		}
		
		priority_queue<pair<int, PII> > pq; // w, node(좌표) 
											// max heap에 음수를 넣어서 min heap 으로 사용
		 
		int sy = 0, sx = 0;
		int desty = n-1, destx = n-1;
		
		for(int i = 0 ; i < n ;i++)
		{
			for(int j = 0 ; j < n;j++)
			{
				dist[i][j] = 1234567890;
			}
		}
		
		dist[sy][sx] = board[sy][sx];
		pq.push(make_pair(-dist[sy][sx], make_pair(sy,sx)));
		
	
		while(!pq.empty())
		{
			int cost = -pq.top().first;
			PII here = pq.top().second;
			pq.pop();
			int herey, herex;
			herey = here.first;
			herex = here.second;		
			
			if(dist[herey][herex] < cost) continue; // 더 빠른 경로를 알고 있으면 계속
			
			for( int dir = 0; dir < 4 ; dir++ )
			{
				PII there;
				there.first = herey + dy[dir]; // 새로운 좌표
				there.second = herex + dx[dir]; // 새로운 좌표
				
				if(there.first >= n || there.second >= n || there.first < 0 || there.second < 0) continue; //  보드 밖으로 나가버리면 무시
				
				int nextDist = cost + board[there.first][there.second];
				
				if(dist[there.first][there.second] == -1 || dist[there.first][there.second] > nextDist)
				{
					dist[there.first][there.second] = nextDist;
					pq.push(make_pair(-nextDist, there));
				}
			}
		}
		
		//for(int i = 0 ; i < n ; i++)
		//{
			//for(int j = 0 ; j < n ;j++)
			//{
				//printf("%d ",dist[i][j]);
			//}
			//printf("\n");
		//}
		
		printf("Problem %d: %d\n",cnt, dist[desty][destx]);
	}
	
	
	return 0;
}

/* memo
*
*
*
*
*
*/
