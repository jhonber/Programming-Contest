// http://codeforces.com/contest/290/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};


int main() {
  vector<string> res;
  res.push_back("Washington");
  res.push_back("Adams");
  res.push_back("Jefferson");
  res.push_back("Madison");
  res.push_back("Monroe");
  res.push_back("Adams");
  res.push_back("Jackson");
  res.push_back("Van Buren");
  res.push_back("Harrison");
  res.push_back("Tyler");
  res.push_back("Polk");
  res.push_back("Taylor");
  res.push_back("Fillmore");
  res.push_back("Pierce");
  res.push_back("Buchanan");
  res.push_back("Lincoln");
  res.push_back("Johnson");
  res.push_back("Grant");
  res.push_back("Hayes");
  res.push_back("Garfield");
  res.push_back("Arthur");
  res.push_back("Cleveland");
  res.push_back("Harrison");
  res.push_back("Cleveland");
  res.push_back("McKinley");
  res.push_back("Roosevelt");
  res.push_back("Taft");
  res.push_back("Wilson");
  res.push_back("Harding");
  res.push_back("Coolidge");
  res.push_back("Hoover");
  res.push_back("Roosevelt");
  res.push_back("Truman");
  res.push_back("Eisenhower");
  res.push_back("Kennedy");
  res.push_back("Johnson");
  res.push_back("Nixon");
  res.push_back("Ford");
  res.push_back("Carter");
  res.push_back("Reagan");

  int n;
  cin >> n;
  cout << res[n - 1];
  return 0;
}