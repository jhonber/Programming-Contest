// http://codeforces.com/contest/586/problem/C

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

struct kid {
  long long id, v, d, p;
  kid () {};
  kid (long long _id, long long _v, long long _d, long long _p) : id(_id), v(_v), d(_d), p(_p) {};
};

int main() { __
  int n;
  cin >> n;

  vector<kid> arr(n);
  for (int i = 0; i < n; ++i) {
    long long v, d, p;
    cin >> v >> d >> p;
    arr[i] = kid(i + 1, v, d, p);
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (arr[i].p >= 0) {
      ans.push_back(arr[i].id);
      long long cur = arr[i].v;
      long long other = 0;
      for (int j = i + 1; j < n; ++j) if (arr[j].p >= 0) {
        if (cur > 0) {
          arr[j].p -= cur;
          cur --;
        }

        arr[j].p -= other;
        if (arr[j].p < 0) {
          other += arr[j].d;
        }

        if (cur <= 0 && other <= 0) break;
      }
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  return 0;
}