// A. Números perfeitos
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Um número é n dito perfeito se a soma de todos os seus divisores próprios,ou seja, a soma de todos os seus divisores que não são ele mesmo se iguala ao seu valor. Diga se um número é perfeito ou não.

// Input
// A única linha de entrada contém um inteiro n (1 <= n <= 109)

// Output
// Caso o número seja perfeito, imprima 1, caso contrário imprima 0.

// Examples
// inputCopy
// 6
// outputCopy
// 1
// inputCopy
// 14
// outputCopy
// 0
// inputCopy
// 28
// outputCopy
// 1

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

vector<long long> all_divisors(long long n) {
  vector<long long> ans;
  for (long long a = 1; a * a <= n; a++) { // comparação que evita o uso de doubles, a <= sqrt(n) é o mesmo que a*a <= n
    if (n % a == 0) {
      long long b = n / a;
      ans.push_back(a);
      if (a != b)
        ans.push_back(b);
    }
  }
  sort(ans.begin(), ans.end()); // frescura para retornar os divisores ordenados como na primeira implementação
  return ans;
}

int main() {
  lli n, count = 0;
  cin >> n;
  vector<long long> ans = all_divisors(n);

  for (auto x : ans) {
    count += x;
  }
  count -= n;

  if (count == n) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}