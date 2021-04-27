#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n, f, p, i, peso, current = 1, time = 0;
  queue<int> pesos;
  cin >> n >> f >> p;

  for (i = 0; i < n; i++) {
    cin >> peso;
    pesos.push(peso);
  }

  while (!pesos.empty()) {
    peso = pesos.front();
    pesos.pop();
    if ((current - 1) % f == 0) {
      if (peso > p) {
        time += 10;
        peso -= 2;
        pesos.push(peso);
      } else {
        time += 5;
      }
    } else {
      time++;
    }
    current++;
  }

  cout << time << endl;

  return 0;
}