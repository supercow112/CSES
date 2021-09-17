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

int binary_exp(int base, int exp, int p = 0) { 
    int res = 1;
    while (exp > 0) {
        if (exp & 1) { 
            res *= base;
            if (p) res %= p;
        }
        base = base*base;
        if (p) base %= p;
        exp >>= 1;
    }
    return res;
}
 
void run_case(int test_case) {
  int a, b, c;
  cin >> a >> b >> c;

  cout << binary_exp(a, binary_exp(b, c, MOD - 1), MOD) << endl;


  // cout << "Case #" << test_case << ": " << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    run_case(i);
  }

  // run_case(0);
}