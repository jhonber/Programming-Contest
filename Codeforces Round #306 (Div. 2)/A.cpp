// http://codeforces.com/contest/550/problem/A

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
  string s;
  cin >> s;

  size_t paila = string::npos;
  size_t ind1 = s.find("AB");
  size_t ind2 = s.find("BA", ind1 + 2);

  if (ind1 != paila && ind2 != paila) {
    cout << "YES";
    return 0;
  }

  size_t ind3 = s.find("BA");
  size_t ind4 = s.find("AB", ind3 + 2);

  if (ind3 != paila && ind4 != paila) {
    cout << "YES";
    return 0;
  }

  cout << "NO";
  return 0;
}