// F. Os ovos de Veras
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Veras quer dar ovos de pascoa para seus amigos, mas não tem o suficiente para dar para todos em um só dia. Veras tem n amigos, numerados de 1 a n e quer dar ovos para eles por m dias. No iésimo dia, Veras pede sua ajuda: ele quer dar ovos para todos seus amigos cujos índices são divisores de xi e não receberam ovos nos ultimos yi dias. Diga a Veras quantos ovos ele precisará cada dia.

// Input
// A primeira linha da entrada contém dois inteiros m e n (1 ≤ m, n ≤ 105), quantos dias Veras pede sua ajuda e o número de amigos dele.

// As próximas m linhas de entrada contém dois inteiros cada, xi e yi (1 ≤ xi ≤ 105, 0 ≤ yi ≤ i - 1, com i indexado a partir de 1).

// Output
// A saída deve conter m linhas, a iésima delas com a quantidade de ovos que Veras precisa para o iésimo dia.

// Examples
// inputCopy
// 6 10000
// 4 0
// 3 1
// 5 2
// 6 2
// 18 4
// 10000 3
// outputCopy
// 3
// 1
// 1
// 3
// 2
// 22
// inputCopy
// 2 9859
// 84917 0
// 62186 1
// outputCopy
// 4
// 13
// Note
// No primeiro caso de teste, Veras vai dar ovos para as seguintes pessoas:

// Dia 1: 1,2,4

// Dia 2: 3

// Dia 3: 5

// Dia 4: 1,2,6

// Dia 5: 9,18

// Dia 6: 4,8,10,16,20,25,32...

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<vector<int>> qnt_div;
map<int, int> mapa;

void computa_divisores(int N) {
  for (int x = 1; x <= N; x++) {
    vector<int> v;
    qnt_div.push_back(v);
    mapa[x] = -1;
  }
  for (int x = 1; x <= N; x++) {
    for (int m = x; m <= N; m += x) {
      qnt_div[m].push_back(x);
    }
  }
}

int main() {
  lli m, n;
  scanf("%lld %lld", &m, &n);

  computa_divisores(100001);

  for (lli i = 1; i <= m; i++) {
    lli x, y, count = 0;
    scanf("%lld %lld", &x, &y);

    for (int elem : qnt_div[x]) {
      if (mapa[elem] + y < i && elem <= n) {
        count++;
        mapa[elem] = i;
      }
    }

    printf("%lld\n", count);
  }

  return 0;
}