// http://codeforces.com/contest/146/problem/C

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
  string a,b;
  cin >> a >> b;


  int four1 = 0, seven1 = 0;
  int four2 = 0, seven2 = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '4') four1 ++;
    else seven1 ++;
  }

  for (int i = 0; i < b.size(); ++i) {
    if (b[i] == '4') four2++;
    else seven2 ++;
  }



  int change4 = 0;
  int change7 = 0;

  if (four2 > four1) change4 = four2 - four1;
  if (seven2 > seven1) change7 = seven2 - seven1;

  int ans = 0;
  if (change4 > change7) {
    for (int i = 0; i < a.size(); ++i) {
      if (change4 > 0 && a[i] == '7' && b[i] == '4') {
        a[i] = '4';
        change4 --;
        ans ++;
      }
    }
  }
  else {
    for (int i = 0; i < a.size(); ++i) {
      if (change7 > 0 && a[i] == '4' && b[i] == '7') {
        a[i] = '7';
        change7 --;
        ans ++;
      }
    }
  }

  int diff = 0;
  for (int i = 0; i < a.size(); ++i) if (a[i] != b[i]) diff ++;
  ans +=  diff / 2;

  cout << ans;
  return 0;
}