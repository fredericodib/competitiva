// C. K-beautiful Strings
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// You are given a string 𝑠 consisting of lowercase English letters and a number 𝑘. Let's call a string consisting of lowercase English letters beautiful if the number of occurrences of each letter in that string is divisible by 𝑘. You are asked to find the lexicographically smallest beautiful string of length 𝑛, which is lexicographically greater or equal to string 𝑠. If such a string does not exist, output −1.

// A string 𝑎 is lexicographically smaller than a string 𝑏 if and only if one of the following holds:

// 𝑎 is a prefix of 𝑏, but 𝑎≠𝑏;
// in the first position where 𝑎 and 𝑏 differ, the string 𝑎 has a letter that appears earlier in the alphabet than the corresponding letter in 𝑏.
// Input
// The first line contains a single integer 𝑇 (1≤𝑇≤10000) — the number of test cases.

// The next 2⋅𝑇 lines contain the description of test cases. The description of each test case consists of two lines.

// The first line of the description contains two integers 𝑛 and 𝑘 (1≤𝑘≤𝑛≤105) — the length of string 𝑠 and number 𝑘 respectively.

// The second line contains string 𝑠 consisting of lowercase English letters.

// It is guaranteed that the sum of 𝑛 over all test cases does not exceed 105.

// Output
// For each test case output in a separate line lexicographically smallest beautiful string of length 𝑛, which is greater or equal to string 𝑠, or −1 if such a string does not exist.

// Example
// inputCopy
// 4
// 4 2
// abcd
// 3 1
// abc
// 4 3
// aaaa
// 9 3
// abaabaaaa
// outputCopy
// acac
// abc
// -1
// abaabaaab
// Note
// In the first test case "acac" is greater than or equal to 𝑠, and each letter appears 2 or 0 times in it, so it is beautiful.

// In the second test case each letter appears 0 or 1 times in 𝑠, so 𝑠 itself is the answer.

// We can show that there is no suitable string in the third test case.

// In the fourth test case each letter appears 0, 3, or 6 times in "abaabaaab". All these integers are divisible by 3.

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

  if ((n % k) != 0) {
    cout << -1 << endl;
    return;
  }
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}