// http://codeforces.com/contest/535/problem/A

#include<bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define foreach(it, x) for (__typeof (x).begin() it = (x).begin(); it != (x).end(); ++it)
#define all(x) x.begin(),x.end()
#define D(x) cout << #x " = " << (x) << endl;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }

template <class T> int toInt(const T &x)
{ stringstream s; s << x; int r; s >> r; return r; }

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

int main() {
vector<string> v;
v.push_back("zero");
v.push_back("one");
v.push_back("two");
v.push_back("three");
v.push_back("four");
v.push_back("five");
v.push_back("six");
v.push_back("seven");
v.push_back("eight");
v.push_back("nine");
v.push_back("ten");
v.push_back("eleven");
v.push_back("twelve");
v.push_back("thirteen");
v.push_back("fourteen");
v.push_back("fifteen");
v.push_back("sixteen");
v.push_back("seventeen");
v.push_back("eighteen");
v.push_back("nineteen");
v.push_back("twenty");
v.push_back("twenty-one");
v.push_back("twenty-two");
v.push_back("twenty-three");
v.push_back("twenty-four");
v.push_back("twenty-five");
v.push_back("twenty-six");
v.push_back("twenty-seven");
v.push_back("twenty-eight");
v.push_back("twenty-nine");
v.push_back("thirty");
v.push_back("thirty-one");
v.push_back("thirty-two");
v.push_back("thirty-three");
v.push_back("thirty-four");
v.push_back("thirty-five");
v.push_back("thirty-six");
v.push_back("thirty-seven");
v.push_back("thirty-eight");
v.push_back("thirty-nine");
v.push_back("forty");
v.push_back("forty-one");
v.push_back("forty-two");
v.push_back("forty-three");
v.push_back("forty-four");
v.push_back("forty-five");
v.push_back("forty-six");
v.push_back("forty-seven");
v.push_back("forty-eight");
v.push_back("forty-nine");
v.push_back("fifty");
v.push_back("fifty-one");
v.push_back("fifty-two");
v.push_back("fifty-three");
v.push_back("fifty-four");
v.push_back("fifty-five");
v.push_back("fifty-six");
v.push_back("fifty-seven");
v.push_back("fifty-eight");
v.push_back("fifty-nine");
v.push_back("sixty");
v.push_back("sixty-one");
v.push_back("sixty-two");
v.push_back("sixty-three");
v.push_back("sixty-four");
v.push_back("sixty-five");
v.push_back("sixty-six");
v.push_back("sixty-seven");
v.push_back("sixty-eight");
v.push_back("sixty-nine");
v.push_back("seventy");
v.push_back("seventy-one");
v.push_back("seventy-two");
v.push_back("seventy-three");
v.push_back("seventy-four");
v.push_back("seventy-five");
v.push_back("seventy-six");
v.push_back("seventy-seven");
v.push_back("seventy-eight");
v.push_back("seventy-nine");
v.push_back("eighty");
v.push_back("eighty-one");
v.push_back("eighty-two");
v.push_back("eighty-three");
v.push_back("eighty-four");
v.push_back("eighty-five");
v.push_back("eighty-six");
v.push_back("eighty-seven");
v.push_back("eighty-eight");
v.push_back("eighty-nine");
v.push_back("ninety");
v.push_back("ninety-one");
v.push_back("ninety-two");
v.push_back("ninety-three");
v.push_back("ninety-four");
v.push_back("ninety-five");
v.push_back("ninety-six");
v.push_back("ninety-seven");
v.push_back("ninety-eight");
v.push_back("ninety-nine");

int n;
cin >> n;
cout << v[n];


return 0;
}