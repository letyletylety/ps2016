#include <iostream> // standard input & output cout cin
#include <cstdio> // scanf printfsssss
#include <vector> // std::vector
#include <algorithm>
#include <string> // std::string
#include <queue> // std::queue
#include <cstring> // memset
#include <set> // std::set
#include <utility> // std::pair, std::make_pair
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <cmath>
#include <climits>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef long double ld;

#define mod 1000000000

const char newline = '\n';

ll powmod(ll a, ll b) {ll res=1; a %= mod; assert(b >= 0); for(; b; b >>= 1) {if (b & 1) res = res * a % mod; a = a * a % mod;} return res;}

struct matrix {
   long long a[2][2];
   matrix() {
      memset(a, 0, sizeof(a));
   }
   matrix operator*(const matrix &b)const {
      matrix c;
      for (int i = 0; i<2; i++) {
         for (int j = 0; j<2; j++) {
            c.a[i][j] = 0;
            for (int k = 0; k<2; k++) {
               c.a[i][j] += a[i][k] * b.a[k][j];
            }
            c.a[i][j] %= mod;
         }
      }
      return c;
   }
};

unsigned long long int fiboCal(long long int n) {
   //fn+1, fn   1 1 ^ n
   //fn, fn-1 = 1 0 
   matrix ans;
   ans.a[0][0] = ans.a[1][1] = 1;
   matrix a;
   a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;

   while (n > 0) {
      if (n % 2 == 1)
         ans = ans * a;
      a = a * a;
      n /= 2;
   }
   return ans.a[0][1];
}

int main(int argc, char **argv)
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	unsigned long long a,b;
	cin>>a>>b;
	cout<<(fiboCal(b+2) - fiboCal(a+1) + mod)%mod<<newline;
  return 0;
}
