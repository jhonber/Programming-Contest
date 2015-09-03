// http://codeforces.com/contest/548/problem/A

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

bool isPal(string s) {
  for (int i = 0; i <= s.size() / 2; ++i)
    if (s[i] != s[s.size() - i - 1]) return false;
  return true;
}

int main() {
  string s;
  cin >> s;

  int k;
  cin >> k;

  for (int i = 1; i <= s.size(); ++i) {
    int f = true;
    int tot = 0;
    for (int j = 0; j < s.size(); j += i) {
      if (s.size() % i != 0) continue;
      string sub = s.substr(j,i);
      int k = isPal(sub);
      if (!k) f = false;
      tot ++;
    }
    if (f and tot == k) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
  return 0;
}