#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

void print(int a, int b) {
  vector<char> v(10);
  int p = 1;
  for (int i = 3; i >= 0; --i, p *= 2) {
    v[i] = (a & p ? 'o' : ' ');
  }

  p = 1;
  for (int i = v.size() - 1; i > 3; --i, p *= 2) {
    v[i] = (b & p ? 'o' : ' ');
  }

  printf(" ____________________________________________\n");
  printf("|                                            |\n");
  printf("|    ____________________________________    |_\n");
  printf("|   |                                    |   |_)\n");
  printf("|   |   8         4         2         1  |   |\n");
  printf("|   |                                    |   |\n");
  printf("|   |   %c         %c         %c         %c  |   |\n", v[0], v[1], v[2], v[3]);
  printf("|   |                                    |   |\n");
  printf("|   |                                    |   |\n");
  printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n", v[4], v[5], v[6], v[7], v[8], v[9]);
  printf("|   |                                    |   |\n");
  printf("|   |   32    16    8     4     2     1  |   |_\n");
  printf("|   |____________________________________|   |_)\n");
  printf("|                                            |\n");
  printf("|____________________________________________|\n");
  cout << endl;
}

int main() {
  int a, b;
  while (scanf("%d:%d", &a, &b) != EOF) {
    print(a, b);
  }

  return 0;
}