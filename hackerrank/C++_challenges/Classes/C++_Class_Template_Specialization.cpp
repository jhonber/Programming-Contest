// https://www.hackerrank.com/challenges/cpp-class-template-specialization

#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Begin my code
#define GET_NAME(x) # x

const char* valuesFruit[] = {GET_NAME(apple), GET_NAME(orange), GET_NAME(pear)};
const char* valuesColor[] = {GET_NAME(red), GET_NAME(green), GET_NAME(orange)};

template <>
class Traits <Fruit> {
  public:
  static string name (int i) {
    if (i < 0 || i > (int)Fruit::pear) return "unknown";
    else return valuesFruit[i];
  }
};

template <>
class Traits <Color> {
  public:
  static string name (int i) {
    if (i < 0 || i > (int)Color::orange) return "unknown";
    else return valuesColor[i];
  }
};
// End my code

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
