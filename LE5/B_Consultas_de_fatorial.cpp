// B. Consultas de fatorial
// time limit per test1.5 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você recebe q consultas. Cada consulta é acompanhada de um inteiro x, e sua resposta é x! MOD 1000000007.

// Input
// A primeira linha contém um inteiro q (1 ≤ q ≤ 105)- A quantidade de consultas Depois seguem q linhas, em cada linha, um inteiro x (0 ≤ x ≤ 106) - O número em questão.

// Output
// Imprima q linhas, a i-ésima linha deve ser a resposta para a iésima consulta.

// Example
// inputCopy
// 10
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 10
// 20
// outputCopy
// 1
// 1
// 2
// 6
// 24
// 120
// 720
// 5040
// 3628800
// 146326063

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

lli mod = 1000000007;
vector<lli> fat(1000001, 0);

void fatorial(lli N) {
  fat[0] = 1;
  fat[1] = 1;
  for (int i = 2; i <= N; i++) {
    fat[i] = (i * fat[i - 1]) % mod;
  }
}

int main() {
  int tests;
  cin >> tests;
  fatorial(1000001);

  while (tests-- > 0) {
    lli x;
    cin >> x;
    cout << fat[x] << endl;
  }

  return 0;
}