// http://codeforces.com/contest/192/problem/A

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

const long long LIM = 1000000000;
const int M = 100;

long long f (long long n) {
  return (n * (n + 1)) / 2;
}

int main() {
  vector<long long> v;
  int i = 1;
  while (true) {
    long long res = f(i);
    if (res > LIM) break;
    v.push_back(res);
    i++;
  }

  long long n;
  cin >> n;

  for (int i = 0; i < v.size(); ++i) {
    long long tmp = n - v[i];
    if ( binary_search(all(v), tmp) ) {
      cout << "YES";
      return 0;
    }
  }

  cout << "NO";
  return 0;
}