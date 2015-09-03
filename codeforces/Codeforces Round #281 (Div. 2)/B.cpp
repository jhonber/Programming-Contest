// http://codeforces.com/contest/493/problem/B

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

bool check(vector<int> a, vector<int> b) {
  for (int i = 0; i < min(a.size(),b.size()); ++i) {
    if (a[i] > b[i]) return true;
    if (a[i] < b[i]) return false;
  }
  return true;
}

int main(){ //__
  int n;
  cin >> n;

  vector<int> p1,p2;
  long long t1 = 0, t2 = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a > 0) {
      t1 += a;
      p1.push_back(a);
      last = 1;
    }
    else {
      t2 += abs(a);
      p2.push_back(abs(a));
      last = 0;
    }
  }

  if (p1 == p2) {
    cout << (last ? "first" : "second");
    return 0;
  }

  if (t1 > t2) cout << "first";
  else if (t2 > t1) cout << "second";
  else {
    if (check(p1,p2)) cout << "first";
    else cout << "second";
  }

  return 0;
}