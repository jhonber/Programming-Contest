// http://codeforces.com/contest/6/problem/C

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

  if (n == 1) {
    cout << "1 0";
    return 0;
  }

  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  if (n == 3) {
    if (v[0] <= v[2]) cout << "2 1";
    else cout << "1 2";
    return 0;
  }

  vector<int> sum(n + 10, 0);
  for (int i = n; i >= 1; --i) sum[i] += v[i - 1] + sum[i + 1];

  int j = 1;
  int left = v[0];
  while (j + 1 < n and left <= sum[j + 2]) {
    left += v[j];
    j ++;
  }

  cout << j << " " << n - j;
  return 0;
}