// C. Vértice dominante
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Em teoria dos grafos, diz-se que um vértice 𝑢 domina um vértice 𝑣 se cada caminho de um vértice de partida 𝑠 até 𝑣 passa obrigatoriamente por 𝑢. Se não for possível alcançar 𝑣 a partir de 𝑠, então o vértice 𝑣 não possui nenhum vértice dominante. Por definição, cada vértice alcançável de 𝑠 domina a si próprio.

// Considere um grafo direcionado e não-ponderado, em que os vértices são enumerados de 1 a 𝑁. Elabore um programa que determine se um vértice do grafo 𝑢 domina um vértice 𝑣, em que 1 é sempre o vértice de partida. Você terá que responder diversas consultas relacionadas a diferentes combinações de vértices 𝑢 e 𝑣.

// Input
// A primeira linha da entrada contém três números inteiros separados por espaço em branco 𝑁, 𝑀 e 𝑄 (2≤𝑁≤500,1≤𝑀≤𝑁×(𝑁−1)/2,1≤𝑄≤100) que representam a quantidade de vértices e de arestas do grafo, e a quantidade de consultas, respectivamente.

// As próximas 𝑀 linhas descrevem as arestas do grafo. Cada linha contém dois números inteiros 𝑎 e 𝑏 (1≤𝑎,𝑏≤𝑁) indicando a existência de uma aresta conectando os vértices 𝑎 e 𝑏.

// Em seguida, existem 𝑄 linhas representando as consultas. Cada linha consiste de dois números inteiros separados por espaço em branco 𝑢 e 𝑣 (1≤𝑢,𝑣≤𝑁) associados aos vértices em que se deve verificar se 𝑣 é um vértice dominante em relação ao vértice 𝑢.

// Output
// Para cada consulta, imprima "sim" (sem aspas duplas) se um vértice 𝑣 é um vértice dominante em relação ao vértice 𝑢. Caso contrário, imprima "nao" (também sem aspas duplas).

// Examples
// inputCopy
// 5 5 4
// 1 2
// 1 3
// 2 4
// 3 4
// 4 5
// 1 2
// 3 2
// 2 4
// 1 4
// outputCopy
// sim
// nao
// nao
// sim
// inputCopy
// 3 3 2
// 2 1
// 2 3
// 1 3
// 1 1
// 1 3
// outputCopy
// sim
// sim
// Note
// No primeiro exemplo, o vértice 3 domina o vértice 4 uma vez que todos os caminhos de 1 até 5 passam pelo vértice 3. O vértice 1 não domina o vértice 3, pois existe o caminho 0−2−3 que não inclui o vértice 1.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int MAX_SIZE = 600;
vector<vector<int>> g(MAX_SIZE);

vector<vector<int>> g_back(MAX_SIZE);
int d[600][600];

vector<bool> alcancavel(MAX_SIZE, false);

void dfs(int vertex) {
  alcancavel[vertex] = true;

  for (int w : g[vertex]) {
    if (!alcancavel[w]) {
      dfs(w);
    }
  }
}

bool shortest_path(int u, int v, vector<bool> path, int n) {
  bool full = true;
  path[v] = true;

  if (v == 1) {
    d[v][u] = 0;
    return false;
  }

  for (int w : g_back[v]) {
    if (alcancavel[w] && w != u && !path[w] && d[w][u] != 1) {
      if (d[w][u] == -1) {
        if (!shortest_path(u, w, path, n)) {
          d[v][u] = 0;
          d[w][u] = 0;
          return false;
        }
      } else {
        return false;
      }
    } else if (path[w]) {
      full = false;
    }
  }
  // cout << u << " " << v << endl;
  if (full || n > 50) {
    d[v][u] = 1;
  }

  return true;
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g_back[b].push_back(a);
  }

  dfs(1);
  vector<bool> path(MAX_SIZE, false);

  for (int i = 0; i < 600; i++) {
    for (int j = 0; j < 600; j++) {
      d[i][j] = -1;
    }
  }

  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    if (!alcancavel[v]) {
      printf("nao\n");
    } else if (!alcancavel[u]) {
      printf("nao\n");
    } else if (v == u) {
      printf("sim\n");
    } else if (shortest_path(u, v, path, n)) {
      printf("sim\n");
    } else {
      printf("nao\n");
    }
  }

  return 0;
}