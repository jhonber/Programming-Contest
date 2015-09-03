// http://codeforces.com/contest/271/problem/B

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

const int mmax = 1000000;
vector<bool> isPrime(mmax + 1, true);
vector<int> primes;

void genPrimes() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= mmax; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j = 2 * i; j <= mmax; j += i) isPrime[j] = false;
    }
  }
}

int main() { __

  genPrimes();

  int n,m;
  cin >> n >> m;

  int mat[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat[i][j];
    }
  }

  int mat2[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int cur = mat[i][j];
      int next = *lower_bound(all(primes), cur);
      mat2[i][j] = next;
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int tot = 0;
    for (int j = 0; j < m; ++j)
      tot += mat2[i][j] - mat[i][j];

    ans = min(ans, tot);
  }

  for (int i = 0; i < m; ++i) {
    int tot = 0;
    for (int j = 0; j < n; ++j)
      tot += mat2[j][i] - mat[j][i];

    ans = min(ans, tot);
  }

  cout << ans;
  return 0;
}