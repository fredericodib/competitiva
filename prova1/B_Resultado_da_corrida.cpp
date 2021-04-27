// B. Resultado da corrida
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// O resultado de uma corrida de rua na Nlogonia gerou bastante controvérsia entre os atletas e a organização após o encerramento do evento. A principal reclamação é que o sistema de cronometragem apresentou problemas na aferição do tempo dos atletas, fazendo com que a posição final de cada um ficasse incorreta. Além disso, houveram registros de que alguns atletas cortaram o percurso, prejudicando o resultado dos atletas que completaram o percurso corretamente.

// A organização agora trabalha para efetuar as correções no resultado da corrida. Sabe-se que o momento da chegada de cada atleta foi registrado pelos árbitros localizados no pórtico de chegada. Tais árbitros numeraram os atletas de 1 a 𝑁 conforme a ordem que chegavam no pórtico. Com base nisso, os organizadores solicitaram o tempo de prova 𝑡𝑖 (em minutos) aferido pessoalmente por cada atleta 𝑖. A ideia é comparar a posição de chegada registrada pelos árbitros com o tempo o próprio atleta para identificar as irregularidades.

// Supondo que todos os atletas aferiram seus tempos, determine a menor posição possível em que cada atleta terminou a corrida após completar todo o percurso. Considere que, como alguns atletas querem tirar vantagem da situação, eles forneceram seu tempo incorretamente à organização.

// Input
// A primeira linha da entrada contém um número inteiro 1≤𝑁≤105 que indica a quantidade de atletas. A segunda linha descreve 𝑁 inteiros 𝑡1,𝑡2,...,𝑡𝑁 separados por um espaço em branco, em que cada 1≤𝑡𝑖≤107 representa o tempo aferido pelo 𝑖-ésimo atleta que cruzou a linha de chegada.

// Output
// Imprima 𝑁 números inteiros separados por espaço em branco indicando a menor posição possível que cada atleta terminou a corrida.

// Examples
// inputCopy
// 3
// 2 4 5
// outputCopy
// 1 2 3
// inputCopy
// 4
// 5 2 10 2
// outputCopy
// 3 1 4 1
// inputCopy
// 5
// 6 1 2 1 3
// outputCopy
// 5 1 3 1 4
// Note
// No primeiro exemplo de teste, o primeiro atleta que cruzou a linha de chegada completou a prova (segundo a aferição do próprio atleta) em 2 minutos. O segundo atleta completou a prova em 4 minutos e o terceiro atleta em 5 minutos. Por isso, a organização determina que o atleta 1 pode ter ficado em 1o, o atleta 2 chegou em 2o e o atleta 3 foi o terceiro colocado.

// No segundo exemplo de teste, o segundo 4 atletas cruzaram a linha chegada, sendo que os primeiro, segundo, terceiro e quarto atletas forneceram os tempos de 5, 2, 10 e 2 minutos, respectivamente. Repare que os atletas 1 e 3 forneceram o mesmo tempo de conclusão da prova, logo algum deles está querendo ganhar vantagem. O resultado final, conforme os cálculos da organização da prova, é que o atleta 1 cruzou a linha de chegada em 3o, o atleta 2 pode ter sido o primeiro colocado, o atleta 3 pode ter sido o quarto colocado e o atleta 4 pode ter sido o primeiro colocado.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n;
  cin >> n;
  vector<lli> v, v2;
  map<lli, lli> m;

  for (int i = 0; i < n; i++) {
    lli x;
    cin >> x;
    v.push_back(x);
    v2.push_back(x);
  }

  sort(v2.begin(), v2.end());

  for (int i = 0; i < n; i++) {
    if (!m.count(v2[i])) {
      m[v2[i]] = i;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << m[v[i]] + 1 << " ";
  }

  cout << endl;

  return 0;
}