// http://codeforces.com/contest/475/problem/A

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

int main () {
  int n;
  cin >> n;

  vector<string> bus;
  bus.push_back("+------------------------+");
  bus.push_back("|#.#.#.#.#.#.#.#.#.#.#.|D|)");
  bus.push_back("|#.#.#.#.#.#.#.#.#.#.#.|.|");
  bus.push_back("|#.......................|");
  bus.push_back("|#.#.#.#.#.#.#.#.#.#.#.|.|)");
  bus.push_back("+------------------------+");

  for (int j = 1; j <= 21; j += 2) {
    for (int i = 1; i <= 4; ++i) if (n > 0) {
      if (j > 1 && i == 3) continue;
      bus[i][j] = 'O';
      n --;
    }
  }

  for (int i = 0; i < bus.size(); ++i) cout << bus[i] << endl;

  return 0;
}