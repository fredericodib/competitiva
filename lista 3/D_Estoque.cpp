#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int q, i, op, item;
  cin >> q;
  map<int, bool> mp;

  for (i = 0; i < q; i++) {
    cin >> op >> item;

    if (op == 1) {
      mp[item] = true;
    } else {
      if (mp.count(item)) {
        cout << "Sim" << endl;
      } else {
        cout << "Nao" << endl;
      }
    }
  }

  return 0;
}