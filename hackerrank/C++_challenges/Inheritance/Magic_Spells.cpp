// https://www.hackerrank.com/challenges/magic-spells

#include <iostream>
#include <vector>
using namespace std;

class Spell {
  private:
    string scrollName;
  public:
    Spell(): scrollName("") { }
    Spell(string name): scrollName(name) { }
    virtual ~Spell() { }
    string revealScrollName() {
      return scrollName;
    }
};

class Fireball : public Spell {
  private: int power;
  public:
           Fireball(int power): power(power) { }
           void revealFirepower(){
             cout << "Fireball: " << power << endl;
           }
};

class Frostbite : public Spell {
  private: int power;
  public:
           Frostbite(int power): power(power) { }
           void revealFrostpower(){
             cout << "Frostbite: " << power << endl;
           }
};

class Thunderstorm : public Spell {
  private: int power;
  public:
           Thunderstorm(int power): power(power) { }
           void revealThunderpower(){
             cout << "Thunderstorm: " << power << endl;
           }
};

class Waterbolt : public Spell {
  private: int power;
  public:
           Waterbolt(int power): power(power) { }
           void revealWaterpower(){
             cout << "Waterbolt: " << power << endl;
           }
};

class SpellJournal {
  public:
    static string journal;
    static string read() {
      return journal;
    }
};

string SpellJournal::journal = "";

void counterspell(Spell *spell) {
  // Begin my code
  Fireball *a = dynamic_cast<Fireball*> (spell);
  if (a != NULL) {
    a->revealFirepower();
  }
  else {
    Frostbite *b = dynamic_cast<Frostbite*> (spell);
    if (b != NULL) {
      b->revealFrostpower();
    }
    else {
      Thunderstorm *c = dynamic_cast<Thunderstorm*> (spell);
      if (c != NULL) {
        c->revealThunderpower();
      }
      else {
        Waterbolt *d = dynamic_cast<Waterbolt*> (spell);
        if (d != NULL) {
          d->revealWaterpower();
        }
        else {
          string s = spell->revealScrollName();
          string t = SpellJournal::journal;

          int m = s.size();
          int n = t.size();

          int lcs[m + 1][n + 1];
          for (int i = 0; i <= m; ++i) for (int j = 0; j <= n; ++j) lcs[i][j] = 0;

          for (int i = m; i >= 0; --i) {
            for (int j = n; j >= 0; --j) {
              if (i == m || j == n) lcs[i][j] = 0;
              else {
                lcs[i][j] = max(lcs[i + 1][j], lcs[i][j + 1]);
                if (s[i] == t[j]) {
                  lcs[i][j] = max(lcs[i][j], lcs[i + 1][j + 1] + 1);
                }
              }
            }
          }

          int ans = lcs[0][0];
          cout << ans << endl;
        }
      }
    }
  }

  SpellJournal::journal = "";
  // End my code
}

class Wizard {
  public:
    Spell *cast() {
      Spell *spell;
      string s; cin >> s;
      int power; cin >> power;
      if(s == "fire") {
        spell = new Fireball(power);
      }
      else if(s == "frost") {
        spell = new Frostbite(power);
      }
      else if(s == "water") {
        spell = new Waterbolt(power);
      }
      else if(s == "thunder") {
        spell = new Thunderstorm(power);
      }
      else {
        spell = new Spell(s);
        cin >> SpellJournal::journal;
      }
      return spell;
    }
};

int main() {
  int T;
  cin >> T;
  Wizard Arawn;
  while(T--) {
    Spell *spell = Arawn.cast();
    counterspell(spell);
  }
  return 0;
}
