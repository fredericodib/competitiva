// E. Vessels
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// There is a system of n vessels arranged one above the other as shown in the figure below. Assume that the vessels are numbered from 1 to n, in the order from the highest to the lowest, the volume of the i-th vessel is ai liters.

// Initially, all the vessels are empty. In some vessels water is poured. All the water that overflows from the i-th vessel goes to the (i + 1)-th one. The liquid that overflows from the n-th vessel spills on the floor.

// Your task is to simulate pouring water into the vessels. To do this, you will need to handle two types of queries:

// Add xi liters of water to the pi-th vessel;
// Print the number of liters of water in the ki-th vessel.
// When you reply to the second request you can assume that all the water poured up to this point, has already overflown between the vessels.

// Input
// The first line contains integer n — the number of vessels (1 ≤ n ≤ 2·105). The second line contains n integers a1, a2, ..., an — the vessels' capacities (1 ≤ ai ≤ 109). The vessels' capacities do not necessarily increase from the top vessels to the bottom ones (see the second sample). The third line contains integer m — the number of queries (1 ≤ m ≤ 2·105). Each of the next m lines contains the description of one query. The query of the first type is represented as "1 pi xi", the query of the second type is represented as "2 ki" (1 ≤ pi ≤ n, 1 ≤ xi ≤ 109, 1 ≤ ki ≤ n).

// Output
// For each query, print on a single line the number of liters of water in the corresponding vessel.

// Examples
// inputCopy
// 2
// 5 10
// 6
// 1 1 4
// 2 1
// 1 2 5
// 1 1 4
// 2 1
// 2 2
// outputCopy
// 4
// 5
// 8
// inputCopy
// 3
// 5 10 8
// 6
// 1 1 12
// 2 2
// 1 1 6
// 1 3 2
// 2 2
// 2 3
// outputCopy
// 7
// 10
// 5

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n;
  vector<lli> cap;

  cin >> n;

  for (int i = 0; i < n; i++) {
    lli x;
    cin >> x;
    cap.push_back(x);
  }

  return 0;
}