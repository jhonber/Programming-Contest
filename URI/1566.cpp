#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() { IO
  int t;
  cin >> t;

  while (t --> 0) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    cout << v[0];
    for (int i = 1; i < n; ++i) cout << " " << v[i]; cout << endl;
  }

  return 0;
}
