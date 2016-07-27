#include<bits/stdc++.h>
using namespace std;

#define D(x) cout << #x << " = " << (x) << endl;

struct node {
  string name;
  vector< pair<string, string> > params;
  bool child;

  node(){}
  node(string n, vector< pair<string, string> > p, bool f) {
    name = n;
    params = p;
    child = f;
  }
};

vector<string> get_tokens (string s) {
  stringstream ss;
  ss << s;

  string t;
  vector<string> tokens;
  while (ss >> t) {
    if (t[0] == '<') t = t.substr(1);
    if (t[t.size() - 1] == '>') t.pop_back();
    tokens.push_back(t);
  }

  return tokens;
}

vector<pair<string, string>> get_params (vector<string> tokens) {
  vector< pair<string, string> > params;
  for (int i = 1; i + 1 < tokens.size(); ++i) {
    if (tokens[i] == "=") {
      string tmp = tokens[i + 1];
      string tmp2;
      for (int j = 0; j < tmp.size(); ++j) {
        if (tmp[j] != '"' && tmp[j] != '>' && tmp[j] != '<')
          tmp2.push_back(tmp[j]);
      }

      params.push_back({tokens[i - 1], tmp2});
    }
  }

  return params;
}

int main() {
  int n, q;

  string s, token;
  getline(cin, s);

  vector<string> t = get_tokens(s);
  n = atoi(t[0].c_str());
  q = atoi(t[1].c_str());

  map<string, node> tag_value;
  map<string, vector<string>> mapa;

  vector<string> Q;

  for (int i = 0; i < n; ++i) {
    getline(cin, s);

    vector<string> cur = get_tokens(s);
    string tag = cur[0];

    if (!Q.size()) {
      Q.push_back(tag);
      tag_value[tag] = node(tag, get_params(cur), 0);
      continue;
    }

    if (tag.find("/") != string::npos) {
      Q.pop_back();
    }
    else {
      tag_value[tag] = node(tag, get_params(cur), 1);
      mapa[Q.back()].push_back(tag);
      Q.push_back(tag);
    }
  }

  for (int i = 0; i < q; ++i) {
    getline(cin, s);

    for (int j = 0; j < s.size(); ++j) if (s[j] == '.') s[j] = ' ';
    if (s.find("~") == string::npos) {
      cout << "Not Found!" << endl;
      continue;
    }

    string param_name;
    while (s.back() != '~') {
      param_name.push_back(s.back());
      s.pop_back();
    }

    s.pop_back();
    reverse(param_name.begin(), param_name.end());

    vector<string> t = get_tokens(s);
    string parent = t[0];

    if (tag_value[parent].child) {
      cout << "Not Found!" << endl;
      continue;
    }

    string last = parent;
    int ok = true;
    for (int j = 1; j < t.size(); ++j) {
      vector<string> childs = mapa[parent];
      last = t[j];
      int found = false;
      for (int k = 0; k < childs.size(); ++k) {
        if (childs[k] == last) {
          found = true;
          break;
        }
      }

      if (!found) {
        ok = false;
        break;
      }

      parent = t[j];
    }

    if (ok) {
      int found = false;
      vector<pair<string, string>> params = tag_value[last].params;
      for (int j = 0; j < params.size(); ++j) if (param_name == params[j].first) {
        cout << params[j].second << endl;
        found = true;
        break;
      }

      if (!found) cout << "Not Found!" << endl;
    }
    else cout << "Not Found!" << endl;
  }

  return 0;
}
