// http://codeforces.com/contest/358/problem/C

using namespace std;
#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);

#define PI acos(-1)
#define fr(i,j,n) for(int i=j;i<n;++i)
#define FR(i,n) fr(i,0,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define D(x) cout<< #x " = "<<(x)<<endl
#define PB push_back
#define MK make_pair
#define F first
#define S second

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef pair <int,int> pii;
typedef vector<pii> vpii;

int main(){
  int n;
  cin >> n;
  vi commands(n);
  FR(i,n) cin >> commands[i];
  vpii v;
  int pos = 0;
  FR(i,n){
    if(!commands[i]){
      pos = 0;
      sort(rall(v));

      if(v.size() == 0) cout << 0 << endl;
      else if (v.size()==1){
        cout << "pushStack" << endl;
        cout << "1 popStack" << endl;
      }
      else if (v.size()==2){
        cout << "pushStack" << endl;
        cout << "pushQueue" << endl;
        cout << "2 popStack popQueue" << endl;
      }
      else if (v.size()==3){
        cout << "pushStack" << endl;
        cout << "pushQueue" << endl;
        cout << "pushFront" << endl;
        cout << "3 popStack popQueue popFront" << endl;
      }
      else {
        vpii vv;

        vv.PB(MK(v[0].S,0));
        vv.PB(MK(v[1].S,1));
        vv.PB(MK(v[2].S,2));

        fr(x,3,v.size()) vv.PB(MK(v[x].S,3));

        sort(all(vv));

        FR(x,vv.size()){
          if(vv[x].S == 0) cout << "pushStack" << endl;
          else if(vv[x].S == 1) cout << "pushQueue" << endl;
          else if(vv[x].S == 2) cout << "pushFront" << endl;
          else cout << "pushBack" << endl;
        }
        
        cout << "3 popStack popQueue popFront" << endl;
      }
      v.clear();
    }
    else v.PB(MK(commands[i],pos));
    pos++;
  }

  if(v.size()) FR(i,v.size()) cout << "pushBack" << endl;

  return 0;
}
