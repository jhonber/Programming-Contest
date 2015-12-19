// http://codeforces.com/contest/298/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int a = 0, b = 0;
  for (int i = 0; i < n; ++i) if (s[i] != '.') {
    a = i;
    break;
  }

  for (int i = n - 1; i >= 0; --i) if (s[i] != '.') {
    b = i;
    break;
  }

  int f = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') f = false;
  }

  if (f) {
    cout << a + 1 << " " << b + 2;
    return 0;
  }

  f = true;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') f = false;
  }

  if (f) {
    cout << b + 1 << " " << a;
    return 0;
  }

  if (s[a] == 'R') {
    cout << a + 1 << " ";
    for (int i = 0; i < n; ++i) if (s[i] == 'L') {
      cout << i;
      break;
    }
  }
  else {
    cout << b + 1 << " " << a;
  }



  return 0;
}