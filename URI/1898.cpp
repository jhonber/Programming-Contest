#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  string a, b;
  cin >> a >> b;

  string aa, bb, corr;
  int tot = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (isdigit(a[i]) && tot < 11) {
      corr.push_back(a[i]);
      tot ++;
    }
    else if (isdigit(a[i]) || a[i] == '.') {
      aa.push_back(a[i]);
    }
  }

  for (int i = 0; i < b.size(); ++i) {
    if (isdigit(b[i]) || b[i] == '.') bb.push_back(b[i]);
  }

  int ind = aa.find('.');
  if (ind != string::npos) {
    int exc = aa.size() - (ind + 1);
    if (exc > 2) {
      while (exc > 2) {
        aa.pop_back();
        exc --;
      }
    }
  }

  ind = bb.find('.');
  if (ind != string::npos) {
    int exc = bb.size() - (ind + 1);
    if (exc > 2) {
      while (exc > 2) {
        bb.pop_back();
        exc --;
      }
    }
  }

  double x, y;
  x = atof(aa.c_str());
  y = atof(bb.c_str());

  cout << "cpf " << corr << endl;
  printf("%.2lf\n", x + y);

  return 0;
}