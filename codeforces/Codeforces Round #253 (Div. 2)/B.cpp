// http://codeforces.com/contest/443/problem/B

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
  string s;
  int k;

  cin >> s >> k;

  string s2 = s;
  for (int i=0; i<k; ++i)
    s2 += "*";

  int mmax = 0;
  int ans = 0;
  for (int i=0; i<s.size(); ++i){
    for (int j=1; j<=s.size(); ++j){
      string cur = s.substr(i,j);

      int rep = 0;
      for (int k=i; k+cur.size() <= s2.size(); k += cur.size()){
        int f = true;
        for (int x=k, xx=0; xx<cur.size(); ++x, ++xx){
          if (cur[xx] != s2[x] && s2[x] != '*'){
            f = false;
            break;
          }
        }
        if (f) rep++;
        else break;
      }

      if (rep>1 && cur.size() > mmax){
        mmax = cur.size();
        ans = rep*cur.size();
      }
    }
  }

  if (k > s.size())
    ans = ((s.size()+k)/2)*2;

  cout << ans;
  return 0;
}
