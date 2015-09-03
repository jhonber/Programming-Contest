// http://codeforces.com/contest/412/problem/C

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

const int MAX = 10e5;

int main(){ __
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector< set<char> > v(s.size());
  for (int i=0; i<s.size(); ++i)
    v[i].insert(s[i]);

  for (int i=0; i<n-1; ++i){
    cin >> s;

    for (int j=0; j<s.size(); ++j)
      v[j].insert(s[j]);
  }

  for (int i=0; i<s.size(); ++i){
    if (v[i].size() == 1){
      char c = *v[i].begin();
      if (c == '?')
        cout << "a";
      else
        cout << c;
    }
    else if (v[i].size() == 2){
      vector<char> tmp;
      foreach(x,v[i])
        tmp.push_back(*x);

      if (tmp[0] != '?' && tmp[1] != '?')
        cout << "?";
      else
        cout << (tmp[0]=='?' ? tmp[1] : tmp[0]);
    }
    else
      cout << "?";
  }

  return 0;
}
