#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.size();

  map<char, int> mapa;
  set<string> st;

  for (int i = 0; i < n; i += 3) {
    string sub = s.substr(i, 3);
    if (st.count(sub) > 0) {
      cout << "GRESKA" << endl;
      return 0;
    }
    st.insert(sub);
    char p = sub[0];
    mapa[p] ++;
  }

  cout << 13 - mapa['P'] << " " << 13 - mapa['K']
  << " " << 13 - mapa['H'] << " " << 13 - mapa['T'] << endl;
  return 0;
}
