// http://codeforces.com/contest/535/problem/B

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

set<int> lucky;
long long pot[] = {
1,
10,
100,
1000,
10000,
100000,
1000000,
10000000,
100000000,
1000000000
};

long long vec_to_int(vector<int> v) {
  long long num = 0;
  for (int i = 0; i < v.size(); ++i) {
    num += v[i] * pot[v.size() - (i + 1)];
  }
  return num;
}

void brute() {
  lucky.insert(4);
  lucky.insert(7);

  for (int k = 2; k <= 10; ++k) {
    for (int i = 0; i <= k; ++i) {
      vector<int> tmp;
      for (int cnt = 0; cnt < i; ++cnt) {
        tmp.push_back(4);
      }
      while (tmp.size() < k) {
        tmp.push_back(7);
      }
      if (tmp.size()) {
        do {
          long long t = vec_to_int(tmp);
          if (t > 1000000000) return;
          lucky.insert(t);
        } while (next_permutation(all(tmp)));
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> ans;
  brute();
  foreach(x,lucky) {
    ans.push_back(*x);
  }

  int ind = (lower_bound(all(ans),n) - ans.begin()) + 1;
  cout << ind;
  return 0;
}