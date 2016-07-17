// http://codeforces.com/contest/665/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool is_prime (int x) {
  if (x == 2) return true;
  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) return false;
    i ++;
  }

  return true;
}

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int found = false;
  int a, b;
  for (int i = 0; i < n && !found; ++i) {
    a = v[i];
    for (int j = i + 1; j < n; ++j) {
      if (is_prime(v[i] + v[j])) {
        b = v[j];
        found = true;
        break;
      }
    }
  }

  sort(v.begin(), v.end());
  int ones = 0;
  int other = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] != 1) {
      while (i < n) {
        if (is_prime(v[i] + 1)) {
          other = v[i];
          break;
        }
        i ++;
      }
      break;
    }
    ones ++;
  }

  if (ones + (other > 0 ? 1 : 0) > 2) {
    cout << ones + (other > 0 ? 1 : 0) << endl;
    for (int i = 0; i < ones; ++i) cout << 1 << " ";
    if (other) cout << other << endl;
  }
  else if (found) {
    cout << 2 << endl;
    cout << a << " " << b << endl;
  }
  else {
    cout << 1 << endl << v[0] << endl;
  }

  return 0;
}