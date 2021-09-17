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
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define int long long
 
void run_case() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<unordered_set<int>> dp(n + 1);

  for (int i = 0; i < n; i++) {
    dp[i + 1].insert(a[i]);
    for (auto v : dp[i]) {
      dp[i + 1].insert(v);
      dp[i + 1].insert(v + a[i]);
    }
  }

  cout << dp[n].size() << endl;
  vector<int> res;
  for (auto v : dp[n]) {
    res.push_back(v);
  }
  sort(res.begin(), res.end());
  for (auto v : res) {
    cout << v << " ";
  } cout << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}