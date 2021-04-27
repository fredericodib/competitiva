// B. Erros de compilação
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A e B estão se preparando para torneios de programação.

// B adora debugar seu código. Mas antes que ele execute a solução e inicie o debug, ele precisa primeiro compilar o código.

// Inicialmente, o compilador exibiu 𝑁 erros de compilação, cada um deles é representado como um inteiro positivo. Depois de algum esforço, B conseguiu consertar algum erro e depois outro erro.

// No entanto, apesar do fato de B ter certeza de que ele corrigiu os dois erros, ele não consegue entender exatamente quais erros de compilação desapareceram - o compilador da linguagem que B usa mostra erros na nova ordem toda vez! B tem certeza de que, ao contrário de muitas outras linguagens de programação, os erros de compilação para sua linguagem de programação não dependem uns dos outros, ou seja, se você corrigir um erro, o conjunto dos outros erros não será alterado.

// Você pode ajudar B a descobrir exatamente quais dois erros ele corrigiu?

// Input
// A primeira linha da entrada contém o inteiro 𝑁 (3≤𝑁≤105) - o número inicial de erros de compilação.

// A segunda linha contém 𝑁 inteiros separados por espaços 𝑎1, 𝑎2, ..., 𝑎𝑛 (1≤𝑎𝑖≤109) - os erros que o compilador exibiu pela primeira vez.

// A terceira linha contém 𝑁−1 inteiros separados por espaços 𝑏1, 𝑏2, ..., 𝑏𝑛−1 - os erros exibidos na segunda compilação. É garantido que a sequência na terceira linha contém todos os números da segunda seqüência, exceto exatamente um.

// A quarta linha contém 𝑁−2 inteiros separados por espaço с1, с2, ..., с𝑛−2 - os erros exibidos na terceira compilação. É garantido que a sequência na quarta linha contém todos os números da terceira linha, exceto exatamente um.

// Output
// Imprima dois números: os números dos erros de compilação que desapareceram após B ter feito a primeira e a segunda correção, respectivamente.

// Examples
// inputCopy
// 5
// 1 5 8 123 7
// 123 7 5 1
// 5 1 7
// outputCopy
// 8
// 123
// inputCopy
// 6
// 1 4 3 3 5 7
// 3 7 5 4 3
// 4 3 7 5
// outputCopy
// 1
// 3

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n;
  cin >> n;
  map<ll int, int> mapa1;
  map<ll int, int> mapa2;
  map<ll int, int> mapa3;

  for (int i; i < n; i++) {
    ll int x;
    cin >> x;
    mapa1[x]++;
  }

  for (int i; i < n - 1; i++) {
    ll int x;
    cin >> x;
    mapa2[x]++;
  }

  for (auto x : mapa1) {
    if (mapa2.find(x.first) == mapa2.end() || mapa2[x.first] < x.second) {
      cout << x.first << endl;
      break;
    }
  }

  for (int i; i < n - 2; i++) {
    ll int x;
    cin >> x;
    mapa3[x]++;
  }

  for (auto x : mapa2) {
    if (mapa3.find(x.first) == mapa3.end() || mapa3[x.first] < x.second) {
      cout << x.first << endl;
    }
  }

  return 0;
}