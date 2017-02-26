// http://codeforces.com/contest/777/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, x;
  while (cin >> n >> x) {
    vector<int> moves = {1, 0, 0, 1, 2, 2};
    int out[3];
    out[0] = moves[(2 + n) % 6];
    out[1] = moves[n % 6];
    out[2] = moves[(4 + n) % 6];

    for (int i = 0; i < 3; ++i) if (out[i] == x) {
      cout << i << endl;
    }
  }

  return 0;
}