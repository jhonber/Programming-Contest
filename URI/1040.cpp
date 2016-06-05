#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

int main() {
  double a, b, c, d, e;
  cin >> a >> b >> c >> d;

  double av = (a * 2 + b * 3 + c * 4 + d) / 10.0;
  printf("Media: %.1lf\n", av);

  if (av >= 7.0) cout << "Aluno aprovado." << endl;
  else if (av < 5.0) cout << "Aluno reprovado." << endl;
  else if (av >= 5.0 && av < 7.0) {
    cout << "Aluno em exame." << endl;
    cin >> e;
    printf("Nota do exame: %.1lf\n", e);

    av = (av + e) / 2.0;
    if (av >= 5.0) cout << "Aluno aprovado." << endl;
    else cout << "Aluno reprovado." << endl;
    printf("Media final: %.1lf\n", av);
  }

  return 0;
}