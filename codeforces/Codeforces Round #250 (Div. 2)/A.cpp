// http://codeforces.com/contest/437/problem/A

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

  vector<string> v(4);
  for (int i=0; i<4; ++i){
    cin >> v[i];
    v[i] = v[i].substr(2,v[i].size());
  }

  int vv[4] = {0,0,0,0};
  char vvv[4] = {'A','B','C','D'};

  for (int i=0; i<4; ++i){
    int f = true;
    int ff = true;
    for (int j=0; j<4; ++j){
      if (i==j) continue;
      if (v[i].size()*2 > v[j].size())
        f = false;

      if (v[i].size() < v[j].size()*2)
        ff = false;
    }

    if (f || ff)
      vv[i] = true;
  }

  if (vv[0]+vv[1]+vv[2]+vv[3] == 1){
    for (int i=0; i<4; ++i)
      if (vv[i]) cout << vvv[i];
  }
  else
    cout << "C";

  return 0;
}