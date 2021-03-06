// A. K-th Largest Value
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given an array ๐ consisting of ๐ integers. Initially all elements of ๐ are either 0 or 1. You need to process ๐ queries of two kinds:

// 1 x : Assign to ๐๐ฅ the value 1โ๐๐ฅ.
// 2 k : Print the ๐-th largest value of the array.
// As a reminder, ๐-th largest value of the array ๐ is defined as following:

// Sort the array in the non-increasing order, return ๐-th element from it.
// For example, the second largest element in array [0,1,0,1] is 1, as after sorting in non-increasing order it becomes [1,1,0,0], and the second element in this array is equal to 1.

// Input
// The first line contains two integers ๐ and ๐ (1โค๐,๐โค105) โ the length of the given array and the number of queries.

// The second line contains ๐ integers ๐1,๐2,๐3,โฆ,๐๐ (0โค๐๐โค1) โ elements of the initial array.

// Each of the following ๐ lines contains two integers. The first integer is ๐ก (1โค๐กโค2) โ the type of query.

// If ๐ก=1 the second integer is ๐ฅ (1โค๐ฅโค๐) โ the position of the modified number. You have to assign to ๐๐ฅ the value 1โ๐๐ฅ.
// If ๐ก=2 the second integer is ๐ (1โค๐โค๐) โ you need to print the ๐-th largest value of the array.
// It's guaranteed that there will be at least one query of the second type (satisfying ๐ก=2).

// Output
// For each query of the second type, print a single integer โ the answer to the query.

// Example
// inputCopy
// 5 5
// 1 1 0 1 0
// 2 3
// 1 2
// 2 3
// 2 1
// 2 5
// outputCopy
// 1
// 0
// 1
// 0
// Note
// Initially ๐=[1,1,0,1,0].

// The first operation is printing the third largest value, which is 1.

// The second operation is assigning ๐2 the value 0, ๐ becomes [1,0,0,1,0].

// The third operation is printing the third largest value, it is 0.

// The fourth operation is printing the first largest value, it is 1.

// The last operation is printing the fifth largest value, it is 0.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
  int n, q;
  cin >> n >> q;
  vi a;
  map<int, int> mapa;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    mapa[x]++;
  }

  for (int i = 0; i < q; i++) {
    int x, k, elem;
    cin >> x >> k;

    if (x == 1) {
      elem = a[k - 1];
      a[k - 1] = 1 - a[k - 1];
      mapa[elem]--;
      mapa[1 - elem]++;
    } else {
      if (k <= mapa[1]) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}