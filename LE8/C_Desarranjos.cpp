// C. Desarranjos
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Você sabia que da mesma forma como existe "n!" também existe "!n" ? Essa função é chamada de desarranjo. O resultado dessa função representa a quantidade de permutações caóticas. Para não confundir, vamos chamar !n de Dn.

// Podemos definir uma permutação como qualquer sequência de n números com todos estando situados de 1 a n e não repetindo nenhum número na sequência. Então [1,2,3], [2,3,1] e [1,3,2] são permutações enquanto [1,3,3], [1,4,3] não são.

// Uma permutação S é dita caótica quando para todo indice i da sequência, Si é diferente de i. Então [3,1,2] e [2,3,1] são permutações caóticas enquanto [1,2,3], [3,2,1] e [1,3,2] não são.

// Você pode ler mais sobre desarranjos aqui: https://pt.wikipedia.org/wiki/Desarranjo

// Olhando todas as permutações, podemos dizer quais são caóticas e quais não são.

// D0 = 1

// D1 = 0

// D2 = 1

// D3 = 2

// D4 = 9

// D5 = 44

// Olha que sequência louca! Por sorte, ao invés de testar todas as possibilidades para descobrir a quantidade de permutações caóticas para um n, há uma recorrência que gera esses numeros.

// D0 = 1

// D1 = 0

// Dn = (n - 1) * (Dn - 1 + Dn - 2)

// Para um dado n, calcule o número de permutações caóticas.

// Input
// Um único inteiro n (1 ≤ n ≤ 106).

// Output
// Imprima um único inteiro, o número de permutações caóticas modulo 1000000007.

// Examples
// inputCopy
// 0
// outputCopy
// 1
// inputCopy
// 1
// outputCopy
// 0
// inputCopy
// 4
// outputCopy
// 9
// inputCopy
// 100
// outputCopy
// 944828409

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

ll tabela[1000005];
int mod = 1000000007;

int f(int x) {
  if (x == 0) {
    return 1;
  }
  if (x == 1) {
    return 0;
  }
  if (tabela[x] != -1) {
    return tabela[x];
  }

  ll r1 = f(x - 1) % mod;
  ll r2 = f(x - 2) % mod;
  ll r3 = x - 1;

  tabela[x] = (r3 * ((r2 + r1) % mod)) % mod;

  return tabela[x];
}

int main() {
  int x;
  cin >> x;

  for (int i = 0; i < 1000005; i++) {
    tabela[i] = -1;
  }

  cout << f(x) << endl;

  return 0;
}