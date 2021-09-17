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
map<int, int> seen;
 
void run_case() {
  int n;
  cin >> n;

  if (seen[n] != 0) {
    cout << seen[n] << endl;
    return;
  }

  int dp[n + 1][3];

  dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 1;
  for (int i = 1; i < n; i++) {
    dp[i][0] = 3*(dp[i - 1][0] + dp[i - 1][2]) % MOD;
    dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
    dp[i][2] = ((dp[i - 1][1] + dp[i - 1][2]) + (dp[i - 1][0] + dp[i - 1][2])) % MOD;
  }

  dp[n][0] = (dp[n- 1][0] + dp[n - 1][2]) % MOD;
  dp[n][1] = (dp[n - 1][1] + dp[n - 1][2]) % MOD;

  int ans = (dp[n][0] + dp[n][1]) % MOD;
  cout << ans % MOD << endl;
  seen[n] = ans;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    run_case();
  }
}