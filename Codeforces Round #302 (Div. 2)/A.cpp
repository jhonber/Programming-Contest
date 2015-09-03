// http://codeforces.com/contest/544/problem/A

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

int main() {
  int k;
  cin >> k;
  string s;
  cin >> s;

  if (k == 1) {
    cout << "YES" << endl << s;
    return 0;
  }

  vector<int> match(26,0);
  match[s[0] - 'a'] = true;

  vector<int> pos;
  pos.push_back(0);
  int k2 = k;
  int tot = 1;
  for (int i = 1; i < s.size() && tot < k; ++i) {
    if (!match[s[i] - 'a']) {
      match[s[i] - 'a'] = true;
      pos.push_back(i);
      tot ++;
    }
  }

  pos.push_back(s.size());
  if (pos.size() == k + 1) {
    cout << "YES" << endl;
    int ant = pos[0];
    for (int i = 1; i < pos.size(); ++i) {
      for (int j = ant; j < pos[i]; ++j) {
        cout << s[j];
      }
      cout << endl;
      ant = pos[i];
    }
    return 0;
  }

  cout << "NO";
  return 0;
}