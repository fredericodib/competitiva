// E. Vestuário de casamento
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Em um recente almoço de confraternização, Anacleto anunciou aos amigos de longa data Bonifácio e Epaminondas que iria se casar, o que deixou Bonifácio e Epaminondas bastante eufóricos. Anacleto também disse que contava com a ajuda dos amigos para auxiliá-lo na compra das roupas que ele vai vestir no casamento.

// Os amigos Bonifácio e Epaminondas ficaram preocupados, pois não entendem muito de vestuário para casamentos, mas sabem que precisam comprar algumas roupas, como camisa, cinto, sapatos, terno, entre outros acessórios. Eles se dirigem ao shopping na busca pelo vestuário apropriado para Anacleto usar no casamento e ao chegar em uma das lojas, ficam com dúvidas, pois existem vários modelos para cada item de vestuário (por exemplo, três camisas, dois cintos, quatro sapatos, cinco gravatas).

// Os amigos necessitam comprar apenas um único modelo de cada item de vestuário. Bonifácio e Epaminondas não podem gastar mais do que o orçamento previsto 𝑉, mas eles querem gastar o máximo que puderem, pois querem que Anacleto utilize as melhores roupas no dia do casamento. É possível também que Bonifácio e Epaminondas não consigam comprar um modelo de cada tipo de vestuário devido a baixa quantia de dinheiro que eles podem carregar.

// Elabore um programa que, dada a quantidade 𝐶 de itens de vestuário que podem ser comprados, determine a quantidade máxima de dinheiro necessário para comprar um modelo de cada tipo de vestuário sem exceder, a quantia inicial 𝑉.

// Input
// A primeira linha contém dois números inteiros separados por um espaço em branco 𝑉 e 𝐶 (1≤𝑉≤200, e 1≤𝐶≤20), em que 𝑉 é a quantia de dinheiro que Bonifácio e Epaminondas possuem e 𝐶 é a quantidade de peças distintas de vestuário que eles tem que comprar.

// As próximas 𝐶 linhas descrevem as peças de vestuário e seus respectivos modelos. Em cada linha, o primeiro número inteiro 𝐾𝑖(1≤𝐾𝑖≤20) indica a quantidade de modelos para a 𝑖-ésima peça de vestuário (𝑖=1,2,...,𝑁). Em seguida, existem 𝐾𝑖 números inteiros separados por um espaço em branco, representando o preço 𝑃𝑗 (1≤𝑃𝑗≤300,𝑗=1,...,𝐾𝑖) de cada modelo da 𝑖-ésima peça de vestuário.

// Output
// Imprima um único número inteiro indicando a quantidade máxima de dinheiro necessário para comprar um modelo de cada tipo vestuário sem exceder a quantia inicial 𝑉. Caso não exista solução, imprima −1.

// Examples
// inputCopy
// 100 4
// 3 8 6 4
// 2 5 10
// 4 1 3 3 7
// 4 50 14 23 8
// outputCopy
// 75
// inputCopy
// 20 3
// 3 4 6 8
// 2 5 10
// 4 1 3 5 5
// outputCopy
// 19
// inputCopy
// 5 3
// 3 6 4 8
// 2 10 6
// 4 7 3 1 7
// outputCopy
// -1

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<vector<int>> roupas;
int v, c;
int tabela[1005][1005];
bool tabela_bool[1005][1005];

int f(int i, int e) {
  if (i >= c) {
    return 0;
  }
  if (tabela_bool[i][e]) {
    return tabela[i][e];
  }

  int count = 0;
  int value = 0;
  for (int x : roupas[i]) {
    if (x + e > v) {
      count++;
    } else {
      int r = f(i + 1, e + x);
      if (r == -1) {
        count++;
      }
      if (r != -1) {
        value = max(value, r + x);
      }
    }
  }

  if (count == roupas[i].size()) {
    tabela[i][e] = -1;
  } else {
    tabela[i][e] = value;
  }

  tabela_bool[i][e] = true;
  return tabela[i][e];
}

int main() {
  memset(tabela, -1, sizeof(tabela));

  cin >> v >> c;

  for (int i = 0; i < c; i++) {
    int x;
    scanf("%d", &x);
    vi vec;

    for (int j = 0; j < x; j++) {
      int y;
      scanf("%d", &y);
      vec.push_back(y);
    }
    roupas.push_back(vec);
  }

  cout << f(0, 0) << endl;

  return 0;
}