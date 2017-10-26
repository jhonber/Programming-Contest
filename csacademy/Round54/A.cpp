#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    int tot = 0;
    for (int i = 0; i < k; ++i) {
       tot += v[i];
    }

    cout << (int)ceil(tot / 100.0) << endl;
  }

  return 0;
}
