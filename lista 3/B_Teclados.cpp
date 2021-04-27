#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int i, n;
  string t1, t2;
  vector<string> palavras;
  string input;
  map<char, char> mapa;

  cin >> t1;
  cin >> t2;
  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> input;
    palavras.push_back(input);
  }

  for (i = 0; i < t1.size(); i++) {
    mapa[t1[i]] = t2[i];
    mapa[toupper(t1[i])] = toupper(t2[i]);
  }

  for (i = 0; i < n; i++) {
    for (auto elem : palavras[i]) {
      if (isdigit(elem)) {
        cout << elem;
      } else {
        cout << mapa[elem];
      }
    }
    cout << endl;
  }

  return 0;
}