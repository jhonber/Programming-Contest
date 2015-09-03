// http://codeforces.com/contest/12/problem/B

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

int main() {
  string aa,bb;
  cin >> aa >> bb;

  if (aa == "0" && bb == "0") {
    cout << "OK";
    return 0;
  }

  if (aa == "0" && bb != aa || bb[0] == '0' || aa.size() != bb.size()) {
    cout << "WRONG_ANSWER";
    return 0;
  }

  int a,b;
  a = toInt(aa);
  b = toInt(bb);

  int zeros = 0;
  int mmin = INT_MAX;
  vector<int> v,vv;
  while ( a ) {
    if (a % 10 == 0) zeros ++;
    if (a % 10 > 0) mmin = min(mmin,a % 10);
    v.push_back(a % 10);
    a /= 10;
  }

  while ( b ) {
    vv.push_back(b % 10);
    b /= 10;
  }

  sort(all(v));
  vector<int> ans;

  if (zeros > 0) {
    ans.push_back(mmin);
    for (int i = 0; i < v.size(); ++i) if (mmin == v[i]) {
      v.erase(v.begin() + i, v.begin() + i + 1);
      break;
    }
    for (int i = 0; i < v.size(); ++i) ans.push_back(v[i]);
  }
  else {
    for (int i = 0; i < v.size(); ++i) ans.push_back(v[i]);
  }


  reverse(all(vv));
  int ff = true;
  for (int i = 0; i < vv.size(); ++i) {
    if (vv[i] != ans[i]) ff = false;
  }

  cout << (ff ? "OK" : "WRONG_ANSWER");

  return 0;
}