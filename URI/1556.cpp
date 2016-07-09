#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios::sync_with_stdio(false); cin.tie(NULL);

vector<string> ans;
unordered_map<string, bool> mapa;
int n;

void go (string s) {
  ans.push_back(s);
  if (s.size() == 1) return;

  for (int i = 0; i < s.size(); ++i) {
    string bef = s;
    bef.erase(bef.begin() + i);
    if (mapa.count(bef) == 0) {
      mapa[bef] = true;
      go (bef);
    }
  }
}

int main() { IO
  string s;
  while (cin >> s) {
    go(s);
    sort(ans.begin(), ans.end());
    for (auto i: ans) cout << i << endl;
    cout << endl;
    ans.clear();
    mapa.clear();
  }

  return 0;
}