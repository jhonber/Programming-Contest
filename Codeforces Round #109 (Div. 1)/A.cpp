// http://codeforces.com/contest/154/problem/A

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

int main() { __
  string s;
  cin >> s;

  int k;
  cin >> k;

  map<char,string> mapa;
  for (int i = 0; i < k; ++i) {
    string f;
    cin >> f;

    mapa[f[0]] = f;
    mapa[f[1]] = f;
  }

  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if ( mapa.find(s[i]) != mapa.end() ) {
      string cur = mapa[s[i]];
      map<char,int> tmp;
      while (s[i] == cur[0] || s[i] == cur[1]) {
        tmp[s[i]] ++;
        i++;
      }
      i --;
      ans += min(tmp[cur[0]], tmp[cur[1]]);
    }
  }

  cout << ans;
  return 0;
}