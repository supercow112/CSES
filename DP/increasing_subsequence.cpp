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

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp;
  for (int i = 0; i < n; i++) {
    int j = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    // cout << j << endl;
    if (j == dp.size()) {
      dp.push_back(a[i]);
    } else {
      dp[j] = a[i];
    }
  }

  cout << dp.size() << endl;
  // for (auto v : dp) {
  //   cout << v << " ";
  // } cout << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}