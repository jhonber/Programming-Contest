// http://codeforces.com/contest/387/problem/B

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

  vi v1(n),v2(m);
  FR(i,n){
    cin >> v1[i];
  }

  FR(i,m){
    cin >> v2[i];
  }

  vi ready(m);
  int ans = 0;
  FR(i,n){
    int act = v1[i];
    FR(j,m){
      if(!ready[j] && v2[j]>=act){
        ready[j] = true;
        ans ++;
        break;
      }
    }
  }

  cout << n-ans << endl;
  return 0;
}
