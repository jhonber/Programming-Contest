// http://codeforces.com/contest/584/problem/D

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

vector<int> primes;

void gen_primes (int lim) {
  primes.push_back(2);

  for (int p = 3; p <= lim; p += 2) {
    int i = 2;
    int f = true;
    while (i * i <= p) {
      if (p % i == 0) {
        f = false;
        break;
      }
      i ++;
    }

    if (f) primes.push_back(p);
  }
}

bool is_prime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  int i = 2;
  while (i * i <= n) {
    if (n % i == 0) return false;
    i ++;
  }
  return true;
}

int main() {
  int mx = 1e6;
  gen_primes(mx);

  int n;
  cin >> n;

  int n2 = n;
  int tmp = n;

  while (n2 > 0) {
    if (!is_prime(n2)) {
      n2 --;
      continue;
    }

    n = tmp;
    int f = false;
    vector<int> ans;
    ans.push_back(n2);
    n -= n2;

    if (!n) f = true;

    for (int i = 0; n > 0 && i < primes.size(); ++i) {
      if (primes[i] <= n) {
        int rest = n - primes[i];
        if (rest == 0) {
          ans.push_back(primes[i]);
          f = true;
          break;
        }
        if (is_prime(rest)) {
          ans.push_back(primes[i]);
          ans.push_back(rest);
          f = true;
          break;
        }
      }
      else break;
    }

    if (f) {
      cout << ans.size() << endl;
      for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
      return 0;
    }
    n2 --;
  }

  return 0;
}