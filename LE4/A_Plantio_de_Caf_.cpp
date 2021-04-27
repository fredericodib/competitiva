// Seu Donato possui um terreno em sua propriedade e como um bom apreciador de café, começou a plantar café para consumo próprio. Após realizar diversos estudos, Donato preparou um terreno e verificou que esse terreno deve ser apropriadamente adubado para produzir um café de alta qualidade.

// O terreno para plantio é dividido em 𝑛 lotes, sequencialmente organizados. Como Seu Donato não tem condições de adubar os lotes manualmente (pois já é um senhor de idade), a solução encontrada foi utilizar uma máquina antiga para "lançar" adubo diariamente nos lotes do terreno. No entanto, a máquina está desregulada e lança aleatoriamente uma quantidade 𝑥 de adubo em lotes contíguos do terreno, definidos no intervalo [𝑙,𝑟], em que 𝑙 é o lote de início e 𝑟 é o lote final. Por isso, a máquina aduba igualmente os lotes compreendidos entre 𝑙 e 𝑟.

// Donato não é capaz de consertar a máquina, mas visualiza os lotes que receberam adubo e a quantidade de adubo que foi lançada nesses lotes em cada dia. Seu Donato pretende adubar os lotes do terreno durante 𝑞 dias e em seguida, realiza a colheita do café para consumo. No entanto, como podem existir vários lotes, Seu Donato não sabe os lotes que receberam adubo de maneira suficiente e que produzirão um café de qualidade.

// Ajude Seu Donato nesta tarefa e escreva um programa que determine a quantidade 𝑘 de lotes que produzirá um café de qualidade. Um café de alta qualidade pode ser colhido em um lote que recebeu, pelo menos, uma quantidade mínima 𝑡 de adubo durante 𝑞 dias.

// Obs: Cálculos intermediários podem estourar um inteiro de 32 bits.

// Input
// A entrada consiste de um único caso de teste. A primeira linha contém um inteiro 1≤𝑛≤105 que representa a quantidade de lotes no terreno de Donato, um inteiro 1≤𝑞≤105 que indica a quantidade de dias de funcionamento da máquina de adubo e um inteiro 1≤𝑡≤105 associado com a quantidade mínima de adubo para que o café produzido seja de alta qualidade. Em seguida, existem 𝑞 linhas, em que cada linha 𝑖 é definida por uma tupla 𝑙𝑖,𝑟𝑖 e 𝑥𝑖 (1≤𝑙𝑖≤𝑟𝑖≤105; 1≤𝑥𝑖≤105), em que 𝑙𝑖 define o lote inicial, 𝑟𝑖 é o lote final e 𝑥𝑖 se refere a quantidade de adubo igualmente lançada entre os lotes no intervalo [𝑙𝑖,𝑟𝑖].

// Output
// Imprima um único valor inteiro 𝑘 que determina a quantidade 𝑘 de lotes que produzirão o melhor café no terreno de Donato.

// Examples
// inputCopy
// 10 3 5
// 1 4 2
// 3 5 3
// 5 8 4
// outputCopy
// 3
// inputCopy
// 3 6 15
// 1 1 5
// 2 3 4
// 1 3 2
// 1 2 1
// 2 3 7
// 2 2 2
// outputCopy
// 1

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n, q, t, count = 0;
  cin >> n >> q >> t;
  vector<lli> d(n, 0);

  for (int i = 0; i < q; i++) {
    lli l, r, x;
    cin >> l >> r >> x;

    d[l - 1] += x;
    if (r < d.size()) {
      d[r] -= x;
    }
  }

  for (int i = 1; i < n; i++) {
    d[i] = d[i] + d[i - 1];
  }

  for (int i = 0; i < n; i++) {
    if (d[i] >= t) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}