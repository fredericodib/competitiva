// B. Balanced Remainders
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a number 𝑛 (divisible by 3) and an array 𝑎[1…𝑛]. In one move, you can increase any of the array elements by one. Formally, you choose the index 𝑖 (1≤𝑖≤𝑛) and replace 𝑎𝑖 with 𝑎𝑖+1. You can choose the same index 𝑖 multiple times for different moves.

// Let's denote by 𝑐0, 𝑐1 and 𝑐2 the number of numbers from the array 𝑎 that have remainders 0, 1 and 2 when divided by the number 3, respectively. Let's say that the array 𝑎 has balanced remainders if 𝑐0, 𝑐1 and 𝑐2 are equal.

// For example, if 𝑛=6 and 𝑎=[0,2,5,5,4,8], then the following sequence of moves is possible:

// initially 𝑐0=1, 𝑐1=1 and 𝑐2=4, these values are not equal to each other. Let's increase 𝑎3, now the array 𝑎=[0,2,6,5,4,8];
// 𝑐0=2, 𝑐1=1 and 𝑐2=3, these values are not equal. Let's increase 𝑎6, now the array 𝑎=[0,2,6,5,4,9];
// 𝑐0=3, 𝑐1=1 and 𝑐2=2, these values are not equal. Let's increase 𝑎1, now the array 𝑎=[1,2,6,5,4,9];
// 𝑐0=2, 𝑐1=2 and 𝑐2=2, these values are equal to each other, which means that the array 𝑎 has balanced remainders.
// Find the minimum number of moves needed to make the array 𝑎 have balanced remainders.

// Input
// The first line contains one integer 𝑡 (1≤𝑡≤104). Then 𝑡 test cases follow.

// The first line of each test case contains one integer 𝑛 (3≤𝑛≤3⋅104) — the length of the array 𝑎. It is guaranteed that the number 𝑛 is divisible by 3.

// The next line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (0≤𝑎𝑖≤100).

// It is guaranteed that the sum of 𝑛 over all test cases does not exceed 150000.

// Output
// For each test case, output one integer — the minimum number of moves that must be made for the 𝑎 array to make it have balanced remainders.

// Example
// inputCopy
// 4
// 6
// 0 2 5 5 4 8
// 6
// 2 0 2 1 0 0
// 9
// 7 1 3 4 2 10 3 9 6
// 6
// 0 1 2 3 4 5
// outputCopy
// 3
// 1
// 3
// 0
// Note
// The first test case is explained in the statements.

// In the second test case, you need to make one move for 𝑖=2.

// The third test case you need to make three moves:

// the first move: 𝑖=9;
// the second move: 𝑖=9;
// the third move: 𝑖=2.
// In the fourth test case, the values 𝑐0, 𝑐1 and 𝑐2 initially equal to each other, so the array 𝑎 already has balanced remainders.

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, res = 0;
  cin >> n;
  map<int, int> c_map;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c_map[x % 3]++;
  }

  int c_final = (c_map[0] + c_map[1] + c_map[2]) / 3;

  while (c_map[0] != c_map[1] || c_map[1] != c_map[2]) {
    if (c_map[2] > c_final) {
      int c_2_dif = max(c_final, c_map[2]) - min(c_final, c_map[2]);
      res += c_2_dif;
      c_map[2] -= c_2_dif;
      c_map[0] += c_2_dif;
    } else if (c_map[1] > c_final) {
      int c_1_dif = max(c_final, c_map[1]) - min(c_final, c_map[1]);
      res += c_1_dif;
      c_map[1] -= c_1_dif;
      c_map[2] += c_1_dif;
    } else {
      int c_0_dif = max(c_final, c_map[0]) - min(c_final, c_map[0]);
      res += c_0_dif;
      c_map[0] -= c_0_dif;
      c_map[1] += c_0_dif;
    }
  }

  cout << res << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}