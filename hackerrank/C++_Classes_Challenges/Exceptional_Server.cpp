// https://www.hackerrank.com/challenges/exceptional-server

#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
  private:
    static int load;
  public:
    static int compute(long long A, long long B) {
      load += 1;
      if(A < 0) {
        throw std::invalid_argument("A is negative");
      }
      vector<int> v(A, 0);
      int real = -1, cmplx = sqrt(-1);
      if(B == 0) throw 0;
      real = (A/B)*real;
      int ans = v.at(B);
      return real + A - B*ans;
    }
    static int getLoad() {
      return load;
    }
};

int Server::load = 0;

int main() {
  int T; cin >> T;
  while(T--) {
    long long A, B;
    cin >> A >> B;

    // Begin my code
    try {
      cout << Server::compute(A, B) << endl;
    }
    catch (std::exception& e) {
      string out = e.what();

      if (out.find("bad_alloc") != string::npos) {
        out = "Not enough memory";
      }
      else {
        out = "Exception: " + out;
      }

      cout << out << endl;
    }
    catch (...) {
      cout << "Other Exception" << endl;
    }
    // End my code

  }

  cout << Server::getLoad() << endl;
  return 0;
}
