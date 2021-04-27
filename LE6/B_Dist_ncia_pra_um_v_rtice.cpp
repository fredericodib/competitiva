// B. Distância pra um vértice
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você recebe um grafo não-direcionado G com n vértices e m arestas. Também recebe um vértice k e q consultas. Os vértices estão enumerados de 1 a n. Cada consulta é descrita por um inteiro x , e a sua resposta é a distância do menor caminho que liga k a x, caso não haja caminho ligando k a x imprima "infinito".

// Input
// A primeira linha contém 2 inteiros n e m (1 ≤ n, m ≤ 105) - Número de vértices, número de arestas.

// A segunda linha contém 2 inteiros k e q ( 1 ≤ k ≤ n e 1 ≤ q ≤ 105) - O vértice k e o número de consultas.

// Depois seguem m linhas, as arestas do grafo, representadas por dois números a e b (1 ≤ a, b ≤ n - Significa que há uma aresta saindo de a e chegando em b.

// Depois seguem q linhas as consultas, em cada consulta, um número x - (1 ≤ x ≤ n) - o vértice em questão.

// Output
// Imprima q linhas, na i-ésima linha deve ser impressa a resposta para a i-ésima consulta.

// Examples
// inputCopy
// 5 4
// 1 5
// 1 2
// 2 3
// 3 4
// 4 5
// 1
// 2
// 3
// 4
// 5
// outputCopy
// 0
// 1
// 2
// 3
// 4
// inputCopy
// 5 5
// 1 5
// 1 2
// 2 3
// 3 4
// 4 5
// 1 3
// 1
// 2
// 3
// 4
// 5
// outputCopy
// 0
// 1
// 1
// 2
// 3

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int MAX_SIZE = 1000001;

vector<vector<int>> g(MAX_SIZE);
vector<int> d(MAX_SIZE, -1), p(MAX_SIZE, -1);

vector<int> shortest_path(int start) {

  queue<int> q;
  q.push(start);

  vector<bool> visited(MAX_SIZE, false);
  visited[start] = true;
  d[start] = 0;

  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int w : g[u]) {
      if (not visited[w]) {
        q.push(w);
        visited[w] = true;
        d[w] = d[u] + 1;
        p[w] = u;
      }
    }
  }

  return d;
}

int main() {
  int n, m, q, k;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &k, &q);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> d = shortest_path(k);

  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    if (d[x] != -1) {
      printf("%d\n", d[x]);
    } else {
      printf("infinito\n");
    }
  }

  return 0;
}