// http://codeforces.com/contest/510/problem/D

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

vector<int> v(303), cost(303);

const int inf = 30300000;

int n;

map< pair<int,int> ,int> dp;

int f(int i, int gcd) {
  pair<int,int> p = make_pair(i,gcd);
  if (dp.count(p)) return dp[p];
  if (gcd == 1) return cost[i];
  if (i == n - 1) return inf;

  int ans = inf;
  for (int j = i + 1; j < n; ++j) {
    ans = min(ans, cost[i] + f(j , __gcd(gcd,v[j])));
  }
  return dp[p] = ans;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i) cin >> cost[i];

  int ans = inf;
  for (int i = 0; i < n; ++i) {
    int t = f(i,v[i]);
    dp[make_pair(i,v[i])] = ans = min(ans,t);
  }
  cout << (ans >= inf ? -1 : ans);

  return 0;
}