#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  int f = false;
  while (getline(cin, s)) {
    if (s == "0") break;

    if (f) cout << endl;
    f = true;
    stringstream ss;
    ss << s;

    int n;
    ss >> n;

    vector<string> v[n];
    vector<int> vv(n, 0);
    int size = 0;
    for (int i = 0; i < n; ++i) {
      getline(cin, s);
      ss.clear();

      ss << s;
      string token;
      int cnt = 0;
      while (ss >> token) {
        cnt += token.size();
        v[i].push_back(token);
      }

      cnt += v[i].size() - 1;
      vv[i] = cnt;
      size = max(size, cnt);
    }

    for (int i = 0; i < n; ++i) {
      int rest = size - vv[i];
      for (int j = 0; j < rest; ++j) cout << " ";
      cout << v[i][0];
      for (int j = 1; j < v[i].size(); ++j) cout << " " << v[i][j];
      cout << endl;
    }
  }

  return 0;
}