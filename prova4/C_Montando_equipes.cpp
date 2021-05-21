// C. Montando equipes
// time limit per test1 s.
// memory limit per test256 MB
// inputstandard input
// outputstandard output
// A Universidade de Brasília (UnB) possui 𝑛 estudantes. A professora Roberta, atual técnica das equipes da UnB, possui os registros das quantidades de vezes que cada um desses estudantes competiu na Maratona SBC de Programação representando a UnB. De acordo com as regras, cada estudante pode participar no máximo 5 vezes dessa competição.

// A próxima edição da Maratona SBC de Programação está por vir e a professora Roberta está incentivando os estudantes a formarem times. Cada equipe deve ser composta por exatamente três pessoas, sendo que nenhum estudante pode pertencer a duas ou mais equipes. Sua tarefa consiste em determinar a quantidade máxima de equipes que a professora Roberta pode formar para que cada membro participe da Maratona SBC de Programação com os mesmos membros pelo menos 𝑘 vezes.

// Input
// A primeira linha da entrada contém dois números inteiros, 𝑛 e 𝑘 (1≤𝑛≤2000; 1≤𝑘≤5). A próxima linha contém 𝑛 inteiros: 𝑦1,𝑦2,...,𝑦𝑛 (0≤𝑦𝑖≤5), em que 𝑦𝑖 apresenta a quantidade de vezes que o 𝑖-ésimo estudante participou da Maratona SBC de Programação.

// Output
// Imprima um único inteiro associado à quantidade máxima de equipes que podem ser montadas pela profa. Roberta, de modo que cada membro participe da competição com os mesmos membros pelo menos 𝑘 vezes.

// Examples
// inputCopy
// 5 2
// 0 4 5 1 0
// outputCopy
// 1
// inputCopy
// 6 4
// 0 1 2 3 4 5
// outputCopy
// 0
// inputCopy
// 6 5
// 0 0 0 0 0 0
// outputCopy
// 2
// Note
// No primeiro exemplo de teste, apenas uma única equipe pode ser formada: o primeiro, o quarto e o quinto estudantes.
// No segundo exemplo de teste, não é possível criar nenhuma equipe.
// No terceiro exemplo de teste, duas equipes podem ser criadas, uma vez que qualquer particionamento de estudantes em duas equipes é possível.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

ll tabela[1000005];
vi y;
int k;

int main() {
  int n;
  cin >> n >> k;

  for (int i = 0; i < 1000005; i++) {
    tabela[i] = -1;
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x + k <= 5) {
      y.push_back(x);
    }
  }

  cout << y.size() / 3 << endl;

  return 0;
}
