// http://codeforces.com/contest/381/problem/B

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

bool comp(int a, int b){
  return a>b;
}

int main(){
  int n;
  cin >> n;

  vi a,b;
  map<int,int> mapa;
  int t;

  FR(i,n){
    cin >> t;
    mapa[t] ++;

    if( mapa[t]==1 ){
      a.push_back(t);
    }
    else if(mapa[t]==2){
      b.push_back(t);
    }
  }

  sort(all(a));
  sort(all(b),comp);


  if( b.size() && a.size() && a[a.size()-1]==b[0] ){
    cout << a.size()+b.size()-1 << endl;
    FR(i,a.size()) cout << a[i] << " ";
    fr(i,1,b.size()) cout << b[i] << " ";
  }
  else {
    cout << a.size()+b.size() << endl;
    FR(i,a.size()) cout << a[i] << " ";
    fr(i,0,b.size()) cout << b[i] << " ";
  }

  return 0;
}
