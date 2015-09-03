// http://codeforces.com/contest/456/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

const int M = 100000;

int main() { __
  int n;
  cin >> n;

  long long freq[M+10];
  memset(freq,0,sizeof freq);

  for (int i=0; i<n; ++i) {
    int t;
    cin >> t;
    freq[t] ++;
  }

  long long dp[M+10];
  dp[M+2] = dp[M+1] = 0;

  for (int i=M; i>=0; --i)
    dp[i] = max(freq[i]*i + dp[i+2], dp[i+1]);

  cout << dp[0];
  return 0;
}