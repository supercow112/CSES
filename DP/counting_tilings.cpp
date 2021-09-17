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
#include <bitset>
using namespace std;
 
#define endl "\n"
#define int long long

int const MOD = 1e9 + 7;

typedef pair<int, int> p_int;

template<class FWIt>
void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  } cout << endl;
}

int n, m;
vector<vector<int>> dp;

void helper(int x, int y, int mask, int next_mask) {
  if (x == m) {
    return;
  }
  if (y >= n) {
    dp[x + 1][next_mask] = (dp[x + 1][next_mask] + dp[x][mask]) % MOD;
    return;
  } else {
    int curr_mask = 1 << y;
    if (mask & curr_mask) {
      // 1 -> 0
      helper(x, y + 1, mask, next_mask);
    } else {
      // 0 -> 1
      helper(x, y + 1, mask, next_mask | curr_mask);
      if (y + 2 <= n && ! (mask & (curr_mask << 1))) {
        // 0 -> 0
        helper(x, y + 2, mask, next_mask);
      }
    }
  }

}
 
void run_case() {
  cin >> n >> m;
  dp.resize(m + 1, vector<int> (1 << n, 0));
  dp[0][0] = 1;

  for (int i = 0; i < m; i++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      // mask is current column bitmask representation
      helper(i, 0, mask, 0);
    }
  }

  cout << dp[m][0] << endl;

}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}
