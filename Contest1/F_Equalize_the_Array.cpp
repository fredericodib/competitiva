// F. Equalize the Array
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Polycarp was gifted an array ๐ of length ๐. Polycarp considers an array beautiful if there exists a number ๐ถ, such that each number in the array occurs either zero or ๐ถ times. Polycarp wants to remove some elements from the array ๐ to make it beautiful.

// For example, if ๐=6 and ๐=[1,3,2,1,4,2], then the following options are possible to make the array ๐ array beautiful:

// Polycarp removes elements at positions 2 and 5, array ๐ becomes equal to [1,2,1,2];
// Polycarp removes elements at positions 1 and 6, array ๐ becomes equal to [3,2,1,4];
// Polycarp removes elements at positions 1,2 and 6, array ๐ becomes equal to [2,1,4];
// Help Polycarp determine the minimum number of elements to remove from the array ๐ to make it beautiful.

// Input
// The first line contains one integer ๐ก (1โค๐กโค104) โ the number of test cases. Then ๐ก test cases follow.

// The first line of each test case consists of one integer ๐ (1โค๐โค2โ105) โ the length of the array ๐.

// The second line of each test case contains ๐ integers ๐1,๐2,โฆ,๐๐ (1โค๐๐โค109) โ array ๐.

// It is guaranteed that the sum of ๐ over all test cases does not exceed 2โ105.

// Output
// For each test case, output one integer โ the minimum number of elements that Polycarp has to remove from the array ๐ to make it beautiful.

// Example
// inputCopy
// 3
// 6
// 1 3 2 1 4 2
// 4
// 100 100 4 100
// 8
// 1 2 3 3 3 2 6 6
// outputCopy
// 2
// 1
// 2

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  map<int, int> groupedByCnt;
  for (auto x : cnt) {
    groupedByCnt[x.second]++;
  }

  int res = 99999999;
  for (auto x : groupedByCnt) {
    int rmv = 0;
    int c = x.first;
    for (auto y : groupedByCnt) {
      if (y.first > c) {
        rmv += (y.first - c) * y.second;
      } else if (y.first < c) {
        rmv += y.first * y.second;
      }
    }
    res = min(res, rmv);
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