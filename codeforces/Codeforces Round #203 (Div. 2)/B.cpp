// http://codeforces.com/contest/350/problem/B

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

  vector<int> G[111111];
  vector<int> in(111111, 0);
  vector<int> mark(111111, 0);

  for (int i = 0; i < n; ++i) cin >> mark[i];
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (!a) continue;
    a--;
    G[i].push_back(a);
    in[a] ++;
  }

  int mx  = 0;
  int ind = -1;
  vector<int> visited(111111, 0);

  for (int i = 0; i < n; ++i) if (mark[i]) {
    stack<int> Q;
    Q.push(i);
    visited[i] = true;
    int cnt = 0;
    int f = true;

    while (!Q.empty()) {
      int cur = Q.top(); Q.pop();

      if (in[cur] < 2 and !mark[cur] or f) {
        cnt ++;
        f = false;
        for (int j = 0; j < G[cur].size(); ++j) {
          int next = G[cur][j];
          if (!visited[next]) {
            visited[next] = true;
            Q.push(next);
          }
        }
      }
    }

    if (cnt > mx) {
      mx  = cnt;
      ind = i;
    }
  }

  cout << mx << endl;
  vector<int> ans;

  stack<int> Q;
  Q.push(ind);
  visited[ind] = 2;
  int f = true;

  while (!Q.empty()) {
    int cur = Q.top(); Q.pop();

    if (in[cur] < 2 and !mark[cur] or f) {
      f = false;
      ans.push_back(cur + 1);
      for (int j = 0; j < G[cur].size(); ++j) {
        int next = G[cur][j];
        if (visited[next] != 2) {
          visited[next] = 2;
          Q.push(next);
        }
      }
    }
  }

  for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << " ";

  return 0;
}