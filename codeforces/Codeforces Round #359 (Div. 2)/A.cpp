// http://codeforces.com/contest/686/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  int paila = 0;
  for (int i = 0; i < n; ++i) {
    char op;
    int x;
    cin >> op >> x;

    if (op == '+') m += x;
    else {
      if (x > m) paila ++;
      else m -= x;
    }
  }

  cout << m << " " << paila << endl;
  return 0;
}