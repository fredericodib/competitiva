// B. Balanced Remainders
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a number ๐ (divisible by 3) and an array ๐[1โฆ๐]. In one move, you can increase any of the array elements by one. Formally, you choose the index ๐ (1โค๐โค๐) and replace ๐๐ with ๐๐+1. You can choose the same index ๐ multiple times for different moves.

// Let's denote by ๐0, ๐1 and ๐2 the number of numbers from the array ๐ that have remainders 0, 1 and 2 when divided by the number 3, respectively. Let's say that the array ๐ has balanced remainders if ๐0, ๐1 and ๐2 are equal.

// For example, if ๐=6 and ๐=[0,2,5,5,4,8], then the following sequence of moves is possible:

// initially ๐0=1, ๐1=1 and ๐2=4, these values are not equal to each other. Let's increase ๐3, now the array ๐=[0,2,6,5,4,8];
// ๐0=2, ๐1=1 and ๐2=3, these values are not equal. Let's increase ๐6, now the array ๐=[0,2,6,5,4,9];
// ๐0=3, ๐1=1 and ๐2=2, these values are not equal. Let's increase ๐1, now the array ๐=[1,2,6,5,4,9];
// ๐0=2, ๐1=2 and ๐2=2, these values are equal to each other, which means that the array ๐ has balanced remainders.
// Find the minimum number of moves needed to make the array ๐ have balanced remainders.

// Input
// The first line contains one integer ๐ก (1โค๐กโค104). Then ๐ก test cases follow.

// The first line of each test case contains one integer ๐ (3โค๐โค3โ104) โ the length of the array ๐. It is guaranteed that the number ๐ is divisible by 3.

// The next line contains ๐ integers ๐1,๐2,โฆ,๐๐ (0โค๐๐โค100).

// It is guaranteed that the sum of ๐ over all test cases does not exceed 150000.

// Output
// For each test case, output one integer โ the minimum number of moves that must be made for the ๐ array to make it have balanced remainders.

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

// In the second test case, you need to make one move for ๐=2.

// The third test case you need to make three moves:

// the first move: ๐=9;
// the second move: ๐=9;
// the third move: ๐=2.
// In the fourth test case, the values ๐0, ๐1 and ๐2 initially equal to each other, so the array ๐ already has balanced remainders.

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