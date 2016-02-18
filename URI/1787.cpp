#include<bits/stdc++.h>
using namespace std;

bool check(int n) {
  long long pot = 1;
  while (pot <= n) {
    if (n == pot) return true;
    pot *= 2;
  }
  return false;
}

int main() {
  int n;
  while (cin >> n) {
    if (!n) break;

    vector<int> points(3, 0);
    for (int x = 0; x < n; ++x) {
      vector< pair<int, int> > v(3);
      for (int i = 0; i < 3; ++i) {
        cin >> v[i].first;
        v[i].second = i;
      }

      sort(v.begin(), v.end());

      if (check(v[2].first)) points[v[2].second] += 2;
      if (check(v[1].first)) points[v[1].second] += 1;
      if (check(v[0].first)) points[v[0].second] += 1;


    }

    int mx = 0;
    int ind = 0;
    for (int i = 0; i < 3; ++i) if (points[i] > mx) {
      mx = points[i];
      ind = i;
    }
    int cnt = 0;
    for (int i = 0; i < 3; ++i) if (points[i] == mx) {
      cnt ++;
    }
    vector<string> ans = {"Uilton", "Rita", "Ingred"};
    if (cnt > 1) cout << "URI" << endl;
    else cout << ans[ind] << endl;

  }

  return 0;
}