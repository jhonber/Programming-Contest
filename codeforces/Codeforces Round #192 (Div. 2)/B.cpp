// http://codeforces.com/contest/330/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define fr(i,j,n) for(int i=j;i<n;i++)
#define FR(i,n) fr(i,0,n)
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
  int n,m;
  cin >> n >> m;
  vi paila(n+1,0);

  FR(i,m){
    int x, y;
    cin >> x >> y;
    paila[x] = paila[y] = true;
  }

  cout << n-1 << endl;
  fr(i,1,n+1){
    if(!paila[i]){
      fr(x,1,n+1){
        if(i != x) cout << i << " " << x << endl;
      }
      return 0;
    }
  }

  return 0;
}
