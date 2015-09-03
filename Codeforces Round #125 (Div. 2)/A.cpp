// http://codeforces.com/contest/199/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;
#define MN 4004

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){
  long long n;
  cin >> n;

  if(n==0){
    cout << "0 0 0";
    return 0;
  }

  vector<long long> v;

  long long mmax = 10e9;
  long long a = 0;
  long long b = 1;

  v.push_back(a);
  v.push_back(b);

  while( b<mmax ){
    long long t = a;
    a = b;
    b = t+b;
    v.push_back( b );
  }

  for(int i=0; i<v.size(); ++i){
    for(int j=0; j<v.size(); ++j){
      for(int k=0; k<v.size(); ++k){
        if(i==j && j==k) continue;
        if(v[i]+ v[j] + v[k] == n){
          cout << v[i] << " " << v[j] << " " << v[k];
          return 0;
        }
      }
    }
  }

  cout << "I'm too stupid to solve this problem";

  return 0;
}