// http://codeforces.com/contest/546/problem/C

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

int main() { __
  int n;
  cin >> n;

  int a,b;
  cin >> a;

  vector<int> p1(a);
  for (int i = 0; i < a; ++i) cin >> p1[i];

  cin >> b;

  vector<int> p2(b);
  for (int i = 0; i < b; ++i) cin >> p2[i];

  map< pair< vector<int>, vector<int> >, bool > states;

  pair< vector<int>, vector<int> > cur = make_pair(p1, p2);
  int ans = 0;
  int win = -1;
  int f = true;

  while (true) {

    if (!cur.first.size()) win = 2;
    if (!cur.second.size()) win = 1;
    if (win != -1) break;

    int x = cur.first[0];
    vector<int> tmp (cur.first.begin() + 1, cur.first.end());
    cur.first = tmp;

    int y = cur.second[0];
    vector<int> tmp2 (cur.second.begin() + 1, cur.second.end());
    cur.second = tmp2;

    if (x > y) {
      cur.first.push_back(y);
      cur.first.push_back(x);
    }
    else {
      cur.second.push_back(x);
      cur.second.push_back(y);
    }

/*    cout << "p1: ";
    for (int i = 0; i < cur.first.size(); ++i) cout << cur.first[i] << " "; cout << endl;

    cout << "p2: ";
    for (int i = 0; i < cur.second.size(); ++i) cout << cur.second[i] << " "; cout << endl;
*/
    if (states[cur]) {
      f = false;
      break;
    }
    else states[cur] = true;

    ans ++;
  }

  if (f) cout << ans << " " << win;
  else cout << -1;

  return 0;
}