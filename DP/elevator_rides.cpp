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
#include <iterator>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
using namespace std;
 
#define endl "\n"
#define int long long

typedef pair<int, int> p_int;

template<class FWIt>
void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  } cout << endl;
}
 
void run_case() {
  int n, w;
  cin >> n >> w;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<pair<int, int>> dp(1e7, make_pair(20, w));
  dp[0] = make_pair(1, 0);

  int p2 = 1;
  for (int i = 0; i < n; i++) {
    p2 *= 2;
  }

  for (int i = 1; i < p2; i++) {
    // binary rep of i represents the subset we are considering
    for (int j = 0; j < n; j++) {
      int pos = 1 << j;
      if ((pos & i) == pos) {
        int c = pos ^ i;
        int x, y;
        x = dp[c].first; y = dp[c].second;

        if (y + a[j] <= w) {
          if (dp[i].first > dp[c].first) {
            dp[i].first = dp[c].first;
            dp[i].second = y + a[j];
          } else if (dp[i].first == dp[c].first) {
            dp[i].second = min(dp[i].second, y + a[j]);
          }
        } else {
          if (dp[i].first > dp[c].first + 1) {
            dp[i].first = dp[c].first + 1;
            dp[i].second = min(a[j], y);
          } else if (dp[i].first == dp[c].first + 1) {
            dp[i].second = min(dp[i].second, min(a[j], y));
          }
        }
      }
    }
  }

  cout << dp[p2 - 1].first << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}