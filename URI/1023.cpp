#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int TC = 1;
  while (cin >> n) {
    if (!n) break;
    if (TC > 1) cout << endl;
    vector< pair<int,int> > v(n);

    double a = 0;
    double b = 0;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      v[i] = {y / x, x};
      a += x;
      b += y;
    }

    sort(v.begin(), v.end());
    cout << "Cidade# " << TC ++ << ":" << endl;

    map<int, int> mapa;
    for (int i = 0; i < v.size(); ++i) {
      mapa[v[i].first] += v[i].second;
    }

    int cnt = 0;
    for (auto i: mapa) {
      if (cnt) cout << " ";
      cout << i.second << "-" << i.first;
      cnt ++;
    }

    double avg = (double)b / a;
    char out[1234];
    sprintf(out,"%lf", avg);
    string o;
    int i;
    for (i = 0; out[i] != '.'; ++i) o.push_back(out[i]);
    o.push_back(out[i]);
    o.push_back(out[i + 1]);
    o.push_back(out[i + 2]);
    cout << "\nConsumo medio: " << o << " m3.\n";
  }

  return 0;
}
