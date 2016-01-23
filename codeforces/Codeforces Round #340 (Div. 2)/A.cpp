// http://codeforces.com/contest/617/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << endl;

int main() {
  int x;
  cin >> x;

  int ans = 0;
  while (x >= 5) {
    x -= 5;
    ans ++;
  }

  while (x >= 4) {
    x -= 4;
    ans ++;
  }

  while (x >= 3) {
    x -= 3;
    ans ++;
  }

  while (x >= 2) {
    x -= 2;
    ans ++;
  }

  while (x >= 1) {
    x -= 1;
    ans ++;
  }


  cout << ans;

  return 0;
}