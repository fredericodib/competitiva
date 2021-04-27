// D. Tainp
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Um dia o jovem Claudio estava brincando no tainp, haviam vários pixels pretos e brancos na sua tela, e ele decidiu colorir tudo de preto. Todos sabem que esses editores de imagem modernos tem a função 'preencher'. No editor Tainp, só há as cores preta e branco, quando Claudio manda preencher uma região branca de preto, todos os pixeis de uma região branca cercada por pixeis pretos será preenchida.

// A imagem que claudio está editando tem n linhas e m colunas de pixels.

// Claudio gostaria de saber quantos preenchimentos tem que fazer até que a tela fique preta.

// Input
// A primeira linha contém dois números n e m (1 ≤ n, m ≤ 500) - O número de linhas e colunas.

// Depois seguem n linhas, cada uma com m caracteres - A representação da imagem. Cada pixel preto é representado por '#' e cada pixel branco é representado por '.'.

// Output
// Imprima um único inteiro. O número de preenchimentos que Claudio deve fazer para que a tela fique completamente preta.

// Examples
// inputCopy
// 5 5
// ..#..
// ..#..
// #####
// ..#..
// ..#..
// outputCopy
// 4
// inputCopy
// 3 3
// ...
// .#.
// .#.
// outputCopy
// 1
// inputCopy
// 4 4
// ....
// ####
// #..#
// .##.
// outputCopy
// 4
// inputCopy
// 4 4
// ....
// .##.
// #.#.
// ....
// outputCopy
// 1
// inputCopy
// 4 4
// #.#.
// .#.#
// #.#.
// ....
// outputCopy
// 5

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

void colore(vector<vector<char>> &g, int i, int j, int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m) {
    return;
  }
  if (g[i][j] == '.') {
    g[i][j] = '#';
    colore(g, i + 1, j, n, m);
    colore(g, i - 1, j, n, m);
    colore(g, i, j + 1, n, m);
    colore(g, i, j - 1, n, m);
  }
}

int main() {
  int n, m, count = 0;
  bool finished = false;
  scanf("%d %d", &n, &m);

  vector<vector<char>> g(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char a;
      scanf("%c", &a);
      if (a == '\n') {
        scanf("%c", &a);
      }
      g[i].push_back(a);
    }
  }

  while (!finished) {
    finished = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '.') {
          finished = false;
          colore(g, i, j, n, m);
          count++;
        }
      }
    }
  }

  cout << count << endl;
  return 0;
}