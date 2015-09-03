// http://codeforces.com/contest/143/problem/C

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

vector<long long> gen_divs(long long n) {
  long long i = 1;
  vector<long long> divs;
  while (i * i <= n) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
    i ++;
  }
  sort(all(divs));
  divs.erase(unique(all(divs)),divs.end());
  return divs;
}

int main() {
  long long n;
  cin >> n;

  long long mmin = LLONG_MAX;
  long long mmax = -1;
  vector<long long> d = gen_divs(n);
  for (int i = 0; i < d.size(); ++i) {
    for (int j = i; j < d.size(); ++j) {
      if (n % (d[i] * d[j]) == 0) {
        long long x = n / (d[i] * d[j]);
        long long tmp = ((x + 1) * (d[i] + 2) * (d[j] + 2)) - n;
        mmin = min(mmin, tmp);
        mmax = max(mmax, tmp);
      }
    }
  }

  cout << mmin << " " << mmax;
  return 0;
}