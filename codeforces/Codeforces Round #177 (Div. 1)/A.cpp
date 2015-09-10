// http://codeforces.com/contest/288/problem/A

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
  int n, k;
  cin >> n >> k;

  if (k > n or k == 1 and n > 1) {
    cout << -1;
    return 0;
  }

  string s;
  for (int i = 0; i < k; ++i) s += toStr(char(i + 'a'));

  if (n == k) {
    cout << s;
    return 0;
  }

  int rest = n - k;
  int tot = rest - (rest % 2);

  cout << s[0];
  for (int i = 0; i < tot / 2; ++i) cout << "ba";

  cout << s[1];
  if (rest % 2) cout << "a";
  for (int i = 2; i < k; ++i) cout << s[i];
  cout << endl;

  return 0;
}