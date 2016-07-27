// https://www.hackerrank.com/challenges/c-tutorial-class

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Student {
  private:
    int age, standard;
    string first_name, last_name;

  public:
    void set_age (int a) {
      age = a;
    }

    int get_age () {
      return age;
    }

    void set_standard (int s) {
      standard = s;
    }

    int get_standard () {
      return standard;
    }

    void set_first_name (string name) {
      first_name = name;
    }

    string get_first_name () {
      return first_name;
    }

    void set_last_name (string name) {
      last_name = name;
    }

    string get_last_name () {
      return last_name;
    }

    string to_string () {
      stringstream ss;
      ss << age;
      ss << ",";
      ss << first_name + ",";
      ss << last_name + ",";
      ss << standard;

      string out;
      ss >> out;
      return out;
    }
};

int main() {
  int age, standard;
  string first_name, last_name;

  cin >> age >> first_name >> last_name >> standard;

  Student st;
  st.set_age(age);
  st.set_standard(standard);
  st.set_first_name(first_name);
  st.set_last_name(last_name);

  cout << st.get_age() << "\n";
  cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
  cout << st.get_standard() << "\n";
  cout << "\n";
  cout << st.to_string();

  return 0;
}
