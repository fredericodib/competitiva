// C. Pekora and Trampoline
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// There is a trampoline park with ๐ trampolines in a line. The ๐-th of which has strength ๐๐.

// Pekora can jump on trampolines in multiple passes. She starts the pass by jumping on any trampoline of her choice.

// If at the moment Pekora jumps on trampoline ๐, the trampoline will launch her to position ๐+๐๐, and ๐๐ will become equal to max(๐๐โ1,1). In other words, ๐๐ will decrease by 1, except of the case ๐๐=1, when ๐๐ will remain equal to 1.

// If there is no trampoline in position ๐+๐๐, then this pass is over. Otherwise, Pekora will continue the pass by jumping from the trampoline at position ๐+๐๐ by the same rule as above.

// Pekora can't stop jumping during the pass until she lands at the position larger than ๐ (in which there is no trampoline). Poor Pekora!

// Pekora is a naughty rabbit and wants to ruin the trampoline park by reducing all ๐๐ to 1. What is the minimum number of passes she needs to reduce all ๐๐ to 1?

// Input
// The first line contains a single integer ๐ก (1โค๐กโค500) โ the number of test cases.

// The first line of each test case contains a single integer ๐ (1โค๐โค5000) โ the number of trampolines.

// The second line of each test case contains ๐ integers ๐1,๐2,โฆ,๐๐ (1โค๐๐โค109), where ๐๐ is the strength of the ๐-th trampoline.

// It's guaranteed that the sum of ๐ over all test cases doesn't exceed 5000.

// Output
// For each test case, output a single integer โ the minimum number of passes Pekora needs to do to reduce all ๐๐ to 1.

// Example
// inputCopy
// 3
// 7
// 1 4 2 2 2 2 2
// 2
// 2 3
// 5
// 1 1 1 1 1
// outputCopy
// 4
// 3
// 0
// Note
// For the first test case, here is an optimal series of passes Pekora can take. (The bolded numbers are the positions that Pekora jumps into during these passes.)

// [1,4,2,2,2,2,2]
// [1,4,1,2,1,2,1]
// [1,3,1,2,1,1,1]
// [1,2,1,2,1,1,1]
// For the second test case, the optimal series of passes is show below.

// [2,3]
// [1,3]
// [1,2]
// For the third test case, all ๐๐ are already equal to 1.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

// void solve() {
//   ll int n, res = 0;
//   cin >> n;
//   map<ll int, ll int> remain;

//   for (ll int i = 0; i < n; i++) {
//     ll int x;
//     cin >> x;
//     if (x != 1) {
//       remain[i] = x;
//     }
//   }

//   while (remain.size() > 0) {
//     res++;
//     ll int i, j, x;
//     i = remain.begin()->first;
//     j = remain.rbegin()->first;

//     while (i <= j) {
//       if (remain.count(i)) {
//         x = remain[i];
//         remain[i]--;
//         if (remain[i] == 1) {
//           remain.erase(i);
//         }
//         i += x;
//       } else {
//         auto y = remain.lower_bound(i);
//         i = y->first;
//       }
//     }
//   }

//   cout << res << endl;
// }

void solve() {
  ll int n, res = 0;
  cin >> n;
  map<ll int, ll int> mapa;

  for (ll int i = 0; i < n; i++) {
    ll int x;
    cin >> x;

    ll int y = x - 1 - mapa[i];
    if (y > 0) {
      res += y;
    }
    ll int j = i + 1, ry = 1;
    while (x - 1 > 0) {
      mapa[j] += ry;
      ry++;
      x--;
      j++;
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