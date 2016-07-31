// https://www.hackerrank.com/challenges/preprocessor-solution

// Begin my code
#define INF 10000000
#define toStr(x) (#x)
#define io(v) cin >> v
#define foreach(v,i) for (int i = 0; i < v.size(); ++i)
#define FUNCTION(func, op) void func(int &a, int &b) { a = (a op b ? a : b); }
// End my code

#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
  int n; cin >> n;
  vector<int> v(n);
  foreach(v, i) {
    io(v)[i];
  }
  int mn = INF;
  int mx = -INF;
  foreach(v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  int ans = mx - mn;
  cout << toStr(Result =) <<' '<< ans;
  return 0;
}
