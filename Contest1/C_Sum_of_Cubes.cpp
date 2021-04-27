#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool test(ll int x) {
  bool end = false;
  ll int i, j, min, max;

  for (i = 1; i < 10000; i++) {
    min = 1;
    max = 9999;
    end = false;

    if ((i * i * i) > x) {
      return false;
    }

    while (!end) {
      j = (min + max) / 2;
      if (max <= min) {
        end = true;
      }

      if ((i * i * i + j * j * j) == x) {
        return true;
      } else if ((i * i * i + j * j * j) > x) {
        max = j - 1;
      } else {
        min = j + 1;
      }
    }
  }
  return false;
}

int main() {
  int t, i;
  ll int x;

  cin >> t;

  for (i = 0; i < t; i++) {
    cin >> x;
    if (test(x)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}