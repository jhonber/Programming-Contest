// http://codeforces.com/contest/371/problem/C

#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x " = " << (x) << endl;

int main(){
  string h;
  cin >> h;

  long long b=0,s=0,c=0;
  for(int i=0; i<h.size(); ++i){
    if(h[i]=='B') b++;
    if(h[i]=='S') s++;
    if(h[i]=='C') c++;
  }

  long long nb,ns,nc,pb,ps,pc,r;
  cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;

  if(b==0) nb = 0;
  if(s==0) ns = 0;
  if(c==0) nc = 0;

  long long ans = 0;
  long long sum = 0;

  while( true ){
    nb -= b;
    ns -= s;
    nc -= c;

    sum = 0;
    if(nb < 0) sum += abs(nb) * pb;
    if(ns < 0) sum += abs(ns) * ps;
    if(nc < 0) sum += abs(nc) * pc;

    if( r - sum >=0 )
      ans ++;
    else {
      sum = 0;
      break;
    }

    if( nb <=0 && ns <= 0 && nc <= 0 )
      break;
  }

  r -= sum;
  long long x = r / ( ( b*pb ) + (s*ps) + (c*pc) );

  cout << ans + x;

  return 0;
}