// A. Dense Array
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Polycarp calls an array dense if the greater of any two adjacent elements is not more than twice bigger than the smaller. More formally, for any 𝑖 (1≤𝑖≤𝑛−1), this condition must be satisfied:
// max(𝑎[𝑖],𝑎[𝑖+1])min(𝑎[𝑖],𝑎[𝑖+1])≤2
// For example, the arrays [1,2,3,4,3], [1,1,1] and [5,10] are dense. And the arrays [5,11], [1,4,2], [6,6,1] are not dense.

// You are given an array 𝑎 of 𝑛 integers. What is the minimum number of numbers you need to add to an array to make it dense? You can insert numbers anywhere in the array. If the array is already dense, no numbers need to be added.

// For example, if 𝑎=[4,2,10,1], then the answer is 5, and the array itself after inserting elements into it may look like this: 𝑎=[4,2,3⎯⎯,5⎯⎯,10,6⎯⎯,4⎯⎯,2⎯⎯,1] (there are other ways to build such 𝑎).

// Input
// The first line contains one integer 𝑡 (1≤𝑡≤1000). Then 𝑡 test cases follow.

// The first line of each test case contains one integer 𝑛 (2≤𝑛≤50) — the length of the array 𝑎.

// The next line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤50).

// Output
// For each test case, output one integer — the minimum number of numbers that must be added to the array to make it dense.

// Example
// inputCopy
// 6
// 4
// 4 2 10 1
// 2
// 1 3
// 2
// 6 1
// 3
// 1 4 2
// 5
// 1 2 3 4 3
// 12
// 4 31 25 50 30 20 34 46 42 16 15 16
// outputCopy
// 5
// 1
// 2
// 1
// 0
// 3
// Note
// The first test case is explained in the statements.

// In the second test case, you can insert one element, 𝑎=[1,2⎯⎯,3].

// In the third test case, you can insert two elements, 𝑎=[6,4⎯⎯,2⎯⎯,1].

// In the fourth test case, you can insert one element, 𝑎=[1,2⎯⎯,4,2].

// In the fifth test case, the array 𝑎 is already dense.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int test(vi vec) {
  int add = 0, first, sec, i, j;

  first = vec[0];

  for (i = 1; i < vec.size(); i++) {
    sec = vec[i];

    while (((float)max(first, sec) / (float)(min(first, sec))) > 2) {
      if (sec > first) {
        add++;
        first = first * 2;
      } else {
        add++;
        first = ceil((float)first / 2);
      }
    }

    first = sec;
  }

  return add;
}

int main() {
  int t, i, n, j, x;
  vi vec;
  cin >> t;

  for (i = 0; i < t; i++) {
    cin >> n;
    for (j = 0; j < n; j++) {
      cin >> x;
      vec.push_back(x);
    }
    cout << test(vec) << endl;
    vec.clear();
  }

  return 0;
}