#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

set< vector<int> > st;

void go (int i, int sum, int t, int n, vector<int> ans, vector<int> &v) {

  if (sum == t) st.insert(ans);
  if (i == n) return;

  go (i + 1, sum, t, n, ans, v);
  ans.push_back(v[i]);
  go (i + 1, sum + v[i], t, n, ans, v);
}

int main() {
  int t, n;
  while (true) {
    cin >> t >> n;

    if (t + n == 0) break;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) {
      vector<int> ans;
      go (i, 0, t, n, ans, v);
    }

    if (!st.size()) {
      cout << "Sums of " << t << ":" << endl << "NONE" << endl;
      continue;
    }

    cout << "Sums of " << t << ":" << endl;
    set< vector<int> > :: reverse_iterator it;
    for (it = st.rbegin(); it != st.rend(); ++it) {
      vector<int> cur = *it;
      cout << cur[0];
      for (int j = 1; j < cur.size(); ++j) {
        cout << "+" << cur[j];
      }
      cout << endl;
    }
    st.clear();
  }

  return 0;
}
