#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  while (cin >> n) {
    int mat[n][n];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> mat[i][j];
      }
    }
 
    set<int> ans;
    for (int i = 0; i < 2 * n; ++i) {
      int x, y;
      cin >> x >> y; x --; y --;
      ans.insert(mat[x][y]);
    }
 
    cout << ans.size() << endl;
  }
 
  return 0;
}
