// A. K-th Largest Value
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given an array 𝑎 consisting of 𝑛 integers. Initially all elements of 𝑎 are either 0 or 1. You need to process 𝑞 queries of two kinds:

// 1 x : Assign to 𝑎𝑥 the value 1−𝑎𝑥.
// 2 k : Print the 𝑘-th largest value of the array.
// As a reminder, 𝑘-th largest value of the array 𝑏 is defined as following:

// Sort the array in the non-increasing order, return 𝑘-th element from it.
// For example, the second largest element in array [0,1,0,1] is 1, as after sorting in non-increasing order it becomes [1,1,0,0], and the second element in this array is equal to 1.

// Input
// The first line contains two integers 𝑛 and 𝑞 (1≤𝑛,𝑞≤105) — the length of the given array and the number of queries.

// The second line contains 𝑛 integers 𝑎1,𝑎2,𝑎3,…,𝑎𝑛 (0≤𝑎𝑖≤1) — elements of the initial array.

// Each of the following 𝑞 lines contains two integers. The first integer is 𝑡 (1≤𝑡≤2) — the type of query.

// If 𝑡=1 the second integer is 𝑥 (1≤𝑥≤𝑛) — the position of the modified number. You have to assign to 𝑎𝑥 the value 1−𝑎𝑥.
// If 𝑡=2 the second integer is 𝑘 (1≤𝑘≤𝑛) — you need to print the 𝑘-th largest value of the array.
// It's guaranteed that there will be at least one query of the second type (satisfying 𝑡=2).

// Output
// For each query of the second type, print a single integer — the answer to the query.

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
// Initially 𝑎=[1,1,0,1,0].

// The first operation is printing the third largest value, which is 1.

// The second operation is assigning 𝑎2 the value 0, 𝑎 becomes [1,0,0,1,0].

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