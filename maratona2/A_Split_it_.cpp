// A. Split it!
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Kawashiro Nitori is a girl who loves competitive programming.

// One day she found a string and an integer. As an advanced problem setter, she quickly thought of a problem.

// Given a string 𝑠 and a parameter 𝑘, you need to check if there exist 𝑘+1 non-empty strings 𝑎1,𝑎2...,𝑎𝑘+1, such that
// 𝑠=𝑎1+𝑎2+…+𝑎𝑘+𝑎𝑘+1+𝑅(𝑎𝑘)+𝑅(𝑎𝑘−1)+…+𝑅(𝑎1).
// Here + represents concatenation. We define 𝑅(𝑥) as a reversed string 𝑥. For example 𝑅(𝑎𝑏𝑐𝑑)=𝑑𝑐𝑏𝑎. Note that in the formula above the part 𝑅(𝑎𝑘+1) is intentionally skipped.

// Input
// The input consists of multiple test cases. The first line contains a single integer 𝑡 (1≤𝑡≤100)  — the number of test cases. The description of the test cases follows.

// The first line of each test case description contains two integers 𝑛, 𝑘 (1≤𝑛≤100, 0≤𝑘≤⌊𝑛2⌋)  — the length of the string 𝑠 and the parameter 𝑘.

// The second line of each test case description contains a single string 𝑠 of length 𝑛, consisting of lowercase English letters.

// Output
// For each test case, print "YES" (without quotes), if it is possible to find 𝑎1,𝑎2,…,𝑎𝑘+1, and "NO" (without quotes) otherwise.

// You can print letters in any case (upper or lower).

// Example
// inputCopy
// 7
// 5 1
// qwqwq
// 2 1
// ab
// 3 1
// ioi
// 4 2
// icpc
// 22 0
// dokidokiliteratureclub
// 19 8
// imteamshanghaialice
// 6 3
// aaaaaa
// outputCopy
// YES
// NO
// YES
// NO
// YES
// NO
// NO
// Note
// In the first test case, one possible solution is 𝑎1=𝑞𝑤 and 𝑎2=𝑞.

// In the third test case, one possible solution is 𝑎1=𝑖 and 𝑎2=𝑜.

// In the fifth test case, one possible solution is 𝑎1=𝑑𝑜𝑘𝑖𝑑𝑜𝑘𝑖𝑙𝑖𝑡𝑒𝑟𝑎𝑡𝑢𝑟𝑒𝑐𝑙𝑢𝑏.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

void solve() {
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;

  if (1 + 2 * k > n) {
    cout << "NO" << endl;
    return;
  }

  
  // if (k % 2 == 0 && n % 2 != 0) {
  //   cout << "NO" << endl;
  //   return;
  // }

  if (k == 0) {
    cout << "YES" << endl;
    return;
  }

  if (n % 2 == 0) {
    cout << "NO" << endl;
    return;
  }

  int u = s.size() - 1;
  int i = 0;
  while (i <= n / 2) {
    if (s[i] != s[u]) {
      cout << "NO" << endl;
      return;
    }
    i++;
    u--;
  }

  cout << "YES" << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}