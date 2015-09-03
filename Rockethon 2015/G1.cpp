// http://codeforces.com/contest/513/problem/G1

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

int n,k;

int getInver (vector<int> &v) {
  int inv = 0;
  int t = v.size();
  for (int i = 0; i < t; ++i) {
    for (int j = i + 1; j < t; ++j) {
      if (v[i] > v[j]) inv ++;
    }
  }
  return inv;
}

double tot;

double f (vector<int> v, int ind, int kk) {
  if (kk == k) return getInver(v);

  double ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      reverse(v.begin() + i, v.begin() + j + 1);
      ans += tot * f (v,ind + 1, kk + 1);
      reverse(v.begin() + i, v.begin() + j + 1);
    }
  }
  return ans;
}

int main() {
  cin >> n >> k;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  tot = 1 / ((n * (n + 1)) / 2.0);
  double ans = f(v,0,0);

  printf("%.16lf", ans);
  return 0;
}