#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n, l, c;
  string s;

  while (cin >> n >> l >> c) {
    cin >> s;
    int ans = 1;
    int size = s.size();

    for (int i = 1; i < n; ++i) {
      cin >> s;
      int t = s.size() + 1;

      if (size + t <= c) {
        size += t;
      }
      else {
        size = s.size();
        ans ++;
      }
    }

    cout << ceil((double)ans / l) << endl;
  }

  return 0;
}