// http://codeforces.com/contest/746/problem/D

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool check(string &s, int &n, int &k) {
  string bad1 = string(k + 2, 'G');
  string bad2 = string(k + 2, 'B');

  return s.find(bad1) == string::npos &&
         s.find(bad2) == string::npos &&
         s.size() == n;
}

string brute (string &s, int &n, int &k) {
  sort(s.begin(), s.end());

  do {
    if (check(s, n, k)) {
      return s;
    }
  }
  while (next_permutation(s.begin(), s.end()));
  return "NO";
}

int main() {
  int n, k, a, b;
  while (cin >> n >> k >> a >> b) {
    string ans;
    map<char, int> mapa;
    mapa['G'] = a;
    mapa['B'] = b;

    int l = min(a, b);
    for (int i = 0; i < l; ++i) {
      if (a > b)
        ans += "GB";
      else
        ans += "BG";

      mapa['G'] --;
      mapa['B'] --;
    }

    k --;
    int ind = 0;
    string out;
    for (int i = 0; i < 2 * l; ++i) {
      char cur = ans[i];
      out += cur;
      int c = 0;
      while (c < k && mapa[cur] > 0) {
        out += cur;
        c ++;
        mapa[cur] --;
      }
    }

    while (mapa['G'] > 0) {
      out += 'G';
      mapa['G'] --;
    }

    while (mapa['B'] > 0) {
      out += 'B';
      mapa['B'] --;
    }

    string out1, out2;
    if (check(out, n, k)) out1 = out;
    else out1 = "NO";

    cout << out1 << endl;
    return 0;

    string s2;
    while (a --> 0) s2 += "G";
    while (b --> 0) s2 += "B";
    out2 = brute(s2, n, k);

    if (out1 == "N0" && "N0" != out2 || out2 == "N0" && "N0" != out1) {
      cout << out1 << endl;
      cout << out2 << endl;
      cout << "**" << endl;
    }
  }

  return 0;
}