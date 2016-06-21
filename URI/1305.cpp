#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;
#define endl '\n'

string f (string s) {
  int ind = s.find('.');
  int size = s.size();
  string in, de;
  if (ind != string::npos) {
    in = s.substr(0, ind);
    de = s.substr(ind + 1, size - (ind + 1));
  }
  else {
    in = s;
    de = "0";
  }

  if (in.size() == 0) in = "0";
  if (de.size() == 0) de = "0";

  return in + "." + de;
}

int main() {
  string a, b;
  while (cin >> a >> b) {
    a = f(a);
    b = f(b);

    string decimal = "0.";
    int ind = a.find('.');
    for (int i = ind + 1; i < a.size(); ++i) {
      decimal.push_back(a[i]);
    }

    double aa, bb;
    aa = stof(decimal);
    bb = stof(b.c_str());

    double x = stod(a);
    if (aa > bb) {
      cout << (int)ceil(x) << endl;
    }
    else {
      cout << (int)floor(x) << endl;
    }
  }

  return 0;
}