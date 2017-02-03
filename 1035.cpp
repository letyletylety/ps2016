#include <cstdio>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;

map<int, int> d;
map<int, int> b;

bool visited[25];
int cnt = 0;

int diff[4] = {-1,1,-5,5};

bool isCoordi(int oldpos, int pos)
{
	if(pos < 0 || 25 <= pos) return false;
	if(pos % 5 == 0)
	{
		if(oldpos == pos - 1)
			return false;
	}
	if(oldpos % 5 == 0)
	{
		if(pos == oldpos - 1)
			return false;
	}
	return true;
}

bool connected(vector<int> & v, int id)
{ 
	// bfs
	queue<int> q;
	memset(visited, 0, sizeof(visited));
//	for(int &i : v)printf("%d ", i);
	q.push(v[0]);
	visited[v[0]] = 1;
	int cc = 0;

	while(!q.empty())
	{
		int tt = q.front(); q.pop();
		cc++;
		int newpos;
		for(int i = 0 ; i < 4 ; i++)
		{
			newpos = tt + diff[i];

			if(isCoordi(tt, newpos) && !visited[newpos] && (id & (1<<newpos)))
			{
				q.push(newpos);	
				visited[newpos] = 1;
			}
		}
	}

//	printf("%d\n", cc);
	return (cc == ::cnt);
}

int main()
{
	char tt;
	int ori = 0;
	for(int i = 0 ; i < 25; i++)
	{
		scanf(" %c", &tt);	
		if(tt == '*')
		{
			ori |= (1<<i);
			cnt++;
		}
	}

//	vector<int> star;
//	for(int i = 0; i < 25 ;i++)
//	{
//		if(ori & (1<<i))
//			star.push_back(i);
//	}	
//
//	for(int i : star)
//		printf("%d ", i);
//
//	if(connected(star, ori))
//	{
//		printf("GOOD");
//	}
//
//	return 0;

	if(cnt <= 1){ puts("0"); return 0;}
	
	d[ori] = 0;
	queue<int> q;
	q.push(ori);
	d[ori] = 0;

	while(!q.empty())
	{
		int tt = q.front();q.pop();
		vector<int> star;

//		for(int i = 0 ; i < 5; i++)
//		{
//			for(int j = 0; j <  5; j++)
//			{
//				printf("%d",((1<<(i*5+j)) == ( tt & (1<<(i*5 + j)))));
//			}
//				puts("");
//		}
//		puts("");

		for(int i = 0; i < 25 ;i++)
		{
			if(tt & (1<<i))
				star.push_back(i);
		}	

		if(connected(star, tt))
		{
//			printf("GOOD");
			printf("%d", d[tt]);

//			while(tt != ori)
//			{
//				tt = b[tt];
//				vector<int> star;
//				for(int i = 0; i < 25 ;i++)
//				{
//					if(tt & (1<<i))
//						star.push_back(i);
//				}
//				for(int &i : star) printf("%d ", i);
//				puts("");
//			}
			break;
		}

		for(int i = 0 ; i < star.size(); i++)
		{
			for(int j = 0 ; j < 4; j++)
			{
				int newpos = star[i] + diff[j];

				int newtt = tt;
				if(isCoordi(star[i], newpos) && (tt & (1<<newpos)) == 0)
				{
					newtt -= (1<<star[i]);
					newtt |= (1<<newpos);

					if(d.count(newtt) == 0)
					{
						d[newtt] = d[tt] + 1;
						b[newtt] = tt;
						q.push(newtt);
					}
				}	
				else
				{
					continue;
				}
				
			}
		}
	}

	return 0;
}
