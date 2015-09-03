// http://codeforces.com/contest/448/problem/B

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
  string a,b;
  cin >> a >> b;

  vector<int> v;
  int pos = 0;
  for (int i=0; i<b.size(); ++i) {
    for (int j=pos; j<a.size(); ++j) {
      if (b[i] == a[j]) {
        v.push_back(j);
        pos = j+1;
        break;
      }
    }
  }

  if (v.size() != b.size()) {
    v.clear();
    for (int i=0; i<b.size(); ++i) {
      int f = true;
      for (int j=0; j<a.size(); ++j) {
        if (b[i] == a[j]) {
          v.push_back(j);
          a[j] = '*';
          f = false;
          break;
        }
      }
      if (f) {
        cout << "need tree";
        return 0;
      }
    }
    if (a.size() != b.size())
      cout << "both";
    else
      cout << "array";
  }
  else
    cout << "automaton";

  return 0;
}