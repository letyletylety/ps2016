#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

const int dy[8] = {-1,-1,-1,0,0,1,1,1};
const int dx[8] = {-1,0,1,-1,1,-1,0,1};

char board[51][51];
int godo[51][51];
bool visited[51][51];
int dd[2501];

int py, px;
int kcnt = 0;
int n;

int bfs( int low, int high )
{
	if(godo[py][px] < low || high < godo[py][px]) return 0;

	memset(visited, 0, sizeof(visited));	

	int ret = 0;
	int ty, tx;
	queue<pair<int, int> > q;

	q.push(make_pair(py,px));
	visited[py][px] = true;

	while(!q.empty())
	{
		tie(ty, tx) = q.front();
		//printf("%d %d\n", ty, tx);
		if(board[ty][tx] == 'K') ret++;

		q.pop();

		for(int dir = 0 ; dir < 8 ; dir++)
		{
			int ny = dy[dir] + ty;
			int nx = dx[dir] + tx;

			if( 0 <= ny && ny < n && 0 <= nx && nx < n && low <= godo[ny][nx] && godo[ny][nx] <= high && !visited[ny][nx]) // inRange
			{
				q.push(make_pair(ny, nx));	
				visited[ny][nx] = true;
			}
		}
	}
//	printf("%d %d %d\n", low, high, ret);
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < n ;j++)
		{
			scanf(" %c", &board[i][j]);
			if(board[i][j] == 'P')
			{
				py = i;
				px = j;
			}
			else if(board[i][j] == 'K')
			{
				kcnt++;
			}
		}
	}

	int cnt = 0;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ;j++)
		{
			scanf("%d", &godo[i][j]);
			dd[cnt++] = godo[i][j];
		}
	}

  // 좌표압축
	std::sort(dd, dd + cnt);

	// two pointer
	int low = 0;
	int high = 0;
	int answer = dd[cnt-1];

	while(low < cnt && high < cnt)
	{
		while(low <= high && bfs(dd[low], dd[high]) == kcnt) // success
		{
//			printf("%d %d\n", dd[low], dd[high]);		

			if(answer > dd[high] - dd[low])
				answer = dd[high] - dd[low];
			low++;	
		}
		high++;
	}
	printf("%d", answer);
	return 0;
}

// 좌표압축 + two pointer + bfs/dfs
