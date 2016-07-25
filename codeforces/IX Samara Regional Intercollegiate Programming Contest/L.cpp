// http://codeforces.com/problemset/gymProblem/100971/L

#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int n;
  cin >> n;

  set<int> st1, st2;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    st1.insert(x);
  }

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    st2.insert(x);
  }

  set<int> tmp = st2;
  int cnt1 = 0, cnt2 = 0;
  for (auto i : st1) {
    auto it = tmp.upper_bound(i);
    if (it != tmp.begin()) it --;

    if (*it < i) {
      cnt1 ++;
      tmp.erase(*it);
    }
  }

  tmp = st1;
  for (auto i : st2) {
    auto it = tmp.upper_bound(i);
    if (it != tmp.begin()) it --;

    if (*it < i) {
      cnt2 ++;
      tmp.erase(it);
    }
  }


  n /= 2;
  if (cnt1 == n && cnt2 == n) cout << "None" << endl;
  else if (cnt1 > n && cnt2 > n) cout << "Both" << endl;
  else if (cnt1 > n) cout << "First" << endl;
  else cout << "Second" << endl;


  return 0;
}
