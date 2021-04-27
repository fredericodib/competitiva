// E. Accidental Victory
// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output
// A championship is held in Berland, in which 𝑛 players participate. The player with the number 𝑖 has 𝑎𝑖 (𝑎𝑖≥1) tokens.

// The championship consists of 𝑛−1 games, which are played according to the following rules:

// in each game, two random players with non-zero tokens are selected;
// the player with more tokens is considered the winner of the game (in case of a tie, the winner is chosen randomly);
// the winning player takes all of the loser's tokens;
// The last player with non-zero tokens is the winner of the championship.

// All random decisions that are made during the championship are made equally probable and independently.

// For example, if 𝑛=4, 𝑎=[1,2,4,3], then one of the options for the game (there could be other options) is:

// during the first game, the first and fourth players were selected. The fourth player has more tokens, so he takes the first player's tokens. Now 𝑎=[0,2,4,4];
// during the second game, the fourth and third players were selected. They have the same number of tokens, but in a random way, the third player is the winner. Now 𝑎=[0,2,8,0];
// during the third game, the second and third players were selected. The third player has more tokens, so he takes the second player's tokens. Now 𝑎=[0,0,10,0];
// the third player is declared the winner of the championship.
// Championship winners will receive personalized prizes. Therefore, the judges want to know in advance which players have a chance of winning, i.e have a non-zero probability of winning the championship. You have been asked to find all such players.

// Input
// The first line contains one integer 𝑡 (1≤𝑡≤104) — the number of test cases. Then 𝑡 test cases follow.

// The first line of each test case consists of one positive integer 𝑛 (1≤𝑛≤2⋅105) — the number of players in the championship.

// The second line of each test case contains 𝑛 positive integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎𝑖≤109) — the number of tokens the players have.

// It is guaranteed that the sum of 𝑛 over all test cases does not exceed 2⋅105.

// Output
// For each test case, print the number of players who have a nonzero probability of winning the championship. On the next line print the numbers of these players in increasing order. Players are numbered starting from one in the order in which they appear in the input.

// Example
// inputCopy
// 2
// 4
// 1 2 4 3
// 5
// 1 1 1 1 1
// outputCopy
// 3
// 2 3 4
// 5
// 1 2 3 4 5

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

void solve() {
  int n;

  vector<ll int> players, playersSorted, res;
  cin >> n;
  ll int corte, base, top, mid;

  for (int i = 0; i < n; i++) {
    ll int x;
    cin >> x;
    players.push_back(x);
    playersSorted.push_back(x);
  }

  sort(playersSorted.begin(), playersSorted.end());

  top = n - 1;
  base = 0;
  corte = *playersSorted.rbegin();

  while (base <= top) {
    mid = (base + top) / 2;
    ll int current = playersSorted[mid];

    for (int i = 0; i < n; i++) {
      if (mid != i) {
        if (current >= playersSorted[i]) {
          current += playersSorted[i];
        } else {
          base = mid + 1;
          break;
        }
      }
      if (i == n - 1) {
        corte = playersSorted[mid];
        top = mid - 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (players[i] >= corte) {
      res.push_back(i + 1);
    }
  }

  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
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