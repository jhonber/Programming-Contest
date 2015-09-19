// http://codeforces.com/contest/4/problem/B

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
  int d, sum;
  cin >> d >> sum;

  int a,b;
  vector<int> v(d);
  vector<int> ans(d);

  int tot = 0;
  for (int i = 0; i < d; ++i) {
    cin >> a >> b;
    v[i] = b;
    ans[i] = a;
    tot += a;
  }

  if (tot == sum) {
    cout << "YES" << endl;
    for (int i = 0; i < d; ++i) cout << ans[i] << " ";
    return 0;
  }

  int lim = 1000000;
  while (lim --> 0) {
    for (int i = 0; i < d; ++i) {
      if (ans[i] < v[i]) {
        ans[i] ++;
        tot ++;

        if (tot == sum) {
          cout << "YES" << endl;
          for (int i = 0; i < d; ++i) cout << ans[i] << " ";
          return 0;
        }

      }
    }
  }

  cout << "NO";
  return 0;
}