// D. Canibais
// time limit per test1.0 s
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// A trilha Nunca-Mais é bastante popular na cidade de Estranhópolis, possuindo diversos atrativos em seu percurso, como cavernas, cachoeiras, riachos etc. Um grupo de canibais que peregrinam entre cidades percebeu o trânsito de pessoas na trilha e resolveu se aproveitar da situação.

// Um andarilho solitário seria um lanche fácil para os famintos antropófagos, mas fornece poucos nutrientes para o grupo todo. Uma excursão seria um banquete, mas o esforço para lidar com muitas pessoas pode ser demais para os antropófagos debilitados pela fome. Além disso, eles sabem que, ao capturarem e devorarem andarilhos, a cidade ficará em alerta e as pessoas deixarão de percorrer a trilha Nunca-Mais, forçando-os a retomar a peregrinação. Por questões de sobrevivência, a ideia dos canibais é simplesmente obter o máximo de energia, capturando as pessoas que oferecem menos resistência, para então preparar o melhor banquete possível antes de migrarem para outra localidade.

// Sabendo que, em um determinado período de tempo, 𝑁 pessoas percorrem a trilha Nunca-Mais, calcule a quantidade máxima de energia que os canibais conseguirão obter ao capturar os andarilhos, considerando que este processo não pode exceder o custo máximo 𝑀 aos canibais.

// Input
// A primeira linha é dada por pelos inteiros 𝑁 (1≤𝑁≤104), indicando a quantidade de pessoas que foram aventurar na trilha Nunca-Mais durante o referido período, e 𝑀 (1≤𝑀≤104), indicando o custo máximo que os canibais pretendem gastar no processo de captura de pessoas, separados por um espaço em branco.

// A segunda linha contém 𝑁 inteiros 𝑒1, 𝑒2, ... , 𝑒𝑁, separados por um espaço em branco, descrevendo a energia que cada pessoa forneceria se for devorada pelos canibais, onde 1≤𝑒𝑖≤104.

// A terceira linha também contém 𝑁 inteiros 𝑐1, 𝑐2, ..., 𝑐𝑁, separados por um espaço em branco, representando o custo de capturar cada pessoa, com 1≤𝑐𝑖≤104.

// Output
// Imprima um único inteiro indicando a quantidade máxima de energia que os canibais podem obter após devorar as pessoas que eles conseguem capturar.

// Examples
// inputCopy
// 4 4
// 2 3 4 6
// 3 1 8 4
// outputCopy
// 6
// inputCopy
// 5 9
// 5 1 5 2 4
// 2 6 4 3 3
// outputCopy
// 14
// Note
// No primeiro caso de teste, os canibais obtém a energia máxima ao capturar e devorar a pessoa 4, pois o custo para capturá-la não excede o custo que os canibais podem demandar nessa tarefa. É importante notar que os canibais também tem condições de capturar as pessoas 1 e 2, mas ao serem devoradas juntas pelos canibais, não oferecerão mais energia do que a pessoa 4.

// No segundo caso de teste, os canibais conseguem obter a energia máxima ao devorar as pessoas 1, 3 e 5, pois juntas oferecem a quantidade de energia que respeita o custo máximo dos canibais no processo de captura.D. Canibais
// time limit per test1.0 s
// memory limit per test512 megabytes
// inputstandard input
// outputstandard output
// A trilha Nunca-Mais é bastante popular na cidade de Estranhópolis, possuindo diversos atrativos em seu percurso, como cavernas, cachoeiras, riachos etc. Um grupo de canibais que peregrinam entre cidades percebeu o trânsito de pessoas na trilha e resolveu se aproveitar da situação.

// Um andarilho solitário seria um lanche fácil para os famintos antropófagos, mas fornece poucos nutrientes para o grupo todo. Uma excursão seria um banquete, mas o esforço para lidar com muitas pessoas pode ser demais para os antropófagos debilitados pela fome. Além disso, eles sabem que, ao capturarem e devorarem andarilhos, a cidade ficará em alerta e as pessoas deixarão de percorrer a trilha Nunca-Mais, forçando-os a retomar a peregrinação. Por questões de sobrevivência, a ideia dos canibais é simplesmente obter o máximo de energia, capturando as pessoas que oferecem menos resistência, para então preparar o melhor banquete possível antes de migrarem para outra localidade.

// Sabendo que, em um determinado período de tempo, 𝑁 pessoas percorrem a trilha Nunca-Mais, calcule a quantidade máxima de energia que os canibais conseguirão obter ao capturar os andarilhos, considerando que este processo não pode exceder o custo máximo 𝑀 aos canibais.

// Input
// A primeira linha é dada por pelos inteiros 𝑁 (1≤𝑁≤104), indicando a quantidade de pessoas que foram aventurar na trilha Nunca-Mais durante o referido período, e 𝑀 (1≤𝑀≤104), indicando o custo máximo que os canibais pretendem gastar no processo de captura de pessoas, separados por um espaço em branco.

// A segunda linha contém 𝑁 inteiros 𝑒1, 𝑒2, ... , 𝑒𝑁, separados por um espaço em branco, descrevendo a energia que cada pessoa forneceria se for devorada pelos canibais, onde 1≤𝑒𝑖≤104.

// A terceira linha também contém 𝑁 inteiros 𝑐1, 𝑐2, ..., 𝑐𝑁, separados por um espaço em branco, representando o custo de capturar cada pessoa, com 1≤𝑐𝑖≤104.

// Output
// Imprima um único inteiro indicando a quantidade máxima de energia que os canibais podem obter após devorar as pessoas que eles conseguem capturar.

// Examples
// inputCopy
// 4 4
// 2 3 4 6
// 3 1 8 4
// outputCopy
// 6
// inputCopy
// 5 9
// 5 1 5 2 4
// 2 6 4 3 3
// outputCopy
// 14
// Note
// No primeiro caso de teste, os canibais obtém a energia máxima ao capturar e devorar a pessoa 4, pois o custo para capturá-la não excede o custo que os canibais podem demandar nessa tarefa. É importante notar que os canibais também tem condições de capturar as pessoas 1 e 2, mas ao serem devoradas juntas pelos canibais, não oferecerão mais energia do que a pessoa 4.

// No segundo caso de teste, os canibais conseguem obter a energia máxima ao devorar as pessoas 1, 3 e 5, pois juntas oferecem a quantidade de energia que respeita o custo máximo dos canibais no processo de captura.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vi energia, custo;
vector<pair<int, int>> custo_energia;
int n, m;
int tabela[10005][10005];

int f(int i, int e) {
  if (i >= n) {
    return 0;
  }
  if (tabela[i][e] != -1) {
    return tabela[i][e];
  }
  if (e + custo_energia[i].first > m) {
    return 0;
  }

  int pegar = custo_energia[i].second + f(i + 1, e + custo_energia[i].first);
  int nao_pegar = f(i + 1, e);

  tabela[i][e] = max(pegar, nao_pegar);
  return tabela[i][e];
}

int main() {
  memset(tabela, -1, sizeof(tabela));

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    energia.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    custo.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    custo_energia.push_back({custo[i], energia[i]});
  }

  sort(custo_energia.begin(), custo_energia.end());

  cout << f(0, 0) << endl;

  return 0;
}