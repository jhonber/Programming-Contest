// http://codeforces.com/contest/466/problem/C

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

  int v[n];
  long long tot = 0;
  for (int i=0; i<n; ++i) {
    cin >> v[i];
    tot += v[i];
  }

  if (tot % 3 == 0) {
    long long numx = tot / 3;
    long long cnt[n];
    memset(cnt,0,sizeof cnt);
    long long sum = 0;

    for (int i=n-1; i>=0; --i) {
      sum += v[i];
      if (sum == numx)
        cnt[i] = 1;
    }

    for (int i=n-2; i+2 >= 0; --i)
      cnt[i] += cnt[i+1];

    long long ans = 0, tmp = 0;
    for (int i=0; i+2 < n; ++i) {
      tmp += v[i];
      if (tmp == numx)
        ans += cnt[i+2];
    }

    cout << ans;
  }
  else cout << 0;

  return 0;
}