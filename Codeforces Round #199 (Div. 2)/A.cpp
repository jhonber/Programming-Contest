// http://codeforces.com/contest/342/problem/A

using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define all(x) x.begin(),x.end()
#define D(x) cout<< #x " = "<<(x)<<endl
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};



int main(){__
  int n;
  cin >> n;

  map<int,int> mapa;
  int paila = false;
  for(int i=0; i<n; ++i){
    int t;
    cin >> t;
    mapa[t] ++;
  }

  if(mapa[5] || mapa[7])
    paila = true;

  if(!paila){
    vector<int> ans;
    int n2 = n;
    while(n2){
      if( mapa[1] && mapa[2] && mapa[4] ){
        mapa[1] --;
        mapa[2] --;
        mapa[4] --;
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(4);
      }
      else if( mapa[1] && mapa[2] && mapa[6] ){
        mapa[1] --;
        mapa[2] --;
        mapa[6] --;
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(6);
      }
      else if( mapa[1] && mapa[3] && mapa[6] ){
        mapa[1] --;
        mapa[3] --;
        mapa[6] --;
        ans.push_back(1);
        ans.push_back(3);
        ans.push_back(6);
      }
      else {
        cout << -1;
        return 0;
      }
      n2 -= 3;
    }

    for(int i=2; i<n; i+=3){
      cout << ans[i-2] << " " << ans[i-1] << " " << ans[i] << endl;
    }
  }
  else cout << -1;

  return 0;
}