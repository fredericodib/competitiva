#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int t, i, n, j;
  long int rest = 0, value;
  vector<long int> vec;

  cin >> t;

  for (i = 0; i < t; i++) {
    cin >> n;
    rest = 0;
    for (j = 0; j < n; j++) {
      cin >> value;
      value += rest;
      rest = value - j;
      if (rest < 0) {
        cout << "NO" << endl;
        break;
      }
    }
    if (rest >= 0) {
      cout << "YES" << endl;
    }
  }

  return 0;
}