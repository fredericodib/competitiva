// B. Troco II
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você está num supermercado e está na fila do caixa para comprar alguns produtos. Assim que você termina de passar as compras pelo caixa, se lembra que tem várias moedas em seu bolso, algumas repetidas, e fica pensando se com elas dá para pagar exatamente o valor das compras (para assim se livrar destas moedas e ficar com os bolsos mais leves). Você consegue pagar o valor exato da conta usando estas moedas?

// Input
// A primeira linha da entrada contém dois números inteiros 𝑉 (1≤𝑉≤105) e 𝑀 (1≤𝑀≤103), indicando, respectivamente, o valor final da compra e o número de moedas que você tem em seu bolso. A segunda linha contém 𝑀 números inteiros que descrevem o valor 𝑀𝑖 (1≤𝑀𝑖≤105) de cada moeda existente em seu bolso.

// Output
// Seu programa deve imprimir apenas uma linha, contendo apenas um caractere: 𝑆 caso seja possível pagar o valor exato da conta usando apenas suas moedas, ou 𝑁 caso contrário.

// Examples
// inputCopy
// 16 4
// 25 10 5 1
// outputCopy
// S
// inputCopy
// 20 4
// 25 10 5 1
// outputCopy
// N
// inputCopy
// 14 3
// 10 5 2
// outputCopy
// N

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

bool tabela[1005][100005];
bool exists[1005][100005] = {false};
vi moedas;
int v, n;

bool dp(int i, int total) {
  if (total == v)
    return true;
  if (i >= n)
    return false;
  if (total > v)
    return false;
  if (exists[i][total])
    return tabela[i][total];

  bool pegar = dp(i + 1, moedas[i] + total);
  bool nao_pegar = dp(i + 1, total);

  if (pegar || nao_pegar) {
    exists[i][total] = true;
    tabela[i][total] = true;
    return tabela[i][total];
  }

  exists[i][total] = true;
  tabela[i][total] = false;
  return tabela[i][total];
}

int main() {
  cin >> v >> n;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    moedas.push_back(x);
  }

  if (dp(0, 0)) {
    cout << "S" << endl;
  } else {
    cout << "N" << endl;
  }

  return 0;
}
