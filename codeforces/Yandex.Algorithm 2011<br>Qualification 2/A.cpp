// http://codeforces.com/contest/82/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  int n;
  cin >> n;

  vector<string> ans = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

  if (n < 6) {
    n --;
    cout << ans[n % 5];
    return 0;
  }

  int i = 0;
  while (true) {
    int cur = 5 * (1 << i);
    if (n > cur) n -= cur;
    else {
      int pot = 1 << i;
      int ind = n % cur;
      if (!ind) ind = cur;

      if (ind >= 0 && ind <= pot) ind = 0;
      else if (ind > pot && ind <= 2 * pot) ind = 1;
      else if (ind > 2 * pot && ind <= 3 * pot) ind = 2;
      else if (ind > 3 * pot && ind <= 4 * pot) ind = 3;
      else ind = 4;
      cout << ans[ind];
      return 0;
    }
    i++;
  }

  return 0;
}