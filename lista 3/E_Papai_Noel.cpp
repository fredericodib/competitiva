#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int q, i;
  long int item;
  char op;
  vector<long int> saco, auxStack;

  cin >> q;

  for (i = 0; i < q; i++) {
    cin >> op >> item;

    if (op == 'A') {
      saco.push_back(item);
      if (!auxStack.empty()) {
        if (auxStack.back() > item) {
          auxStack.push_back(auxStack.back());
        } else {
          auxStack.push_back(item);
        }
      } else {
        auxStack.push_back(item);
      }
    } else if (op == 'R') {
      saco.pop_back();
      auxStack.pop_back();
    } else {
      if (!auxStack.empty()) {
        cout << auxStack.back() << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}