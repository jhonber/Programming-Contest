#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  getline(cin, s);

  while (getline(cin, s)) {
    set<char> all;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ' && s[i] != ',') all.insert(s[i]);
    }

    int cnt = all.size();
    if (cnt == 26) cout << "frase completa" << endl;
    else if (cnt >= (26 / 2)) cout << "frase quase completa" << endl;
    else cout << "frase mal elaborada" << endl;
  }

  return 0;
}