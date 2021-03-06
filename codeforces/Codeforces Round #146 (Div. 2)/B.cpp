// http://codeforces.com/contest/236/problem/B

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

const int MOD = 1073741824;
const int mmax = 1000100;
vector<bool> isPrime(mmax + 1, true);
vector< vector<int> > factors(mmax);

void genPrimes() {
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= mmax; i++) {
    if (isPrime[i]) {
      factors[i].push_back(i);
      for (int j = 2 * i; j <= mmax; j += i) {
        isPrime[j] = false;
        factors[j].push_back(i);
      }
    }
  }
}

int count(int n, int p) {
  int exp = 0;
  while (n % p == 0) {
    n /= p;
    exp ++;
  }
  return exp;
}

int main() {
  genPrimes();
  int a, b, c;
  cin >> a >> b >> c;

  vector<int> countDivs(mmax, 2);
  countDivs[1] = 1;
  for (int i = 2; i <= mmax; ++i) {
    if (isPrime[i]) continue;

    int tot = 1;
    for (int j = 0; j < factors[i].size(); ++j) {
      int cnt = count(i, factors[i][j]);
      tot *= cnt + 1;
    }
    countDivs[i] = tot;
  }

  long long sum = 0;
  for (int i = 1; i <= a; ++i) {
    for (int j = 1; j <= b; ++j) {
      for (int k = 1; k <= c; ++k) {
        sum += countDivs[i*j*k] % MOD;
      }
    }
  }

  cout << sum % MOD;
  return 0;
}