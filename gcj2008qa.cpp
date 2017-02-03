#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;

	cin>>n;

	for(int j =1; j <=n;j++)
	{
		int s;
		int answer = 0;
		string tt;

		cin>>s;
		vector<string> vs(s);
		vector<queue<int> > adj(s);

		getline(cin, tt);
		for(int i = 0 ; i< s; i++)
		{
			getline(cin, vs[i]);
		}
		sort(vs.begin(), vs.end());

		int q;
		cin>>q;
//		vector<bool> exist(s);
		getline(cin, tt);
		for(int i = 0 ; i < q; i++)
		{
			getline(cin, tt);

			int it = lower_bound(vs.begin(), vs.end(), tt) - vs.begin();

			adj[it].push(i);
		}

		for(int i = 0 ; i < s; i++)
		{
//			cout<<vs[i]<<'\n';
			adj[i].push(q);
		}

//		int here = -1;
		while(1)
		{
			int maxt = -1;
			int idx;
			for(int i = 0 ; i < s; i++)
			{
				if(maxt < adj[i].front())	
				{
					maxt = adj[i].front();
					idx = i;
				}
			}

			for(int i = 0 ; i < s; i++)
			{
				while(!adj[i].empty() && adj[i].front() < maxt)
					adj[i].pop();
			}	

			if(maxt == q) break;
			answer++;
		}

		cout<<"Case #"<<j<<": "<<answer<<'\n';
	}
	return 0;
}
