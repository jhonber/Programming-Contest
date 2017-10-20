// http://codeforces.com/contest/864/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    map<int, int> cnt;
    int x;
    for (int i = 0; i < n; ++i) {
      cin >> x;
      cnt[x] ++;
    }

    if (cnt.size() == 2 && cnt[x] == n / 2) {
      cout << "YES" << endl;
      for (auto i: cnt) cout << i.first << " "; cout << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }

  return 0;
}