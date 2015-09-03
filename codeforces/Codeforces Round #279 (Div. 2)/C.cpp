// http://codeforces.com/contest/490/problem/C

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

int main(){ __
  string k;
  int a,b;
  cin >> k >> a >> b;

  int s = k.size();
  int left[s - 1], right[s - 1];

  int mod = 0;
  for (int i = 0; i < s; ++i) {
    mod = (mod * 10) + (k[i] - '0');
    mod %= a;
    left[i] = mod;
  }

  int mod2 = 0;
  int p = 1;
  for (int i = s - 1; i >= 0; --i) {
    mod2 = mod2 + ((k[i] - '0') * p);
    mod2 %= b;
    right[i] = mod2;
    p = (p * 10) % b;
  }


  for (int i = 0; i < s - 1; ++i) {
    if (!left[i] && !right[i + 1] && k[i + 1] != '0') {
      cout << "YES" << endl << k.substr(0,i + 1) << endl << k.substr(i + 1, s) << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}