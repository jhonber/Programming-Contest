// http://codeforces.com/contest/244/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> get(k, 0);
  vector<int> v(k * n, -1);
  for (int i = 0; i < k; ++i) {
    int a;
    cin >> a;
    v[a - 1] = i;
    get[i] ++;
  }

  int ind = 0;
  int f = true;
  while (f) {
    int cur = get[ind];
    f = false;

    for (int i = 0; i < k * n && cur < n; ++i) if (v[i] == -1) {
      v[i] = ind;
      cur ++;
      f = true;
    }
    ind ++;
  }

  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k * n; ++j) if (v[j] == i) {
      cout << j + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}