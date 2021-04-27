// E. Portais
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Uma cidade na Nlogonia foi planejada visando estabelecer as casas de seus habitantes de maneira linear, isto é, uma do lado da outra. Esse planejamento definiu que cada célula é enumerada por um inteiro de 1 a 𝑛 e é capaz de receber uma única residência. No entanto, tal disposição dificultou o deslocamento dos habitantes pelas células - eles não conseguem atravessar as células pelo fato de elas serem bem delimitadas.

// Para facilitar o deslocamento dos habitantes entre as células, um sistema de transporte baseado em portais foi concebido pela prefeitura da cidade. O engenheiro responsável pelo sistema pensou em 𝑛−1 inteiros 𝑎1,𝑎2,...,𝑎𝑛−1, em que cada inteiro 𝑖 (1≤𝑖≤𝑛−1) satisfaz a condição 1≤𝑎𝑖≤𝑛−𝑖. Em seguida, o engenheiro concebeu 𝑛−1 portais, cada um sendo enumerado por um inteiro de 1 a 𝑛−1. A ideia é que o 𝑖-ésimo portal (1≤𝑖≤𝑛−1) conduz uma pessoa que está na célula 𝑖 e para a célula (𝑖+𝑎𝑖).

// Mesmo a prefeitura alegando que os portais funcionem corretamente, a população local está bastante desconfiada. Elabore um programa que determine se é possível chegar a uma célula 𝑡 qualquer dessa cidade a partir na célula 1.

// Input
// A primeira linha contém dois números inteiros separados por espaço em branco 𝑛 (3≤𝑛≤3×104) e 𝑡 (2≤𝑡≤𝑛), representando a quantidade de células e o índice da célula de chegada.

// A segunda linha contém 𝑛−1 números inteiros separados por espaço em branco 𝑎1,𝑎2,...,𝑎𝑛−1 (1≤𝑎𝑖≤𝑛−𝑖). É garantido que, utilizando o sistema de transporte baseados em portais, não se pode sair da cidade.

// Output
// Imprima "sim" (sem as aspas duplas) se for possível chegar à célula 𝑡 a partir da célula 1 utilizando o sistema de transporte baseado em portais. Caso contrário imprima "nao" (também sem as aspas duplas).

// Examples
// inputCopy
// 8 4
// 1 2 1 2 1 2 1
// outputCopy
// sim
// inputCopy
// 8 5
// 1 2 1 2 1 1 1
// outputCopy
// nao
// inputCopy
// 5 3
// 1 1 2 1
// outputCopy
// sim
// Note
// No primeiro exemplo, as células visitas são, na ordem: 1, 2 e 4. Então podemos visitar a célula 4.

// No segundo exemplo, é possível visitar as células 1, 2, 4, 6, 7, e 8. Portanto, a célula 5 é inatingível.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  int n, t, current = 1;
  bool chegou = false;
  scanf("%d %d", &n, &t);

  for (int i = 0; i < n - 1; i++) {
    int a;
    scanf("%d", &a);

    if (i + 1 == current) {
      current += a;
      if (current == t) {
        chegou = true;
        break;
      }
    }
  }

  if (chegou) {
    cout << "sim" << endl;
  } else {
    cout << "nao" << endl;
  }

  return 0;
}