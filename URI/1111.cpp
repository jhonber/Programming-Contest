#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct node {
  int x, y, cost;
  node (){}
  node (int a, int b) {x = a; y = b; cost = 0;};
  node (int a, int b, int c) {x = a; y = b; cost = c;};
};

vector<string> mat[111];

int dx[] = {-1, 0, 1,  0};
int dy[] = {0 , 1, 0, -1};

bool valid (int x, int y, int n) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

void bfs (int x1, int y1, int x2, int y2, int n) {
  if (x1 == x2 && y1 == y2) {
    cout << 0 << endl;
    return;
  }

  queue<node> Q;
  Q.push(node(x1, y1));

  int visited[111][111];
  memset(visited, 0, sizeof visited);
  visited[x1][y1] = true;

  while (!Q.empty()) {
    node cur = Q.front(); Q.pop();

    for (int i = 0; i < 4; ++i) {
      if (mat[cur.x][cur.y][i] == '1') {
        int x = cur.x + dx[i];
        int y = cur.y + dy[i];

        if (valid(x, y, n) && !visited[x][y]) {
          if (x == x2 && y == y2) {
            cout << cur.cost + 1 << endl;
            return;
          }

          Q.push(node(x, y, cur.cost + 1));
          visited[x][y] = true;
        }
      }
    }
  }

  cout << "Impossible" << endl;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    for (int i = 0; i < 111; ++i) mat[i].clear();
    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < n; ++k) {
        string s;
        for (int j = 0; j < 4; ++j) {
          char c;
          cin >> c;
          s.push_back(c);
        }

        string s2;
        s2.push_back(s[0]);
        s2.push_back(s[3]);
        s2.push_back(s[1]);
        s2.push_back(s[2]);

        mat[i].push_back(s2);
      }
    }

    int q;
    cin >> q;

    n --;
    int x1, y1, x2, y2;
    for (int i = 0; i < q; ++i) {
      cin >> x1 >> y1 >> x2 >> y2;
      bfs(abs(y1 - n), x1, abs(y2 - n), x2, n + 1);
    }

    cout << endl;
  }

  return 0;
}