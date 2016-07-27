// https://www.hackerrank.com/challenges/attending-workshops

#include<bits/stdc++.h>

using namespace std;

// Begin my code
struct Workshop {
  int start_time;
  int duration;

  bool operator < (const Workshop &other) const {
    int t1 = start_time + duration;
    int t2 = other.start_time + other.duration;

    if (t1 == t2) start_time > other.start_time;
    return t1 < t2;
  }
};

struct Available_Workshops {
  int n;
  vector<Workshop> w;
};

Available_Workshops * initialize (int start_time[], int duration[], int n) {
  Available_Workshops* r = new Available_Workshops();
  r->n = n;

  Workshop t;
  for (int i = 0; i < n; ++i) {
    t.start_time = start_time[i];
    t.duration = duration[i];
    r->w.push_back(t);
  }

  sort(r->w.begin(), r->w.end());
  return r;
}

int CalculateMaxWorkshops (Available_Workshops *r) {
  int ans = 0;
  int n = r->n;
  int last = 0;

  for (int i = 0; i < n; ++i) {
    int start = r->w[i].start_time;
    int duration = r->w[i].duration;
    int end = start + duration;

    if (start >= last) {
      last = end;
      ans ++;
    }
  }

  return ans;
}
// End my code

int main(int argc, char *argv[]) {
  int n; // number of workshops
  cin >> n;
  // create arrays of unknown size n
  int* start_time = new int[n];
  int* duration = new int[n];

  for(int i=0; i < n; i++){
    cin >> start_time[i];
  }
  for(int i = 0; i < n; i++){
    cin >> duration[i];
  }

  Available_Workshops * ptr;
  ptr = initialize(start_time,duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  return 0;
}
