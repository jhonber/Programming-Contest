// http://codeforces.com/contest/371/problem/B

#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;

  int va[3] = {0,0,0};
  int vb[3] = {0,0,0};

  while( a%2==0 ){
    a /= 2;
    va[0]++;
  }
  while( a%3==0 ){
    a /= 3;
    va[1]++;
  }
  while( a%5==0 ){
    a /= 5;
    va[2]++;
  }

  while( b%2==0 ){
    b /= 2;
    vb[0]++;
  }

  while( b%3==0 ){
    b /= 3;
    vb[1]++;
  }

  while( b%5==0 ){
    b /= 5;
    vb[2]++;
  }

  if((a>1 || b>1) && a!=b)
    cout << -1;
  else
    cout << abs( vb[0]-va[0] ) + abs( vb[1]-va[1] ) + abs(vb[2]-va[2]);


  return 0;
}