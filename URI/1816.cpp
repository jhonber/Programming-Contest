#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  int TC = 1;
  while (cin >> n) {
    if (!n) break;

    vector<char> v(26);
    for (int i = 0; i < 26; ++i) v[i] = char(i + 'a');

    vector<char> ans;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a; a --;

      char c = v[a];
      ans.push_back(c);
      v.erase(v.begin() + a);
      v.insert(v.begin(), c);
    }

    cout << "Instancia " << TC ++ << endl;
    for (int i = 0; i < ans.size(); ++i) {
      ans[i] = toupper(ans[i]);
      cout << ans[i];
    }
    cout << endl << endl;
  }

  return 0;
}