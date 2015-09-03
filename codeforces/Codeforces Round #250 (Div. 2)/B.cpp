// http://codeforces.com/contest/437/problem/B

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
  int s,l;
  cin >> s >> l;

  vector<int> ans;
  for (int i=l; s>0 && i>=1; --i) {
    int mask = 1;
    int tmp;
    for (int j=0; mask <= i ; j++) {
      if (i & mask) {
        tmp = mask;
        break;
      }
      mask *= 2;
    }
    if (tmp <= s) {
      s -= tmp;
      ans.push_back(i);
    }
  }

  if (s == 0 ) {
    cout << ans.size() << endl;
    for (int i=0; i<ans.size(); ++i)
      cout << ans[i] << " ";
  }
  else cout << -1;

  return 0;
}