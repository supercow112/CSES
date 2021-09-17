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
  int n, x;
  cin >> n >> x;

  vector<int> cost, page;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    cost.push_back(v);
  }

  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    page.push_back(v);
  }

  vector<int> dp(x + 1);
  for (int i = 0; i < n; i++) {
    for (int c = cost[i]; c <= x; c++) {
      dp[c] = max(dp[c], dp[c - cost[i]] + page[i]);
    }
  }

  cout << dp[x] << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}