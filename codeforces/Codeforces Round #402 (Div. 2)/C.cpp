// http://codeforces.com/contest/779/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

struct item {
  int x, y;
  item(){}
  item(int a, int b){
    x = a;
    y = b;
  }

  bool operator < (item const &other) const {
    int a = x + other.y;
    int b = other.x + y;
    if (a == b) return y > other.y;
    return a < b;
  }
};

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<item> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(item(a[i], b[i]));
  }

  sort(v.begin(), v.end());

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      ans += v[i].x;
    }
    else {
      ans += min(v[i].x, v[i].y);
    }
  }

  cout << ans << endl;

  return 0;
}