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

typedef pair<int, int> p_int;
 
void run_case() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  vector<vector<p_int>> dp(n + 1, vector<p_int> (n + 1, make_pair(0, 0)));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < n - i + 1; j++) {
      if (i == 1) {
        dp[i][j].first = a[j];
        continue;
      }
      int x1, y1, x2, y2;
      p_int p1 = dp[i - 1][j + 1];
      p_int p2 = dp[i - 1][j];

      x1 = p1.first;
      y1 = p1.second;
      x2 = p2.first;
      y2 = p2.second;

      if (a[j] + y1 > a[j + i - 1] + y2) {
        dp[i][j] = make_pair(a[j] + y1, x1);
      } else {
        dp[i][j] = make_pair(a[j + i - 1] + y2, x2);
      }
    }
  }
  cout << dp[n][0].first << endl; 
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // int t;
  // cin >> t;
  // for (int i = 0; i < t; i++) {
  //   run_case();
  // }

  run_case();
}