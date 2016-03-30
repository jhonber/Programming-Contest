#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int m = 131071;
  string all, tmp;
  while (cin >> tmp) {
    all += tmp;
  }

  stringstream ss;
  ss << all;
  string s;

  while (getline(ss, s,'#')) {
    string n = s;
    int i = n.size() - 1;
    long long num = 0;
    long long p = 1;
    for ( ; i >= 0; --i) {
      if (n[i] == '1') {
        num = (num + p) % m;
      }
      p *= 2;
      p %= m;
    }

    if (!num) cout << "YES" << endl;
    else cout << "NO" << endl;
  }



  return 0;
}