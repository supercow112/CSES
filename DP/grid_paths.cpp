#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
#define endl "\n"
#define int long long

int const MOD = 1e9 + 7;
 
void run_case() {
  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char> (n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> dp(n, vector<int> (n, 0));
  if (grid[0][0] != '*') dp[0][0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '*') continue;
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
      dp[i][j] %= MOD;
    }
  }

  cout << dp[n - 1][n - 1] << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // for (int i = 0; i < t; i++) {
  //   run_case();
  // }

  run_case();
}