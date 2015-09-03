// http://codeforces.com/contest/472/problem/A

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

bool good(int a) {
  int d = 2;
  for (;d*d <= a;++d) {
    if (a%d == 0) {
      return true;
    }
  }
  return false;
}

int main(){ __
  int n;
  cin >> n;

  int a = n-1, b = 1;

  while (a>0) {
    if (good(a) && good(b)) {
      cout << a << " " << b <<endl;
      break;
    }
    a--; b++;
  }

  return 0;
}