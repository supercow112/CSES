#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
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
  int n;
  cin >> n;
  // answers the question in range [1, a)
  function<int(int)> helper;
  helper = [&helper](int a) {
    int k = log2(a);
    int p2 = 1;
    for (int i = 0; i < k; i++) {
      p2 *= 2;
    }
    if (k == log2(a)) {
      return k * p2/2;
    } else {
      return k * p2/2 + (a - p2) + helper(a - p2);
    }
  };

  int ans = helper(n + 1);

  cout << ans << endl;

  // cout << "Case #" << test_case << ": " << ans << endl;
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