#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;

  while (cin >> n) {
    stack<int> S;
    queue<int> Q;
    priority_queue<int> PQ;

    int v[3] = {1, 1, 1};
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      if (a == 1) {
        S.push(b);
        Q.push(b);
        PQ.push(b);
      }
      else {
        int x1 = S.top(); S.pop();
        int x2 = Q.front(); Q.pop();
        int x3 = PQ.top(); PQ.pop();

        if (x1 != b) v[0] = 0;
        if (x2 != b) v[1] = 0;
        if (x3 != b) v[2] = 0;
      }
    }

    string ans;
    if (v[0] == 1 && !v[1] && !v[2]) ans = "stack";
    else if (v[1] == 1 && !v[0] && !v[2]) ans = "queue";
    else if (v[2] == 1 && !v[0] && !v[1]) ans = "priority queue";
    else if (v[0] + v[1] + v[2] == 0) ans = "impossible";
    else ans = "not sure";

    cout << ans << endl;
  }

  return 0;
}