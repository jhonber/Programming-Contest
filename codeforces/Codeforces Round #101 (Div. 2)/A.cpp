// http://codeforces.com/contest/141/problem/A

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
  string a,b,c;
  cin >> a >> b >> c;

  vector<char> v ,vv;

  for (int i=0; i<a.size(); ++i)
    v.push_back(a[i]);

  for (int i=0; i<b.size(); ++i)
    v.push_back(b[i]);

  for (int i=0; i<c.size(); ++i)
    vv.push_back(c[i]);

  sort (all(v));
  sort (all(vv));

  if (v.size() != vv.size() )
    cout << "NO";
  else {
    int f = true;
    for (int i=0; i<v.size(); ++i)
      if (v[i] != vv[i]){
        f = false;
        break;
      }

    if (f) cout << "YES";
    else cout << "NO";
  }

  return 0;
}
