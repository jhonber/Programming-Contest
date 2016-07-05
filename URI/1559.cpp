#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;


int main() {
  int t;
  cin >> t;

  while (t --> 0) {
    int mat[4][4];

    int win = false;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 2048) win = true;
      }
    }

    if (win) {
      cout << "NONE" << endl;
      continue;
    }

    vector<int> v(4);
    for (int i = 0; i < 4; ++i) { // up
      for (int j = 0; j < 4; ++j) {
        if (j + 1 < 4 && mat[j][i] > 0 && mat[j][i] == mat[j + 1][i]) v[3] ++;
        if (j + 1 < 4 && !mat[j][i] && mat[j + 1][i] > 0) v[3] ++;
      }
    }

    for (int i = 0; i < 4; ++i) { // left
      for (int j = 0; j < 4; ++j) {
        if (j + 1 < 4 && mat[i][j] > 0 && mat[i][j] == mat[i][j + 1]) v[1] ++;
        if (j + 1 < 4 && !mat[i][j] && mat[i][j + 1] > 0) v[1] ++;
      }
    }

    for (int i = 0; i < 4; ++i) { // right
      for (int j = 3; j >= 0; --j) {
        if (j - 1 >= 0 && mat[i][j] > 0 && mat[i][j] == mat[i][j - 1]) v[2] ++;
        if (j - 1 >= 0 && !mat[i][j] && mat[i][j - 1] > 0) v[2] ++;
      }
    }

    for (int i = 3; i >= 0; --i) { // down
      for (int j = 3; j >= 0; --j) {
        if (j - 1 >= 0 && mat[j][i] > 0 && mat[j][i] == mat[j - 1][i]) v[0] ++;
        if (j - 1 >= 0 && !mat[j][i] && mat[j - 1][i] > 0) v[0] ++;
      }
    }

    vector<string> out = {"DOWN", "LEFT", "RIGHT", "UP"};
    string ans;
    for (int i = 0; i < 4; ++i) if (v[i] > 0) {
      if (ans.size() > 0) ans += " " + out[i];
      else ans += out[i];
    }

    cout << (ans.size() > 0 ? ans : "NONE") << endl;
  }

  return 0;
}