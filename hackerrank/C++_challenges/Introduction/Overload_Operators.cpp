//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
  public:
    int a,b;
    void input(string s)
    {
      int v1=0;
      int i=0;
      while(s[i]!='+')
      {
        v1=v1*10+s[i]-'0';
        i++;
      }
      while(s[i]==' ' || s[i]=='+'||s[i]=='i')
      {
        i++;
      }
      int v2=0;
      while(i<s.length())
      {
        v2=v2*10+s[i]-'0';
        i++;
      }
      a=v1;
      b=v2;
    }
};

// Begin my code
Complex operator + (Complex &i, Complex &j) {
  string res;
  int r1 = i.a + j.a;
  int r2 = i.b + j.b;
  res += to_string(r1) + "+" + to_string(r2);

  Complex ans;
  ans.input(res);
  return ans;
}

ostream& operator << (ostream& out, Complex i) {
  return out << i.a << "+i" << i.b;
}
// End my code

int main()
{
  Complex x,y;
  string s1,s2;
  cin>>s1;
  cin>>s2;
  x.input(s1);
  y.input(s2);
  Complex z=x+y;
  cout<<z<<endl;
}

