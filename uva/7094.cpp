#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cie.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

bool is_prime(int x) {
  if (x == 1) return false;
  if (x == 2) return true;
  int i = 2;
  while (i * i <= x) {
    if (x % i == 0) return false;
    i ++;
  }
  return true;
}

map<int, bool> visited;
bool f (int x) {
  if (x == 1) return true;
  if (visited[x]) return false;

  visited[x] = true;
  int res = 0;
  while (x) {
    int t = x % 10;
    x /= 10;
    res += t * t;
  }

  int ans = 0;
  ans += f (res);

  return ans;
}

int main() {
  int TC;
  cin >> TC;

  while (TC --> 0) {
    int k, m;
    cin >> k >> m;

    visited.clear();
    string ans = ((is_prime(m) && f(m)) ? "YES" : "NO");
    cout << k << " " << m << " " << ans << endl;
  }

  return 0;
}
