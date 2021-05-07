// D. Soldados
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Um grupo de soldados foi designado para uma tarefa crítica. Eles devem destruir um quartel inimigo. O quartel inimigo consiste em vários edifícios e os edifícios estão ligados por estradas. Os soldados devem visitar cada edifício e colocar uma bomba na base de cada edifício. Eles começam a sua missão na base de um edifício particular 𝑆 e de lá eles se disseminam para chegar a cada edifício. Os soldados devem usar as estradas disponíveis para viajar entre os edifícios. Qualquer um deles pode visitar um edifício após o outro, mas todos eles devem se reunir em um lugar comum, o edifício 𝑇, quando sua tarefa for feita.

// Seu trabalho é determinar o tempo mínimo necessário para completar a missão. Cada soldado leva exatamente uma unidade de tempo para se deslocar entre os edifícios. Você pode assumir que o tempo necessário para colocar uma bomba é insignificante. Cada soldado pode transportar número ilimitado de bombas e há um suprimento ilimitado de soldados para a missão.

// Input
// A primeira linha tem 2 números 𝑁 (2≤𝑁≤100) e 𝑀 (0≤𝑀≤10000), onde 𝑁 é o número de edifícios no quartel inimigo e 𝑀 é o de estradas que ligam os edifícios nesses quarteis.

// A seguir, tem 𝑀 linhas, com dois números inteiros 𝑎 (0≤𝑎<𝑁) e 𝑏 (0≤𝑏<𝑁), indicando que há uma estrada bidirecional ligando o quartel 𝑎 com o quartel 𝑏. A última linha contém dois inteiros 0≤𝑆,𝑇<𝑁. Onde 𝑆 denota o edifício de onde a missão começa e 𝑇 denota o edifício final, onde todos devem se encontrar ao final da missão . É garantido que tem como completar a missão.

// Output
// Imprima um inteiro, indicando o menor tempo para completar a missão.

// Examples
// inputCopy
// 4 3
// 0 1
// 2 1
// 1 3
// 0 3
// outputCopy
// 4
// inputCopy
// 2 1
// 0 1
// 1 0
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

const int N = 200;
const ll oo = 1e18;

ll dT[N];
ll dO[N];
vector<ll> d(N, -1);

vector<pair<int, ll>> g[N];

void dijkstraT(int start, int n) {
  for (int u = 0; u < n; u++)
    dT[u] = oo;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
      pq;

  dT[start] = 0;
  pq.emplace(dT[start], start);

  ll dt, w;
  int u, v;
  while (!pq.empty()) {
    tie(dt, u) = pq.top();
    pq.pop();
    if (dt > dT[u])
      continue;
    for (auto edge : g[u]) {
      tie(v, w) = edge;

      if (dT[v] > dT[u] + w) {
        dT[v] = dT[u] + w;
        pq.emplace(dT[v], v);
      }
    }
  }
}

void dijkstraO(int start, int n) {
  for (int u = 0; u < n; u++)
    dO[u] = oo;

  priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                 greater<pair<ll, int>>>
      pq;

  dO[start] = 0;
  pq.emplace(dO[start], start);

  ll dt, w;
  int u, v;
  while (!pq.empty()) {
    tie(dt, u) = pq.top();
    pq.pop();
    if (dt > dO[u])
      continue;
    for (auto edge : g[u]) {
      tie(v, w) = edge;

      if (dO[v] > dO[u] + w) {
        dO[v] = dO[u] + w;
        pq.emplace(dO[v], v);
      }
    }
  }
}

int main() {
  int n, m, s, t;
  char a1, a2;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back({b, 1});
    g[b].push_back({a, 1});
  }

  scanf("%d %d", &s, &t);

  dijkstraO(s, n);
  dijkstraT(t, n);

  for (int i = 0; i < n; i++) {
    d[i] = dO[i] + dT[i];
  }

  ll maxi = 0;
  for (int i = 0; i < N; i++) {
    maxi = max(maxi, d[i]);
  }

  if (maxi < oo) {
    cout << maxi << endl;
  } else {
    cout << -1 << endl;
  }
  // cout << maxi << endl;

  return 0;
}