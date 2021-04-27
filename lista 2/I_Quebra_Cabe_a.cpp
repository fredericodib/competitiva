#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int i, is_even = 0;
  string n;
  map<char, int> pecas;

  cin >> n;

  for (i = 0; i < n.size(); i++) {
    if (pecas.count(n[i])) {
      pecas[n[i]]++;
    } else {
      pecas[n[i]] = 1;
    }
  }

  for (auto &p : pecas) {
    if (p.second % 2 != 0) {
      is_even++;
    }
  }

  if (n.size() % 2 == 0) {
    if (is_even > 0) {
      cout << "Nao" << endl;
    } else {
      cout << "Sim" << endl;
    }
  } else {
    if (is_even != 1) {
      cout << "Nao" << endl;
    } else {
      cout << "Sim" << endl;
    }
  }

  return 0;
}