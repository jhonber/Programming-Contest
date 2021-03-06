// http://codeforces.com/contest/540/problem/A

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

  string a,b;
  cin >> a >> b;


  int ans = 0;
  for (int i = 0; i < n ; ++i) {
    int t1 = 0, t2 = 0;
    int aa = toInt(a[i]);
    int bb = toInt(b[i]);

    while (aa != bb) {
      t1 ++;
      aa ++;
      if (aa >= 10) aa = aa % 10;
    }

    aa = toInt(a[i]);
    while (aa != bb) {
      t2 ++;
      aa --;
      if(aa == -1) aa = 9;
    }

    ans += min(t1, t2);
  }

  cout << ans;

  return 0;
}