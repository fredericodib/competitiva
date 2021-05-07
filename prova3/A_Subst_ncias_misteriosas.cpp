// A. Substâncias misteriosas
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Nos últimos meses, a Dra. Valdira têm trabalhado na produção de duas substâncias misteriosas que são capazes que provocar a fusão ou a clonagem de organismos vivos. A substância 𝑋 foi a primeira a ser estudada pela pesquisadora, tendo a capacidade de clonar um organismo vivo. A substância 𝑌 ainda está sendo elaborada, mas a princípio, a ideia é que tal substância realize a fusão entre dois organismos similares.

// A Dra. Valdira solicitou a aquisição de planárias para iniciar os primeiros experimentos e, caso tais experimentos sejam bem sucedidos, ela deseja realizar experimentos em outros tipos de seres vivos. Nos experimentos preliminares em uma população inicial de 𝑁 planárias, ela verificou que a substância 𝑋 clonava perfeitamente uma população de planárias, ou seja, dobrando sua população. Já a substância 𝑌 apresentou-se menos efetiva, sendo que ao ser aplicada na população de planárias, apenas dois organismos similares realizavam a fusão, enquanto que o restante da população se manteve intacto.

// Agora a Dra. Valdira está interessada em ampliar a produção de substâncias e para isso, ela precisa quantificar todas as aplicações em outras populações de planárias, como também obter mais planárias para realizar experimentos adicionais. Ajude ela nesta tarefa e elabore um programa que, a partir de uma população inicial de 𝑁 planárias, determine a quantidade mínima de aplicações de substâncias 𝑋 e 𝑌 para se obter uma população de 𝑀 organismos vivos.

// Input
// A entrada consiste de dois valores inteiros 1≤𝑁≤105 e 1≤𝑀≤105 que consistem, respectivamente, na quantidade inicial e na quantidade esperada de planárias na população da Dra. Valdira.

// Output
// Imprima a quantidade mínima de aplicações das substâncias 𝑋 e 𝑌 que a Dra. Valdira deverá executar na amostra inicial de 𝑁 planárias para obter 𝑀 planárias.

// Examples
// inputCopy
// 10 8
// outputCopy
// 2
// inputCopy
// 20 7
// outputCopy
// 13
// inputCopy
// 1 4
// outputCopy
// 2
// Note
// No primeiro caso de teste, a Dra. Valdira aplica a substância 𝑌 duas vezes para obter 8 planárias, a partir de uma população inicial de 10 planárias.

// No terceiro caso de teste, a Dra. Valdira aplica a substância 𝑋 duas vezes para obter 4 planárias, a partir de uma população inicial de 1 planária.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  int n, m, res = 0;
  scanf("%d %d", &n, &m);

  // while (n != m) {
  //   if (n < m) {
  //     n *= 2;
  //     res++;
  //   } else {
  //     int temp;
  //     temp = n - m;
  //     res += temp;
  //     n = m;
  //   }
  // }

  while (n != m) {
    if (n < m) {
      if (m % 2 == 0) {
        m /= 2;
        res++;
      } else {
        m += 1;
        res++;
      }
    } else {
      int temp;
      temp = n - m;
      res += temp;
      n = m;
    }
  }

  cout << res << endl;
  return 0;
}