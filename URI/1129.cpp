#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<char> v = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      int ans = 0;
      for (int j = 0; j < 5; ++j) {
        int a;
        cin >> a;
        if (a <= 127) {
          cnt ++;
          ans = j;
        }
      }
      if (cnt > 1 || cnt == 0) cout << "*" << endl;
      else cout << v[ans] << endl;
    }
  }

  return 0;
}