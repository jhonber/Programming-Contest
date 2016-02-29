#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int go (int dir, char c) {
  if (dir == 0 && c == 'D') {
    return 1;
  }

  if (dir == 0 && c == 'E') {
    return 3;
  }

  if (dir == 1 && c == 'D') {
    return 2;
  }

  if (dir == 1 && c == 'E') {
    return 0;
  }

  if (dir == 2 && c == 'D') {
    return 3;
  }

  if (dir == 2 && c == 'E') {
    return 1;
  }

  if (dir == 3 && c == 'D') {
    return 0;
  }

  if (dir == 3 && c == 'E') {
    return 2;
  }
}

int main() {
  int n;

  while (cin >> n) {
    if (!n) break;

    string s;
    cin >> s;

    int dir = 0;
    for (int i = 0; i < n; ++i) {
      dir = go (dir, s[i]);
    }

    string ans = "NLSO";
    cout << ans[dir] << endl;
  }

  return 0;
}
