// http://codeforces.com/contest/474/problem/A

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

int main(){ __
  string ss = "qwertyuiopasdfghjkl;zxcvbnm,./";
  char c;
  string s, ans;

  cin >> c >> s;
  for (int i = 0; i < s.size() ; ++i) {
    for (int j = 0; j < ss.size(); ++j) {
      if (ss[j] == s[i]) {
        if (c == 'R') {
          ans += toStr(ss[j-1]);
        }
        else {
          ans += toStr(ss[j+1]);
        }
      }
    }
  }

  cout << ans;
  return 0;
}