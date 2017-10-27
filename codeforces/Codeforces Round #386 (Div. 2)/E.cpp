// http://codeforces.com/contest/746/problem/E

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
#ifdef ONLINEJUDGE
  IO
#endif

  int n, m;
  while (cin >> n >> m) {
    vector<int> v(n), out;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      cnt[v[i]] ++;
    }

    out = v;
    int odd = 0, even = 0;
    for (auto i: cnt) {
      if (i.first % 2 == 0) even ++;
      else odd ++;
    }

    int i = 1, j = 2;
    vector<int> a, b;
    while (i <= m || j <= m) {
      if (a.size() < n && i <= m && cnt.count(i) == 0) {
        a.push_back(i);
      }

      if (b.size() < n && j <= m && cnt.count(j) == 0) {
        b.push_back(j);
      }

      i += 2;
      j += 2;
    }

    for (int i = 0; i < n && even < n / 2; ++i) {
      if (cnt[v[i]] > 1 && b.size() > 0) {
        cnt[v[i]] --;
        v[i] = b.back(); b.pop_back();
        even ++;
      }
    }

    for (int i = 0; i < n && odd < n / 2; ++i) {
      if (cnt[v[i]] > 1 && a.size() > 0) {
        cnt[v[i]] --;
        v[i] = a.back(); a.pop_back();
        odd ++;
      }
    }

    vector<int> pos_a, pos_b;
    for (int i = 0; i < n; ++i) {
      if (v[i] % 2 != 0) pos_a.push_back(i);
      else pos_b.push_back(i);
    }

    bool ok = true;
    while (odd != even) {
      if (even < odd) {
        if (b.size() == 0) {
          ok = false;
          break;
        }

        v[pos_a.back()] = b.back();
        b.pop_back();
        pos_a.pop_back();
        even ++;
        odd --;
      }
      else if (even > odd){
        if (a.size() == 0) {
          ok = false;
          break;
        }

        v[pos_b.back()] = a.back();
        a.pop_back();
        pos_b.pop_back();
        odd ++;
        even --;
      }
    }



    if (!ok) cout << "-1" << endl;
    else {
      ok = true;
      odd = 0;
      for (int i = 0; i < n; ++i) {
        odd += (v[i] % 2 == 0);
        if (cnt[v[i]] > 1) ok = false;
      }

      if (odd != n / 2 || !ok) {
        cout << "-1" << endl;
        continue;
      }

      int changed = 0;
      for (int i = 0; i < n; ++i) changed += (v[i] != out[i]);
      cout << changed << endl;
      for (auto i: v) cout << i << " "; cout << endl;
    }
  }

  return 0;
}