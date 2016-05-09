#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n --> 0) {
    string a, b;
    cin >> a >> b;

    int f = true;
    if (a.size() < b.size()) f = false;
    else {
      for (int i = b.size() - 1, j = a.size() - 1; i >= 0; --i, --j) {
        if (b[i] != a[j]) {
          f = false;
          break;
        }
      }
    }

    cout << (f ? "encaixa" : "nao encaixa") << endl;
  }

  return 0;
}