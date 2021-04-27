// D. Primos-T
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Um número é considerado um Primo-T se ele tem exatamente 3 divisores. Você recebe Q consultas, em cada consulta, um número X, e deve dizer se X é um primo-t.

// (Lembre-se que os divisores de um número podem ser calculados a partir dos fatores primos, por exemplo, 36 = 2²x3² tem 9 divisores, pois podemos escolher 3 potências para 2 e 3 potências para 3, e combiná-las. Sabendo disso, em qual situação um número terá 3 divisores?)

// Input
// A primeira linha contém um número Q (1 <= Q <= 105)- A quantidade de consultas. As próximas Q linhas contém em cada um número X (1 <= X <= 1012) - As consultas.

// Output
// Imprima Q linhas, a resposta para a i-ésima consulta deve estar na i-ésima linha. Se a resposta for verdadeiro, imprima 1, caso contrário, imprima 0.

// Examples
// inputCopy
// 3
// 4 5 6
// outputCopy
// 1
// 0
// 0
// inputCopy
// 4
// 1 2 3 4
// outputCopy
// 0
// 0
// 0
// 1

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<int> primos(1000001, 1);

vector<int> primos_ate_n(int N) {
  primos[0] = 0;
  primos[1] = 0;
  for (int x = 2; x <= N; x++)
    if (primos[x] == 1) {
      for (int m = x + x; m < N; m += x) {
        primos[m] = 0;
      }
    }
  return primos;
}

int main() {
  int tests;
  cin >> tests;
  vi primos = primos_ate_n(1000001);

  while (tests-- > 0) {
    lli x;
    scanf("%lld", &x);
    lli sqr = sqrt(x);
    if (sqr * sqr == x) {
      printf("%d\n", primos[sqr]);
    } else {
      printf("0\n");
    }
  }
  return 0;
}