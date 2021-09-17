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

template<class FWIt>
void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  } cout << endl;
}
 
void run_case() {
  int n;
  cin >> n;

  vector<vector<int>> a;
  int L = 1e9, R = 1;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    L = min(L, x);
    R = max(R, y);
    vector<int> b = {x, y, z};
    a.push_back(b);
  }

  sort(a.begin(), a.end(), [] (vector<int> x, vector<int> y) {
    if (x[1] < y[1]) {
      return true;
    } else if (x[1] > y[1]) {
      return false;
    } else {
      return x[2] > y[2];
    }
  });

  vector<int> r(n);
  for (int i = 0; i < n; i++) {
    r[i] = a[i][1];
  }

  vector<int> dp(n + 1, 0);
  dp[1] = a[0][2];

  for (int i = 1; i < n; i++) {
    int j = lower_bound(r.begin(), r.begin() + i, a[i][0]) - r.begin();
    dp[i + 1] = max(dp[j] + a[i][2], dp[i]);
  }

  cout << dp[n] << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}