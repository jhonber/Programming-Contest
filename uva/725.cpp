#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

pair<int, int> vec_to_int(vector<int> v) {
  int a = 0;
  int b = 0;
  int p = 1;
  for (int i = (v.size() / 2) - 1; i >= 0; --i, p *= 10) {
    a += v[i] * p;
  }

  p = 1;
  for (int i = v.size() - 1; i >= v.size() / 2 ; --i, p *= 10) {
    b += v[i] * p;
  }

  return {a , b};
}

int size (int n) {
  int d = 0;
  while (n) {
    n /= 10;
    d ++;
  }

  return d;
}

int main() {
  vector<int> v = {0,1,2,3,4,5,6,7,8,9};
  vector< pair<int,int> > ans[111];

  do {
    pair<int, int> ab = vec_to_int(v);
    int a = ab.first;
    int b = ab.second;

    if (b > 0) {
      int x = a / b;
      if (a % b == 0) {
        ans[x].push_back({a, b});
      }
    }
  }
  while (next_permutation(v.begin(), v.end()));

  int x;
  int f = false;
  while (cin >> x) {
    if (!x) break;
    if (f) cout << endl;
    if (!ans[x].size()) cout << "There are no solutions for " << x << "." << endl;
    else {
      for (int i = 0; i < ans[x].size(); ++i) {
        int a = ans[x][i].first;
        int b = ans[x][i].second;
        if (size (a) < 5) cout << "0"; cout << a;
        cout << " / ";
        if (size (b) < 5) cout << "0"; cout << b;
        cout << " = " << x << endl;
      }
    }
    f = true;
  }
  return 0;
}
