#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

vector<vector<int> > adj;
int c[100001];
set<pair<int, int> > inverse;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;

	adj.resize(n+1);
	for(int i = 1; i < n ;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	

	for(int i = 1; i <= n ; i++)
	{
		cin>>c[i];
	}

	for(int i = 1; i <= n ; i++)
	{
		for(auto there : adj[i])
		{
			if(there > i && c[there] != c[i])
			{
				inverse.insert({there, i});
			}
		}
	}

	if(inverse.empty())
	{
		cout<<"YES"<<'\n';
		cout<<1<<'\n';
	}
	else if(inverse.size() == 1)
	{
		cout<<"YES"<<'\n';
		cout<<(inverse.begin())->first<<'\n';
	}
	else
	{
//		for(auto &ii : inverse)
//		{
//			cout<<ii.first<<' '<<ii.second<<'\n';
//		}	
//		vector<pair<int, int> > answer(inverse.begin(), inverse.end());
		int tt = inverse.size();
//		cout<<tt<<'\n';
		int cnt[100001] = {0};

		for(auto & ii : inverse)
		{
//			cout<<ii.first<<' '<<ii.second<<'\n';
			cnt[ii.first]++;
			cnt[ii.second]++;
		}

		for(int i = 1 ; i <= n ; i++)
		{
			if(cnt[i] == tt)
			{
				cout<<"YES"<<'\n';
				cout<<i<<'\n';
				return 0;
			}
		}
		cout<<"NO"<<'\n';
	}

	return 0;
}



