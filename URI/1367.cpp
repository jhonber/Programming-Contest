#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    char name;
    int time;
    string verdict;
    map<char, int> mapa;
    int tot = 0;
    int acc = 0;

    for (int i = 0; i < n; ++i) {
      cin >> name >> time >> verdict;

      if (verdict == "incorrect") {
        mapa[name] += 20;
      }
      else {
        tot += mapa[name] + time;
        acc ++;
      }
    }

    cout << acc << " " << tot << endl;
  }

  return 0;
}
