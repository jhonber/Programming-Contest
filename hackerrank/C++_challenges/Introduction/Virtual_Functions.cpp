// https://www.hackerrank.com/challenges/virtual-functions

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Begin my code
class Person {
  protected:
    string name;
    int age;
  public:
    static int p_id;
    static int s_id;
    virtual void getdata () = 0;
    virtual void putdata () = 0;
};

int Person::p_id = 1;
int Person::s_id = 1;

class Professor: public Person {
  int publications, cur_id;
  public:
  Professor () {
    cur_id = p_id ++;
  }

  void getdata () {
    cin >> name >> age >> publications;
  }

  void putdata () {
    cout << name << " " << age << " " << publications << " " << cur_id << endl;
  }
};

class Student: public Person {
  vector<int> marks;
  int cur_id;

  public:
  Student () {
    cur_id = s_id ++;
    marks.resize(6);
  }

  void getdata () {
    cin >> name >> age;
    for (int i = 0; i < 6; ++i) cin >> marks[i];
  }

  void putdata () {
    cout << name << " " << age << " ";
    int sum = 0;
    for (int i = 0; i < marks.size(); ++i) sum += marks[i];
    cout << sum << " " << cur_id << endl;
  }
};
// End my code

int main(){

  int n, val;
  cin>>n; //The number of objects that is going to be created.
  Person *per[n];

  for(int i = 0;i < n;i++){

    cin>>val;
    if(val == 1){
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    }
    else per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.

  }

  for(int i=0;i<n;i++)
    per[i]->putdata(); // Print the required output for each object.

  return 0;

}
