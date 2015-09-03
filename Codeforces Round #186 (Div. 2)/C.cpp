// http://codeforces.com/contest/313/problem/C

using namespace std;
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

typedef long long ll;

bool comp(int i, int j){ return i>j; }

int main(){
  int n;
  cin >> n;
  
  vector<int> v(2222222);
  
  for(int i=0;i<n;i++) cin >> v[i];
  sort(v.begin(),v.begin()+n,comp);
  
  ll ans = v[0];  
  
  if(n==1){
    cout << ans;
    return 0;
  }
  
  for(int i=4;i<=n;i*=4){
    for(int j=0; j<i; j++){
      ans += v[j];
    }
  }
  
  cout << ans << endl;
  return 0;
}