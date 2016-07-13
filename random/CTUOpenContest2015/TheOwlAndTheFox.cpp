#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int cnt(int n) {
  int tot = 0;
  while (n > 0) {
    tot += n % 10;
    n /= 10;
  }

  return tot;
}

int main() {
  string s;

  while (getline(cin, s)) {
    if (s == "END") break;

    int n = atoi(s.c_str());
    int tot = cnt(n);
    if (tot == 1) {
      cout << 0 << endl;
      continue;
    }

    int k = 0;
    while (n >= 0) {
      n --;
      if (cnt(n) + 1 == tot) {
        cout << n << endl;
        break;
      }
    }

  }

  return 0;
}
