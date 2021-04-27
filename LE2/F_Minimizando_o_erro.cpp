// F. Minimizando o erro
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você recebe dois arrays 𝐴 e 𝐵, cada um com tamanho 𝑁. O erro 𝐸 entre esses dois arrays é definido como 𝐸=∑𝑖=1𝑛(𝑎𝑖−𝑏𝑖)2. Você tem que executar exatamente 𝑘1 operações no array 𝐴 e exatamente 𝑘2 operações no array 𝐵. Em uma operação, você tem que escolher um elemento do array e aumentá-lo ou diminuí-lo em 1.

// Emita o valor mínimo possível de erro após as 𝑘1 operações no array 𝐴 e 𝑘2 operações no array B terem sido executadas.

// Input
// A primeira linha contém três inteiros separados por espaço 𝑁 (1≤𝑁≤103), 𝑘1 e 𝑘2 (0≤𝑘1+𝑘2≤103, 𝑘1 e 𝑘2 são não-negativos) - tamanho dos arrays e número de operações a serem executadas em 𝐴 e 𝐵, respectivamente.

// A segunda linha contém 𝑁 inteiros separados por espaço 𝑎1, 𝑎2, ..., 𝑎𝑛 (−106≤𝑎𝑖≤106) - array 𝐴.

// A terceira linha contém 𝑁 inteiros separados por espaços 𝑏1, 𝑏2, ..., 𝑏𝑛 (−106≤𝑏𝑖≤106) - array 𝐵.

// Output
// Imprima um único inteiro - o valor mínimo possível de ∑𝑖=1𝑛(𝑎𝑖−𝑏𝑖)2 depois de fazer exatamente 𝑘1 operações no array 𝐴 e exatamente 𝑘2 operações no array 𝐵.

// Examples
// inputCopy
// 2 0 0
// 1 2
// 2 3
// outputCopy
// 2
// inputCopy
// 3 2 2
// 5 3 7
// 0 1 2
// outputCopy
// 22
// inputCopy
// 2 5 7
// 3 4
// 14 4
// outputCopy
// 1

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  ll int n, k1, k2, k;
  vi a, b;
  map<pair<ll int, ll int>, bool> sum;

  cin >> n >> k1 >> k2;

  for (ll int i = 0; i < n; i++) {
    ll int x;
    cin >> x;
    a.push_back(x);
  }

  for (ll int i = 0; i < n; i++) {
    ll int x, dif;
    cin >> x;
    b.push_back(x);
    dif = a[i] - x;
    dif = dif < 0 ? -dif : dif;
    sum[{dif, i}] = true;
  }

  k = k1 + k2;

  for (ll int i = 0; i < k; i++) {
    ii x = sum.rbegin()->first;
    if (x.first >= 0) {
      x.first -= 1;
    } else {
      x.first += 1;
    }
    sum.erase(sum.rbegin()->first);
    sum[x] = true;
  }

  ll int soma = 0;
  for (auto x : sum) {
    ll int y = x.first.first;
    soma += y * y;
  }
  cout << soma << endl;
  return 0;
}