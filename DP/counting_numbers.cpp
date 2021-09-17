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

void tester(int a) {
  int ans = 0;
  for (int i = 0; i <= a; i++) {
    string s = to_string(i);
    bool k = true;
    for (int j = 0; j < s.size() - 1; j++) {
      if (s[j] == s[j + 1]) {
        k = false;
        break;
      }
    }
    ans += k;
  }
  cout << "a: " << a << " res: " << ans << endl;
}
 
void run_case() {
  int n, m;
  cin >> n >> m;

  int k = m > 0 ? ceil(log10(m)) + 1 : 2;
  if (n == m) {
    string a = to_string(m);
    for (int i = 0; i < a.size() - 1; i++) {
      if (a[i] == a[i + 1]) {
        cout << 0 << endl;
        return;
      }
    }
    cout << 1 << endl;
    return;
  }


  vector<vector<int>> dp(k + 1, vector<int> (10, 0));
  vector<vector<int>> pr(k + 1, vector<int> (10, 0));
  for (int j = 0; j < 10; j++) {
    dp[1][j] = 1;
    pr[1][j] = ((j > 0 ? pr[1][j - 1] : 0) + dp[1][j]);
  }
  for (int j = 1; j < 10; j++) {
    dp[2][j] = 9;
    pr[2][j] = pr[2][j - 1] + dp[2][j];
  }
  for (int j = 1; j < 10; j++) {
    dp[3][j] = 81;
    pr[3][j] = pr[3][j - 1] + dp[3][j];
  }

  for (int i = 4; i <= k; i++) {
    int t = 0;
    t = (pr[i - 1][9] + pr[i - 2][9]);
    for (int j = 1; j < 10; j++) {
      dp[i][j] += (t - dp[i - 1][j]);
      pr[i][j] = (pr[i][j - 1] + dp[i][j]);
    }
  }

  function<int(int, int)> helper;
  helper = [dp, pr, &helper](int a, int i) {
    string s = to_string(a);
    int ans = 0;
    int L = s.size() - i;
    int k, l;
    if (i > 0) k = s[i - 1] - '0';
    if (i == s.size()) return (long long) 0;

    if (L == 0) {
      return (long long) 0;
    }
    l = s[i] - '0';
    if (L == 1) {
      ans += pr[1][s[i] - '0'];
      if (i > 0 && k <= l) {
        ans -= 1;
      }
      return ans;
    }
    if (l == 0) {
      return helper(a, i + 1);  
    }

    if (i == 0) {
      for (int j = 0; j < L; j++) {
        ans += pr[j][9];
      }
    } else {
      ans += pr[L - 1][9];
      if (L == 2) ans -= 1;
    }
    ans += pr[L][l - 1];
    if (i > 0 && k < l) {
      ans -= dp[L][k];
    }

    if (!(i > 0 && k == l)) ans += helper(a, i + 1);
    return ans;
  };

  cout << helper(m, 0) - (n > 0 ? helper(n - 1, 0) : 0) << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  run_case();
}