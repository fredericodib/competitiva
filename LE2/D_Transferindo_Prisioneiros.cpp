// D. Transferindo Prisioneiros
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A prisão da sua cidade tem 𝑁 prisioneiros. Como a prisão não pode acomodar todos eles, o prefeito da cidade decidiu transferir 𝐶 dos prisioneiros para uma prisão localizada em outra cidade.

// Por essa razão, ele fez os 𝑁 prisioneiros ficarem em fila, com um número escrito em seus peitos. O número é a gravidade do crime que cada um cometeu. Quanto maior o número, maior a gravidade do crime.

// Então, o prefeito lhe disse para escolher os prisioneiros, que serão transferidos para a outra prisão. Ele também impôs duas condições:

// - Os prisioneiros escolhidos devem formar um segmento contíguo de prisioneiros. - Qualquer nível de crime do prisioneiro escolhido não deve ser maior que 𝑇. Porque isso tornará o prisioneiro um criminoso severo e o prefeito não quer correr o risco do criminoso fugir durante a transferência.

// Encontre o número de maneiras de escolher os prisioneiros.

// Input
// A primeira linha de entrada conterá três inteiros separados por espaço 𝑁 (1≤𝑁≤2∗105), 𝑇 (0≤𝑇≤109) e 𝐶 (1≤𝐶≤𝑁). A próxima linha conterá 𝑁 inteiros separados por espaços, o i-ésimo inteiro é a gravidade do crime do i-ésimo prisioneiro. O valor das severidades do crime será não negativo e não excederá 109.

// Output
// Imprima um único inteiro - o número de maneiras de escolher os 𝐶 prisioneiros.

// Examples
// inputCopy
// 4 3 3
// 2 3 1 1
// outputCopy
// 2
// inputCopy
// 1 1 1
// 2
// outputCopy
// 0
// inputCopy
// 11 4 2
// 2 2 0 7 3 2 2 4 9 1 4
// outputCopy
// 6

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  ll int n, t, c, res = 0, strick = 0;
  cin >> n >> t >> c;
  vector<ll int> v;

  for (ll int i = 0; i < n; i++) {
    ll int x;
    cin >> x;
    v.push_back(x);
  }

  for (ll int i = 0; i < n; i++) {
    strick++;
    if (v[i] > t) {
      strick = 0;
    } else if (strick >= c) {
      res++;
    }
  }

  cout << res << endl;
  return 0;
}