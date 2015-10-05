// http://codeforces.com/contest/583/problem/C

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
  int n;
  cin >> n;

  multiset<int> mset;
  for (int i = 0; i < n * n; ++i) {
    int t;
    cin >> t;
    mset.insert(t);
  }

  vector<int> ans;
  int mx = *mset.crbegin();
  mset.erase(mset.find( mx ));
  ans.push_back(mx);

  while (ans.size() != n) {
    mx = *mset.crbegin();
    ans.push_back(mx);

    for (int i = 0; i < ans.size(); ++i) {
      int gcd = __gcd(ans[i], ans[ans.size() - 1]);
      if (mset.find( gcd ) != mset.end())
        mset.erase(mset.find( gcd ));
      if (mset.find( gcd ) != mset.end())
        mset.erase(mset.find( gcd ));
    }

  }

  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  return 0;
}