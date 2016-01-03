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
  int TC;
  string tmp;
  getline(cin, tmp);
  TC = atoi(tmp.c_str());

  while (TC --> 0) {
    map<char, int> mapa;
    int n;
    getline(cin, tmp);
    n = atoi(tmp.c_str());

    for (int i = 0; i < n; ++i) {
      char c;
      int t;
      getline(cin, tmp);
      stringstream ss(tmp);
      string one,two;
      ss >> one;
      c = one[0];
      ss >> two;
      t = atoi(two.c_str());
      mapa[c] = t;
    }

    int k;
    getline(cin, tmp);
    k = atoi(tmp.c_str());

    int ans = 0;
    for (int i = 0; i < k; ++i) {
      string s;
      getline(cin, s);

      for (int j = 0; j < s.size(); ++j) {
        ans += mapa[s[j]];
      }
    }

    int dollars = ans / 100;
    ans -= dollars * 100;
    if (ans < 10) {
      cout << dollars << ".0" << ans << "$" << endl;
    }
    else {
      cout << dollars << "." << ans << "$" << endl;
    }
  }

  return 0;
}
