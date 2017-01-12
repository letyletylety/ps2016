#include <cstdio>
#include <algorithm>

#define N 100001

/* convex hull optimization */

using namespace std;

struct line // 선분 하나를 표시
{ 
	long long int m, c; // 기울기와 y 절편

	// y = ax + b
	line(long long int mm = 0, long long int mc = 0)
	{
		m = mm;
		c = mc;
	}
};

long long int D[N];
long long int A[N], B[N];
line stack[N];
int size, last;

double cross_xpoint(line &A, line &B) // 두 선분의 교점의 x 좌표
{
	return (double)(B.c - A.c)/(A.m - B.m);
}

void insert(long long int x, long long int y) // stack push 연산
{
	stack[size] = line(x,y); 
	
	// 단 이전 두 직선의 교점보다 현재 직선과 top에 있던 직선과의 교점을
	// 비교해서
	// 현재 들어온 직선과 top의 교점이 더 왼쪽에 있으면 top을 고려할 필요없음
	while( size >= 2 && cross_xpoint(stack[size-2], stack[size-1]) > cross_xpoint(stack[size-1], stack[size]))
	{
		stack[size-1] = stack[size];
		size -= 1;
	}
	size += 1;
}

long long query(long long x)
{ 
	// x좌표가 주어졌을때 가장 작은 y값
	// stack에 들어있는 직선들만 가지고 구해준다.	
	while(last + 1 < size && cross_xpoint(stack[last], stack[last+1]) <= x)
	{
		last += 1;
	}
	return x*stack[last].m + stack[last].c;
}

int main()
{
	int n;
	scanf("%d", &n);

	for(int i = 0 ; i < n ; i++)
		scanf("%lld", A+i);
	for(int i = 0 ; i < n ; i++)
		scanf("%lld", B+i);

	// 첫 직선은 그냥 넣어준다.
	insert(B[0], D[0]); // y = B[0] * x + D[0]
	for(int i = 1; i< n ; i++)
	{
		// 쿼리 한번 돌려줌
		// D[i] = A[i] 에서 최소값
		D[i] = query(A[i]);
		insert(B[i], D[i]);
	}

	printf("%lld", D[n-1]);
	return 0;
}
