#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;


int main() { IO
  int TC;
  cin >> TC;
  int t = 1;

  while (TC --> 0) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int rest = a * b;
    vector<int> cnt(26, 0);
    for (int i = 0; i < a; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < s.size(); ++j) {
        cnt[s[j] - 'A'] ++;
      }
    }

    int mx = *max_element(cnt.begin(), cnt.end());
    int tot = 0;
    for (int i = 0; i < 26; ++i) if (cnt[i] == mx) tot ++;

    rest -= (mx * tot);
    cout << "Case " << t << ": " << (mx * tot) * c + rest * d << endl;
    t ++;
  }

  return 0;
}
