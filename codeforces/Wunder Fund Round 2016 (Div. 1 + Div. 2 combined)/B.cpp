// http://codeforces.com/contest/618/problem/B

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int ind = 0;
  int found = false;
  int mat[n][n];
  for (int i = 0; i < n; ++i) {
    set<int> st;
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
      st.insert(mat[i][j]);
    }

    if (!found && st.size() == n) {
      ind = i;
      found = true;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!mat[ind][i]) cout << n << " ";
    else cout << mat[ind][i] << " ";
  }

  return 0;
}