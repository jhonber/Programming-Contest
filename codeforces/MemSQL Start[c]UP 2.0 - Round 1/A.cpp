// http://codeforces.com/contest/452/problem/A

#include<bits/stdc++.h>
using namespace std;

#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for(typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main(){ __
  string v[6] = {"jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"};

  int n;
  cin >> n;
  string s;
  cin >> s;

  if (n==6) cout << "espeon";
  else if (n==8) cout << "vaporeon";
  else {
    int score[6] = {0,0,0,0,0,0};
    for (int i=0; i<6; ++i){
      for (int j=0; j<v[i].size(); ++j)
        if (s[j]==v[i][j])
          score[i] ++;
    }

    int mmax = 0;
    string ans;

    for (int i=0; i<6; ++i){
      if (score[i] > mmax){
        mmax = score[i];
        ans = v[i];
      }
    }

    cout << ans;
  }

  return 0;
}
