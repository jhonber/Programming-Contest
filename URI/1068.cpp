#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        cnt ++;
      }
      else if (s[i] == ')') {
        if (cnt == 0) cnt = 10000000;
        cnt --;
      }

    }

    cout << (cnt == 0 ? "correct" : "incorrect") << endl;
  }

  return 0;
}
