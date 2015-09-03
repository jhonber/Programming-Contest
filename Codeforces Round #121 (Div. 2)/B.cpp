// http://codeforces.com/contest/192/problem/B

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

const int inf = 1000000;
int main() {
  int n;
  cin >> n;


  priority_queue<int, std::vector<int>, std::greater<int> > Q;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    Q.push(v[i]);
  }

  if (n == 1) {
    cout << v[0];
    return 0;
  }

  if (n == 2) {
    cout << *min_element(all(v));
    return 0;
  }



  int ans = 0;
  while (!Q.empty()) {
    int cur = Q.top(); Q.pop();
    ans += cur;
    int mmin = inf;
    for (int i = 0; i < n; ++i) {
      v[i] -= cur;
      if (v[i] < mmin && v[i] > 0) mmin = v[i];
    }

    if (!v[0] || !v[n - 1]) {
      cout << ans;
      return 0;
    }

    int i = 0;
    while (i < n - 1) {
      if (v[i] <= 0 && v[i + 1] <= 0) {
        cout << ans;
        return 0;
      }
      i++;
    }

    Q.push(mmin);
  }

  return 0;
}