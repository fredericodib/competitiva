// D. Little Girl and Maximum Sum
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// The little girl loves the problems on array queries very much.

// One day she came across a rather well-known problem: you've got an array of n elements (the elements of the array are indexed starting from 1); also, there are q queries, each one is defined by a pair of integers li, ri (1 ≤ li ≤ ri ≤ n). You need to find for each query the sum of elements of the array with indexes from li to ri, inclusive.

// The little girl found the problem rather boring. She decided to reorder the array elements before replying to the queries in a way that makes the sum of query replies maximum possible. Your task is to find the value of this maximum sum.

// Input
// The first line contains two space-separated integers n (1 ≤ n ≤ 2·105) and q (1 ≤ q ≤ 2·105) — the number of elements in the array and the number of queries, correspondingly.

// The next line contains n space-separated integers ai (1 ≤ ai ≤ 2·105) — the array elements.

// Each of the following q lines contains two space-separated integers li and ri (1 ≤ li ≤ ri ≤ n) — the i-th query.

// Output
// In a single line print a single integer — the maximum sum of query replies after the array elements are reordered.

// Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

// Examples
// inputCopy
// 3 3
// 5 3 2
// 1 2
// 2 3
// 1 3
// outputCopy
// 25
// inputCopy
// 5 3
// 5 2 4 1 3
// 1 5
// 2 3
// 2 3
// outputCopy
// 33

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define lli long long int

int main() {
  lli n, q, h = 0;
  vector<lli> v;

  cin >> n >> q;

  for (int i = 0; i < n; i++) {
    lli x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());

  vector<lli> d(n, 0);
  for (int i = 0; i < q; i++) {
    lli l, r;
    cin >> l >> r;
    d[l - 1] += 1;
    if (r < d.size())
      d[r] -= 1;
  }

  for (int i = 1; i < n; i++) {
    d[i] = d[i - 1] + d[i];
  }

  sort(d.begin(), d.end());

  while (d.size() > 0) {
    h += d.back() * v.back();
    d.pop_back();
    v.pop_back();
  }

  cout << h << endl;

  return 0;
}