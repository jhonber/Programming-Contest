#include<bits/stdc++.h>
using namespace std;
 
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define D(x)cout << #x << " = " << (x) << endl;
 
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
 
template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }
 
int main() {
  string line;
  int last = 0;
  map<string, int> mapa;
  while (getline(cin, line)) {
    int op = 1;
    string token;
    vector<string> tokens;
    stringstream ss(line);
 
    while (ss >> token) {
      if (token == ":=") continue;
      if (token == "+") {
        op = 2;
        continue;
      }
      tokens.push_back(token);
    }
 
    if (op == 1) {
      mapa[tokens[0]] = toInt(tokens[1]);
      last = mapa[tokens[0]];
    }
    else {
      mapa[tokens[0]] = mapa[tokens[1]] + mapa[tokens[2]];
      last = mapa[tokens[0]];
    }
  }
  cout << last << endl;
  return 0;
}
