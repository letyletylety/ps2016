#include <iostream> // standard input & output cout cin

using namespace std;

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin>>n;
	int g[100000][2];

	for(int i = 0 ; i < n ; i++)
	{
		cin>>g[i][0]>>g[i][1];
	}

	int res = 0;
	int idx = 0;
	for(int grade = 1; grade <= 5; grade++)
	{
		int tt = 0;
		int pre = 0;
		for(int i = 0 ;i < n ; i++)
		{
			if(g[i][0] == grade || g[i][1] == grade)
			{
				pre++;
			}
			else
			{
				if(pre > tt)
					tt = pre;
				pre = 0;
			}		
		}

		if(pre > tt)
			tt = pre;

		if(tt > res)
		{
			res = tt;
			idx = grade;
		}
	}
	cout<<res<<' '<<idx<<'\n';
  return 0;
}
