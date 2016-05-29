#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string s;
  vector<string> v;
  while (cin >> s) {
    v.push_back(s);
  }

  int f = false;
  int size = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] == "<br>") {
      cout << endl;
      f = true;
      size = 0;
    }
    else if (v[i] == "<hr>") {
      if (i > 0 && !f) cout << endl;
      for (int j = 0; j < 80; ++j) cout << "-";
      cout << endl;
      f = true;
      size = 0;
    }
    else if (!size) {
      cout << v[i];
      size += v[i].size();
      f = false;
    }
    else {
      int n = v[i].size() + 1;
      if (n + size <= 80) {
        cout << " " << v[i];
        size += n;
        f = false;
      }
      else {
        cout << endl;
        f = true;
        i --;
        size = 0;
      }
    }
  }
  if (!f) cout << endl;

  return 0;
}