// http://codeforces.com/contest/841/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n, k;
  while (cin >> n >> k) {
    string s;
    cin >> s;

    map<char, int> cnt;
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i]] ++;
    }

    bool ok = true;
    for (auto i: cnt) {
      if (i.second > k) {
        ok = false;
      }
    }

    cout << (ok ? "YES" : "NO") << endl;
  }

  return 0;
}