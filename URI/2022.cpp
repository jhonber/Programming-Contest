#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

struct item {
  string name;
  int p;
  double val;
};

bool comp (item a, item b) {
  if (a.p == b.p) {
    if (a.val == b.val)
      return a.name < b.name;
    return a.val < b.val;
  }
  return a.p > b.p;
}

int main() {
  string name, s;
  int n;

  while (getline(cin, s)) {
    stringstream ss;
    ss << s;

    ss >> name;
    ss >> n;

    vector<item> v(n);
    item it;
    for (int i = 0; i < n; ++i) {
      getline(cin, it.name);
      getline(cin, s);
      ss.clear();
      ss << s;

      string value, preference;
      ss >> value;
      ss >> preference;

      it.val = stod(value.c_str());
      it.p = atoi(preference.c_str());

      v[i] = it;
    }

    sort(v.begin(), v.end(), comp);

    cout << "Lista de " << name << endl;
    for (int i = 0; i < n; ++i) {
      cout << v[i].name;
      printf(" - R$%.2lf\n", v[i].val);
    }
    cout << endl;
  }

  return 0;
}