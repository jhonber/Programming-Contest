// http://codeforces.com/contest/581/problem/C

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

int close(int x) {
  int r = 0;
  while (x % 10 != 0) {
    x ++;
    r ++;
  }
  return r;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector< pair<int, int> > v(n);
  vector<int> mark(n, 0);

  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    v[i] = make_pair(close(t), t);
  }

  sort(all(v));

  int cnt = 0;
  for (int i = 0; i < n && cnt < k; ++i) if (v[i].first > 0) {
    while (v[i].second % 10 != 0 && cnt < k) {
      v[i].second ++;
      cnt ++;
    }
  }

  cnt = k - cnt;
  int ind = 0;
  int f = true;
  while (f && ind < n) {
    if (v[ind % n].second == 100) {
      ind ++;
      continue;
    }
    f = false;
    while (cnt >= 10 && v[ind % n].second + 10 <= 100) {
      v[ind % n].second += 10;
      cnt -= 10;
      f = true;
    }
    ind ++;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans += v[i].second / 10;

  cout << ans;
  return 0;
}