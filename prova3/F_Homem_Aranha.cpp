// F. Homem Aranha
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Em 2018, Thanos concluiu seu plano de dizimar metade da vida no universo ao reunir todas as Jóias do Infinito e realizar o estalo (blip). Cinco anos depois, os Vingadores sobreviventes foram bem sucedidos ao reverter o estalo de Thanos e trazer à vida novamente todos aqueles que tinham virado pó.

// Estamos em 2023. O Homem Aranha é o responsável por manter a ordem em Nova York. Como se sabe, ele se locomove entre os prédios utilizando sua teia, de forma a visualizar do alto as áreas das ruas e calçadas. Sabe-se que o Homem Aranha consegue ir de um prédio para outro se a distância entre eles é no máximo 𝐷, em que 𝐷 é o alcance de sua teia.

// Suponha que existam 𝑁 prédios em Nova York. O Homem Aranha quer saber se ele consegue chegar em todos os 𝑁 prédios para combater o crime nas ruas de Nova York. Nesse sentido, ele precisa ser capaz de, partindo de qualquer um dos prédios, poder chegar a todos os outros prédios, possivelmente passando por outros prédios no caminho, sempre utilizando somente suas teias.

// Input
// A primeira linha da entrada contém dois inteiros, 𝑁 e 𝐷 (2≤𝑁≤1000,1≤𝐷≤5000), indicando respectivamente o número de prédios remanescentes e o alcance da teia do Homem Aranha.

// Cada uma das 𝑁 linhas seguintes contém dois inteiros 𝑥𝑖 e 𝑦𝑖 (1≤𝑥𝑖,𝑦𝑖≤5000), as coordenadas do i-ésimo prédio. Podem existir dois prédios com as mesmas coordenadas devido ao caos causado pelo blip.

// Output
// Seu programa deve escrever uma única linha, contendo um único caractere: "sim" (sem aspas duplas) se o Homem Aranha consegue passear utilizando suas teias entre todos os prédios de Manhatan restantes e "nao" (sem aspas duplas) caso contrário.

// Examples
// inputCopy
// 4 5
// 1 1
// 6 1
// 6 6
// 11 6
// outputCopy
// sim
// inputCopy
// 4 5
// 1 1
// 6 6
// 11 6
// 13 8
// outputCopy
// nao
// inputCopy
// 6 9
// 2 3
// 5 9
// 2 8
// 7 3
// 2 4
// 10 5
// outputCopy
// sim

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<bool> visited(1000000, false);

void dfs(int vertex, vector<vector<int>> &graph) {
  visited[vertex] = true;

  for (int w : graph[vertex]) {
    if (!visited[w]) {
      dfs(w, graph);
    }
  }
}

int main() {
  int n, d;
  scanf("%d %d", &n, &d);

  vector<vector<int>> g(n);
  vector<ii> m(n);

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    m[i] = {a, b};
  }

  for (int i = 0; i < n - 1; i++) {
    ii p1 = m[i];
    for (int j = i + 1; j < n; j++) {
      ii p2 = m[j];
      float dx = p1.first - p2.first;
      float dy = p1.second - p2.second;
      float dfinal = sqrt(dx * dx + dy * dy);

      if (dfinal <= d) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }

  dfs(0, g);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      printf("nao\n");
      return 0;
    }
  }

  printf("sim\n");
  return 0;
}