// http://codeforces.com/contest/569/problem/B

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
  int n, t;
  cin >> n;

  vector < pair<int,int> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> t;
    v[i] = make_pair(t, i);
  }

  vector< pair<int,int> > ans;
  vector<int> mark(n + 1, 0);
  vector<int> ready(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    int num = v[i].first;
    if (num <= n and !mark[num]) {
      mark[num] = true;
      ready[i] = true;
      swap(v[i].first, v[i].second);
      ans.push_back(v[i]);
    }
  }

  int cnt = 1;
  for (int i = 0; i < n; ++i) {
    if (ready[i]) continue;
    while (cnt <= n and mark[cnt]) cnt ++;
    if (!mark[cnt]) {
      mark[cnt] = true;
      v[i].first = cnt;
      swap(v[i].first, v[i].second);
      ans.push_back(v[i]);
    }
  }

  sort(all(ans));
  for (int i = 0; i < n; ++i) cout << ans[i].second << " ";

  return 0;
}