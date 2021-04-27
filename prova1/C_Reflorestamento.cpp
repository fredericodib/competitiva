// C. Reflorestamento
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Nos últimos anos, diversas queimadas e desmatamentos, provocados pela ação humana, assolaram a Nlogonia. Tais adversidades motivaram o governo a planejar uma estratégia para reflorestar essas áreas. Para esse propósito, o governo formou uma equipe de profissionais que podem contar com o apoio e infraestrutura do Jardim Botânico da Nlogonia.

// A equipe responsável pelo reflorestamento dividiu a Nlogonia em 𝑁 regiões, enumeradas de 1 até 𝑁, e resolve plantar mudas de árvores, que são produzidas em larga escala no Jardim Botânico. Apesar de existirem mudas de 𝑀 espécies distintas, a equipe de biológos prefere que sejam plantadas as espécies de árvores nativas da Nlogonia, que são as espécies numeradas de 1 a 5 no catálogo do Jardim Botânico.

// Antes de iniciar o reflorestamento, a equipe faz um levantamento da quantidade de árvores 𝑎𝑖 que cobrem a vegetação natural de cada região 𝑖=1,...,𝑁 da Nlogonia. Devido aos recursos de transportes e de pessoal do Jardim Botânico serem limitados, a equipe planejou realizar 𝑄 operações, em que cada operação 𝑞𝑖 consiste em plantar 𝑥𝑖 mudas de árvores da espécie 𝑚𝑖 em cada uma das 𝑁 regiões que estão no intervalo [𝑙𝑖,𝑟𝑖]. Como se trata de um plano urgente para a recuperação da vegetação da Nlogonia, a equipe decide plantar mudas de árvores de todas as espécies disponíveis no Jardim Botânico, mesmo sabendo que seria apropriado plantar apenas as mudas de árvores nativas.

// Após efetuar as operações de reflorestamento, o governo avalia se a estratégia adotada pela equipe foi bem sucedida, isto é, se a maioria das árvores plantadas nas regiões da Nlogonia são de espécies nativas. Portanto, considerando todas as operações realizadas no reflorestamento, determine a quantidade de árvores nativas que foram plantadas em cada uma das 𝑁 regiões da Nlogonia.

// Input
// A primeira linha da entrada consiste em três inteiros 2≤𝑁≤105, 5≤𝑀≤25 e 1≤𝑄≤105, que representam a quantidade de regiões da Nlogonia, a quantidade de espécies de mudas existentes no Jardim Botânico e a quantidade total de operações de plantio de mudas nessas regiões, respectivamente.

// A segunda linha descreve 𝑁 números inteiros separados por espaço em branco 𝑎1,𝑎2,...𝑎𝑁, em que 0≤𝑎𝑖≤102 indica a quantidade de árvores contabilizadas na região 𝑖 da Nlogonia.

// Em seguida são definidas 𝑄 linhas, em que cada linha 𝑖 descreve uma operação 𝑞𝑖, definida por quatro inteiros 1≤𝑙𝑖≤𝑁−1, 𝑙𝑖<𝑟𝑖≤𝑁, 1≤𝑥𝑖≤103 e 1≤𝑚𝑖≤𝑀 separados por um espaço branco, associados às regiões de início e de fim do plantio de mudas, a quantidade de mudas e a espécie das árvores a serem plantadas, respectivamente.

// Output
// Imprima 𝑁 números inteiros separados por espaço em branco indicando a quantidade total de árvores nativas que cada uma das 𝑁 regiões da Nlogonia apresenta após o reflorestamento.

// Examples
// inputCopy
// 5 6 4
// 3 10 7 8 4
// 1 3 2 1
// 2 4 5 2
// 1 2 4 3
// 3 5 1 2
// outputCopy
// 9 21 15 14 5
// inputCopy
// 4 6 3
// 2 0 0 7
// 1 4 8 1
// 1 2 2 1
// 3 4 3 2
// outputCopy
// 12 10 11 18
// inputCopy
// 6 7 5
// 0 3 10 5 1 2
// 4 6 9 6
// 1 3 7 7
// 2 3 1 2
// 1 4 2 1
// 1 6 1 3
// outputCopy
// 3 7 14 8 2 3

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n, m, q;
  cin >> n >> m >> q;
  vector<lli> v;

  for (int i = 0; i < n; i++) {
    lli x;
    cin >> x;
    v.push_back(x);
  }

  vector<lli> d(v.size(), v[0]);
  for (int i = 1; i < v.size(); i++) {
    d[i] = v[i] - v[i - 1];
  }

  for (int i = 0; i < q; i++) {
    lli l, r, x, m1;
    cin >> l >> r >> x >> m1;

    if (m1 <= 5) {
      d[l - 1] += x;
      if (r < d.size())
        d[r] -= x;
    }
  }

  cout << d[0] << " ";
  for (int i = 1; i < v.size(); i++) {
    d[i] = d[i] + d[i - 1];
    cout << d[i] << " ";
  }

  cout << endl;

  return 0;
}