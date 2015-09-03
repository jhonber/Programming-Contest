// http://codeforces.com/contest/385/problem/C

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

const int N = 10000000;

int main(){__
  int n,q,l,r;
  cin >> n;

  vi v(N+1);
  FR(i,n){
    int t; cin >> t;
    v[t] ++;
  }

  vi image(N+1);
  vi mark(N+1);
  int count = 0;
  for(int p=2; p<=N; p += 2){
    count += v[p];
    mark[p] = true;
  }

  image[2] = count;

  int last;
  for(int p = 3, i=3; p<=N ; p++, i++){
    if(mark[p]) {
      image[i] = image[i-1];
      continue;
    }
    count = 0;
    for(int k = p; k<=N ; k+=p){
      count += v[k];
      mark[k] = true;
    }
    image[i] = image[i-1] + count;
    last = image[i];
  }

  cin >> q;
  FR(i,q){
    cin >> l >> r;
    r = min(N,r);
    l = min(N,l);
    cout << image[r] - image[l-1] << endl;
  }

  return 0;
}