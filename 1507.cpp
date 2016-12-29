#include <iostream>
#include <queue>
#include <utility>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int board[21][21];
	int answer = 0;	

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			cin>>board[i][j];
			answer += board[i][j];
		}
	}

	answer >>= 1;
	bool ok = true;

	for(int k = 0 ; k < n ; k++)
	{
		for(int i = 0 ; i < n ; i++)
		{
			if(!board[i][k]) continue;

			for(int j = 0 ; j < n ; j++)
			{
				if(!board[k][j]) continue;
				if(!board[i][j]) continue;

				if(board[i][j] == board[i][k] + board[k][j]) // 없어도 되는 간선
				{
					answer -= board[i][j];
					board[i][j] = board[j][i] = 0;
				}
				else	
				if(board[i][j] > board[i][k] + board[k][j]) // impossible
				{
					ok = false;
					goto Fail;
				}
			}
		}
	}

Fail:
	if(!ok) return printf("-1"), 0;

	printf("%d\n", answer);
	return 0;
}
