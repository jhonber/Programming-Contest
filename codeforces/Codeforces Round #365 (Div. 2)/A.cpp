// http://codeforces.com/contest/703/problem/A

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int win = 0;
  int bad = 0;

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a < b) bad ++;
    else if (a > b) win ++;
  }

  if (win == bad) cout << "Friendship is magic!^^" << endl;
  else if (bad > win) cout << "Chris" << endl;
  else cout << "Mishka" << endl;

  return 0;
}