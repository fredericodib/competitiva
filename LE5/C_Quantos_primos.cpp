// C. Quantos primos
// time limit per test2.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você recebe Q consultas. Em cada consulta você recebe dois inteiros l e r. A resposta de cada consulta é quantos primos distintos existem no intervalo [l,r] (inclusivo).

// Input
// A primeira linha de entrada contém um inteiro Q (1 <= Q <= 10⁶) - A quantidade de consultas.

// Depois, seguem Q linhas, em cada uma, dois inteiros l e r (1 <= l <= r <= 10⁶).

// Output
// Imprima Q linhas, na i-ésima linha deve ser impressa a resposta para a i-ésima consulta.

// Examples
// inputCopy
// 3
// 1 3
// 1 1
// 1 5
// outputCopy
// 2
// 0
// 3
// inputCopy
// 1
// 1 1000000
// outputCopy
// 78498

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<int> marcacao(1000001, 1);

vector<int> primos_ate_n(int N) {
  marcacao[0] = 0;
  marcacao[1] = 0;
  for (int x = 2; x < N; x++)
    if (marcacao[x] == 1) {
      for (int m = x + x; m < N; m += x) {
        marcacao[m] = 0;
      }
    }
  return marcacao;
}

int main() {
  int tests;
  cin >> tests;
  vi marcacao = primos_ate_n(1000001);
  vi sum(1000001, 0);
  sum[1] = marcacao[1];
  for (int i = 2; i < 1000001; i++) {
    sum[i] = marcacao[i] + sum[i - 1];
  }

  while (tests-- > 0) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", sum[r] - sum[l] + marcacao[l]);
  }
  return 0;
}