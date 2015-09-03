// http://codeforces.com/contest/467/problem/C

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

int m,n;
long long v[5555];
long long image[5555];
long long dp[5555][5555];

long long getSum(int i) {
  return image[i+m] - image[i-1];
}

long long f(int i, int k) {
  if (i+m > n || k==0) return 0;

  if (dp[i][k] != -1) return dp[i][k];

  long long ans = 0;
  ans = max(ans, f(i+m+1,k-1) + getSum(i));

  return dp[i][k] = max(ans, f(i+1, k));
}

int main(){ __
  int k;
  cin >> n >> m >> k;

  for (int i=0; i<n; ++i)
    cin >> v[i];

  m --;
  memset(dp, -1, sizeof dp);
  image[0] = 0;

  for (int i=1; i<=n; ++i)
    image[i] = image[i-1] + v[i-1];

  cout << f(0,k);
  return 0;
}