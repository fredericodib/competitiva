// A. Graus de entrada e saída
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você recebe um grafo direcionado G com n vértices e m arestas, e q consultas. Os vértices estão enumerados de 1 a n. Cada consulta tem um tipo t, e um vértice x, consultas do tipo 1 querem saber o grau de saída do vértice x, e consultas do tipo 2 querem saber o grau de entrada do vértice x.

// Input
// A primeira linha contém 3 inteiros n, m e q (1 ≤ n, m, q ≤ 105) - Número de vértices, número de arestas e número de consultas.

// Depois seguem m linhas, as arestas do grafo, representadas por dois números a e b (1 ≤ a, b ≤ n - Significa que há uma aresta saindo de a e chegando em b.

// Depois seguem q linhas as consultas, em cada consulta, haverá dois números t e x - (1 ≤ t ≤ 2 e 1 ≤ x ≤ n) - o tipo da consulta e o vértice em questão.

// Output
// Imprima q linhas, na iésima linha deve estar a resposta para a i-ésima consulta.

// Example
// inputCopy
// 5 5 5
// 3 1
// 1 2
// 2 4
// 4 1
// 4 5
// 1 1
// 1 4
// 2 1
// 1 5
// 2 3
// outputCopy
// 1
// 2
// 2
// 0
// 0

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);

  vector<vector<int>> graph(n + 1);
  vector<vector<int>> graph_reverse(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph_reverse[b].push_back(a);
  }

  for (int i = 0; i < q; i++) {
    int t, x;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      printf("%d\n", graph[x].size());
    } else {
      printf("%d\n", graph_reverse[x].size());
    }
  }

  return 0;
}