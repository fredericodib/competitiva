// C. The wall
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Donald Mrump está fazendo uma muralha de madeira para conter a entrada de texicanos nos Ustados Enidos. Os Ustadenidenses tem um estoque de N tábuas de madeira, todas com a mesma largura, mas podendo ter alturas diferentes.

// A qualquer momento, qualquer uma dessas tábuas pode ser partida em dois, contanto que os pedaços tenham tamanho inteiro. Então por exemplo uma tábua de tamanho 15 pode ser dividida em duas de tamanho (7,8) ou três de tamanho (5,5,5) etc. Note que não é possível juntar duas tábuas, apenas separá-las.

// Para bloquear totalmente a passagem na fronteira, será necessário que a muralha seja feita de pelo menos k tábuas de largura. Ao final da construção, uma demanda de Mrump é que as tábuas usadas (não é necessário usar toda a madeira) tenham o mesmo tamanho.

// Mrump não gosta nada de texicanos, por isso, quer se sua muralha seja a mais alta possível.

// Ajude-o a descobrir o tamanho máximo que essa muralha pode ter, ou informe caso seja impossível construir tal muralha.

// Input
// A primeira linha de entrada contém dois inteiros n (1 <= n <= 105) e k (1 <= k <= 1014).

// A segunda linha contém N inteiros, as alturas de cada uma das tábuas. A altura de cada tábua é um inteiro x tal que 1 <= x <= 109.

// Output
// Imprima um inteiro, a resposta para o problema.

// Caso não seja possível construir a muralha, imprima 0.

// Examples
// inputCopy
// 3 4
// 15 10 8
// outputCopy
// 7
// inputCopy
// 3 5
// 1 1 1
// outputCopy
// 0
// inputCopy
// 3 1
// 10 10 10
// outputCopy
// 10
// inputCopy
// 3 4
// 100 5 10
// outputCopy
// 25
// Note
// No primeiro caso de teste, podemos fazer o seguinte com cada tábua:

// e assim temos 4 tábuas de tamanho 7, não é possível dividir de forma que tenhamos 8 tábuas inteiras de tamanho 8.

// No segundo caso de teste, não é possível dividirmos as tábuas para termos 5 tábas de tamanho 1, então não é possível fazer muralha alguma.

// No quarto caso de teste, podemos dividir a primeira tábua em 4 tábuas de tamanho 25, e não aproveitamos as últimas duas.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define lli long long int
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

bool test(lli mid, vector<lli> vec, lli k) {
  lli receive = 0;

  if (mid == 0) {
    return true;
  }

  for (int i = 0; i < vec.size(); i++) {
    receive += vec[i] / mid;
  }
  if (receive < k) {
    return false;
  }

  return true;
}

int main() {
  lli n, k, res = 0;
  cin >> n >> k;
  vector<lli> vec;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  sort(vec.begin(), vec.end());

  lli l = 0;
  lli r = vec.back();

  while (l <= r) {
    lli mid = (l + r) / 2;
    if (test(mid, vec, k)) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << res << endl;

  return 0;
}