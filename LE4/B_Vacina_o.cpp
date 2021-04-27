// B. Vacinação
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A Nlogônia está passando por sérios problemas com a pandemia de Covid-19 como ocorre em diversas nações do mundo. Enquanto os pesquisadores locais correm contra o tempo para desenvolver uma vacina contra o Sars-Cov-2, o Ministério da Saúde planeja realizar uma grande campanha de vacinação contra os vírus da gripe para imunizar a população. O respeitado órgão da saúde dividiu a Nlogônia conforme os 𝑁 setores censitários existentes, numerados de 1 a 𝑁, que possuem registros da quantidade de pessoas que foram acometidas pela gripe e que nunca foram vacinadas.

// O Ministério da Saúde decide realizar 𝑀 operações de vacinação durante um determinado período de tempo, respeitando os critérios logísticos da Nlogônia e a disponibilidade de vacinas na sede. Nesse sentido, uma operação de vacinação 𝑗 consiste em transportar 𝑎𝑗 vacinas para cada um dos setores censitários, cujos identificadores estão compreendidos no intervalo [𝑙𝑗,𝑟𝑗]. Vale ressaltar que, em cada operação, a equipe responsável vacina cada habitante uma única vez e que as vacinas nunca são reaproveitadas em outros setores.

// Como é difícil registrar os dados de todas as 𝑀 operações, você foi contratado para auxiliar os especialistas na árdua tarefa de investigar possíveis falhas operacionais nos setores com pessoas não vacinadas. Seu papel é determinar, para os setores que ainda têm habitantes gripados, a quantidade de operações que foram realizadas.

// Input
// A primeira linha da entrada contém dois números inteiros 𝑁 e 𝑀 (2≤𝑁≤105,2≤𝑀≤105), separados por um espaço em branco, que indicam a quantidade de setores censitários da Nlogônia e a quantidade de operações de vacinação realizadas no período.

// A segunda linha apresenta 𝑁 números inteiros 𝑝𝑖 (0≤𝑝𝑖≤104), separados por espaço em branco, os quais representam a quantidade de pessoas gripadas no 𝑖-ésimo setor censitário da Nlogônia.

// As próximas 𝑀 linhas descrevem cada uma das operações de vacinação realizadas na Nlogônia. Cada linha é definida por três números inteiros 𝑙𝑗,𝑟𝑗,𝑎𝑗 (1≤𝑙𝑗<𝑟𝑗≤𝑁 e 1≤𝑎𝑗≤103) separados por espaço em branco, indicando os identificadores dos setores censitários limítrofes que receberão, cada um, 𝑎𝑗 vacinas.

// Output
// Imprima um número inteiro indicando a quantidade total de operações que foram realizadas nos setores onde restaram habitantes ainda não vacinados.

// Examples
// inputCopy
// 4 2
// 2 5 1 3
// 1 3 2
// 2 3 1
// outputCopy
// 2
// inputCopy
// 5 3
// 3 0 1 4 2
// 1 2 3
// 3 4 1
// 2 4 1
// outputCopy
// 2
// inputCopy
// 6 5
// 0 10 12 6 7 4
// 2 6 2
// 4 5 1
// 2 4 3
// 1 2 1
// 1 3 4
// outputCopy
// 6
// Note
// No primeiro caso de teste, os setores censitários possuem, respectivamente, 2, 5, 1 e 3 pessoas não vacinadas.

// A primeira operação leva 2 vacinas para cada um dos setores 1, 2 e 3, resultando na distribuição de [0,3,0,3] pessoas não vacinadas.
// A segunda operação leva 1 vacina para cada um dos setores 2 e 3, obtendo-se [0,2,0,3] sem vacinação.
// Ao total, foram realizadas 1 operação no setor 1, 2 operações nos setores 2 e 3, e nenhuma operação no setor 4. Considerando apenas os setores com habitantes que ainda não foram vacinados, tem-se um total de 2 operações realizadas.

// No segundo caso de teste, os setores possuem a seguinte configuração de pessoas não-vacinadas: [3,0,1,4,2].

// A primeira operação leva 3 vacinas para cada um dos setores 1 e 2, resultando em [0,0,1,4,2].
// A segunda operação leva 1 vacina para cada um dos setores 3 e 4, levando a [0,0,0,3,2].
// A última operação leva 1 vacina para cada um dos setores 2, 3 e 4, de modo que a situação final é [0,0,0,2,2].
// Os setores que ainda apresentam habitantes sem vacinação são os setores 4 e 5, onde foram realizadas 2 operações de vacinação.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n, m, count = 0;
  vector<lli> v;

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  vector<lli> d(n, v[0]);
  vector<lli> d2(n, 0);
  for (int i = 1; i < n; i++) {
    d[i] = v[i] - v[i - 1];
  }

  for (int i = 0; i < m; i++) {
    lli l, r, x;
    cin >> l >> r >> x;
    d[l - 1] -= x;
    d2[l - 1] += 1;
    if (r < n) {
      d[r] += x;
      d2[r] -= 1;
    }
  }

  for (int i = 1; i < n; i++) {
    d[i] = d[i] + d[i - 1];
    d2[i] = d2[i] + d2[i - 1];
  }

  for (int i = 0; i < n; i++) {
    if (d[i] > 0) {
      count += d2[i];
    }
  }

  cout << count << endl;

  return 0;
}