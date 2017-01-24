// http://codeforces.com/contest/714/problem/B

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);

  int mx = -1;
  int mm = INT_MAX;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];

    mx = max(mx, v[i]);
    mm = min(mm, v[i]);
  }

  set<int> tmp;
  tmp.insert(v.begin(), v.end());
  if (tmp.size() <= 2) {
    cout << "YES" << endl;
    return 0;
  }

  int mid = (mx + mm) / 2;

  set<int> st;
  for (int i = 0; i < n; ++i) {
    if (abs(mid - v[i]) != 0) {
      st.insert(abs(mid - v[i]));
    }
  }

  cout << (st.size() == 1 ? "YES" : "NO") << endl;
  return 0;
}