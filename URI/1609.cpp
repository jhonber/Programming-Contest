#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t, n;
  cin >> t;

  while (t --> 0) {
    cin >> n;

    set<int> st;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      st.insert(a);
    }

    cout << st.size() << endl;
  }

  return 0;
}