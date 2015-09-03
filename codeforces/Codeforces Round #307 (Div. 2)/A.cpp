// http://codeforces.com/contest/551/problem/A

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
  int n;
  cin >> n;

  vector< pair<int,int> > v(n);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    v[i] = make_pair(a,i);
  }
  
  sort(all(v));
  
  vector< pair<int,int> > ans;
  int cnt = 1;
  int mmax = v[n - 1].first;
  for (int i = n - 1; i >= 0; ) {
    int tot = 0;
    while (v[i].first == mmax) {
      ans.push_back(make_pair(v[i].second, cnt));
      -- i;
      tot ++;
    }

    mmax = v[i].first;
    cnt += tot;
  }
  sort(all(ans));
  for (int i = 0; i < n; ++i) cout << ans[i].second << " ";
  return 0;
}

