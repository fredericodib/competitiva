// G. Fita cortada
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// André tem uma fita, seu comprimento é 𝑁. Ele quer cortar a fita de uma maneira que satisfaça as três condições a seguir:

// Após o corte, cada pedaço da fita deve ter comprimento 𝐴, 𝐵 ou 𝐶.
// Após o corte, o número de pedaços de fita deve ser máximo.
// Ajude Polycarpus e encontre o número de pedaços de fita após o corte necessário.

// Input
// A primeira linha contém quatro inteiros separados por espaço 𝑁, 𝐴, 𝐵 e 𝐶 (1≤N,A,B,C≤4000) - o comprimento da fita original e os comprimentos aceitáveis das peças da fita após o corte, respectivamente. Os números 𝐴, 𝐵 e 𝐶 podem coincidir.

// Output
// Imprima um único número - o número máximo possível de pedaços de fita. Se não tiver como partir a fita em pedaços somente de tamanho 𝐴, 𝐵 ou 𝐶, imprima 0.

// Examples
// inputCopy
// 5 5 3 2
// outputCopy
// 2
// inputCopy
// 7 5 5 2
// outputCopy
// 2
// inputCopy
// 11 5 3 7
// outputCopy
// 3
// inputCopy
// 10 4 7 8
// outputCopy
// 0

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int n, a, b, c;
vi tb(4005, -1);

int fita(int total) {
  if (total == 0) {
    return 1;
  }
  if (total < 0) {
    return 0;
  }
  if (tb[total] != -1) {
    return tb[total];
  }

  int v1 = fita(total - a);
  int v2 = fita(total - b);
  int v3 = fita(total - c);

  int r1 = max(v1, max(v2, v3));
  if (r1 != 0) {
    r1++;
  }
  tb[total] = r1;
  return tb[total];
}

int main() {
  cin >> n >> a >> b >> c;

  int res = fita(n);
  if (res != 0) {
    cout << res - 1 << endl;
  } else {
    cout << res << endl;
  }

  return 0;
}
