#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t;
  cin >> t;

  for (int j = 0; j < t; ++j) {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> solved;
    int tot = 0;
    int time = 0;
    for (int i = 0; i < n; ++i) {
      if (time + v[i] <= 300) {
        time += v[i];
        solved.push_back(v[i]);
      }
      else break;
      tot ++;
    }

    int penalty = 0;
    int t = tot;
    for (int i = 0; i < solved.size(); ++i) {
      penalty += solved[i] * t;
      t --;
    }

    cout << "Case " << j + 1 << ": " << tot << " " << penalty << endl;
  }

  return 0;
}
