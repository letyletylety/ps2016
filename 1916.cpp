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

typedef pair<int,int> PI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

#define INF 123456789;
// -------------------------- global variable


// ; 빼먹지 않았는지 확인 ;;;;;;;;;;;;;;;;;
// -------------------------- declare function

vector<PI> adj[1002];

// -------------------------- main

int main(int argc, char **argv)
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i =  0; i< m ;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		adj[u].push_back(make_pair(v,w));
	}
	int source, dest;
	scanf("%d%d",&source, &dest);	
	
	vector<int> dist(n+2, 123456789);	// dist[i] : source에서 i까지 가는 경로의 최소
	dist[source] = 0;			// source -> source 는 0
	priority_queue<PI> pq;		// priority queue
	pq.push(make_pair(0, source));			// dist[v], v
	
	while(!pq.empty())
	{
		int cost = -pq.top().first; // 제일 긴을 -로 바꾸어 제일 짧은 경로 길이 출력
		int here = pq.top().second;	// 제일 짧은 경로를 가지는 노드
		pq.pop();
		// 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
		if(dist[here] < cost) continue;
		// 인접한 정점들은 모두 검사한다.
		for(int i = 0 ; i < adj[here].size() ;i++)
		{
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			// 더 짧은 경로를 발견하면 dist[] 를 갱신하고 우선순위 큐에 넣는다.
			if(dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	printf("%d\n", dist[dest]);
	return 0;
}

/* memo
*
*
*
*
*
*/

