#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n --> 0) {
    string a, b;
    cin >> a >> b;

    int ans = true;
    if (b.size() > a.size()) ans = false;

    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 && j >= 0) {
      if (a[i] != b[j]) {
        ans = false;
        break;
      }

      i --;
      j --;
    }

    cout << (ans ? "encaixa" : "nao encaixa") << endl;
  }

  return 0;
}