// A. Distâncias para um vértice com pesos
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// você recebe um grafo com n vértices e m arestas, os vértices estão enumerados de 1 a n e as arestas tem pesos e são bidirecionais. Nesse grafo há um vértice especial s. Você deve responder a Q consultas, em cada consulta você vai receber um vértice x, e informar a menor distância de s até x.

// Input
// Na primeira linha de entrada você recebe dois inteiros n e m. (1 ≤ n ≤ 2 * 104 e 1 ≤ m ≤ 2 * 105

// Na segunda linha você recebe dois inteiros s e Q. (1 ≤ s ≤ n e 1 ≤ Q ≤ 105).

// Depois seguem m linhas, as arestas do grafo. Cada aresta é bidirecional e é representada por 3 inteiros, a, b, w. a e b são os vértices que ela conecta e w seu peso. (1 ≤ a, b ≤ n e 1 ≤ w ≤ 104.

// Após isso, seguem Q consultas, cada consulta é descrita por um inteiro x, representando um vértice a resposta será a distância mínima de s para x.

// Output
// Imprima Q linhas, a resposta para a i-ésima consulta deve ser a i-ésima linha.

// Examples
// inputCopy
// 3 3
// 1 3
// 1 2 2
// 2 3 2
// 1 3 5
// 1
// 2
// 3
// outputCopy
// 0
// 2
// 4
// inputCopy
// 3 3
// 1 3
// 1 2 2
// 2 3 2
// 1 3 3
// 1
// 2
// 3
// outputCopy
// 0
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

const int N = 100005;
const ll oo = 1e18;

// vector<vector<pair<int, int>>> g(N);
ll d[N];

vector<pair<int, ll>> g[N];

void dijkstra(int start, int n) {

  for (int u = 1; u <= n; u++)
    d[u] = oo;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
      pq;

  d[start] = 0;
  pq.emplace(d[start], start);

  ll dt, w;
  int u, v;
  while (!pq.empty()) {
    tie(dt, u) = pq.top();
    pq.pop();
    if (dt > d[u])
      continue;
    for (auto edge : g[u]) {
      tie(v, w) = edge;

      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        pq.emplace(d[v], v);
      }
    }
  }
}

int main() {
  int n, m, s, q;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &s, &q);

  for (int i = 0; i < m; i++) {
    int a, b;
    ll w;
    scanf("%d %d %lld", &a, &b, &w);

    g[a].push_back({b, w});
    g[b].push_back({a, w});
  }

  dijkstra(s, n);

  for (int i = 0; i < q; i++) {
    int a;
    scanf("%d", &a);

    printf("%d\n", d[a]);
  }

  return 0;
}