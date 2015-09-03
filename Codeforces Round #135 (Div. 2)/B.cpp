// http://codeforces.com/contest/219/problem/B

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

int nines(long long x){
  int ans = 0;
  while (x%10 == 9){
    x /= 10;
    ans ++;
  }

  return ans;
}

int getDig(long long x, int pos){
  int d = x%10;
  while (pos--){
    d = x%10;
    x /= 10;
  }
  if (!x) return -1;
  return d;
}

int main(){ __
  long long p,d;
  cin >> p >> d;

  long long ans = p;
  long long pot = 1;
  long long tot = 0;
  int c = 1;
  while (true){
    int f = false;
    long long dig = getDig(p,c);
    if (dig==-1) break;

    if (dig != 9){
      long long res = 10 + dig;
      long long x = res - 9;
      x *= pot;
      tot += x;

      if (tot > d)
        f = true;
      else
        p -= x;
    }

    if (f) break;

    if (nines(p) > nines(ans))
      ans = p;

    pot *= 10;
    c ++;
  }

  cout << ans;

  return 0;
}
