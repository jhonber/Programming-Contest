// http://codeforces.com/contest/408/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){__

  string s1,s2;

  cin >> s1 >> s2;

  char v[s1.size()];
  char vv[s2.size()];

  map<char,int> mapa1;
  map<char,int> mapa2;

  for(int i=0; i<s1.size(); ++i){
    v[i] = s1[i];
    mapa1[s1[i]] ++;
  }

  for(int i=0; i<s2.size(); ++i){
    vv[i] = s2[i];
    mapa2[s2[i]] ++;
  }

  sort(v,v+s1.size());
  sort(vv,vv+s2.size());

  for(int i=0; i<s2.size(); ++i){
    int f = false;
    for(int j=0; j<s1.size(); ++j){
      if(s2[i] == s1[j]){
        f = true;
        break;
      }
    }
    if(!f){
      cout << -1;
      return 0;
    }
  }

  int ans = 0;

  map<char,int> :: iterator it = mapa2.begin();

  for( ;it != mapa2.end() ; ++it){
    if(it->second > mapa1[it->first])
      ans += mapa1[it->first];
    else
      ans += it->second;
  }

  cout << ans;

  return 0;
}