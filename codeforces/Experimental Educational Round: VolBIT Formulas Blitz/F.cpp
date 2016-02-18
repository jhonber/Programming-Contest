// http://codeforces.com/contest/630/problem/F

#include<bits/stdc++.h>
using namespace std;

long long pascal[1111][1111];

int main() {
  for (int i = 0; i < 1111; ++i) {
    for (int j = 0; j < 1111; ++j) pascal[i][j] = 1;
  }

  int n;
  cin >> n;

  for (int i = 1; i < 1111; ++i) {
    for (int j = 1; j < 1111; ++j) {
      pascal[i][j] = pascal[i][j - 1] + pascal[i - 1][j];
    }
  }

  cout << pascal[n - 5][5] + pascal[n - 6][6] + pascal[n - 7][7] << endl;
  return 0;
}