#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int mat[9][9];
bool check () {
  for (int j = 0; j < 9; ++j) {
    set<int> st;
    for (int k = 0; k < 9; ++k) st.insert(mat[j][k]);
    if (st.size() < 9) return false;
  }

  for (int j = 0; j < 9; ++j) {
    set<int> st;
    for (int k = 0; k < 9; ++k) st.insert(mat[k][j]);
    if (st.size() < 9) return false;
  }

  vector<set<int>> v(9);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (i >= 0 && i <= 2) {
        if (j >= 0 && j <= 2) {
          v[0].insert(mat[i][j]);
        }
        else if (j >= 3 && j <= 5) {
          v[1].insert(mat[i][j]);
        }
        else {
          v[2].insert(mat[i][j]);
        }
      }
      else if (i >= 3 && i <= 5) {
        if (j >= 0 && j <= 2) {
          v[3].insert(mat[i][j]);
        }
        else if (j >= 3 && j <= 5) {
          v[4].insert(mat[i][j]);
        }
        else {
          v[5].insert(mat[i][j]);
        }
      }
      else {
        if (j >= 0 && j <= 2) {
          v[6].insert(mat[i][j]);
        }
        else if (j >= 3 && j <= 5) {
          v[7].insert(mat[i][j]);
        }
        else {
          v[8].insert(mat[i][j]);
        }
      }
    }
  }

  for (int i = 0; i < 9; ++i) if (v[i].size() < 9) return false;

  return true;
}

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    for (int j = 0; j < 9; ++j) {
      for (int k = 0; k < 9; ++k) {
        cin >> mat[j][k];
      }
    }

    cout << "Instancia " << i << endl;

    int t = check();
    cout << (t ? "SIM" : "NAO") << endl;
    cout << endl;
  }

  return 0;
}