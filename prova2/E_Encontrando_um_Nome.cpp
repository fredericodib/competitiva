// E. Encontrando um Nome
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Alberto estava pensando em uma historinha para um problema da prova da disciplina de Competição Programativa, mas não conseguiu pensar em nada. Ao pedir ajuda ao Tiago, seu amigo disse que só ajudaria com o nome caso Alberto conseguisse resolver o seguinte problema.

// Dado um vetor 𝑎 de 𝑛 inteiros, encontre a quantidade de divisores do produto de todos os elementos do vetor, módulo 109+7. Mais formalmente, se 𝑎𝑖 é o 𝑖-ésimo elemento do vetor 𝑎, defina 𝑚=𝑎1∗𝑎2∗...∗𝑎𝑛, e imprima a quantidade de divisores (mod 109+7) do número 𝑚.

// Input
// A primeira linha contém um único inteiro 𝑛 (1≤𝑛≤105), a quantidade de números do vetor.

// A segunda linha contém 𝑛 inteiros 𝑎𝑖 separados por espaço (1≤𝑎𝑖≤105), os números do vetor.

// Output
// Imprima um único inteiro, a quantidade de divisores módulo 109+7 do produto de todos os números do vetor 𝑎.

// Examples
// inputCopy
// 2
// 4 3
// outputCopy
// 6
// inputCopy
// 4
// 1 9 8 4
// outputCopy
// 18
// inputCopy
// 3
// 1000 1000 1000
// outputCopy
// 100
// inputCopy
// 4
// 10007 10007 10007 10007
// outputCopy
// 5
// Note
// Para o caso de teste 1 temos 4∗3=12, e 12 tem 6 divisores: 1, 2, 3, 4, 6 e 12.

// Para o caso de teste 4 temos 100074=10028029413722401. Este número tem 5 divisores: 1, 10007, 1000072, 100073 e 100074. Note que tiramos o mod apenas na quantidade de divisores, e 5%(109+7)=5.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<lli> lp(100001, -1);
lli mod = 1000000007;

map<lli, lli> fatora(lli x) {
  map<lli, lli> expoentes;
  while (x > 1) {
    expoentes[lp[x]]++;
    x /= lp[x];
  }
  return expoentes;
}

int main() {
  for (lli x = 2; x < 100001; x++)
    if (lp[x] == -1) {
      for (lli m = x; m < 100001; m += x)
        lp[m] = x;
    }

  lli n, count = 1;
  scanf("%lld", &n);

  map<lli, lli> expoentes_final;

  for (lli i = 0; i < n; i++) {
    lli x;
    scanf("%lld", &x);

    map<lli, lli> expoentes_temp = fatora(x);

    for (auto elem : expoentes_temp) {
      expoentes_final[elem.first] += elem.second;
    }
  }

  for (auto elem : expoentes_final) {
    count = ((count % mod) * (elem.second + 1 % mod)) % mod;
  }

  cout << count << endl;
  return 0;
}