// A. Split it!
// time limit per test1 second
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// Kawashiro Nitori is a girl who loves competitive programming.

// One day she found a string and an integer. As an advanced problem setter, she quickly thought of a problem.

// Given a string ๐  and a parameter ๐, you need to check if there exist ๐+1 non-empty strings ๐1,๐2...,๐๐+1, such that
// ๐ =๐1+๐2+โฆ+๐๐+๐๐+1+๐(๐๐)+๐(๐๐โ1)+โฆ+๐(๐1).
// Here + represents concatenation. We define ๐(๐ฅ) as a reversed string ๐ฅ. For example ๐(๐๐๐๐)=๐๐๐๐. Note that in the formula above the part ๐(๐๐+1) is intentionally skipped.

// Input
// The input consists of multiple test cases. The first line contains a single integer ๐ก (1โค๐กโค100)  โ the number of test cases. The description of the test cases follows.

// The first line of each test case description contains two integers ๐, ๐ (1โค๐โค100, 0โค๐โคโ๐2โ)  โ the length of the string ๐  and the parameter ๐.

// The second line of each test case description contains a single string ๐  of length ๐, consisting of lowercase English letters.

// Output
// For each test case, print "YES" (without quotes), if it is possible to find ๐1,๐2,โฆ,๐๐+1, and "NO" (without quotes) otherwise.

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
// In the first test case, one possible solution is ๐1=๐๐ค and ๐2=๐.

// In the third test case, one possible solution is ๐1=๐ and ๐2=๐.

// In the fifth test case, one possible solution is ๐1=๐๐๐๐๐๐๐๐๐๐๐ก๐๐๐๐ก๐ข๐๐๐๐๐ข๐.

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