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

vector<int> max_sieve;
vector<int> sieve(int n) {
    vector<int> sieve(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (!sieve[i]) {
            sieve[i] = i;
            for (int j = 1; j <= n/i; j++) {
                sieve[i*j] = i;
            }
        }
    }

    return sieve;
}
 
void run_case(int test_case) {
  int n;
  cin >> n;

  int res = 1;
  while (n > 1) {
    int p = max_sieve[n];
    int e = 0;
    while (n % p == 0) {
      e += 1;
      n /= p;
    }

    res *= (e + 1);
  }

  cout << res << endl;

  // cout << "Case #" << test_case << ": " << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  max_sieve = sieve(1e6 + 10);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    run_case(i);
  }

  // run_case(0);
}