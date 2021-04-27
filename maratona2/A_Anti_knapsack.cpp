// A. Anti-knapsack
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given two integers 𝑛 and 𝑘. You are asked to choose maximum number of distinct integers from 1 to 𝑛 so that there is not subset of chosen numbers with sum equal to 𝑘.

// A subset of a set is a set that can be obtained from initial one by removing some (possibly all or none) elements of it.

// Input
// The first line contains the number of test cases 𝑇 (1≤𝑇≤100).

// Each of the next 𝑇 lines contains two integers 𝑛 and 𝑘 (1≤𝑘≤𝑛≤1000) — the description of test cases.

// Output
// For each test case output two lines. In the first line output a single integer 𝑚 — the number of chosen integers.

// In the second line output 𝑚 distinct integers from 1 to 𝑛 — the chosen numbers.

// Example
// inputCopy
// 3
// 3 2
// 5 3
// 1 1
// outputCopy
// 2
// 3 1
// 3
// 4 5 2
// 0

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

void solve() {
  int n, k;
  vi res;
  map<int, bool> mapa;
  cin >> n >> k;

  for (int i = k + 1; i <= n; i++) {
    res.push_back(i);
  }

  for (int i = k - 1; i > 0; i--) {
    if (!mapa.count(k - i)) {
      res.push_back(i);
      mapa[i] = true;
    }
  }

  cout << res.size() << endl;
  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}