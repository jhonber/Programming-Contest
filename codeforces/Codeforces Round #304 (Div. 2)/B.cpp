// http://codeforces.com/contest/546/problem/B

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

  map<int,int> mapa;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    mapa[t] ++;
  }

  vector<long long> no;
  for(int i = 1; i <= 33333; ++i) {
    if (i <= n) {
      if (!mapa[i]) no.push_back(i);
    }
    else no.push_back(i);
  }

  int k = 0;
  long long ans = 0;
  foreach(x, mapa) {
    int t = x->first;
    int cur = x->second;
    if (cur > 1) {
      while (cur --> 1 && k < no.size()) {
        while ( k < no.size() && no[k] < t) k ++;
        ans += abs(no[k] - t);
        k ++;
      }
    }
  }

  cout << ans;

  return 0;
}