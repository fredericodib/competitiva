// A. Estacionamento Linear
// time limit per test6 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Fonte: https://www.urionlinejudge.com.br/judge/pt/problems/view/1523

// Após muito tempo juntando dinheiro, Rafael finalmente conseguiu comprar seu carro (parcelado, é claro). Chega de pegar ônibus, agora sua vida será mais fácil. Pelo menos isso é o que ele pensava, até ouvir falar do estacionamento perto da faculdade onde ele decidiu estacionar o carro todos os dias.

// O estacionamento tem apenas um corredor, com largura o suficiente para acomodar um carro, e profundidade suficiente para acomodar 𝐾 carros, um atrás do outro. Como este estacionamento só tem um portão, só é possível entrar e sair por ele.

// Quando o primeiro carro entra no estacionamento, o mesmo ocupa a posição próxima à parede, ao fundo do estacionamento. Todos os próximos carros estacionam logo atrás dele, formando uma fila. Obviamente, não é possível que um carro passe por cima de outro, portanto só é possível que um carro saia do estacionamento se ele for o último da fila.

// Dados o horário de chegada e saída prevista de 𝑁 motoristas, incluindo Rafael, diga se é possível que todos consigam estacionar e remover seus carros no estacionamento citado.

// Input
// A primeira linha contém dois inteiros 𝑁 e 𝐾 (3≤𝑁≤106,1≤𝐾≤103), representando o número de motoristas que farão uso do estacionamento, e o número de carros que o estacionamento consegue comportar, respectivamente.

// Em seguida haverá 𝑁 linhas, cada uma contendo dois inteiros 𝐶𝑖 e 𝑆𝑖 (1≤𝐶𝑖,𝑆𝑖≤108), representando, respectivamente, o horário de chegada e saída do motorista 𝑖 (1≤𝑖≤𝑁). Os valores de 𝐶𝑖 são dados de forma crescente, ou seja, 𝐶𝑖<𝐶𝑖+1 para todo 1≤𝑖<𝑁.

// Não haverá mais de um motorista que chegam ao mesmo tempo, e nem mais de um motorista que saiam ao mesmo tempo. É possível que um motorista consiga estacionar no mesmo momento em que outro motorista deseja sair.

// Output
// Imprima a palavra "Sim", caso seja possível que todos os 𝑁 motoristas façam uso do estacionamento, ou "Nao" caso contrário.

// Examples
// inputCopy
// 3 2
// 1 10
// 2 5
// 6 9
// outputCopy
// Sim
// inputCopy
// 3 2
// 1 10
// 2 5
// 6 12
// outputCopy
// Nao

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n, k;
  cin >> n >> k;
  vector<ii> a;

  for (int i; i < n; i++) {
    int x, y;
    ii p;
    cin >> x >> y;
    p = {x, y};

    if (a.size() == 0) {
      a.push_back(p);
    } else {
      while (p.first >= a.back().second) {
        a.pop_back();
      }
      if (a.size() > k) {
        cout << "Nao" << endl;
        return 0;
      } else {
        if (a.size() > 0 && p.second > a.back().second) {
          cout << "Nao" << endl;
          return 0;
        }
        a.push_back(p);
      }
    }
  }

  cout << "Sim" << endl;
  return 0;
}