// http://codeforces.com/contest/546/problem/D

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

int main() { __
  int n = 5000000;
  int countFactors[n + 1];
  countFactors[1] = 0;
  vector<bool> isPrime(n + 1, true);
  vector<vector<int> > primeFactors(n + 1);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primeFactors[i].push_back(i);
      for (int j = 2 * i; j <= n; j += i) {
        isPrime[j] = false;
        if (!primeFactors[j].size()) primeFactors[j].push_back(i);
      }
    }
    countFactors[i] = countFactors[i / primeFactors[i][0]] + 1;
  }

  for (int i = 2; i <= n; ++i) countFactors[i] += countFactors[i - 1];

  int t;
  cin >> t;

  while (t --> 0) {
    int a,b;
    cin >> a >> b;
    cout << countFactors[a] - countFactors[b] << endl;
  }

  return 0;
}
