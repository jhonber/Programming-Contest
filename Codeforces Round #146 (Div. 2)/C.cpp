// http://codeforces.com/contest/236/problem/C

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

long long lcm (long long a, long long b) {
  return a / __gcd (a, b) * b;
}

int main() {
  int n;
  cin >> n;

  if (n < 4) {
    if (n == 1) cout << 1;
    else if (n == 2) cout << 2;
    else cout << 6;
  }
  else {
    if (n % 2 != 0) {
      cout << (0LL + n) * (0LL + n - 1) * (0LL + n - 2);
    }
    else {
      long long ans = (0LL + n - 1) * (0LL + n - 2) * (0LL + n - 3);
      int a,b,c;
      int cnt1 = 55;
      for (int i = n; cnt1 --> 0 && i > 0; --i) {
        int cnt2 = 55;
        for (int j = i - 1; cnt2 --> 0 && j > 0; --j) {
          int cnt3 = 55;
          for (int k = j - 1; cnt3 --> 0 && k > 0; --k) {
            long long tmp = lcm(i, lcm(j, k));
            if (tmp > ans) {
              a = i; b = j; c = k;
              ans = tmp;
            }
          }
        }
      }
      cout << ans;
    }
  }

  return 0;
}