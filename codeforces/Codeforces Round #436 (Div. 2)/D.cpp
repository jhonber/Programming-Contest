// http://codeforces.com/contest/864/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    set<int> lack;
    map<int, int> cnt;
    for (int i = 1; i <= n; ++i) lack.insert(i);

    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      lack.erase(v[i]);
      cnt[v[i]] ++;
    }

    int tot = 0;
    int i = 0;
    set<int> ready;
    while (lack.size() > 0 && i < n) {
      int f = *lack.begin();
      if (cnt[v[i]] == 1) {
        ready.insert(v[i]);
        i ++;
        continue;
      }

      if (v[i] > f || ready.count(v[i]) > 0) {
        lack.erase(f);
        ready.insert(f);
        cnt[v[i]] --;
        v[i] = f;
        tot ++;
      }
      else {
        ready.insert(v[i]);
      }

      i ++;
    }

    cout << tot << endl;
    for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;
  }

  return 0;
}