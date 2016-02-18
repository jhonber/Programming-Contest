#include<bits/stdc++.h>
using namespace std;

int main() {

  vector<string> mat(4);
  for (int i = 0; i < 4; ++i) cin >> mat[i];

  int n = mat[0].size();
  string f, l, m;
  for (int i = 0; i < 4; ++i) f += mat[i][0];
  for (int i = 0; i < 4; ++i) l += mat[i][n - 1];

  long long ff;
  stringstream ss;
  ss << f;
  ss >> ff;

  long long ll;
  stringstream sss;
  sss << l;
  sss >> ll;

  for (int i = 1; i + 1 < n; ++i) {
    stringstream s;
    string mi;
    for (int j = 0; j < 4; ++j) {
      mi += mat[j][i];
    }

    long long m;
    s << mi;
    s >> m;

    ff %= 257;
    ll %= 257;
    m %= 257;

    int c =  (ff * m + ll) % 257;

    cout << char(c);
  }
  cout << endl;
}