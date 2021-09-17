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
 
void run_case() {
  int n;
  cin >> n;

  int dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;

  for (int i = 2; i <= n; i++) {
    string t = to_string(i);

    int ans = i;
    for (auto v : t) {
      int j = v - '0';
      if (j == 0) continue;
      ans = min(ans, dp[i- j]);
    }
    dp[i] = ans + 1;
  }

  cout << dp[n] << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  run_case();
}