// http://codeforces.com/contest/456/problem/A

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <list>
#include <bitset>
#include <complex>
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
  int n;

  cin >> n;

  vector< pair<int,int> > v(n);
  for (int i=0; i<n; ++i)
    cin >> v[i].first >> v[i].second;

  sort(all(v));

  for (int i=1; i<n; ++i){
    if (v[i-1].first < v[i].first && v[i-1].second > v[i].second) {
      cout << "Happy Alex";
      return 0;
    }
  }

  cout << "Poor Alex";
  return 0;
}