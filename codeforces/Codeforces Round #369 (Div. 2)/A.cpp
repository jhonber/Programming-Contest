// http://codeforces.com/contest/711/problem/A

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int found = false;
  for (int i = 0; i < n; ++i) {
    if (v[i][0] == 'O' && v[i][1] == 'O') {
      v[i][0] = v[i][1] =  '+';
      found = true;
      break;
    }

    if (v[i][3] == 'O' && v[i][4] == 'O') {
      v[i][3] = v[i][4] =  '+';
      found = true;
      break;
    }
  }

  if (found) {
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) cout << v[i] << endl;
  }
  else cout << "NO" << endl;

  return 0;
}