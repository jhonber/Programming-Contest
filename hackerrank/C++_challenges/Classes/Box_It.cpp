// https://www.hackerrank.com/challenges/box-it

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

// Begin my code
class Box {
  long long l, b, h;

  public:
  Box () {
    l = b = h = 0;
    BoxesCreated ++;
  }

  Box (int l_, int b_, int h_) {
    l = l_; b = b_; h = h_;
    BoxesCreated ++;
  }

  Box (const Box& i) {
    l = i.l; b = i.b; h = i.h;
    BoxesCreated ++;
  }

  ~Box () {
    BoxesDestroyed ++;
  }

  int getLength () {
    return l;
  }

  int getBreadth () {
    return b;
  }

  int getHeight () {
    return h;
  }

  long long CalculateVolume () {
    return l * b * h;
  }

  bool operator < (Box &other) {
    if (l == other.l) {
      if (b == other.b) return h < other.h;
      return b < other.b;
    }
    return l < other.l;
  }
};

ostream& operator << (ostream& out, Box B) {
  return out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
}
// End my code

void check2()
{
  int n;
  cin>>n;
  Box temp;
  for(int i=0;i<n;i++)
  {
    int type;
    cin>>type;
    if(type ==1)
    {
      cout<<temp<<endl;
    }
    if(type == 2)
    {
      int l,b,h;
      cin>>l>>b>>h;
      Box NewBox(l,b,h);
      temp=NewBox;
      cout<<temp<<endl;
    }
    if(type==3)
    {
      int l,b,h;
      cin>>l>>b>>h;
      Box NewBox(l,b,h);
      if(NewBox<temp)
      {
        cout<<"Lesser"<<endl;
      }
      else
      {
        cout<<"Greater"<<endl;
      }
    }
    if(type==4)
    {
      cout<<temp.CalculateVolume()<<endl;
    }
    if(type==5)
    {
      Box NewBox(temp);
      cout<<NewBox<<endl;
    }

  }
}

int main()
{
  BoxesCreated = 0;
  BoxesDestroyed = 0;
  check2();
  cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
