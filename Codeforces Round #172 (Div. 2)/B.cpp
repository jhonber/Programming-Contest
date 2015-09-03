// http://codeforces.com/contest/281/problem/B

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

class Fraction {
  public:
    long long num,den;
    Fraction () {}
    Fraction(long long num_) : num(num_), den(1LL) {}
    Fraction (long long num_, long long den_) : num(num_), den(den_) {};

    Fraction operator + (const Fraction & other) {
      Fraction res;
      res.num = (this->num * other.den) + (this->den * other.num);
      res.den = this->den * other.den;
      return res;
    }

    Fraction operator - (const Fraction & other) {
      Fraction res;
      res.num = (this->num * other.den) - (this->den * other.num);
      res.den = this->den * other.den;
      return res;
    }

    Fraction operator * (const Fraction & other) {
      Fraction res;
      res.num = this->num * other.num;
      res.den = this->den * other.den;
      return res;
    }

    Fraction operator / (const Fraction & other) {
      Fraction res;
      res.num = this->num * other.den;
      res.den = this->den * other.num;
      return res;
    }

    bool operator < (const Fraction & other) {
      return (this->num * other.den) < (this->den * other.num);
    }

    bool equal(const Fraction & other) {
      return (this->num == other.num) && (this->den == other.den);
    }

    void print() { cout << this->num << "/" << this->den; }

    void inverse () { swap(this->num, this->den); }

    void simplify() {
      long long k = __gcd(this->num, this->den);
      this->num /= k;
      this->den /= k;
    }
};

bool comp (Fraction a, Fraction b) {
  if (a.den < b.den) return a.den < b.den;
  if (a.den == b.den) return a.num < b.num;
}

Fraction close (Fraction t, Fraction cur) {
  Fraction rez;
  rez.num = abs((t.num * cur.den) - (t.den * cur.num));
  rez.den = t.den * cur.den;
  return rez;
}

const long long inf = 1000000000000 + 100;

int main() {__
  long long x,y,n;
  cin >> x >> y >> n;

  Fraction t (x,y);
  Fraction best (inf, inf);

  for (int b = 1; b <= n; ++b) {
    long long a = (t.num * b) / t.den;
    long long a2 = a + 1;
    Fraction cur1 (a,b);
    Fraction cur2 (a2,b);

    Fraction d1,d2;
    d1 = close (t, cur1);
    d2 = close (t, cur2);

    if (d1 < d2) {
      if (!(best < d1)) best = d1;
    }
    else if (!(best < d2)) best = d2;
  }

  vector<Fraction> v;
  for (int b = 1; b <= n; ++b) {
    long long a = (x * b) / y;
    long long a2 = a + 1;
    Fraction cur1 (a,b);
    Fraction cur2 (a2,b);

    Fraction d1,d2;
    d1 = close (t,cur1);
    d2 = close (t,cur2);

    if (d1.equal(best)) v.push_back(cur1);
    if (d2.equal(best)) v.push_back(cur2);
  }

  sort(all(v),comp);

  v[0].simplify();
  v[0].print();

  return 0;
}