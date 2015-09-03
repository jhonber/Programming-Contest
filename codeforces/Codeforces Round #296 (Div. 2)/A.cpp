// http://codeforces.com/contest/527/problem/A

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
  long long a,b;
  cin >> a >> b;

  long long ans = 0;
  while (a > 0 && b > 0) {
    long long parts = a / b;
    long long tmp = b;
    b = a - (b * parts);
    a = tmp;
    ans += parts;
    if (a == b) {
      break;
    }
    if (a < b) swap(a,b);
  }

  cout << ans;

  return 0;
}