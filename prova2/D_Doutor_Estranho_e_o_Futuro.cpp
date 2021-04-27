// D. Doutor Estranho e o Futuro
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Doutor Estranho está com os Vingadores no planeta Titan à espera do vilão Thanos. Como o titã é difícil de ser derrotado, Doutor Estranho utilizou a Jóia do Tempo para avançar no futuro e assim analisar todos os possíveis desfechos que a batalha poderia tomar, considerando cada ação que fosse tomada durante o confronto.

// Assim que terminou, o Doutor Estranho diz: "Das 𝑁! possibilidades que eu vi ao avançar no futuro, podemos vencer apenas em 𝑥 delas!". O Homem Aranha indaga o que seriam os valores 𝑁 e 𝑥, pois ele está preocupado com a notícia dada por Estranho. "Não sei dizer sobre 𝑁, mas pelas minhas contas, 𝑥 é o primeiro dígito (da direita para esquerda) de 𝑁! que seja diferente de zero".

// Agora, o Homem Aranha, com ajuda de Mantis, tentam adivinhar em quais situações poderão derrotar Thanos. Assim, a partir de um número inteiro 𝑁, sua tarefa é determinar 𝑥, conforme as orientações do Doutor Estranho.

// Input
// A entrada consiste de um único número inteiro 𝑁 (1≤𝑁≤106), indicando a quantidade total de cenários/possibilidades que o Doutor Estranho considerou no seu "avanço ao futuro".

// Output
// Imprima um número inteiro 𝑥 associado ao primeiro dígito (da direita para esquerda) de 𝑁! que seja diferente de zero".

// Examples
// inputCopy
// 3
// outputCopy
// 6
// inputCopy
// 5
// outputCopy
// 2
// inputCopy
// 8
// outputCopy
// 2

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli m, res = 1, count5 = 0, count2 = 0;

  scanf("%lld", &m);

  for (lli i = m; i > 0; i--) {
    lli x = i;
    while (x % 5 == 0) {
      x /= 5;
      count5++;
    }
    while (x % 2 == 0) {
      x /= 2;
      count2++;
    }
    res *= x;
    res %= 10;
  }

  lli m_min = min(count5, count2);
  count5 -= m_min;
  count2 -= m_min;

  for (lli i = 0; i < count5; i++) {
    res *= 5;
    res %= 10;
  }

  for (lli i = 0; i < count2; i++) {
    res *= 2;
    res %= 10;
  }

  cout << res << endl;

  return 0;
}