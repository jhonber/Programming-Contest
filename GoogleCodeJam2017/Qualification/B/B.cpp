#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  int t, TC = 1;
  cin >> t;

  while (t --> 0) {
    long long n;
    cin >> n;

    vector<int> v;
    while (n > 0) {
      v.insert(v.begin(), n % 10);
      n /= 10;
    }

    if (v.size() == 1) {
      cout << "Case #" << TC ++ << ": " << v[0] << endl;
      continue;
    }

    bool found = false;
    for (int i = 1; i < v.size(); ++i) {
      if (v[i - 1] > v[i]) {
        if (v[i - 1] == 1) {
          int times = v.size() - 1;
          cout << "Case #" << TC ++ << ": " << string(times, '9') << endl;
          found = true;
          break;
        }
        else {
          i --;
          int last = i;
          while (i > 0 && v[i] == v[last]) i --;
          if (i < 0 || v[i] != v[last]) i ++;

          v[i] --;
          for (int j = i + 1; j < v.size(); ++j) v[j] = 9;
          cout << "Case #" << TC ++ << ": ";
          found = true;

          for (int j = 0; j < v.size(); ++j) {
            if (j == 0 && v[j] == 0) continue;
            cout << v[j];
          }
          cout << endl;
          break;
        }
      }
    }

    if (!found) {
      cout << "Case #" << TC ++ << ": ";
      for (int j = 0; j < v.size(); ++j) cout << v[j];
      cout << endl;
    }

  }


  return 0;
}
