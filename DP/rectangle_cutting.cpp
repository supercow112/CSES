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

int const MAX = 1e5;
 
void run_case() {
  int a, b;
  cin >> a >> b;

  vector<vector<int>> dp(a + 1, vector<int> (b + 1, MAX));

  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      if (i == j) {
        dp[i][j] = 0;
        continue;
      }
      for (int x = 0; x <= i/2; x++) {
        dp[i][j] = min(dp[i][j], 1 + dp[x][j] + dp[i - x][j]);
      }
      for (int x = 0; x <= j/2; x++) {
        dp[i][j] = min(dp[i][j], 1 + dp[i][j - x] + dp[i][x]);
      }
    }
  }
  cout << dp[a][b] << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}