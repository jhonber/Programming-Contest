// http://codeforces.com/contest/591/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl "\n"
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  map<char, char> mapa;
  for (int i = 0; i < 26; ++i) {
    mapa[char(i + 'a')] = char(i + 'a');
  }

  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  for (int i = 0; i < m; ++i) {
    char a, b;
    cin >> a >> b;

    char t1, t2;
    for (auto j : mapa) {
      if (j.second == a) t1 = j.first;
      if (j.second == b) t2 = j.first;
    }
    swap(mapa[t1], mapa[t2]);
  }

  for (int i = 0; i < n; ++i) {
    cout << mapa[s[i]];
  }

  return 0;
}