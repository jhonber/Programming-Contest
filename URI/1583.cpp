#include<bits/stdc++.h>
using namespace std;
 
int visited[55][55];
char mat[55][55];
int x, y;
 
bool check(int i, int j) {
  return i >= x || i < 0 || j >= y || j < 0;
}
 
void dfs(int i, int j) {
  if (!visited[i][j]) {
    mat[i][j] = 'T';
    visited[i][j] = true;
 
    int dx[] = {-1, 0, 1,  0};
    int dy[] = { 0, 1, 0, -1};
    for (int k = 0; k < 4; ++k) {
      int x2 = dx[k] + i;
      int y2 = dy[k] + j;
      if (!check (x2, y2) && mat[x2][y2] == 'A') {
        dfs(x2, y2);
      }
    }
  }
}
 
int main() {
 
  while (cin >> x >> y) {
    if (!x && !y) break;
    memset(visited, 0, sizeof visited);
 
    vector<pair<int,int>> pos;
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 'T') pos.push_back({i,j});
      }
    }
 
    for (int i = 0 ; i < pos.size(); ++i) {
      dfs(pos[i].first, pos[i].second);
    }
 
    for (int i = 0; i < x; ++i) {
      for (int j = 0; j < y; ++j) {
        cout << mat[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
 
  return 0;
}
