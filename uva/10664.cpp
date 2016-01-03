#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(NULL); cin.tie(false);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int go (int i, int sum, int x, vector<int> &v) {
  if (i == v.size()) {
    if (sum == x) return true;
    return false;
  }

  int ans = 0;
  ans += go (i + 1, sum + v[i], x, v);
  ans += go (i + 1, sum, x, v);
  return ans;
}




int main() {
  int n;
  string tmp;
  getline(cin, tmp);

  n = atoi(tmp.c_str());

  for (int i = 0; i < n; ++i) {
    getline(cin, tmp);

    stringstream ss(tmp);
    int x;
    vector<int> v;
    int tot = 0;
    while (ss >> x) {
      v.push_back(x);
      tot += x;
    }

    if (tot % 2 != 0) {
      cout << "NO" << endl;
    }
    else {
      int ans = 0;
      for (int j = 0; j < v.size(); ++j) {
        ans += go (j, 0, tot / 2, v);
      }

      if (ans > 0) {
        cout << "YES" << endl;
      }
      else {
        cout << "NO" <<endl;
      }
    }
  }

  return 0;
}
