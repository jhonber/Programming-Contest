// http://codeforces.com/contest/791/problem/C

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int cur_l = 0;

string next (int &tot) {
  if (tot > 9) {
    tot = 0;
    cur_l ++;
  }

  char l = char(cur_l + 'a');
  string s;
  s.push_back(toupper(l));

  for (int i = 0; i < tot; ++i) s.push_back(l);
  return s;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<bool> v(n - k + 1);
  for (int i = 0; i < n - k + 1; ++i) {
    string s;
    cin >> s;
    v[i] = (s == "YES");
  }

  vector<string> ans;
  int ind = v.size() - 2;
  int cnt = 0;

  for (int i = 1; i < k; ++i) {
    ans.insert(ans.begin(), next(cnt));
    cnt ++;
  }

  if (v[ind + 1]) {
    ans.insert(ans.begin(), next(cnt));
    cnt ++;
  }
  else {
    ans.insert(ans.begin(), ans[ans.size() - 1]);
  }

  while (ind >= 0) {
    if (v[ind]) {
      ans.insert(ans.begin(), next(cnt));
      cnt ++;
    }
    else {
      ans.insert(ans.begin(), ans[k - 2]);
    }

    ind --;
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << endl;

  return 0;
}