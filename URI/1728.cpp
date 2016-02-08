#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (cin >> s) {
    string a = s.substr(0, s.find('+'));
    string b = s.substr(s.find('+') + 1, (s.find('=') - s.find('+')) - 1);
    string c = s.substr(s.find('=') + 1, s.size());

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());


    int aa, bb, cc;
    stringstream ss(a);
    stringstream sss(b);
    stringstream ssss(c);
    ss >> aa;
    sss >> bb;
    ssss >> cc;

    if (aa + bb == cc) cout << "True" << endl;
    else cout << "False" << endl;

    if (s == "0+0=0") break;
  }
  return 0;
}
