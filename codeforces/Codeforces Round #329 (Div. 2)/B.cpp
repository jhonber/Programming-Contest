// http://codeforces.com/contest/593/problem/B

#include<bits/stdc++.h>
using namespace std;
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

long long getY (long long k, long long b, long long x) {
  return k * x + b;
}

bool comp (pair<long long, long long> i, pair<long long, long long> j) {
  if (i.first == j.first) return i.second > j.second;
  return i.first > j.first;
}

int main() {
  int n;

  cin >> n;

  vector< pair<long long, long long> > y(n);
  long long x1, x2;
  cin >> x1 >> x2;

  long long k, b;
  for (int i = 0; i < n; ++i) {
    cin >> k >> b;
    y[i] = make_pair(getY(k, b, x1), getY(k, b, x2));
  }

  sort(y.begin(), y.end(), comp);

  vector<long long> pre(n);
  pre[0] = y[0].second;
  for (int i = 1; i < n; ++i)
    pre[i] = min(pre[i - 1], y[i].second);

  for (int i = 1; i < n; ++i) {
    if (pre[i] < y[i].second) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
  return 0;
}