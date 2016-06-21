#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

int main() {
  string s;
  vector<string> v;
  map<string, string> mapa;
  while (getline(cin, s)) {

    string s2 = s;
    for (int i = 0; i < s.size(); ++i ) s[i] = tolower(s[i]);
    mapa[s] = s2;
    v.push_back(s);
  }

  sort(v.begin(), v.end());

  int pos = v.size() - 1;
  cout << mapa[v[pos]] << endl;
  return 0;
}