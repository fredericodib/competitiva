#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool test(string n, char s) {
  char missing;
  map<char, char> mapa;
  vector<char> stack;

  mapa[n.front()] = '(';
  mapa[n.back()] = ')';

  if (mapa.find('A') == mapa.end()) {
    missing = 'A';
  } else if (mapa.find('B') == mapa.end()) {
    missing = 'B';
  } else {
    missing = 'C';
  }

  mapa[missing] = s;

  for (char x : n) {
    if (mapa[x] == '(') {
      stack.push_back('(');
    } else {
      if (stack.back() == '(') {
        stack.pop_back();
      } else {
        return false;
      }
    }
  }

  if (stack.size() > 0) {
    return false;
  }

  return true;
}

void solve() {
  string n;
  cin >> n;

  if (n.front() == n.back()) {
    cout << "NO" << endl;
    return;
  }

  if (test(n, '(') || test(n, ')')) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}