// http://codeforces.com/contest/382/problem/A

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
  string a,b;

  cin >> a >> b;

  string izq, der;
  FR(i,a.size()){
    if(a[i]=='|') {
      izq = a.substr(0,i);
      der = a.substr(i+1,a.size());
      break;
    }
  }

  int c = b.size(), i = 0;
  while( c ){
    if(izq.size() < der.size()){
      izq += b[i];
      c--;
    }
    else {
      der +=  b[i];
      c--;
    }
    i++;
  }

  if(izq.size()==der.size()){
    cout << izq << "|" << der << endl;
  }
  else cout << "Impossible" << endl;

  return 0;
}
