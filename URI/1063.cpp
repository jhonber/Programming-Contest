#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<char> v(n), out(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) cin >> out[i];

    reverse(v.begin(), v.end());
    reverse(out.begin(), out.end());

    string ans;
    vector<char> Q;

    while (!v.empty()) {
      char first = v.back(); v.pop_back();
      Q.push_back(first);
      ans += "I";

      while (!Q.empty() && Q.back() == out.back()) {
        ans += "R";
        Q.pop_back();
        out.pop_back();
      }
    }

    int paila = false;
    while (!Q.empty()) {
      char first = Q.back(); Q.pop_back();
      char other = out.back(); out.pop_back();

      if (first != other) {
        paila = true;
        break;
      }
      ans += "R";
    }

    cout << ans << (paila ? " Impossible" : "") << endl;
  }

  return 0;
}