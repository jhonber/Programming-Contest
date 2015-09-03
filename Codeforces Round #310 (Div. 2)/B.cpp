// http://codeforces.com/contest/556/problem/B

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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ant = v[0];
  int cnt = 0;
  int f = true;

  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      v[i] = (v[i] + 1) % n;
    }
    else {
      if (v[i] - 1 < 0) v[i] = n - 1;
      else v[i] --;
    }

    if (cnt != v[i]) f = false;
    cnt ++;
  }

  if (f) {
    cout << "Yes";
    return 0;
  }

  while (v[0] != ant) {
    int cnt = 0;
    int f = true;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        v[i] = (v[i] + 1) % n;
      }
      else {
        if (v[i] - 1 < 0) v[i] = n - 1;
        else v[i] --;
      }
      if (cnt != v[i]) f = false;
      cnt ++;
    }

    if (f) {
      cout << "Yes";
      return 0;
    }
  }

  cout << "No";
  return 0;
}