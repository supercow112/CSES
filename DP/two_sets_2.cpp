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
  int N;
  cin >> N;
 
  int m = N * (N + 1) / 2;
  int l = m / 2;
 
  if (m % 2 == 1) {
    cout << 0 << endl;
    return;
  }
 
  vector<int> dp(l + 1);
 
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    vector<int> new_dp(l + 1, 0);
    for (int j = 0; j < i; j++) {
      new_dp[j] = dp[j];
    }
    for (int j = 0; j + i <= l; j++) {
      new_dp[j + i] = (dp[j + i] + dp[j]) % MOD;
    }
    dp = new_dp;
  }
 
  cout << dp[l] * 500000004 % MOD << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  run_case();
}