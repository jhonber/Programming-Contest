#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

struct item {
  string name;
  int w, a;
  double h;
};


bool comp(item a, item b) {
  if (a.w == b.w) {
    if (a.a == b.a) {
      if (a.h == b.h) {
        return a.name < b.name;
      }
      return a.h < b.h;
    }
    return a.a < b.a;
  }

  return a.w > b.w;
}

int main() {
  int t;
  cin >> t;

  for (int j = 1; j <= t; ++j) {
    int n, m;
    cin >> n >> m;

    vector<item> v;
    item cur;


    for (int i = 0; i < n; ++i) {
      cin >> cur.name >> cur.w >> cur.a >> cur.h;
      v.push_back(cur);
    }

    sort(v.begin(), v.end(), comp);
    cout << "CENARIO {" << j << "}" << endl;
    for (int i = 0; i < m; ++i) cout << i + 1 << " - " << v[i].name << endl;
  }

  return 0;
}