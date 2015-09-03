// http://codeforces.com/contest/465/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  int n;
  cin >> n;

  string cell, cell2;
  cin >> cell;

  cell2 = cell;

  int carry = false;
  for (int i=0; i<n; ++i) {
    if ((cell[i] == '1' && carry) || ( cell[i] == '1' && !i)) {
      cell[i] = '0';
      carry = true;
      continue;
    }

    if (cell[i] == '0' && carry) {
      cell[i] = '1';
      carry = false;
      continue;
    }

    if (cell[i] == '0' && !i) {
      cell[i] = '1';
      if (!i) break;
    }
  }

  int ans = 0;
  for (int i=0; i<n; ++i)
    if (cell[i] != cell2[i])
      ans ++;

  cout << ans;
  return 0;
}