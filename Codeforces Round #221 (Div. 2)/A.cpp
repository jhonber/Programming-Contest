// http://codeforces.com/contest/376/problem/A

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

string solve(string s){
  ll left = 0, right=0;
  int piv;
  FR(i,s.size()){
    if(s[i]=='^'){
      piv = i;
      break;
    }
  }

  int i = piv - 1, j = piv + 1, k = 1;
  while(i >= 0){
    left += s[i] != '=' ? toInt(s[i])*k : 0;
    i--;
    k++;
  }

  k=1;
  while(j < s.size()){
    right += s[i] != '=' ? toInt(s[j])*k : 0;
    j++;
    k++;
  }

  if(left == right) return "balance";
  if(left > right) return "left";
  return "right";
}

int main(){
  string s;
  cin >> s;

  cout << solve(s) << endl;

  return 0;
}
