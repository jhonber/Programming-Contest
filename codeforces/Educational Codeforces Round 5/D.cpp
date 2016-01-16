// http://codeforces.com/contest/616/problem/D

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() { IO
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ind = 0;
  int i = 0, j = 0;
  int mx = 1;

  int size = 0;
  vector<int> cnt(2000222, 0);
  while (i < n && j < n) {
    if (!cnt[v[j]]) size ++;
    cnt[v[j]] ++;

    if (size <= k) {
      j ++;
      int t = (j - i) + 1;
      if (t > mx) {
        mx = t;
        ind = i;
      }
    }
    else {
      while (i < n && size > k) {
        cnt[v[i]] --;
        if (!cnt[v[i]]) size --;
        i ++;
      }

      cnt[v[j]] --;
      if (!cnt[v[j]]) size --;
    }
  }

  cout << ind + 1 << " " << (ind + mx) - 1;
  return 0;
}