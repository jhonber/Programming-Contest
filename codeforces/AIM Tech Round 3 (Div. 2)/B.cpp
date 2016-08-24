// http://codeforces.com/contest/709/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) //cout << #x << " = " << (x) << endl;

int main() {
  long long n, a;
  cin >> n >> a;

  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int ind1 = n - 1;
  for (int i = 0; i < n; ++i) {
    if (v[i] > a) {
      ind1 = i;
      break;
    }
  }

  int ind2 = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] > a && i > 0) {
      ind2 = i - 1;
      break;
    }
  }

  D(ind1) D(ind2)
  vector<long long> ans(4, 0);
  long long p = a;
  int k = n - 1;

  vector<int> visited(n, 0);
  int i = ind1;
  while (k > 0 && i + 1 < n) {
    ans[0] += abs(p - v[i]);
    visited[i] = true;
    p = v[i];
    k --;
    i ++;
  }

  i --;
  while (k > 0 && i >= 0) {
    ans[0] += abs(p - v[i]);
    p = v[i];
    if (!visited[i]) k --;
    i --;
  }

  // ---
  for (int i = 0; i < n; ++i) visited[i] = 0;
  k = n - 1;
  p = a;
  i = ind1;
  while (k > 0 && i < n) {
    ans[1] += abs(p - v[i]);
    visited[i] = true;
    p = v[i];
    k --;
    i ++;
  }

  i --;
  while (k > 0 && i >= 0) {
    ans[1] += abs(p - v[i]);
    p = v[i];
    if (!visited[i]) k --;
    i --;
  }

  // ---
  for (int i = 0; i < n; ++i) visited[i] = 0;
  k = n - 1;
  p = a;
  i = ind2;
  while (k > 0 && i > 0) {
    ans[2] += abs(p - v[i]);
    visited[i] = true;
    p = v[i];
    k --;
    i --;
  }

  i ++;
  while (k > 0 && i < n) {
    ans[2] += abs(p - v[i]);
    p = v[i];
    if (!visited[i]) k --;
    i ++;
  }

  // ---
  for (int i = 0; i < n; ++i) visited[i] = 0;
  k = n - 1;
  p = a;
  i = ind2;
  while (k > 0 && i >= 0) {
    ans[3] += abs(p - v[i]);
    visited[i] = true;
    p = v[i];
    k --;
    i --;
  }

  i ++;
  while (k > 0 && i < n) {
    ans[3] += abs(p - v[i]);
    p = v[i];
    if (!visited[i]) k --;
    i ++;
  }


  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;

//  for (int i = 0; i < 4; ++i) cout << ans[i] << " "; cout << endl;

  return 0;
}