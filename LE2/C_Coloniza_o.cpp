// C. Colonização
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Na era das Grandes Navegações, a Nlogonia despontava como uma das nações que possuíam as melhores condições de desbravar os oceanos e o mundo afora. Um grupo de aventureiros da Nlogonia, liderado pelo experiente navegador Bonifácio de Almeida, planeja colonizar o recém-descoberto território da Quadradonia, atraídos pelas notícias de suas grandes reservas de ouro.

// Assim, o capitão Bonifácio de Almeida fabricou 𝑁 navios de grande porte, cada um capaz de carregar 𝑀 toneladas de ouro. Além disso, para maximizar a quantidade de ouro extraída da Quadradonia, ele organizou as expedições de modo que o 𝑖-ésimo navio realize uma nova jornada exploratória a cada 𝑡𝑖 anos.

// A Quadradonia possui 𝑅 toneladas de ouro antes da chegada da primeira expedição, e a natureza local é capaz de gerar exatamente 1 tonelada de ouro por ano. Ao chegar à Quadradonia, o 𝑖-ésimo navio do capitão Bonifácio de Almeida extrai todo o ouro que puder e o leva à Nlogonia. Caso haja ouro nas reservas da colônia, ele retorna 𝑡𝑖 anos depois para continuar a exploração. Quando um navio levar todo o ouro restante no território, ele encerra as expedições à Quadradonia e parte para novas aventuras!

// Os 𝑁 navios partem juntos da Nlogonia nas primeiras expedições, e sua tarefa é determinar quanto tempo dura (em anos) a colonização do novo território. Caso haja duas ou mais expedições que saiam no mesmo ano da Quadradonia, aquela cujo navio possui o menor identificador terá prioridade de extrair o ouro. Para esse propósito, considere que cada navio é enumerado por um número inteiro de 1 a 𝑁. Considere também que o tempo de navegação (tanto ida, como a volta) são irrelevantes.

// Input
// A primeira linha da entrada contém três números inteiros separados por um espaço em brancos 1≤𝑁≤104, 1≤𝑅≤106 e 2≤𝑀≤100, indicando a quantidade navios da Nlogonia, a quantidade de ouro (em toneladas) e a capacidade de cada navio, respectivamente.

// A segunda linha contém 𝑁 inteiros separados por espaço em branco 𝑡1,𝑡2,...,𝑡𝑁, em que cada 1≤𝑡𝑖<𝑀 descreve o período (em anos) do 𝑖-ésimo navio.

// Output
// Imprima um número inteiro que descreve a quantidade total de anos da colonização da Constantonia. É garantido que tal número nunca ultrapassa 109.

// Examples
// inputCopy
// 2 12 4
// 3 2
// outputCopy
// 4
// inputCopy
// 3 20 5
// 4 5 3
// outputCopy
// 5
// inputCopy
// 4 26 6
// 3 2 4 5
// outputCopy
// 3
// Note
// No primeiro exemplo de teste, existem 𝑁=2 navios, 𝑅=12 toneladas de ouro e a capacidade dos navios é 𝑀=4. Pode-se verificar que a colonização da Quadradonia durou 4 anos:

// As duas primeiras expedições consistem dos navios 1 e 2, que chegam juntos à Quadradonia e extraem 8 toneladas de ouro;
// A terceira expedição utiliza o navio 2, que retorna após dois anos, pois 𝑡2=2. Nesses dois anos, a natureza recuperou 2 toneladas de ouro, logo as reservas de ouro da Quadradonia possuem 6 toneladas. A expedição extrai 4 toneladas de ouro, deixando as reservas locais com apenas 2 toneladas.
// A quarta expedição está a bordo do navio 1, que retorna após três anos, pois 𝑡1=3. Eles esgotam as reservas de ouro da Quadradonia e a colonização é encerrada.
// No segundo exemplo de teste, existem 𝑁=3 navios, 𝑅=20 toneladas de ouro e a capacidade dos navios é 𝑀=5. Aqui, o período de colonização da Quadradonia durou 5 anos, pois:

// As três primeiras expedições consistem dos navios 1, 2 e 3, que chegam juntos à Quadradonia e extraem 15 toneladas de ouro, restando 5 toneladas na reserva;
// A quarta expedição utiliza o navio 3 (𝑡3=3). As reservas de ouro da Quadradonia possuem 8 toneladas, pois nesses três anos, a natureza recuperou 3 toneladas. A expedição extrai 5 toneladas de ouro, deixando as reservas locais com 3 toneladas.
// Por meio do navio 1, a quinta expedição chega à Quadradonia após quatro anos (𝑡1=4). Eles esgotam as reservas de ouro da Quadradonia e a colonização é encerrada.
// No terceiro exemplo de teste, existem 𝑁=4 navios, 𝑅=26 toneladas de ouro e a capacidade dos navios é 𝑀=6.

// As quatro primeiras expedições consistem dos navios 1, 2, 3 e 4, que chegam juntos à Quadradonia e extraem 20 toneladas de ouro, restando 2 toneladas na reserva;
// A quinta expedição retorna após 2 anos por meio do navio 2 (𝑡2=2). As reservas de ouro da Quadradonia possuem 4 toneladas, pois nesses dois últimos anos, a natureza recuperou 2 toneladas. Mesmo assim, a expedição extrai as 4 toneladas restantes, esgotando as reservas de ouro da Quadradonia. Portanto, a colonização é encerrada após 3 anos de seu início.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n, r, m, res = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  vi time;
  cin >> n >> r >> m;

  for (int i; i < n; i++) {
    int x;
    cin >> x;
    pq.push(mp(0, i));
    time.push_back(x);
  }

  while (r > 0) {
    ii x = pq.top();
    r += x.first - res;
    r -= m;
    res = x.first;
    pq.pop();
    x.first = res + time[x.second];
    pq.push(x);
  }

  cout << res + 1 << endl;
  return 0;
}