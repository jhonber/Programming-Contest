#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

bool comp(pair<int, int> i, pair<int, int> j) {
  if (i.second == j.second) return i.first > j.first;
  return i.second < j.second;
}

int main() {
  string s;
  int cnt = 0;
  while (cin >> s) {
    if (cnt > 0)
      cout << endl;
    map<int, int> ans;
    for (int i = 0; i < s.size(); ++i) {
      ans[(int)s[i]] ++;
    }

    vector<pair<int, int>> v;
    for (auto i: ans) {
      v.push_back(i);
    }

    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); ++i) {
      cout << v[i].first << " " << v[i].second << endl;
    }
    cnt ++;
  }

  return 0;
}