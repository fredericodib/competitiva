// D. Premium ou Popular?
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// O comitê diretor de uma empresa deseja reposicionar seu produto no mercado, o qual é vendido por 𝑃 reais, mas não há um consenso entre eles. Parte do comitê deseja vendê-lo como um produto premium, e a cada reunião tenta aprovar um aumento de 𝑋 reais no preço atual; outra parte tenta transformar o produto em um item popular, e a cada reunião tenta revogar os últimos 𝑌 aumentos aprovados.

// Dadas as atas das 𝑁 reuniões que aconteceram desde que se decidiu reposicionar o produto, determine o preço que o produto será vendido.

// Input
// A primeira linha da entrada contém os valores dos inteiros 𝑃 e 𝑁 (1≤𝑃≤106,1≤𝑁≤2×105), separados por um espaço em branco.

// As 𝑁 linhas contém, cada uma, o registro de uma ata, que pode ter uma das duas formas a seguir:

// 1 𝑋, que indica que a reunião aprovou um aumento de 𝑋 (1≤𝑋≤1000) reais no preço;
// 2 𝑌, que indica que a reunião revogou os últimos 𝑌 (1≤𝑌≤𝑇) aumentos aprovados, onde 𝑇 é o total de aumento aprovados antes desta reunião.
// Output
// Imprima, em uma linha, o valor de venda do produto, em reais, após as 𝑁 reuniões.

// Examples
// inputCopy
// 500 3
// 1 100
// 1 200
// 2 1
// outputCopy
// 600
// inputCopy
// 350 4
// 1 1000
// 1 200
// 1 500
// 2 3
// outputCopy
// 350
// inputCopy
// 100 2
// 1 50
// 1 30
// outputCopy
// 180
// Note
// No primeiro caso, o produto é vendido inicialmente por 500 reais. Após a primeira reunião, o aumento aprovado eleva o preço para 600 reais; a segunda reunião aumenta o preço novamente para 800 reais; por fim, a última reunião revoga o aumento mais de recente (de 200 reais), de modo que o preço final é de 600 reais.

// No segundo caso, a última reunião revoga todos os 3 aumentos anteriores, e o produto retorna ao seu valor original de 350.

// No terceiro caso, todas as reuniões decidem por aumentos de preço, de modo que o preço final do produto é de 100 + 50 + 30 = 180 reais.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli p, n;
  cin >> p >> n;
  vector<lli> v;

  v.push_back(p);
  for (int i = 0; i < n; i++) {
    lli x, y;
    cin >> x >> y;
    if (x == 1) {
      v.push_back(v.back() + y);
    } else {
      for (int j = 0; j < y; j++) {
        v.pop_back();
      }
    }
  }

  cout << v.back() << endl;

  return 0;
}