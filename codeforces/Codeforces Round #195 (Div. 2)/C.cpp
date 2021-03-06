// http://codeforces.com/contest/336/problem/C

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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i];

  vector<int> ans;
  for (int i=29; i>=0; --i) {
    int curr = 1<<i;
    int val;
    ans.clear();
    for (int j=0; j<n; ++j) {
      if(v[j] & curr) {
        ans.push_back(v[j]);
        if (ans.size() == 1)
          val = ans[0];
        else
          val = val & v[j];
      }
    }

    if (val % curr == 0 & ans.size()>=1) {
      cout << ans.size() << endl;
      for (int j=0; j<ans.size(); ++j)
        cout << ans[j] << " ";
      return 0;
    }
  }

  cout << -1;
  return 0;
}