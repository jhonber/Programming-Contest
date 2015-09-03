// http://codeforces.com/contest/519/problem/D

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
  vector<int> v(26);
  for (int i = 0; i < 26; ++i) cin >> v[i];

  string s;
  cin >> s;

  long long ans = 0;
  long long sum = 0;
  map< pair<char,long long>, long long> magic;
  for (int i = 0; i < s.size(); ++i) {
    ans += magic[make_pair(s[i],sum)];
    sum += v[s[i] - 'a'];
    magic[make_pair(s[i],sum)] ++;
  }

  cout << ans;
  return 0;
}