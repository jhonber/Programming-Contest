#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int h, m;
  while (scanf("%d:%d", &h, &m) != EOF) {
    int cnt = 0;
    while (cnt < 60) {
      m ++;
      if (m >= 60) {
        m = 0;
        h ++;
      }
      cnt ++;
    }

    cout << "Atraso maximo: ";
    if (h < 8) cout << 0 << endl;
    else {
      cout << m + ( (h - 8) * 60) << endl;
    }
  }

  return 0;
}