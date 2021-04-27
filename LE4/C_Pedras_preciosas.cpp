// C. Pedras preciosas
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Dona Zulmira estava passeando pela Chapada dos Veadeiros e em um dia caminhando por uma trilha, encontrou 𝑛 pedras preciosas. Cada pedra é enumerada por um número inteiro de 1 até 𝑛. Após realizar diversas pesquisas, ela estimou o custo de cada pedra, sendo que 𝑣𝑖 denota o custo da 𝑖-ésima pedra. Dona Zulmira quer conhecer mais sobre as pedras que ela encontrou e te faz 𝑀 perguntas que podem ser de dois tipos:

// Ela vai te dizer dois números 𝑙 e 𝑟 (1≤𝑙≤𝑟≤𝑛) e você deve responder o resultado de ∑𝑟𝑖=𝑙𝑣𝑖.
// Seja 𝑢𝑖 o custo da 𝑖-ésima pedra mais barata (𝑢𝑖 é o custo da pedra que está na 𝑖-ésima posição se ordenamos as pedras de maneira crescente em relação ao custo). Dona Zulmira te informa dois números 𝑙 e 𝑟 (1≤𝑙≤𝑟≤𝑛) e você deve responder ∑𝑟𝑖=𝑙𝑢𝑖.
// Sua tarefa é determinar a resposta correta para cada questionamento feito pela Dona Zulmira. Tenha cuidado pois as respostas podem exceder 32 bits.

// Input
// A primeira linha da entrada contém dois números inteiros 𝑁 e 𝑀 (1≤𝑁≤105,1≤𝑀≤105), separados por um espaço em branco, que indicam a quantidade de pedras preciosas e a quantidade de perguntas feitas por Dona Zulmira.

// A segunda linha apresenta 𝑁 números inteiros 𝑣𝑖 (1≤𝑣𝑖≤109) associados aos custos de cada pedra preciosa.

// As próximas 𝑀 linhas descrevem cada pergunta feita por Dona Zulmira. Cada linha (pergunta) contém três inteiros 𝑡, 𝑙 e 𝑟 (1≤𝑙≤𝑟≤𝑛;1≤𝑡≤2). Se 𝑡=1, você deve computar e imprimir a resposta para a questão de tipo 1, caso contrário, você deve produzir a resposta para a questão de tipo 2.

// Output
// Imprima 𝑚 linhas, cada uma contendo um número inteiro associado à resposta para a pergunta de Dona Zulmira. Imprima as respostas para as questões conforme a ordem da entrada.

// Examples
// inputCopy
// 6 3
// 6 4 2 7 2 7
// 2 3 6
// 1 3 4
// 1 1 6
// outputCopy
// 24
// 9
// 28
// inputCopy
// 10 4
// 3 2 3 4 2 50 10 7 21 12
// 1 3 6
// 2 4 9
// 2 2 5
// 1 1 9
// outputCopy
// 59
// 57
// 12
// 102
// inputCopy
// 4 10
// 5 5 2 3
// 1 2 4
// 2 1 4
// 1 1 1
// 2 1 4
// 2 1 2
// 1 1 1
// 1 3 3
// 1 1 3
// 1 4 4
// 1 2 2
// outputCopy
// 10
// 15
// 5
// 15
// 5
// 5
// 2
// 12
// 3
// 5

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n, m;
  vector<lli> v, sumv, v2, sumv2;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
    v2.push_back(x);
  }

  sort(v2.begin(), v2.end());

  sumv.push_back(v[0]);
  sumv2.push_back(v2[0]);
  for (int i = 1; i < n; i++) {
    sumv.push_back(v[i] + sumv[i - 1]);
    sumv2.push_back(v2[i] + sumv2[i - 1]);
  }

  for (int i = 0; i < m; i++) {
    lli t, l, r;
    cin >> t >> l >> r;

    if (t == 1) {
      cout << sumv[r - 1] - sumv[l - 1] + v[l - 1] << endl;
    } else {
      cout << sumv2[r - 1] - sumv2[l - 1] + v2[l - 1] << endl;
    }
  }

  return 0;
}