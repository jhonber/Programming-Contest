// http://codeforces.com/contest/113/problem/B

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

vector<unsigned long long> h(2002);
vector<unsigned long long> p_pow(2002);
const long long p = 31;

unsigned long long getHash(string s) {
  unsigned long long h = 0;
  for (int i = 0; i < s.size(); ++i)
    h += (s[i] - 'a' + 1) * p_pow[i];
  return h;
}

int main() { __
  string s, beg, end;
  cin >> s >> beg >> end;

  p_pow[0] = 1;
  for (int i = 1; i < s.size() + 1; ++i)
    p_pow[i] = p_pow[i - 1] * p;

  h[0] = 0;
  for (int i = 1; i <= s.size(); ++i) {
    h[i] = (s[i - 1] - 'a' + 1) * p_pow[i - 1];
    h[i] += h[i - 1];
  }

  unsigned long long h_beg = getHash(beg);
  unsigned long long h_end = getHash(end);

  int mmax = max(beg.size(), end.size());
  unordered_set<unsigned long long> st;
  for (int i = 1; i <= s.size(); ++i) {
    for (int j = i; j <= s.size(); ++j) {
      if (j - i + 1 >= mmax ) {
        unsigned long long h_b = h[i + beg.size() - 1] - h[i - 1];
        unsigned long long h_e = h[j] - h[j - end.size()];
        if (h_b != p_pow[i - 1] * h_beg) break;
        if (h_e == p_pow[j - end.size()] * h_end )
          st.insert( p_pow[s.size() - i] * (h[j] - h[i - 1]) );
      }
    }
  }

  cout << st.size();

  return 0;
}