// http://codeforces.com/contest/257/problem/B

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){__
  //  1 0
  int n,m;
  cin >> n >> m;

  int n2 = n;
  int m2 = m;

  int f = 1;
  vector<int> v;
  v.push_back(1);
  n2--;

  while(n2>0 || m2>0){
    int ant = v[v.size()-1];
    if(f%2 == 0){
      if(ant == 1){
        if(n2 > 0){
          n2--;
          v.push_back(1);
        }
        else if(m2 > 0){
          m2--;
          v.push_back(0);
        }
      }
      else {
        if(m2 > 0){
          m2--;
          v.push_back(0);
        }
        else if(n2 > 0){
          n2--;
          v.push_back(1);
        }
      }
    }
    else {
      if(ant == 0){
        if(n2 > 0){
          n2--;
          v.push_back(1);
        }
        else if(m2 > 0){
          m2--;
          v.push_back(0);
        }
      }
      else {
        if(m2 > 0){
          m2--;
          v.push_back(0);
        }
        else if(n2 > 0){
          n2--;
          v.push_back(1);
        }
      }
    }
    f ++;
  }

  int ans1 = 0;
  int ans2 = 0;
  for(int i=1; i<n+m; ++i){
    if(v[i-1] == v[i])
      ans1 ++;
    else
      ans2 ++;
  }

  n2 = n;
  m2 = m;
  v.clear();
  v.push_back(0);
  m2--;
  f = 1;
  while(n2>0 || m2>0){
    int ant = v[v.size()-1];
    if(f%2 == 0){
      if(ant == 1){
        if(n2 > 0){
          n2--;
          v.push_back(1);
        }
        else if(m2 > 0){
          m2--;
          v.push_back(0);
        }
      }
      else {
        if(m2 > 0){
          m2--;
          v.push_back(0);
        }
        else if(n2 > 0){
          n2--;
          v.push_back(1);
        }
      }
    }
    else {
      if(ant == 0){
        if(n2 > 0){
          n2--;
          v.push_back(1);
        }
        else if(m2 > 0){
          m2--;
          v.push_back(0);
        }
      }
      else {
        if(m2 > 0){
          m2--;
          v.push_back(0);
        }
        else if(n2 > 0){
          n2--;
          v.push_back(1);
        }
      }
    }
    f ++;
  }

  int ans3 = 0;
  int ans4 = 0;
  for(int i=1; i<n+m; ++i){
    if(v[i-1] == v[i])
      ans3 ++;
    else
      ans4 ++;
  }

  if( ans1 > ans3 || ans1 == ans3 && ans2 < ans4)
    cout << ans1 << " " << ans2;
  else
    cout << ans3 << " " << ans4;

  return 0;
}