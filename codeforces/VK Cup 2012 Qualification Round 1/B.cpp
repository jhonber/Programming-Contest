// http://codeforces.com/contest/158/problem/B

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
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i=0; i<n; ++i){
    cin >> v[i];
  }

  sort(all(v));

  int i = 0;
  int j = n-1;
  int sum = 0;

  int ans = 0;
  while (i<=j){
    if (i==j){
      ans ++;
      break;
    }
    sum = v[j];
    if (sum>=4){
      ans ++;
      j --;
    }
    else {
      while (i<j){
        if (sum + v[i] == 4){
          ans ++;
          j --;
          i++;
          sum = 0;
          break;
        }
        if (sum+v[i] > 4){
          j --;
          ans ++;
          sum = 0;
          break;
        }
        sum += v[i];
        i++;
      }
    }
  }

  cout << ans;

  return 0;
}