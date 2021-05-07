// B. Na cara do gol
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Neymar recebeu um passe e agora ele não tem para quem passar, então vai correr até o gol e chutar. O campo pode ser visto como uma matriz N × M, Neymar está na posição (1, 1) quando recebe o passe, e seu objetivo é chegar na posição (N, M) para realizar seu chute.

// Está chovendo muito e alguns pontos do campo estão alagados, e demora mais pra passar por lá, além disso, o menino Ney não pode passar por onde há marcação. A zaga está em choque em por conta disso não se move. Então Basta neymar não passar por onde ele estão que não perderá a bola.

// É sabido que neymar se movimenta somente para células adjacentes no campo. Se ele está na célula (I,J), ele pode se mover para a célula imediatamente a baixo ou a direita, isto é a célula (I+1,J) ou (I,J+1). Ele só pode se mover para uma célula caso ela esteja dentro do campo.

// Além disso nos lugares alagados, Neymar se movimenta de forma mais lenta, normalmente ele leva 1 segundo para transitar de uma célula do campo para outra, mas caso ele esteja numa célula alagada, ele demorará 5 segundos.

// Agora o técnico Tite está interessado em saber quanto tempo em segundos Neymar levará para chegar ao lugar do chute, já que o jogo está no fim! Ajude-o a resolver esse problema.

// Assuma que sempre é possível chegar ao lugar do chute.

// Input
// A primeira linha de entrada contém dois inteiros N e M (1 ≤ N, M ≤ 200).

// Depois seguem N linhas, cada uma com M caracteres, descrevendo as condições de cada célula do campo. Cada célula pode ser alagada, vazia, ou estar marcada, representadas por 'A', '.' e 'M' respectivamente.

// Output
// Imprima um único inteiro, o número mínimo de segundos que Neymar levará para chegar ao lugar do chute.

// Examples
// inputCopy
// 3 3
// AAA
// AAA
// AAA
// outputCopy
// 20
// inputCopy
// 3 3
// ...
// ...
// ...
// outputCopy
// 4
// inputCopy
// 5 4
// ....
// AAA.
// A...
// A.AA
// A...
// outputCopy
// 11
// inputCopy
// 1 1
// .
// outputCopy
// 0
// inputCopy
// 4 4
// ....
// AMM.
// AMMM
// AAAA
// outputCopy
// 26

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
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int idx = j + i * m;
      char c;
      ll w = 1;
      scanf("%c", &c);
      if (c == '\n') {
        scanf("%c", &c);
      }
      if (c == '.') {
        w = 1;
      } else if (c == 'A') {
        w = 5;
      } else {
        w = 10000;
      }

      if (j + 1 < m) {
        int dir = j + 1 + i * m;
        g[idx].push_back({dir, w});
      }

      if (i + 1 < n) {
        int down = j + (i + 1) * m;
        g[idx].push_back({down, w});
      }
    }
  }

  dijkstra(0, n * m - 1);

  printf("%lld\n", d[m * n - 1]);

  return 0;
}