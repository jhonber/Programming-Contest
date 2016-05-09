#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  string line;
  getline(cin, line);
  n = atoi(line.c_str());

  while (n --> 0) {
    map<char, int> mapa;

    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);

    int paila = false;
    for (int i = 0; i < a.size(); ++i) mapa[a[i]] ++;

    for (int i = 0; i < b.size(); ++i) {
      int tot = mapa.count(b[i]);
      if (tot == 0 || tot > 2) paila = true;
      mapa[b[i]] ++;
    }

    for (int i = 0; i < c.size(); ++i) {
      int tot = mapa.count(c[i]);
      if (tot == 0 || tot > 2) paila = true;
      mapa[c[i]] ++;
    }

    if (paila) {
      cout << "CHEATER" << endl;
      continue;
    }

    vector<char> ans;
    for (auto i: mapa) {
      char l = i.first;
      int val= i.second;
      if (val == 1) ans.push_back(l);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i]; cout << endl;
  }

  return 0;
}