// http://codeforces.com/contest/381/problem/A

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
typedef vector<vi> vvi;
typedef pair<int,int> pii;

int main(){
  int n;
  cin >> n;

  vi v(n);
  FR(i,n) cin  >> v[i];

  int j=0,k=n-1,a=0,b=0;

  FR(i,n){
    if(v[j] > v[k]){
      if(i%2==0) a += v[j];
      else b += v[j];
      j++;
    }
    else {
      if(i%2==0) a += v[k];
      else b += v[k];
      k--;
    }
  }

  cout << a << " " << b << endl;

  return 0;
}
