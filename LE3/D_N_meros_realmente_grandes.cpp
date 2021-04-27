// D. Números realmente grandes
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Mikael gosta muito de números, e está especialmente interessado em números realmente grandes. Mikael considera um número x realmente grande se x - f(x) >  = y, aonde f(x) é a soma dos dígitos de x. Uma coisa que mikael observou é que se x é realmente grande, então com certeza x+1 é realmente grande.

// Ele está tentando resolver o seguinte problema: dados n e y, mikael gostaria de saber a quantidade de números realmente grandes até n.

// Então por exemplo, se n é 12 e y é 3, o primeiro número realmente grande que encontraremos é 10, pois 10 - f(10) >= 3, e pela observação de mikael, 11 e 12 serão realmente grandes também. Então há 3 números realmente grandes até o número 12.

// Input
// Dois inteiros, n e y (1 <= n,y <= 1018).

// Output
// Imprima um único inteiro: a resposta para o problema.

// Examples
// inputCopy
// 12 1
// outputCopy
// 3
// inputCopy
// 12 3
// outputCopy
// 3
// inputCopy
// 20 3
// outputCopy
// 11
// inputCopy
// 25 18
// outputCopy
// 6
// inputCopy
// 25 20
// outputCopy
// 0

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define lli long long int
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool test(lli mid, lli y) {
  lli fx = 0;
  string s = to_string(mid);

  for (char c : s) {
    fx += c - '0';
  }

  if ((mid - fx) >= y) {
    return true;
  }
  return false;
}

int main() {
  lli n, y, res = 0;
  cin >> n >> y;

  lli l = 0;
  lli r = n;

  while (l <= r) {
    lli mid = (l + r) / 2;
    if (test(mid, y)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  if (res == 0) {
    cout << 0 << endl;
  } else {
    cout << n - res + 1 << endl;
  }

  return 0;
}