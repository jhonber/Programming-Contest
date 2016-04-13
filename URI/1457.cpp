#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    string num;
    string k;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '!') k.push_back(s[j]);
      else num.push_back(s[j]);
    }

    long long nn;
    stringstream ss;
    ss << num;
    ss >> nn;

    long long kk = k.size();
    long long ans = nn;

    for (long long j = 1; j < 1000; ++j) {
      long long diff = nn - (j * kk);
      if (diff < 1) break;
      ans *= diff;
    }

    cout << ans << endl;
  }

  return 0;
}