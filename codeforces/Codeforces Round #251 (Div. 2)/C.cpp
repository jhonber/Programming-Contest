// http://codeforces.com/contest/439/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, k, p;
  while (cin >> n >> k >> p) {
    vector<int> a, b;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;

      if (x % 2 == 0) a.push_back(x);
      else b.push_back(x);
    }

    vector<int> sets[k];
    bool ok = true;
    int i = 0;

    while (i < p) {
      if (a.size() > 0) {
        sets[i].push_back(a.back());
        a.pop_back();
      }
      else if (b.size() > 1) {
        sets[i].push_back(b.back());
        b.pop_back();
        sets[i].push_back(b.back());
        b.pop_back();
      }
      else {
        ok = false;
        break;
      };

      i ++;
    }

    for (int j = p; j < k; ++j) {
      if (b.size() > 0) {
        sets[j].push_back(b.back());
        b.pop_back();
      }
      else {
        ok = false;
        break;
      }
    }

    i = k - 1;
    if (p == k || p == 0) {
      if (b.size() % 2 != 0) {
        ok = false;
      }
      else {
        while (a.size() > 0) {
          sets[i].push_back(a.back());
          a.pop_back();
        }

        while (b.size() > 1) {
          sets[i].push_back(b.back());
          b.pop_back();
          sets[i].push_back(b.back());
          b.pop_back();
        }
      }
    }
    else {
      if (b.size() % 2 != 0) {
        ok = false;
      }
      else {
        i = k - 1;
        while (b.size() > 1) {
          sets[i].push_back(b.back());
          b.pop_back();
          sets[i].push_back(b.back());
          b.pop_back();
        }

        i = 0;
        while (a.size() > 0) {
          sets[i].push_back(a.back());
          a.pop_back();
        }
      }
    }

    for (int i = 0; i < k && ok; ++i) {
      int sum = 0;
      for (int j = 0; j < sets[i].size(); ++j) {
        sum += sets[i][j];
        sum %= 2;
      }

      if (i < p && sum % 2 != 0) ok = false;
      if (i >= p && sum % 2 == 0) ok = false;
      if (sets[i].size() == 0) ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
    if (ok) {
      for (int i = 0; i < k; ++i) {
        cout << sets[i].size();
        for (int j = 0; j < sets[i].size(); ++j) cout << " " << sets[i][j];
        cout << endl;
      }
    }
  }

  return 0;
}