// http://codeforces.com/contest/146/problem/B

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

bool check(string a,string b) {
  string res;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] == '4' || a[i] == '7') res += a[i];
  }

  if (res == b) return true;
  return false;
}

int main() {
  string a,b;
  cin >> a >> b;

  a = toStr(toInt(a) + 1);
  while (true){
    if (check(a,b)) {
      cout << a;
      return 0;
    }
    a = toStr(toInt(a) + 1);
  }

  return 0;
}