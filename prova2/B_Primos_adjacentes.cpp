// B. Primos adjacentes
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Primos adjacentes são definidos por dois números primos que não possuem um terceiro número primo entre eles. Por exemplo, os números 3 e 5 são dois números primos adjacentes, pois não existe outro número primo entre eles.

// Dados dois números inteiros 𝑁 e 𝑀, sua tarefa consiste em encontrar os dois números primos adjacentes 𝐴 e 𝐵 (𝑁≤𝐴<𝐵≤𝑀) que são os mais próximos, isto é, que a distância ⏐𝐵−𝐴⏐ é mínima. Se existirem outros pares que possuem a mesma distância, considere como resposta o primeiro par de primos (em que 𝐴 e 𝐵 possuem menor magnitude).

// Input
// A primeira linhda da entrada contém um número inteiro 1≤𝑄≤102 indicando a quantidade de consultas. Em seguida, existem 𝑄 linhas, cada uma apresentando dois números inteiros positivos 𝑁 e 𝑀 separados por um espaço em branco (1≤𝑁<𝑀≤106).

// Output
// Imprima os dois números primos adjacentes 𝐴 e 𝐵, caso seja possível obtê-los. Caso contrário, imprima −1.

// Example
// inputCopy
// 4
// 3 7
// 1 17
// 10 50
// 185 321
// outputCopy
// 3 5
// 2 3
// 11 13
// 191 193

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<int> primos;

vector<int> primos_ate_n(int N) {
  vector<int> marcacao(N, 1); // 1 = possivel primo, 0 = com certeza não primo
  for (int x = 2; x < N; x++)
    if (marcacao[x] == 1) {
      primos.push_back(x);
      for (int m = x + x; m < N; m += x) {
        marcacao[m] = 0; // aqui descobrimos que m não é primo
      }
    }
  return primos;
}

int main() {
  int tests;
  cin >> tests;
  primos_ate_n(1000001);

  while (tests-- > 0) {
    int l, r;
    scanf("%d %d", &l, &r);

    vector<pair<int, int>> par;

    for (int i = 0; i < primos.size() - 1; i++) {
      if (primos[i] >= r) {
        break;
      }
      if (primos[i] >= l && primos[i + 1] <= r) {
        par.push_back({primos[i + 1] - primos[i], i});
      }
    }

    sort(par.begin(), par.end());

    if (par.size() != 0) {
      printf("%d %d\n", primos[par[0].second], primos[par[0].second + 1]);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}