// C. Labirinto de ratos
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Um conjunto de ratos de laboratório está sendo treinado para escapar de um labirinto. O labirinto é feito de células, e cada célula está conectada a algumas outras células. No entanto, existem obstáculos na passagem entre as células e, portanto, há uma penalidade de tempo para superar a passagem.

// Suponha que todos os ratos estejam treinados e, quando colocados em uma célula arbitrária no labirinto, fazem um caminho que os leva à célula de saída em um tempo mínimo. Vamos realizar a seguinte experiência: um rato é colocado em cada célula do labirinto e um cronômetro de contagem regressiva é iniciado. Quando o tempo chega em 0, contamos o número de ratos fora do labirinto.

// Escreva um programa que, dada uma descrição do labirinto e do tempo inicial no cronômetro, prevê o número de ratos que sairão do labirinto. Suponha que todas as células tem espaço para um número arbitrário de ratos.

// Input
// A primeira linha tem 4 números: 𝑁 (2≤𝑁≤100000), 𝑀 (0≤𝑀≤500000), 𝑆 (0≤𝑆<𝑁) e 𝑇 (1≤𝑇≤100000). Onde 𝑁 é o número de células no labirinto, 𝑀 é o número de conexões no labirinto, 𝑆 representa a célula de saída e 𝑇 é o tempo inicial, em segundos, do cronômetro.

// A seguir, tem 𝑀 linhas, cada uma especificando uma conexão no labirinto, com três números inteiros: 𝑎 (0≤𝑎<𝑁), 𝑏 (0≤𝑏<𝑁), 𝑤 (0≤𝑤≤10000), indicando que há uma conexão unidirecional da célula 𝑎 para a célula 𝑏 e o tempo que um rato leva para passar por esta conexão é 𝑤 segundos.

// Output
// A saída consiste em uma única linha com o número de ratos que alcançou a célula de saída 𝑆 em no máximo 𝑇 segundos.

// Examples
// inputCopy
// 4 8 2 1
// 0 1 1
// 0 2 1
// 1 0 1
// 1 3 1
// 2 0 1
// 2 3 1
// 3 1 1
// 3 2 1
// outputCopy
// 3
// inputCopy
// 2 1 0 87597
// 0 1 2762
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

const int N = 100005;
const ll oo = 1e18;

// vector<vector<pair<int, int>>> g(N);
ll d[N];

vector<pair<int, ll>> g[N];

void dijkstra(int start, int n) {

  for (int u = 0; u < n; u++)
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
  int n, m, s, count = 0;
  ll t;
  scanf("%d %d", &n, &m);
  scanf("%d %lld", &s, &t);

  for (int i = 0; i < m; i++) {
    int a, b;
    ll w;
    scanf("%d %d %lld", &a, &b, &w);

    g[b].push_back({a, w});
  }

  dijkstra(s, n);

  for (int i = 0; i < n; i++) {
    // printf("%lld\n", d[i]);
    if (i == s || (d[i] <= t && d[i] != 0)) {
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}