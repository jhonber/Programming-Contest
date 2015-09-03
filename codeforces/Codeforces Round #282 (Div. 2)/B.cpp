// http://codeforces.com/contest/495/problem/B

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

vector<int> gen_divs(int n) {
  int i = 1;
  vector<int> divs;
  while (i * i <= n) {
    if (n % i == 0) {
      divs.push_back(i);
      divs.push_back(n / i);
    }
    i ++;
  }
  sort(all(divs));
  divs.erase(unique(all(divs)),divs.end());
  return divs;
}

int main(){ __
  int a,b;
  cin >> a >> b;

  if (a < b) cout << 0;
  else if (a == b) cout << "infinity";
  else {
    vector<int> divs = gen_divs(a - b);
    int cnt = 0;
    for (int i = 0; i < divs.size(); ++i) {
      if (divs[i] <= b) cnt ++;
      else break;
    }
    int ans = divs.size() - cnt;
    cout << ans;
  }

  return 0;
}