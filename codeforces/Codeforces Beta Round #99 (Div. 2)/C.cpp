// http://codeforces.com/contest/139/problem/C

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

bool isvowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string getSuf (string &s, int &k) {
  int cnt = 0;
  for (int i = s.size() - 1; i >= 0; --i) {
    if (isvowel(s[i])) cnt ++;
    if (cnt == k) return s.substr(i);
  }
  return "paila";
}

int getType(vector<string> &v, int &k) {
  string a,b,c,d;
  a = getSuf(v[0],k);
  b = getSuf(v[1],k);
  c = getSuf(v[2],k);
  d = getSuf(v[3],k);

  if (a == "paila" || b == "paila" || c == "paila" || d == "paila") return 0;

  set<string> st;
  st.insert(a);
  st.insert(b);
  st.insert(c);
  st.insert(d);

  if (st.size() == 1) return 1;
  if (a == b && c == d) return 2;
  if (a == c && b == d) return 3;
  if (a == d && b == c) return 4;
  return 0;
}

int main() {
  int n,k;
  cin >> n >> k;

  set<int> st;
  for (int i = 0; i < n; ++i) {
    vector<string> v(4);
    for (int j = 0; j < 4; ++j) {
      cin >> v[j];
    }
    int type = getType(v,k);
    st.insert(type);
  }

  int t = *st.begin();
  if (t == 0) {
    cout << "NO";
    return 0;
  }

  if (st.size() == 1) {
    if (t == 1) cout << "aaaa";
    else if (t == 2) cout << "aabb";
    else if (t == 3) cout << "abab";
    else cout << "abba";
  }
  else if (st.size() == 2) {
    set<int> :: iterator it = st.begin();
    it ++;
    int t2 = *it;
    if (t == 1) {
      if (t2 == 2) cout << "aabb";
      else if (t2 == 3)cout << "abab";
      else cout << "abba";
    }
    else cout << "NO";
  }
  else cout << "NO";

  return 0;
}