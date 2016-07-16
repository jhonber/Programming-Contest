// http://codeforces.com/contest/669/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool check(int x, int &n) {
  return x < 0 || x >= n;
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int good = true;

  int i = 0;
  vector<int> visited(n + 1, 0);
  visited[i] = true;

  while (true) {
    if (s[i] == '>') {
      int next = i + v[i];
      if (!check(next, n) && visited[next]) break;

      if (!check(next, n)) {
        i = next;
        visited[i] = true;
      }
      else {
        good = false;
        break;
      }
    }
    else {
      int next = i - v[i];
      if (!check(next, n) && visited[next]) break;
      if (!check(next, n)) {
        i = next;
        visited[i] = true;
      }
      else {
        good = false;
        break;
      }
    }
  }

  cout << (!good ? "FINITE" : "INFINITE") << endl;

  return 0;
}