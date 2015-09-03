// http://codeforces.com/contest/36/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  #ifdef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  int n;
  cin >> n;

  string s;
  cin >> s;

  int ant = -1;
  int diff = 0;
  set<int> st;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      if (ant != -1)
        st.insert(i - ant);
      ant = i;
    }
  }

  if (st.size() == 1)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}