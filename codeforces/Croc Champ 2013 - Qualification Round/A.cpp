// http://codeforces.com/contest/291/problem/A

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
  int n;
  cin >> n;

  vi v(n);
  FR(i,n){
    cin >> v[i];
  }

  sort(all(v));

  int ans = 0,f=false;

  FR(i,n-1){
    if(!v[i]) continue;
    if(v[i]==v[i+1] && v[i+1] == v[i+2]){
      f = true; break;
    }
    if(v[i]==v[i+1]) {
      ans ++; i++;
    }
  }

  if(f) cout << -1 << endl;
  else  cout << ans << endl;

  return 0;
}
