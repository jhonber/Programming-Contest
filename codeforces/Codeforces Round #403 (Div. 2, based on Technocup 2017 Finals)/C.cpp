// http://codeforces.com/contest/782/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MX = 222222;
int ans;
int color[MX];
vector<int> G[MX];

void paint (int cur, int bef, int next) {
  if (!color[cur]) {
    color[cur] = next;
    ans = max(ans, next);

    int t = G[cur].size();
    set<int> ready;
    for (int i = 0; i < t; ++i) {
      int other = G[cur][i];
      if (color[other]) continue;

      for (int j = 1; j <= MX; ++j) {
        if (j != next && j != bef && ready.count(j) == 0) {
          ready.insert(j);
          paint(other, next, j);
          break;
        }
      }
    }
  }
}

int main() {
#ifdef ONLINE_JUDGE
  IO
#endif

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  int tot = 0;
  int ind = 0;
  for (int i = 1; i <= n; ++i) {
    int t = G[i].size();
    if (t > tot) {
      ind = i;
      tot = t;
    }
  }


  memset(color, 0, sizeof color);
  color[ind] = 1;
  ans = 1;

  int cnt = 2;
  for (int i = 0; i < G[ind].size(); ++i) {
    paint (G[ind][i], 1, cnt);
    cnt ++;
  }

  cout << ans << endl;
  for (int i = 1; i <= n; ++i) {
    cout << color[i] << " ";
  }
  cout << endl;

  return 0;
}
