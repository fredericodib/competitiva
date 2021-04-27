// A. Quantos divisores 2
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você recebe um número Q de consultas. Em cada consulta, lhe é informado um número x. A resposta de cada consulta é o número de divisores de um número.

// Input
// A primeira linha de entrada consiste de um número Q (1 <= Q <= 106). Depois seguem Q linhas, as consultas. (1 <= x <= 106).

// Output
// Imprima Q linhas, a i-ésima linha deve ser a resposta para a i-ésima consulta.

// Examples
// inputCopy
// 3
// 1
// 2
// 3
// outputCopy
// 1
// 2
// 2
// inputCopy
// 5
// 1
// 4
// 9
// 16
// 25
// outputCopy
// 1
// 3
// 3
// 5
// 3

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int qnt_div[1000001];

void computa_divisores(int N) {
  for (int x = 1; x < N; x++) {
    for (int m = x; m < N; m += x) {
      qnt_div[m]++;
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tests, m = 0;
  scanf("%d", &tests);

  for (int i; i < 1000001; i++) {
    qnt_div[i] = 0;
  }

  computa_divisores(1000001);

  while (tests-- > 0) {
    int x;
    scanf("%d", &x);
    printf("%d\n", qnt_div[x]);
  }

  return 0;
}