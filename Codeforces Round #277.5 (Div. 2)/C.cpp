// http://codeforces.com/contest/489/problem/C

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

int main(){ //__
  int m,s;
  cin >> s >> m;

  if (s == 1 && m == 0) {
    cout << 0 << " " << 0;
    return 0;
  }

  int mmin = m / s;
  int rest = m - (mmin * s);
  int v[s];

  for (int i = 0; i < s; ++i)
    v[i] = mmin;

  for (int i = 0; i < s && rest; ++i) {
    if ( v[i] + 1 <= 9 ) {
      v[i] ++;
      rest --;
    }
  }

  int summ = 0;
  int paila = false;
  for (int i = 0; i < s; ++i) {
    if (v[i] > 9 )
      paila = true;
    summ += v[i];
  }

  if (summ != m || v[0] == 0 || paila ) {
    cout << -1 << " " << -1 << endl;
    return 0;
  }

  for (int i = 0; i < s; ++i) {
    if (v[i] == 1 && i == 0) continue;
    for (int j = i + 1; j < s; ++j) {
      while (v[j] + 1 <= 9 && ((v[i] - 1 >= 0 && i > 0) || (i==0 && v[i] - 1 > 0)) ) {
        v[i] --;
        v[j] ++;
      }
    }
  }

  for (int i = 0; i < s; ++i)
    cout << v[i];
  cout << " ";


  for (int i = 0; i < s; ++i) {
    if (v[i] == 9) continue;
    for (int j = i + 1; j < s; ++j) {
      while (v[j] - 1 >= 0 && v[i] + 1 <= 9) {
        v[i] ++;
        v[j] --;
      }
    }
  }

  for (int i = 0; i < s; ++i)
    cout << v[i];


  return 0;
}