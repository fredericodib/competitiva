// C. Encontrando com Deivis
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A cidade de Brasúlia é composta por várias esquinas e ruas. As ruas conectam as esquinas e para andar em cada rua há um custo associado.

// Deivis e André estão em Brasúlia após anos sem se verem! Ambos estão em uma esquina da cidade (possivalmente a mesma) e combinaram de se encontrar na esquina mais adequada. A esquina mais adequada é aonde o custo conjunto de Deivis e André para alcançá-la é mínimo. O problema é que André só anda de Ober, enquanto que Deivis só anda de Táxi e, os custos para andar de Ober e Táxi pelas ruas geralmente são diferentes.

// Input
// A primeira linha da entrada contém um inteiro 𝑁 (1≤𝑁≤1300), que indica quantas ruas existem em Brasúlia. As próximas 𝑁 linhas contêm a descrição de cada rua. A descrição de cada rua consiste em quatro letras maiúsculss e um inteiro. A primeiro letra é 'O' (indica que a descrição da rua é para quem anda de Ober) ou 'T' (indica que a descrição da rua é para quem anda de Táxi), o segundo caractere é 'U' (indica que a rua é unidirecional) ou 'B' (indica que a rua é bidirecional). O terceiro e quarto caracteres, 'X' e 'Y', podem ser qualquer letras maiúsculas e indicam que as esquinas com o nome 'X' e 'Y' da cidade estão conectadas (no caso de unidirecional significa que há uma rua de sentido único de 'X' a 'Y') e o último inteiro não negativo 𝐶 (0≤𝐶≤500) indica o custo necessário para atravessar a rua (de Ober ou de Táxi dependendo da primeira letra). A última linha de cada entrada contém duas letras indicando duas esquinas, que são as esquinas iniciais de André e Deivis, respectivamente.

// Output
// Imprima uma linha indicando o custo mínimo conjunto e, na linha seguinte, qual a esquina mais adequada para André e Deivis se encontrarem. Se existe mais de uma esquina ideal para eles se encontrarem, printe todas as esquinas, em ordem lexicográfica e separadas por espaço. Se, infelizmente, não tem como André e Deivis se encontrarem, apenas printe -1.

// Examples
// inputCopy
// 4
// O U A B 4
// O U C A 1
// T U D B 6
// T B C D 2
// A D
// outputCopy
// 10
// B
// inputCopy
// 2
// O U A B 10
// T U C D 20
// A D
// outputCopy
// -1

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

const int N = 40;
const ll oo = 1e18;

ll dT[N];
ll dO[N];
vector<ll> d(N, -1);

map<char, int> m;
map<int, char> m2;
int idx = 0;

vector<pair<int, ll>> gT[N];
vector<pair<int, ll>> gO[N];

int charIndex(char a) {
  if (m.count(a)) {
    return m[a];
  }
  m[a] = idx;
  m2[idx] = a;
  idx++;
  return m[a];
}

void dijkstraT(int start, int n) {
  for (int u = 0; u < 40; u++)
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
    for (auto edge : gT[u]) {
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
    for (auto edge : gO[u]) {
      tie(v, w) = edge;

      if (dO[v] > dO[u] + w) {
        dO[v] = dO[u] + w;
        pq.emplace(dO[v], v);
      }
    }
  }
}

int main() {
  int n;
  char a1, a2;
  scanf("%d", &n);
  getchar();

  for (int i = 0; i < n; i++) {
    char x1, x2, x3, x4;
    ll x5;
    scanf("%c", &x1);
    getchar();
    scanf("%c", &x2);
    getchar();
    scanf("%c", &x3);
    getchar();
    scanf("%c", &x4);
    getchar();
    scanf("%lld", &x5);
    getchar();

    if (x1 == 'O') {
      gO[charIndex(x3)].push_back({charIndex(x4), x5});
      if (x2 == 'B') {
        gO[charIndex(x4)].push_back({charIndex(x3), x5});
      }
    } else {
      gT[charIndex(x3)].push_back({charIndex(x4), x5});
      if (x2 == 'B') {
        gT[charIndex(x4)].push_back({charIndex(x3), x5});
      }
    }
  }

  scanf("%c", &a1);
  getchar();
  scanf("%c", &a2);

  dijkstraO(charIndex(a1), 40);
  dijkstraT(charIndex(a2), 40);

  for (int i = 0; i < 40; i++) {
    if (dO[i] < oo && dT[i] < oo) {
      d[i] = dO[i] + dT[i];
    }
  }

  ll mini = oo;
  for (int i = 0; i < 40; i++) {
    if (d[i] != -1) {
      mini = min(mini, d[i]);
    }
  }

  if (mini == oo) {
    cout << -1 << endl;
  } else {
    cout << mini << endl;
    vector<char> c_vec;
    for (int i = 0; i < 40; i++) {
      if (d[i] == mini) {
        c_vec.push_back(m2[i]);
      }
    }
    sort(c_vec.begin(), c_vec.end());
    for (int i = 0; i < c_vec.size(); i++) {
      cout << c_vec[i] << " ";
    }
  }

  return 0;
}