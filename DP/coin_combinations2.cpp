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
 
int32_t main() {
  int N, T;
  cin >> N >> T;
  int coins[N];

  for (int i = 0; i < N; i++) {
    cin >> coins[i];
  }

  vector<int> dp(T + 1, 0);
  dp[0] = 1;


  for (int i = 0; i < N; i++) {
    for (int j = coins[i]; j <= T; j++) {
      if (coins[i] <= j) {
        dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
      }
    }
  }
  cout << dp[T] << endl;
}