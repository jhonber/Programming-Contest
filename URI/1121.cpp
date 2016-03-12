#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'

int n, m, s;
char mat[111][111];
map<pair<char, char>, char> mapa;
map<char, int> mapa2;

bool check(int x, int y) {
  return x >= n || x < 0 || y >= m || y < 0 || mat[x][y] == '#';
}

char go (char dir, char step, int &x, int &y, int &ans) {
  int dx[] = {-1, 0, 1,  0};
  int dy[] = {0 , 1, 0, -1};

  if (step != 'F') {
    return mapa[{dir, step}];
  }

  int i = mapa2[dir];
  if (!check(x + dx[i], y + dy[i])) {
    mat[x][y] = '.';
    x += dx[i];
    y += dy[i];
    if (mat[x][y] == '*') {
      ans ++;
    }
  }

  return dir;
}

int main() { IO

  mapa[{'N', 'D'}] = 'L';
  mapa[{'S', 'E'}] = 'L';
  mapa[{'L', 'D'}] = 'S';
  mapa[{'O', 'E'}] = 'S';
  mapa[{'L', 'E'}] = 'N';
  mapa[{'O', 'D'}] = 'N';
  mapa[{'S', 'D'}] = 'O';
  mapa[{'N', 'E'}] = 'O';

  mapa2['N'] = 0;
  mapa2['L'] = 1;
  mapa2['S'] = 2;
  mapa2['O'] = 3;

  while (cin >> n >> m >> s) {
    if (!n) break;

    string ss = "NSLO";
    char dir;
    int x, y;
    for (int i = 0; i < n; ++i) {
      string line;
      cin >> line;
      for (int j = 0; j < m; ++j) {
        mat[i][j] = line[j];
        for (int k = 0; k < ss.size(); ++k)
          if (line[j] == ss[k]) {
            dir = line[j];
            x = i; y = j;
          }
      }
    }

    string path;
    cin >> path;

    int ans = 0;
    for (int i = 0; i < s; ++i) {
      dir = go (dir, path[i], x, y, ans);
    }

    cout << ans << endl;
  }

  return 0;
}