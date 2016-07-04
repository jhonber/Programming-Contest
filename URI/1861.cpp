#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a, b;
  map<string, int> mapa;
  vector<string> v;
  set<string> dead;
  while (cin >> a >> b) {
    if (!mapa[a])
      v.push_back(a);
    mapa[a] ++;
    dead.insert(b);
  }

  sort(v.begin(), v.end());

  cout << "HALL OF MURDERERS" << endl;
  for (auto i: v) {
    if (dead.count(i) == 0)
      cout << i << " " << mapa[i] << endl;
  }

  return 0;
}