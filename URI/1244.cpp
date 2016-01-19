#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string n2;
  getline(cin,n2);
  n = atoi(n2.c_str());

  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string word;
    vector<string> mapa[55555];

    while (ss >> word) {
      mapa[(int)word.size()].push_back(word);
    }

    int f = true;
    for (int j = 5555; j >= 0; --j) {
      if (mapa[j].size() > 0) {
        for (int k = 0; k < mapa[j].size(); ++k) {
          if (!f) cout << " " << mapa[j][k];
          else cout << mapa[j][k];
          f = false;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
