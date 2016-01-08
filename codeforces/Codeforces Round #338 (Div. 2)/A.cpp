// http://codeforces.com/contest/615/problem/A

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int m, n;
  cin >> n >> m;

  set<int> st;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int j = 0; j < a; ++j) {
      int b;
      cin >> b;
      st.insert(b);
    }
  }


  int tot = st.size();
  if (tot == m) cout << "YES";
  else cout << "NO";
  return 0;
}