#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;

      if (!a) cnt ++;
    }

    cout << "Mary won " << cnt << " times and John won " << n - cnt << " times" << endl;
  }

  return 0;
}