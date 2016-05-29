#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  long long n, m;
  while (cin >> n >> m) {
    if (n + m == 0) break;
    n *= 100;
    m *= 100;

    long long l;
    cin >> l;

    int k;
    cin >> k;

    vector<int> sizes(k);
    vector<int> v(1000100, 0);

    for (int i = 0; i < k; ++i) {
      int a;
      cin >> a;
      a *= 100;

      v[a] ++;
      sizes[i] = a;
    }

    sort(sizes.begin(), sizes.end());
    reverse(sizes.begin(), sizes.end());

    vector<int> copy = v;

    int ans1 = 0;
    int f = m % l;
    long long tot = 0;

    for (int i = 0; i < sizes.size() && !f && tot < n * m; ++i) {
      int cur = sizes[i];
      int t = n - cur;
      if (t < 0) continue;
      if (t == 0) {
        if (v[cur] > 0) {
          v[cur] --;
          tot += cur * l;
          ans1 ++;
        }
      }
      else {
        if (t != cur) {
          if (v[t] > 0 && v[cur] > 0) {
            v[t] --;
            v[cur] --;
            tot += (t + cur) * l;
            ans1 += 2;
          }
        }
        else {
          if (v[t] > 1) {
            v[t] --;
            v[cur] --;
            tot += (t + cur) * l;
            ans1 += 2;
          }
        }

      }
    }

    if (tot != n * m) ans1 = -1;

    v = copy;
    tot = 0;
    int ans2 = 0;
    f = n % l;

    for (int i = 0; i < sizes.size() && !f && tot < n * m; ++i) {
      int cur = sizes[i];
      int t = m - cur;
      if (t < 0) continue;
      if (t == 0) {
        if (v[cur] > 0) {
          v[cur] --;
          tot += cur * l;
          ans2 ++;
        }
      }
      else {
        if (t != cur) {
          if (v[t] > 0 && v[cur] > 0) {
            v[t] --;
            v[cur] --;
            tot += (t + cur) * l;
            ans2 += 2;
          }
        }
        else {
          if (v[t] > 1) {
            v[t] --;
            v[cur] --;
            tot += (t + cur) * l;
            ans2 += 2;
          }
        }
      }
    }

    if (tot != n * m) ans2 = -1;

    int ans;
    if (ans1 != -1 && ans2 != -1) ans = min(ans1, ans2);
    else ans = max(ans1, ans2);

    if (ans == -1) cout << "impossivel" << endl;
    else cout << ans << endl;
  }
  return 0;
}