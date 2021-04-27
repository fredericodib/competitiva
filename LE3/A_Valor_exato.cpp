// A. Valor exato
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Vivendo sua merecida aposentadoria no interior de Goiás, Seu Donato passa o tempo lendo livros sem pressa alguma, sendo capaz de ler exatamente um livro por semana.

// Seu Donato costuma comprar livros na livraria do Edson, que somente aceita pagamentos utilizando dinheiro em espécie. Por isso, antes de se dirigir à livraria, Seu Donato sempre passa na agência bancária para sacar dinheiro. "Para evitar a fadiga", Seu Donato vai à livraria do Edson a cada duas semanas e sempre compra dois livros, que serão lidos nessas duas semanas.

// Em cada ida à livraria, Seu Donato pretende gastar todo o dinheiro na compra dos dois livros, uma vez que ele detesta ficar carregando dinheiro por aí. Por isso, ele deve escolher dois livros, em que a soma dos seus preços é igual à quantia de dinheiro que ele carrega. Elabore um programa que encontre os livros em que seus preços somados são iguais à quantia de dinheiro que seu Donato possui.

// Input
// A primeira linha da entrada possui dois valores inteiros 2≤𝑁≤105 e 1≤𝑀≤106, indicando o número de livros na livraria do Edson e a quantia de dinheiro em espécie que seu Donato carrega, respectivamente. A segunda linha descreve 𝑁 números inteiros separados por um espaço em branco 𝑝1𝑝2...𝑝𝑁 representando o preço de cada livro, em que 0≤𝑝𝑖≤106.

// Output
// Imprima dois números inteiros 𝑥 e 𝑦 (𝑥≤𝑦), separados por um espaço em branco, indicando os preços dos livros cuja soma é igual a 𝑀, em que a diferença de preços 𝑥 e 𝑦 é a menor possível. Assuma que sempre é possível encontrar os números 𝑥 e 𝑦, isto é, que sempre existe, no mínimo, uma solução para o problema.

// Examples
// inputCopy
// 2 40
// 20 20
// outputCopy
// 20 20
// inputCopy
// 3 13
// 5 3 8
// outputCopy
// 5 8
// inputCopy
// 5 10
// 10 2 6 8 4
// outputCopy
// 4 6

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n, m;
  cin >> n >> m;
  vi vec;
  ii res = {-1, -1};

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  sort(vec.begin(), vec.end());

  for (int j = 0; j < n; j++) {
    int x = vec[j];
    int y = m - x;
    int l, r, mid;
    l = 0;
    r = n - 1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (vec[mid] == y && mid != j) {
        if (res.first == -1) {
          res = {min(x, y), max(x, y)};
        } else if (res.second - res.first > max(x, y) - min(x, y)) {
          res = {min(x, y), max(x, y)};
        }
        break;
      } else if (vec[mid] > y) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }

  cout << res.first << " " << res.second << endl;

  return 0;
}