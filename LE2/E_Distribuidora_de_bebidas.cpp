// E. Distribuidora de bebidas
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Uma distribuidora de bebidas acabou de construir seu galpão para armazenar bebidas que chegam das fábricas, e de lá fornecê-las ao comércio da cidade. No galpão, existem o espaço 𝑈 usado para guardar as caixas de garrafas e o espaço 𝑉 para guardar temporariamente garrafas avulsas, que podem sobrar nas operações de carregamento e descarregamento dos caminhões de transporte. Por ter uma área reduzida, as diversas caixas, formadas pelas garrafas de bebibas descarregadas dos caminhões, são empilhadas no espaço 𝑈.

// A distribuidora organiza as garrafas em caixas de fabricação própria. Cada caixa armazena exatamente 𝐵 garrafas de bebidas e só pode ser estocada no espaço 𝑈 se estiver cheia. Portanto, ao preencher uma caixa com garrafas de bebidas, as garrafas excedentes ficarão no espaço 𝑉. No momento que houver 𝐵 garrafas no espaço 𝑉, elas são imediatamente encaixotadas e colocadas no espaço 𝑈.

// Dentro do galpão, o acesso ao espaços 𝑈 e 𝑉 é feito por uma via estreita, que permite a passagem de apenas um caminhão por vez. À medida em que chegam mais caminhões, cada um com sua capacidade de carga específica, eles esperam a definição de suas funções conforme a ordem de chegada. São duas atividades possíveis:

// carregar: o caminhão é carregado com a maior quantidade possível de garrafas das caixas de 𝑈, sem extrapolar sua capacidade máxima, ou até que não haja mais caixas a serem levadas. Portanto, se uma caixa é retirada de 𝑈, todas as garrafas que a compõe devem ser carregadas dentro do caminhão. Caso o caminhão chegue ao espaço 𝑈 e não encontre nenhuma caixa, ele retorna para o final da fila com a esperança futura de carregar seu caminhão com bebidas. No entanto, caso em sua segunda tentativa o caminhão encontrar a pilha vazia, ele deixa o galpão definitivamente.
// descarregar: o caminhão descarrega todas as suas garrafas de bebidas avulsas em 𝑉 (que são imediatamente encaixotadas, e as caixas cheias levadas a 𝑈).
// Vale ressaltar que todos os caminhões que chegam com a função de descarregar bebidas estão completamente cheios, enquanto que todos os caminhões que serão carregados estão completamente vazios.

// Preocupado com a grande movimentação do galpão, o dono da distribuidora de bebidas quer controlar a quantidade de bebidas chegam e saem. Elabore um programa que determine a quantidade de garrafas de bebidas que restaram no galpão após a saída de todos os caminhões.

// Input
// A primeira linha contém três números inteiros 1≤𝑁≤104, 1≤𝐶≤104 e 2≤𝐵≤103 separados por um espaço em branco, indicando a quantidade de caminhões, a quantidade inicial de caixas no espaço 𝑈 e a capacidade máxima de cada caixa, respectivamente.

// A segunda linha contém 𝑁 inteiros 𝑚1,𝑚2,...,𝑚𝑁 (1≤𝑚𝑖≤500), que indicam a capacidade máxima de armazenamento de garrafas do 𝑖-ésimo caminhão aguardando a tarefa.

// A última linha contém 𝑁 inteiros 𝑓1,𝑓2,...,𝑓𝑁 definindo a tarefa de cada caminhão. 𝑓𝑖=1 indica que o 𝑖-ésimo caminhão será carregado, e 𝑓𝑖=0 indica que ele será descarregado.

// Output
// Imprima um número inteiro indicando a quantidade total de garrafas de bebidas (em 𝑈 e 𝑉) que sobraram no galpão após a saída de todos os caminhões.

// Examples
// inputCopy
// 4 4 3
// 2 3 1 6
// 0 1 0 1
// outputCopy
// 6
// inputCopy
// 6 3 2
// 2 2 2 4 2 4
// 1 0 1 1 0 1
// outputCopy
// 0
// inputCopy
// 1 2 2
// 3
// 1
// outputCopy
// 2
// inputCopy
// 3 1 2
// 3 2 5
// 1 1 0
// outputCopy
// 3
// Note
// *** No primeiro caso de teste, existem 𝑁=4 caminhões, 𝐶=4 caixas no espaço 𝑈 e as caixas armazenam 𝐵=3 garrafas.

// O caminhão 1 descarrega 2 garrafas, que são deixadas no espaço 𝑉 por não completarem uma caixa;
// O caminhão 2 é carregado com três garrafas, aquelas que estão na caixa do topo da pilha;
// O caminhão 3 descarrega uma garrafa, sendo colocada no espaço 𝑉 por não completar uma caixa.
// Nesse momento, o espaço 𝑉 passa a ter 3 garrafas avulsas, que completam uma nova caixa, sendo empilhada no espaço 𝑈.

// O último caminhão é carregado com 6 garrafas a partir das duas caixas que são desempilhadas do espaço 𝑈.
// Ao final do processo, o espaço 𝑈 conta com 2 caixas e o espaço 𝑉 não contém garrafas avulsas. Portanto, o total de garrafas existentes no galpão é 2∗𝐵=2∗3=6.

// *** No segundo caso de teste, existem 𝑁=6 caminhões, 𝐶=3 caixas no espaço 𝑈 e as caixas armazenam 𝐵=2 garrafas. Inicialmente, o espaço 𝑈 possui 6 garrafas.

// O caminhão 1 é carregado com 2 garrafas, provenientes da caixa que está no topo do empilhamento no espaço 𝑈;
// O caminhão 2 descarrega 2 garrafas, que completam uma caixa, sendo estocada diretamente no espaço 𝑈;
// O caminhão 3 é carregado com 2 garrafas, provenientes da caixa que está no topo do empilhamento no espaço 𝑈;
// O caminhão 4 é carregado com 4 garrafas, provenientes de duas caixas do topo do empilhamento no espaço 𝑈;
// O caminhão 5 descarrega 2 garrafas, que completam uma caixa, sendo estocada diretamente no espaço 𝑈;
// O caminhão 6 é carregado com 4 garrafas, provenientes de duas caixas do topo do empilhamento no espaço 𝑈;
// Ao final do processo, o espaço 𝑈 está vazio e o espaço 𝑉 não contém garrafas avulsas. Portanto, não há garrafas no galpão após a saída de todos os caminhões.

// *** No terceiro caso de teste, existe um caminhão na fila, duas caixas contendo 2 garrafas de bebidas cada. O caminhão consegue ser carregado com apenas duas garrafas avulsas da caixa que está no topo. Nesse sentido, o caminhão deixa o galpão sem completar sua capacidade máxima, pois não se pode retirar apenas algumas das garrafas da caixa do espaço 𝑈. Portanto, sobrou apenas uma caixa no espaço 𝑈, totalizando 2 garrafas no galpão.

// *** No quarto exemplo, existem três caminhões, uma caixa no espaço 𝑈 de capacidade 2. O caminhão 1 é carregado com as duas garrafas da única caixa, deixando o espaço 𝑈 vazio. Desta maneira, o caminhão 2 não pode ser carregado com garrafas, logo ele vai realizar uma última tentativa indo para o final da fila. O caminhão 3 descarrega cinco garrafas, formando duas caixas que são estocadas no espaço 𝑈 e a garrafa remanescente fica no espaço 𝑉. O caminhão 2 retorna e agora é capaz de ser carregado com duas garrafas de bebidas. Ao final, restaram uma caixa no espaço 𝑈 e uma garrafa avulsa no espaço 𝑉, logo existem 3 garrafas no galpão.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n, b, v = 0, u;
  vi truck, w, truck2, w2;
  cin >> n >> u >> b;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    truck.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    w.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    if (w[i] == 1) {
      int x;
      x = truck[i] / b;
      if (u == 0) {
        truck2.push_back(truck[i]);
        w2.push_back(w[i]);
      }
      u = u >= x ? u - x : 0;
    } else {
      v += truck[i];
      u += v / b;
      v = v % b;
    }
  }

  for (int i = 0; i < truck2.size(); i++) {
    if (w2[i] == 1) {
      int x;
      x = truck2[i] / b;
      u = u >= x ? u - x : 0;
    } else {
      v += truck2[i];
      u += v / b;
      v = v % b;
    }
  }

  cout << u * b + v << endl;
  return 0;
}