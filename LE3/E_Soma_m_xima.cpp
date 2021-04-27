// E. Soma máxima
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Dado um vetor de tamanho 𝑛 de inteiros positivos e um limite 𝑝, determine o tamanho do maior intervalo tal que a soma dos elementos do intervalo seja menor ou igual a 𝑝.

// Input
// A primeira linha contém dois inteiros 𝑛 (1≤𝑛≤105) e 𝑝 (1≤𝑝≤1014) — o tamanho do vetor e o limite da soma , respectivamente.

// A segunda linha contém 𝑛 inteiros 𝑥𝑖 (1≤𝑥𝑖≤109) separados por espaço.

// Output
// Imprima o tamanho do maior intervalo cuja soma não ultrapassa 𝑝.

// Examples
// inputCopy
// 7 5
// 8 2 1 4 3 7 1
// outputCopy
// 2
// inputCopy
// 3 10
// 100 100 100
// outputCopy
// 0
// Note
// No primeiro exemplo o intervalo desejado é [2,3] (indexado em 1), cujo tamanho é 2.

// No segundo exemplo não há intervalo satisfazendo o problema.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define lli long long int
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  lli n, p, res = 0, strick = 0, sum = 0;
  queue<lli> q;
  cin >> n >> p;

  for (lli i = 0; i < n; i++) {
    lli x;
    cin >> x;
    q.push(x);
    sum += x;
    strick++;
    if (sum <= p) {
      res = max(strick, res);
    } else {
      while (sum > p) {
        x = q.front();
        sum -= x;
        q.pop();
        strick--;
      }
    }
  }

  cout << res << endl;

  return 0;
}