// http://codeforces.com/contest/197/problem/B

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
  pair<long long, long long> a,b;
  cin >> a.second >> b.second;
  cin >> a.first;
  int tmp;
  for (int i = 0; i < a.second; ++i) cin >> tmp;

  cin >> b.first;
  for (int i = 0; i < b.second; ++i) cin >> tmp;

  int siga = a.first;
  int sigb = b.first;

  a.first = abs(a.first);
  b.first = abs(b.first);

  while (a.second > 0 && b.second > 0) {
    a.first *= a.second;
    b.first *= b.second;
    long long k = __gcd(a.first, b.first);
    a.first /= k;
    b.first /= k;
    a.second --;
    b.second --;
  }

  long long k = __gcd(a.first, b.first);
  a.first /= k;
  b.first /= k;


  if (a.second > b.second) {
    if (siga > 0 && sigb < 0 || siga < 0 && sigb > 0) cout << "-";
    cout << "Infinity";
  }
  else if (a.second < b.second) {
    cout << "0/1";
  }
  else {
    if (siga > 0 && sigb < 0 || siga < 0 && sigb > 0) cout << "-";
    cout << a.first << "/" << b.first;
  }

  return 0;
}