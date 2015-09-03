// http://codeforces.com/contest/224/problem/B

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
  int n,k;
  cin >> n >> k;

  int v[n];
  for (int i=0; i<n; ++i)
    cin >> v[i];

  set<int> diff;
  for (int i=0; i<n; ++i) {
    diff.insert(v[i]);
    if (diff.size() == k) {
      set<int> diff2;
      for (int j=i; j>=0; --j){
        diff2.insert(v[j]);
        if (diff2.size() == k) {
          cout << j+1 << " " << i+1;
          return 0;
        }
      }
    }
  }
  cout << "-1 -1";
  return 0;
}