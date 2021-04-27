// C. Criptografia RSA
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Amir, um estudante de Ciência da Computação, está estudando sobre criptografia RSA. Ele aprende que uma parte da chave pública desse sistema é um número inteiro 𝑛=𝑝∗𝑞, onde 𝑝 e 𝑞 são ambos inteiros primos e 𝑝≠𝑞.

// Amir, então, se pergunta: "quantos inteiros 𝑛 entre 1 e 𝑚 eu posso usar na chave pública?". Como o garoto não consegue achar a solução ele decide perguntar para você. Faça um programa que calcule a quantidade de inteiros 𝑛 entre 1 e 𝑚 que satisfazem a propriedade.

// Input
// Uma única linha contendo um único inteiro 𝑚 (1≤𝑚≤107)
// Output
// Imprima um único inteiro — a quantidade de inteiros 𝑛 (1≤𝑛≤𝑚), onde 𝑛=𝑝∗𝑞, e 𝑝 e 𝑞 são primos distintos.

// Examples
// inputCopy
// 6
// outputCopy
// 1
// inputCopy
// 12
// outputCopy
// 2
// inputCopy
// 47
// outputCopy
// 13
// inputCopy
// 100000
// outputCopy
// 23313
// Note
// No primeiro exemplo o único número que satisfaz a propriedade no intervalo [1,6] é 6 (6=2∗3).

// No terceiro exemplo temos 13 números: 6,10,14,15,21,22,26,33,34,35,38,39,46.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<lli> primos;

vector<lli> primos_ate_n(lli N) {
  vector<lli> marcacao(N, 1); // 1 = possivel primo, 0 = com certeza não primo
  for (lli x = 2; x < N; x++)
    if (marcacao[x] == 1) {
      primos.push_back(x);
      for (lli m = x + x; m < N; m += x) {
        marcacao[m] = 0; // aqui descobrimos que m não é primo
      }
    }
  return primos;
}

int main() {
  lli m, count = 0;
  cin >> m;
  primos_ate_n(m + 10);

  for (lli i = 0; i < primos.size() - 1; i++) {
    for (lli j = i + 1; j < primos.size(); j++) {
      if (to_string(primos[i]).size() - 1 + to_string(primos[j]).size() - 1 > to_string(m).size() - 1) {
        break;
      } else if (primos[i] * primos[j] <= m) {
        count++;
      } else {
        break;
      }
    }
  }

  cout << count << endl;
  return 0;
}