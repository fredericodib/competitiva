// A. Dense Array
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Polycarp calls an array dense if the greater of any two adjacent elements is not more than twice bigger than the smaller. More formally, for any ๐ (1โค๐โค๐โ1), this condition must be satisfied:
// max(๐[๐],๐[๐+1])min(๐[๐],๐[๐+1])โค2
// For example, the arrays [1,2,3,4,3], [1,1,1] and [5,10] are dense. And the arrays [5,11], [1,4,2], [6,6,1] are not dense.

// You are given an array ๐ of ๐ integers. What is the minimum number of numbers you need to add to an array to make it dense? You can insert numbers anywhere in the array. If the array is already dense, no numbers need to be added.

// For example, if ๐=[4,2,10,1], then the answer is 5, and the array itself after inserting elements into it may look like this: ๐=[4,2,3โฏโฏ,5โฏโฏ,10,6โฏโฏ,4โฏโฏ,2โฏโฏ,1] (there are other ways to build such ๐).

// Input
// The first line contains one integer ๐ก (1โค๐กโค1000). Then ๐ก test cases follow.

// The first line of each test case contains one integer ๐ (2โค๐โค50) โ the length of the array ๐.

// The next line contains ๐ integers ๐1,๐2,โฆ,๐๐ (1โค๐๐โค50).

// Output
// For each test case, output one integer โ the minimum number of numbers that must be added to the array to make it dense.

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

// In the second test case, you can insert one element, ๐=[1,2โฏโฏ,3].

// In the third test case, you can insert two elements, ๐=[6,4โฏโฏ,2โฏโฏ,1].

// In the fourth test case, you can insert one element, ๐=[1,2โฏโฏ,4,2].

// In the fifth test case, the array ๐ is already dense.

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