// D. Lanche na Empresa
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Atualmente, uma empresa precisa oferecer mais que altos salários para manter seus melhores funcionários. Um dos benefícios comumente oferecidos é acesso a um suprimento infinito de comida e bebida disponível em cozinhas, onde os funcionários podem preparar lanches e refeições.

// Uma empresa de tecnologia decidiu posicionar uma cozinha em suas instalações; entretanto, essa tarefa requer um certo planejamento. Analisando a planta do prédio é possível criar um diagrama contendo todas as salas, todos os corredores que as ligam e os seus respectivos comprimentos, em metros. A cozinha deve ser posicionada em uma das salas de tal forma que a distância entre a cozinha e a sala mais distante da cozinha seja a menor possível.

// Obviamente, a empresa deseja utilizar esse fato para anunciar que "nenhum de seus funcionários está a mais de 𝑋 metros de uma cozinha". Eles contrataram o seu escritório de arquitetura para posicionar a cozinha na sala que minimiza 𝑋 e você, como programador, deve escrever um programa que informa qual será essa distância.

// Input
// A primeira linha da entrada contém dois inteiros, 𝑆 e 𝐶, (1≤𝑆≤250,1≤𝐶≤50.000) indicando, respectivamente, o número de salas e o número de corredores. As 𝐶 linhas seguintes contêm, cada uma, três inteiros, 𝐴, 𝐵 e 𝐷 (1≤𝐴≤𝑁,1≤𝐵≤𝑁,1≤𝐷≤100,𝐴≠𝐵) indicando que existe um corredor de 𝐷 metros ligando a sala 𝐴 à sala 𝐵. Cada corredor é informado uma única vez na entrada. Note que um corredor ligando as salas 𝐴 e 𝐵 pode ser percorrido nos dois sentidos (da sala 𝐴 para a sala 𝐵 e da sala 𝐵 para a sala 𝐴).

// Output
// Imprima uma única linha contendo um inteiro indicando a distância entre a cozinha e a sala mais distante, considerando que a cozinha foi posicionada na sala onde essa distância é mínima.

// Examples
// inputCopy
// 4 6
// 1 2 1
// 2 3 1
// 2 4 2
// 3 4 1
// 1 4 1
// 3 1 4
// outputCopy
// 2
// inputCopy
// 4 4
// 1 2 10
// 2 3 1
// 3 4 4
// 2 4 3
// outputCopy
// 10
// inputCopy
// 5 6
// 1 2 10
// 2 3 10
// 2 4 11
// 2 5 11
// 3 4 10
// 4 5 10
// outputCopy
// 11

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

const int N = 260;
const ll oo = 1000000;

// vector<vector<pair<int, int>>> g(N);

vector<pair<int, ll>> g[N];

int dijkstra(int start, int n) {
  int maxi = 0;
  int d[N];

  for (int u = 1; u <= n; u++)
    d[u] = oo;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
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

  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, d[i]);
  }
  return maxi;
}

int main() {
  int n, m, maxi = 1000000;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);

    g[a].push_back({b, w});
    g[b].push_back({a, w});
  }

  for (int i = 1; i <= n; i++) {
    maxi = min(maxi, dijkstra(i, n));
  }

  printf("%d\n", maxi);

  return 0;
}