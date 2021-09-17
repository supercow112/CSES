#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define us unordered_set
#define REP(i, a, b) for (int i = a; i <= b; i++)

typedef pair<int, int> p_int;

int const MOD = 1e9 + 7;
int const MAX_N = 1e12;

template<class FWIt>
void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  } cout << endl;
}
 
void run_case() {
  int n, k;
  cin >> n >> k;

  // int dp[n + 1][k + 1];
  // int pr[n + 1][k + 2];
  vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
  vector<int> pr(k + 2, 0);

  dp[1][0] = 1;
  // pr[j] = dp[j - 1] + ... + dp[0]
  pr[0] = 0;
  for (int i = 1; i < k + 2; i++) {
    pr[i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    // 1, 2, ..., i - 1, i
    vector<int> tmp(k + 2, 0);
    for (int j = 0; j <= k; j++) {
      // j inversions on i numbers
      // 0 | j, ..., j | 0
      dp[i][j] = (pr[j + 1] - pr[max(j - i + 1, (int) 0)] + MOD) % MOD;
      tmp[j + 1] = (tmp[j] + dp[i][j]) % MOD;
    }
    pr = tmp;
  }

  cout << dp[n][k] << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}