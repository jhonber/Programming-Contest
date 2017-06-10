// https://csacademy.com/contest/virtual6147/task/numbers-game/

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  int n;
  cin >> n;

  int ant, ans = 0;
  cin >> ant;

  for (int i = 1; i < n; ++i) {
    int cur;
    cin >> cur;
    if (ant % 10 != cur / 10) ans ++;
    ant = cur;
  }

  cout << ans << endl;;

  return 0;
}
