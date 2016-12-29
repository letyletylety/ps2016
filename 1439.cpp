#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 어차피 한번 뒤집어야 함
// 같이 뒤집는건 크게 의미가 없음
int main()
{
	string s;
	cin>>s;
	auto end = unique(s.begin(), s.end());
	int nn = end - s.begin();	
	cout<< (nn>>1) <<'\n';
	return 0;
}
