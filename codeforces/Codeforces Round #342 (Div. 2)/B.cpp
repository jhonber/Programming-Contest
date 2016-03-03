// http://codeforces.com/contest/625/problem/B

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int solve(string s, string r) {
  int ind = 0;
  int cnt = 0;

  while (ind < s.size()) {
    int i = s.find(r, ind);
    if (i == string::npos) break;
    cnt ++;
    ind = i + r.size();
  }

  return cnt;
}

int main() { IO
  string s, r;
  while (cin >> s >> r) {
    cout << solve(s, r) << endl;
  }

  return 0;
}