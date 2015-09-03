// http://codeforces.com/contest/144/problem/C

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

int main() {
  string s,p;
  cin >> s >> p;

  int v[26], vv[26];
  memset(v,0,sizeof v);
  memset(vv,0,sizeof vv);

  for (int i=0; i<p.size(); ++i) {
    v[p[i]-'a'] ++;
    vv[p[i]-'a'] ++;
  }

  int ans = 0;
  int size = 0;
  int q = 0;
  int t = p.size();
  for (int i=0; i<s.size(); ++i) {

    if (s[i] == '?')
      q ++;
    else if ( vv[s[i]-'a'] )
      v[s[i]-'a'] --;

    size ++;

    if (size == t) {
      int c = 0;
      for (int x=0; x<26; ++x) {
        c += v[x];
        if (v[x] < 0)
          c = 1000;
      }

      if (c==0 || c==q) ans ++;

      if (s[i-size+1] != '?' && v[s[i-size+1]-'a'] < vv[s[i-size+1]-'a'])
        v[s[i-size+1]-'a'] ++;

      if (s[i-size+1] == '?')
        q --;

      size --;
    }
  }

  cout << ans;

  return 0;
}