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
  vector<char> pilha;

  cin >> n;

  for (i = 0; i < n.size(); i++) {

    if (n[i] == ' ') {
    } else if (n[i] != ')') {
      pilha.push_back(n[i]);
    } else if (pilha.size() == 0) {
      cout << "nao" << endl;
      return 0;
    } else {
      while (pilha.back() != '(') {
        pilha.pop_back();
        if (pilha.size() == 0) {
          cout << "nao" << endl;
          return 0;
        }
      }
      pilha.pop_back();
      pilha.push_back(')');
    }
  }

  while (pilha.size() != 0) {
    if (pilha.back() == '(') {
      cout << "nao" << endl;
      return 0;
    }
    pilha.pop_back();
  }

  cout << "sim" << endl;

  return 0;
}