// http://codeforces.com/contest/714/problem/A

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long k;
  pair<long long, long long> a, b;
  cin >> a.first >> a.second >> b.first >> b.second >> k;

  long long tot = 0;

  if (a.second < b.first || b.second < a.first) {
    cout << tot << endl;
    return 0;
  }

  if (a.first >= b.first) {
    tot = min(a.second, b.second) - a.first;

    if (!(k >= a.first && k <= min(a.second, b.second)))
      tot ++;
  }
  else if (b.first >= a.first) {
    tot = min(a.second, b.second) - b.first;
    if (!(k >= b.first && k <= min(a.second, b.second)))
      tot ++;
  }

  cout << tot << endl;
  return 0;
}