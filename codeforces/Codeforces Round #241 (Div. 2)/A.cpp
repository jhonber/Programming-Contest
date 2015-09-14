// http://codeforces.com/contest/416/problem/A

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


struct range {
  int left, rigth;
  bool closeL;
  bool closeR;
};

void printR (range &r) {
  if (!r.closeL) cout << "( ";
  else cout << "[ ";

  cout << r.left << " - " << r.rigth;

  if (!r.closeR) cout << " )";
  else cout << " ]";
  cout << endl;
}

int main() {
  int n;
  cin >> n;

  string op;
  int num;
  bool yes;
  char ans;

  const int inf = 1e9 + 10000;
  range r, tmp;
  r.left = -inf;
  r.rigth= inf;
  r.closeL = r.closeR = true;

  tmp = r;
  for (int i = 0; i < n; ++i) {
    cin >> op >> num >> ans;

    if (op == ">" && ans == 'N')       op = "<=";
    else if (op == "<" && ans == 'N')  op = ">=";
    else if (op == ">=" && ans == 'N') op = "<";
    else if (op == "<=" && ans == 'N') op = ">";

    if (op == ">") {
      if (tmp.left < num + 1) {
        tmp.left = num + 1;
        tmp.closeL = false;
      }
    }
    else if (op == "<") {
      if (tmp.rigth > num -1) {
        tmp.rigth = num - 1;
        tmp.closeR = true;
      }
    }
    else if (op == ">=") {
      if (tmp.left < num) {
        tmp.left = num;
        tmp.closeL = true;
      }
    }
    else if (op == "<=") {
      if (tmp.rigth > num) {
        tmp.rigth = num;
        tmp.closeR = true;
      }
    }

    int left, rigth;
    if (tmp.closeL) left = tmp.left;
    else left = tmp.left + 1;

    if (tmp.closeR) rigth = tmp.rigth;
    else rigth = tmp.rigth - 1;

    if (left > rigth) {
      cout << "Impossible";
      return 0;
    }
  }

  int left;
  if (tmp.closeL) left = tmp.left;
  else left = tmp.left + 1;


  cout << left;
  return 0;
}