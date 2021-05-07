// E. Desvio de Rota
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// O sistema rodoviário de um país interliga todas as suas 𝑁 cidades de modo que, a partir de uma cidade qualquer, é possível chegar a cada uma das outras cidades trafegando pelas estradas existentes. Cada estrada liga duas cidades distintas, tem mão dupla e um único posto de pedágio (o pedágio é pago nos dois sentidos de tráfego). As estradas não se intersectam a não ser nas cidades. Nenhum par de cidades é interligado por duas ou mais estradas.

// A Transportadora Dias oferece um serviço de transporte de encomendas entre as cidades. Cada encomenda deve ser levada de uma cidade 𝐴 para uma outra cidade 𝐵. A direção da Transportadora Dias define, para cada encomenda, uma rota de serviço, composta por 𝐶 cidades e 𝐶−1 estradas: a primeira cidade da rota de serviço é a origem da encomenda, a última o destino da encomenda. A rota de serviço não passa duas vezes pela mesma cidade, e o veículo escolhido para fazer o transporte de uma encomenda pode trafegar apenas pela rota de serviço definida.

// Certo dia, no entanto, o veículo que executava uma entrega quebrou e precisou ser levado para conserto em uma cidade que não está entre as cidades de sua rota de serviço. A direção da Transportadora Dias quer saber qual é o menor custo total, em termos de pedágio, para que o veículo entregue a encomenda na cidade destino, a partir da cidade em que foi consertado, mas com uma restrição adicional: se em algum momento o veículo passar por uma das cidades que compõem a sua rota de serviço, ele deve voltar a obedecer a rota de serviço.

// Input
// A primeira linha contém quatro inteiros 𝑁, 𝑀, 𝐶 e 𝐾 (4≤𝑁≤250, 3≤𝑀≤𝑁∗(𝑁−1)/2, 2≤𝐶≤𝑁−1 e 𝐶≤𝐾≤𝑁−1), representando, respectivamente, o número de cidades do país, o número de estradas, o número de cidades na rota de serviço e a cidade em que o veículo foi consertado. As cidades são identificadas por inteiros de 0 a 𝑁−1. A rota de serviço é 0, 1, ... , 𝐶−1, ou seja, a origem é 0, de 0 passa para 1, de 1 para 2 e assim por diante, até o destino 𝐶−1.

// As 𝑀 linhas seguintes descrevem o sistema rodoviário do país. Cada uma dessas linhas descreve uma estrada e contém três inteiros 𝑈, 𝑉 e 𝑃 (0≤𝑈, 𝑉≤𝑁−1, 𝑈 ≠ 𝑉, 0≤𝑃≤250), indicando que há uma estrada interligando as cidades 𝑈 e 𝑉 com custo de pedágio 𝑃.

// Output
// O seu programa deve imprimir uma única linha, contendo um único inteiro 𝑇, o custo total mínimo necessário, em termos de pedágio, para que o veículo chegue ao destino.

// Examples
// inputCopy
// 4 6 3 3
// 0 1 10
// 1 2 10
// 0 2 1
// 3 0 1
// 3 1 10
// 3 2 10
// outputCopy
// 10
// inputCopy
// 6 7 2 5
// 5 2 1
// 2 1 10
// 1 0 1
// 3 0 2
// 3 4 2
// 3 5 3
// 5 4 2
// outputCopy
// 6
// inputCopy
// 5 5 2 4
// 0 1 1
// 1 2 2
// 2 3 3
// 3 4 4
// 4 0 5
// outputCopy
// 6

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
  int n, m, c, k;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &c, &k);

  for (int i = 0; i < m; i++) {
    int a, b;
    ll w;
    scanf("%d %d %lld", &a, &b, &w);

    if (a >= c && b >= c) {
      g[a].push_back({b, w});
      g[b].push_back({a, w});
    } else if (a >= c && b < c) {
      g[a].push_back({b, w});
    } else if (b >= c && a < c) {
      g[b].push_back({a, w});
    } else {
      if (max(a, b) - min(a, b) == 1) {
        g[min(a, b)].push_back({max(a, b), w});
      }
    }
  }

  dijkstra(k, n);

  printf("%d\n", d[c - 1]);

  return 0;
}