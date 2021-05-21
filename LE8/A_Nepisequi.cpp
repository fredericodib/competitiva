// A. Nepisequi
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// O menino Nepisequi está jogando um joguinho em que ele possui um carro que pode carregar no máximo W quilos e deve transportar diferentes itens para um determinado destino, cada item possui um peso Pi e um valor Vi, como Nepisequi pode não conseguir transportar todos os itens em seu carro ele pediu a sua ajuda para determinar qual o conjunto de itens que ele pode transportar que possui a maior soma de valores.

// Input
// A primeira linha possui dois inteiros W e N (1  ≤  W, N  ≤  1000), o peso que o carro de Nepisequi suporta e a quantidade de itens disponíveis.

// A segunda linha contém N inteiros separados por espaço, representado os pesos dos itens, o i-ésimo inteiro representa o valor de Pi.

// A ultima linha contém N inteiros separados por espaço, representado os valores dos itens, o i-ésimo inteiro representa o valor de Vi. 1  ≤  Pi, Vi  ≤  1000

// Output
// Imprima um único inteiro, a soma dos valores do conjunto de itens que possui a maior soma de valores.

// Examples
// inputCopy
// 10 3
// 1 10 7
// 5 10 7
// outputCopy
// 12
// inputCopy
// 100 6
// 12 54 90 80 23 6
// 23 43 60 50 30 10
// outputCopy
// 106

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vi p, v;
int w;
int tabela[1005][1005];

int soma_func(int i, int current_p) {
  if (i > p.size()) {
    return 0;
  }
  if (tabela[i][current_p] != -1) {
    return tabela[i][current_p];
  }

  if (p[i] + current_p <= w) {
    int r1, r2;
    r1 = soma_func(i + 1, current_p + p[i]) + v[i];
    r2 = soma_func(i + 1, current_p);
    tabela[i][current_p] = max(r1, r2);
    return tabela[i][current_p];
  }

  tabela[i][current_p] = soma_func(i + 1, current_p);
  return tabela[i][current_p];
}

int main() {
  int n;
  cin >> w >> n;

  for (int i = 0; i < 1005; i++) {
    for (int j = 0; j < 1005; j++) {
      tabela[i][j] = -1;
    }
  }

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    p.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }

  cout << soma_func(0, 0) << endl;

  return 0;
}