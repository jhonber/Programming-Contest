// http://codeforces.com/contest/513/problem/A

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
  int n1,n2,k1,k2;
  cin >> n1 >> n2 >> k1 >> k2;

  int ans = 0;
  int i = 0;
  while (n1 > 0 && n2 > 0) {
    if (i % 2 == 0) {
      n1 --;
      ans = !ans;
    }
    else {
      n2 --;
      ans = !ans;
    }
    i++;
  }

  cout << (!ans ? "First" : "Second");
  return 0;
}