// http://codeforces.com/contest/363/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

const int INF = 100000000;

int main(){
  int n,k;
  cin >> n >> k;
  k--;

  vector<int> image(n+1,0);
  for(int i=1; i<n+1; ++i)
    cin >> image[i];

  for(int i=0; i<n+1; ++i)
    image[i] += image[i-1];

  int mmax = INF;
  int index = 1;

  for(int i=1; i+k<n+1; ++i){
    int tmp = image[i+k] - image[i-1];
    if(tmp < mmax){
      mmax = tmp;
      index = i;
    }
  }

  cout << index;

  return 0;
}