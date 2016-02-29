#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int r;

  while (cin >> r) {
    if (!r) break;

    int cnt1 = 0;
    vector<int> v1(r);

    for (int i = 0; i < r; ++i) {
      cin >> v1[i];
      cnt1 += v1[i];
    }

    int cnt2 = 0;
    vector<int> v2(r);

    for (int i = 0; i < r; ++i) {
      cin >> v2[i];
      cnt2 += v2[i];
    }

    int f1 = -1;
    for (int i = 1; i + 1 < r; ++i) {
      if (v1[i - 1] == v1[i] &&  v1[i - 1] == v1[i + 1]) {
        f1 = i - 1;
        break;
      }
    }

    int f2 = -1;
    for (int i = 1; i + 1 < r; ++i) {
      if (v2[i - 1] == v2[i] &&  v2[i - 1] == v2[i + 1]) {
        f2 = i - 1;
        break;
      }
    }

    if (f1 == -1 && f2 >= 0 || (f1 != -1 && f2 != -1 && f1 > f2)) cnt2 += 30;
    else if (f2 == -1 && f1 >= 0 || (f1 != -1 && f2 != -1 && f1 < f2)) cnt1 += 30;

    if (cnt1 > cnt2) cout << "M" << endl;
    else if (cnt2 > cnt1) cout << "L" << endl;
    else cout << "T" << endl;

  }

  return 0;
}