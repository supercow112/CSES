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
 
void run_case(int test_case) {
  int n;
  cin >> n;

  vector<int> a = {0, 1};

  for (int i = 2; i <= n; i++) {
    int k = 1 << (i - 1);

    for (int j = a.size() - 1; j >= 0; j--) {
      a.push_back(k + a[j]);
    }
  }

  for (auto v : a) {
    bitset<32> res(v);
    string k = res.to_string();
    cout << k.substr(32 - n, n) << endl;
  }




  // cout << "Case #" << test_case << ": " << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // int t;
  // cin >> t;
  // for (int i = 1; i <= t; i++) {
  //   run_case(i);
  // }

  run_case(0);
}