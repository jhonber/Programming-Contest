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

vector<int> get_div(int n) {
  vector<int> divs;
  int i = 1;
  while (i * i <= n) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
    i ++;
  }
  sort(all(divs));
  divs.resize(distance(divs.begin(), unique(all(divs))));
  return divs;
}

double dp[111111];

double f (int d) {
  if (d == 1) return 1;
  if (dp[d] != 0) return dp[d];

  double exp = 0;
  vector<int> divs = get_div(d);
  int n = divs.size();
  for (int i = 1; i < n; ++i) {
    double tmp = (f (d / divs[i]) + 1) / (n - 1);
    exp += tmp;
  }

  return dp[d] = exp;
}

int main() {
  int T, n;
  cin >> T;
  int TC = 1;
  while (T --> 0) {
    cin >> n;
    memset(dp, 0, sizeof dp);
    double ans = f(n);
    if (n == 1) ans = 0;
    printf("Case %d: %.10lf\n", TC ++, ans);
  }

  return 0;
}
