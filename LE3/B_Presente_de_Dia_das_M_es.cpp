// B. Presente de Dia das Mães
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// No dia das mães, Cristiano resolveu fazer uma surpresa para todas as mães de sua família. Ele comprou várias caixas de chocolate para presentear cada mãe com uma quantidade de chocolates de forma que:

// cada mãe receba a mesma quantidade de chocolates,
// uma mãe não pode receber chocolates de caixas diferentes, por conta da diferença de sabores, e
// a quantidade de chocolates presenteados a cada mãe é a maior possível.
// Como Cristiano quer ser o mais justo possível e não consegue fazer esta distribuição sozinho devido à grande quantidade de mães e a complexidade dos critérios, você ficou responsável por ajudá-lo.

// Input
// A primeira linha da entrada possui dois números inteiros 𝑁 (1≤𝑁≤105) e 𝑀 (1≤𝑀≤109), separados por um espaço em branco, representando a quantidade de caixas de chocolate e o número de mães, respectivamente.

// A próxima linha contém 𝑁 inteiros 𝑉0,𝑉1,…,𝑉𝑖,…,𝑉𝑁−1, separados por um espaço em branco, de modo que 𝑉𝑖 (0≤𝑉𝑖≤109) indica a quantidade de chocolates presentes na 𝑖-ésima caixa.

// Output
// Seu programa deverá imprimir a maior quantidade de chocolate possível distribuída a cada mãe de acordo com os critérios apresentados.

// Examples
// inputCopy
// 3 3
// 1 2 3
// outputCopy
// 1
// inputCopy
// 3 4
// 8 2 1
// outputCopy
// 2
// inputCopy
// 3 3
// 5 9 2
// outputCopy
// 4
// Note
// No primeiro caso de teste, exitem três caixas de chocolate com 1, 2 e 3 chocolates respectivamente e 3 mães. Nesse caso, o máximo de chocolates presenteados a cada mãe é 1. Um chocolate de cada caixa é uma possível configuração que atende os critérios.

// No segundo caso de teste, existem três caixas de chocolate com 8, 2 e 1 chocolates respectivamente e 4 mães. Nesse caso, o máximo de chocolates presenteados a cada mãe é 2. Uma possibilidade de configuração é distribuir 2 chocolates da primeira caixa a todas as mães.

// No terceiro caso de teste, existem três caixas de chocolate com 5, 9 e 2 chocolates respectivamente e 3 mães. Nesse caso, o máximo de chocolates presenteados a cada mãe é 4. Uma possibilidade de configuração é distribuir 4 chocolates da primeira caixa a uma mãe e dividir 8 chocolates da segunda caixa entre as duas mães restantes.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define lli long long int
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool test(lli mid, vector<lli> vec, lli m) {
  lli receive = 0;

  if (mid == 0) {
    return true;
  }

  for (int i = 0; i < vec.size(); i++) {
    receive += vec[i] / mid;
  }
  if (receive < m) {
    return false;
  }

  return true;
}

int main() {
  lli n, m, res;
  cin >> n >> m;
  vector<lli> vec;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  sort(vec.begin(), vec.end());

  lli l = 0;
  lli r = vec.back();

  while (l <= r) {
    lli mid = (l + r) / 2;
    if (test(mid, vec, m)) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << res << endl;

  return 0;
}