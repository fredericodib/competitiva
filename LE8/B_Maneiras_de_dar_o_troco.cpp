// B. Maneiras de dar o troco
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Joãozinho tem infinitas moedas de N valores diferentes, e ele gostaria de saber quantas sequências de inteiros distintas ele consegue formar de forma que os inteiros nessa sequência sejam valores das moedas, e a soma de todos os valores na sequência seja x.

// Em outras palavras joãozinho quer dar um troco x, e quer saber de quantas maneiras diferentes consegue construir esse troco, mas com a ordem importando.

// Então por exemplo: se joãozinho quer somar o valor 8, e ele tem moedas de valores 2, 3 e 5, há várias formas de dar o troco:

// [5,3],[3,5], [2,3,3], [3,2,3], [3,3,2], [2,2,2,2].

// Ajude joãozinho a resolver esse problema.

// Input
// A primeira linha contém dois inteiros N e X (1 ≤ n ≤ 15, 1 ≤ x ≤ 10000).

// Na segunda linha seguem N inteiros, os valores de cada moeda. Esses valores são distintos e positivos, e não excedem 10000.

// Output
// Imprima a quantidade de maneiras de dar o troco, como esse número pode ser muito grande, imprima-o modulo 1000000007.

// Examples
// inputCopy
// 3 8
// 2 3 5
// outputCopy
// 6
// inputCopy
// 2 3
// 1 2
// outputCopy
// 3
// inputCopy
// 2 4
// 1 2
// outputCopy
// 5
// inputCopy
// 2 5
// 1 2
// outputCopy
// 8
// inputCopy
// 3 12
// 1 2 4
// outputCopy
// 520
// inputCopy
// 4 50
// 2 3 9 17
// outputCopy
// 1826413

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vi p;
int x;
int tabela[10005];

int f(int total) {
  if (total == x) {
    return 1;
  }
  if (tabela[total] != -1) {
    return tabela[total];
  }

  int value = 0;
  for (int y : p) {
    if (total + y <= x) {
      value = (value + f(total + y)) % 1000000007;
    }
  }

  tabela[total] = value % 1000000007;
  return tabela[total];
}

int main() {
  int n;
  cin >> n >> x;

  for (int i = 0; i < 10005; i++) {
    tabela[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    p.push_back(x);
  }

  cout << f(0) << endl;

  return 0;
}