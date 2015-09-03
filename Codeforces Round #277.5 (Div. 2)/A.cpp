// http://codeforces.com/contest/489/problem/A

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

int main(){ __
  int n;
  cin >> n;

  vector<int> v(n),vv;
  for (int i = 0; i < n; ++i)
    cin >> v[i];

  vv = v;
  sort(all(vv));

  vector<int> mark(n,0);
  vector<pair<int,int> > ans;
  for (int i = 0; i < n; ++i) {
    while (v[i] != vv[i]) {
      for (int j = i; j < n; ++j) {
        if (vv[j] == v[i] && !mark[j]) {
          ans.push_back(make_pair(i,j));
          swap(v[i],v[j]);
          mark[j] = true;
        }
      }
    }
  }

  cout << ans.size()<< endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first << " " << ans[i].second << endl;

  return 0;
}