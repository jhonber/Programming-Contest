// http://codeforces.com/contest/592/problem/A

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  char mat[8][8];
  for (int i = 0; i < 8; ++i) {
    string line;
    cin >> line;
    for (int j = 0; j < 8; ++j) {
      mat[i][j] = line[j];
    }
  }

  int p1= INT_MAX;
  int p2 = INT_MAX;

  for (int i = 0; i < 8; ++i) {
    int cnt = 0;
    int f = false;
    for (int j = 7; j >= 0; --j) {
      if (mat[j][i] == 'W') break;
      if (mat[j][i] == 'B') {
        f = true;
        break;
      }
      cnt ++;
    }
    if (f) p2 = min(p2, cnt);
  }


  for (int i = 0; i < 8; ++i) {
    int cnt = 0;
    int f = false;
    for (int j = 0; j < 8; ++j) {
      if (mat[j][i] == 'B') break;
      if (mat[j][i] == 'W') {
        f = true;
        break;
      }
      cnt ++;
    }
    if (f) p1 = min(p1, cnt);
  }

  p2 ++;
  if (p1 < p2) cout << "A" << endl;
  else cout << "B" << endl;


  return 0;
}