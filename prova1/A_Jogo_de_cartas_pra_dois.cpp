// A. Jogo de cartas pra dois
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Alice e Bob estão jogando um jogo de cartas, existem N em uma mesa, cada carta possui um valor escrito nela, a i-ésima carta possui o valor ai, Alice e Bob pegam cartas alternadamente, Alice pega no primeiro turno, vence o jogo quem tiver a maior soma de valores das cartas escolhidas.

// Considerando que Alice e Bob jogam otimamente, tentando conseguir a maior pontuação possível, imprima a diferença entre a pontuação de Alice e de Bob.

// Obs: Perceba que a resposta pode estourar um inteiro de 32 bits.

// Input
// A primeira linha da entrada contém um único inteiro N (1  ≤  N  ≤  100000), a quantidade de cartas no jogo.

// A segunda linha contém N inteiros separados por espaço, o i-ésimo inteiro, ai, representa o valor da i-ésima carta ( 1  ≤  ai  ≤  1000000000).

// Output
// Imprima um único inteiro, a diferença entre a pontuação de Alice e Bob.

// Examples
// inputCopy
// 2
// 3 1
// outputCopy
// 2
// inputCopy
// 3
// 2 7 4
// outputCopy
// 5
// inputCopy
// 4
// 20 18 2 18
// outputCopy
// 18
// Note
// No segundo exemplo, as cartas disponíveis inicialmente são:

// [2, 7, 4]

// Alice começa pegando a carta 7, pois quer maximizar seus pontos, deixando na mesa as cartas:

// [2, 4]

// Bob pega a carta 4, pois também quer maximizar seus pontos, deixando na mesa:

// [2]

// Por fim, Alice pega a carta de número 2, somando 9 pontos contra os 9 pontos de Bob, logo a diferença de pontos entre eles é 5.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli first = 0, second = 0;
  int n;
  cin >> n;
  vector<lli> v;

  for (int i = 0; i < n; i++) {
    lli x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  while (v.size() > 0) {
    lli x;
    x = v.back();
    first += x;
    v.pop_back();

    if (v.size() > 0) {
      x = v.back();
      second += x;
      v.pop_back();
    }
  }

  cout << max(first, second) - min(first, second) << endl;

  return 0;
}