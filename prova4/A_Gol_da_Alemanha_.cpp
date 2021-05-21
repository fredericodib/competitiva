// A. Gol da Alemanha!
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A quantidade de gols que a alemanha fez no Brasil foi 7! Muito tempo depois, em 2018 perceberam que o motivo de serem 7 gols estava diretamente relacionado a sequência de Tribonacci, Afinal T(6) = 7. Pode-se mostrar que essa sequência pode ser usada para estimar como o placar do jogo estaria neste momento.

// Tribonacci é uma sequência parecida com a sequência de Fibonacci, mas com algumas mudanças. Nos referimos ao n-ésimo termo dessa sequencia como T(n) e ela é definida da seguinte forma:

// T(0) = 0

// T(1) = 1

// T(2) = 1

// T(n) = T(n-1) + T(n-2) + T(n-3).

// Para um dado n, calcule T(n) modulo 1000000007.

// Input
// Um único inteiro, n (0 ≤ n ≤ 106).

// Output
// Imprima um único inteiro, a resposta para o problema.

// Examples
// inputCopy
// 0
// outputCopy
// 0
// inputCopy
// 1
// outputCopy
// 1
// inputCopy
// 3
// outputCopy
// 2
// inputCopy
// 4
// outputCopy
// 4
// inputCopy
// 5
// outputCopy
// 7
// inputCopy
// 420
// outputCopy
// 837509781
// inputCopy
// 1337
// outputCopy
// 791206819A. Gol da Alemanha!
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A quantidade de gols que a alemanha fez no Brasil foi 7! Muito tempo depois, em 2018 perceberam que o motivo de serem 7 gols estava diretamente relacionado a sequência de Tribonacci, Afinal T(6) = 7. Pode-se mostrar que essa sequência pode ser usada para estimar como o placar do jogo estaria neste momento.

// Tribonacci é uma sequência parecida com a sequência de Fibonacci, mas com algumas mudanças. Nos referimos ao n-ésimo termo dessa sequencia como T(n) e ela é definida da seguinte forma:

// T(0) = 0

// T(1) = 1

// T(2) = 1

// T(n) = T(n-1) + T(n-2) + T(n-3).

// Para um dado n, calcule T(n) modulo 1000000007.

// Input
// Um único inteiro, n (0 ≤ n ≤ 106).

// Output
// Imprima um único inteiro, a resposta para o problema.

// Examples
// inputCopy
// 0
// outputCopy
// 0
// inputCopy
// 1
// outputCopy
// 1
// inputCopy
// 3
// outputCopy
// 2
// inputCopy
// 4
// outputCopy
// 4
// inputCopy
// 5
// outputCopy
// 7
// inputCopy
// 420
// outputCopy
// 837509781
// inputCopy
// 1337
// outputCopy
// 791206819

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

ll tabela[1000005];
int mod = 1000000007;

int f(int x) {
  if (x == 0) {
    return 0;
  }
  if (x == 1) {
    return 1;
  }
  if (x == 2) {
    return 1;
  }
  if (tabela[x] != -1) {
    return tabela[x];
  }

  ll r1 = f(x - 1) % mod;
  ll r2 = f(x - 2) % mod;
  ll r3 = f(x - 3) % mod;

  tabela[x] = (r3 + ((r2 + r1) % mod)) % mod;

  return tabela[x];
}

int main() {
  int x;
  cin >> x;

  for (int i = 0; i < 1000005; i++) {
    tabela[i] = -1;
  }

  cout << f(x) << endl;

  return 0;
}
