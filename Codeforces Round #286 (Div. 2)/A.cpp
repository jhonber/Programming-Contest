// http://codeforces.com/contest/505/problem/A

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

bool ispal(string s) {
  int t = s.size();
  for (int i = 0; i < t / 2; ++i)
    if (s[i] != s[t - i - 1]) return false;
  return true;
}

int main() { __
  string s;
  cin >> s;

  string s2;
  for (int i = 0; i < 26; ++i) {
    char let = i + 'a';
    for (int j = 0; j <= s.size(); ++j) {
      s2 = s;
      s2 = s2.insert(j,toStr(let));
      if (ispal(s2)) {
        cout << s2;
        return 0;
      }
    }
  }

  cout << "NA";

  return 0;
}