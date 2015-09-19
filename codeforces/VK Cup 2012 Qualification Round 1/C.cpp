// http://codeforces.com/contest/158/problem/C

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

string pwd (vector<string> &v) {
  string p = "/";
  for (int i = 0; i < v.size(); ++i) p += v[i] + "/";
  return p;
}

void cd (vector<string> &v, string parms) {
  stringstream ss;
  ss << parms;

  string s;
  vector<string> tokens;
  while (getline(ss, s, '/')) tokens.push_back(s);

  bool root = false;
  if (parms[0] == '/') root = true;

  for (int i = 0; i < tokens.size(); ++i) {
    if (root) {
      v.clear();
      root = false;
    }
    else if (tokens[i] == "..") v.pop_back();
    else if (tokens[i].size() > 0) v.push_back(tokens[i]);
  }
}

int main() {
  int n;
  string line;
  getline(cin, line);

  n = atoi(line.c_str());

  vector<string> v;
  for (int i = 0; i < n; ++i) {
    getline(cin, line);

    stringstream ss;
    ss << line;
    string token;

    ss >> token;
    if (token == "pwd") {
      cout << pwd(v) << endl;
    }
    else {
      ss >> token;
      cd (v, token);
    }
  }

  return 0;
}