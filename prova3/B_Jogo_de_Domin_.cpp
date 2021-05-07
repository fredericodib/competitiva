// B. Jogo de Dominó
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Todos conhecem o jogo de dominós, em que peças com dois valores devem ser colocadas na mesa em seqüência, de tal forma que os valores de peças imediatamente vizinhas sejam iguais. O objetivo desta tarefa é determinar se é possível colocar todas as peças de um conjunto dado em uma formação válida.

// É dado um conjuto de peças de dominó. Cada peça tem dois valores 𝑋 e 𝑌, com 𝑋 e 𝑌 variando de 0 a 6 (𝑋 pode ser igual a 𝑌). Sua tarefa é escrever um programa que determine se é possível organizar todas as peças recebidas em sequência, obedecendo as regras do jogo de dominó.

// Input
// A primeira linha da entrada contém um número inteiro 𝑁 (1≤𝑁≤100) que indica a quantidade de peças do conjunto. As 𝑁 linhas seguintes contêm, cada uma, a descrição de uma peça. Uma peça é descrita por dois inteiros 𝑋 e 𝑌 (0≤𝑋≤6 e 0≤𝑌≤6) que representam os valores de cada lado da peça.

// Output
// Imprima "sim" (sem aspas duplas) se for possível organizar todas as peças em uma formação válida ou a expressão ''nao" (sem aspas duplas), caso contrário.

// Examples
// inputCopy
// 3
// 0 1
// 2 1
// 2 1
// outputCopy
// sim
// inputCopy
// 2
// 1 1
// 0 0
// outputCopy
// nao
// inputCopy
// 6
// 3 0
// 0 0
// 1 6
// 4 1
// 0 6
// 2 3
// outputCopy
// sim

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

bool checkDom(vector<map<int, int>> g, ii dom, int left, int f, int s) {
  bool ret = false;

  g[dom.first][dom.second]--;
  g[dom.second][dom.first]--;

  if (g[dom.first][dom.second] == 0) {
    g[dom.first].erase(g[dom.first].find(dom.second));
  }
  if (g[dom.second][dom.first] == 0) {
    g[dom.second].erase(g[dom.second].find(dom.first));
  }

  if (left == 0) {
    return true;
  }
  for (ii x : g[f]) {
    ii p = {x.first, f};
    if (checkDom(g, p, left - 1, x.first, s)) {
      return true;
    }
  }
  for (ii x : g[s]) {
    ii p = {s, x.first};
    if (checkDom(g, p, left - 1, f, x.first)) {
      return true;
    }
  }
  return false;
}

int main() {
  int n, left;
  ii dom;
  scanf("%d", &n);
  left = n - 1;
  map<int, int> m;

  vector<map<int, int>> g(7);

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b) {
      m[a]++;
    }
    if (a != b || m[a] == 1) {
      g[a][b]++;
      g[b][a]++;
      if (i == 0) {
        dom = {a, b};
      }
    } else {
      left--;
    }
  }

  bool res = checkDom(g, dom, left, dom.first, dom.second);

  if (res) {
    cout << "sim" << endl;
  } else {
    cout << "nao" << endl;
  }

  return 0;
}