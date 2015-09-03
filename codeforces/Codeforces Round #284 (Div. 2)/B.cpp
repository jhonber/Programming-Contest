// http://codeforces.com/contest/499/problem/B

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

int main() { __
  int n,m;
  cin >> n >> m;

  map<string,string> mp1;
  map<string,string> mp2;

  string s1,s2;
  for (int i = 0; i < m; ++i) {
    cin >> s1 >> s2;
    mp1[s1] = s2;
    mp2[s2] = s1;
  }

  vector<string> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  for (int i = 0; i < n; ++i) {
    int t1,t2;
    if (mp1.find( v[i] ) != mp1.end()) {
      t1 = mp1[v[i]].size();
      t2 = mp2[mp1[v[i]]].size();

      if (t1 >= t2) cout << " " << mp2[mp1[v[i]]];
      else cout << " " << mp1[v[i]];
    }
    else if ( mp2.find( v[i] ) != mp2.end() ) {
      t1 = mp2[v[i]].size();
      t2 = mp1[mp2[v[i]]].size();

      if(t1 >= t2) cout << " " << mp1[mp2[v[i]]];
      else cout << " " << mp2[v[i]];
    }
  }

  return 0;
}