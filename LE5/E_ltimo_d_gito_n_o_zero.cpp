// E. Último dígito não-zero
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Sejam dois números 𝑀 e 𝑁. Determine o último dígito de 𝐴𝑁,𝑀, que descreve quantas formas distintas é possível escolher 𝑀 elementos de um grupo de 𝑁 elementos por vez. Por exemplo, se 𝐴𝑁,𝑀=720 (para quaisquer 𝑀 e 𝑁), então o último dígito não-zero é 2.

// Input
// A entrada contém dois números inteiros 0≤𝑁≤2⋅107 e 0≤𝑀≤𝑁.

// Output
// Imprima um único dígito inteiro, que é o último dígito não-zero de 𝐴𝑁,𝑀.

// Examples
// inputCopy
// 4 2
// outputCopy
// 2
// inputCopy
// 5 3
// outputCopy
// 6
// inputCopy
// 10 10
// outputCopy
// 8
// inputCopy
// 25 6
// outputCopy
// 2
// Note
// No primeiro caso de teste, 𝐴𝑁,𝑀=𝐴4,2=𝑁!/(𝑁−𝑀)!=4!/(4−2)!=12, logo o último dígito não-zero é 2.

// No terceiro caso de teste, 𝐴𝑁,𝑀=𝐴10,10=3628800, portanto, o último dígito não-zero é 8.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli m, n, res = 1, count5 = 0, count2 = 0;

  scanf("%lld %lld", &m, &n);

  for (lli i = m; i > m - n; i--) {
    lli x = i;
    while (x % 5 == 0) {
      x /= 5;
      count5++;
    }
    while (x % 2 == 0) {
      x /= 2;
      count2++;
    }
    res *= x;
    res %= 10;
  }

  lli m_min = min(count5, count2);
  count5 -= m_min;
  count2 -= m_min;

  for (lli i = 0; i < count5; i++) {
    res *= 5;
    res %= 10;
  }

  for (lli i = 0; i < count2; i++) {
    res *= 2;
    res %= 10;
  }

  cout << res << endl;

  return 0;
}