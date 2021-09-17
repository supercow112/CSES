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
int const MOD = 1e9 + 7;

void run_case() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp(m + 2, 0);
  if (a[0] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[i] = 1;
    }
  } else {
    dp[a[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    vector<int> new_dp(m + 2, 0);
    if (a[i] == 0) {
      for (int j = 1; j <= m; j++) {
        new_dp[j] = (dp[j - 1] + dp[j] + dp[j + 1]) % MOD;
      }
    } else {
      new_dp[a[i]] = (dp[a[i] - 1] + dp[a[i]] + dp[a[i] + 1]) % MOD;
    }
    dp = new_dp;
  }

  int ans = 0;
  for (auto v : dp) {
    ans = (ans + v) % MOD;
  }

  cout << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}