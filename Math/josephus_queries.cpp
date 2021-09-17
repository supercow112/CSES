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

// start of the sequence, bool whether we start at start, k (2**k is the jump), query, n
int helper(int s, bool t, int k, int q, int n) {
  int p2 = 1 << k;
  if (q == 1) {
    if (s + p2/2 > n) {
      return s;
    } else {
      return t ? s : s + p2/2;
    }
  }
  int next_start = !t ? s : s + p2/2;
  int start = t ? s : s + p2/2;

  int l = (n - start)/p2;
  
  int a = (n - s)/p2;
  int b = (n - s - p2/2)/p2;
  bool next_t;
  if (a == b) {
    next_t = t;
  } else {
    next_t = !t;
  }

  if (q - 1 > l) {
    return helper(next_start, next_t, k + 1, q - 1 - l, n);
  } else {
    return start + p2 * (q - 1);
  }
}

 
void run_case(int test_case) {
  int n, q;
  cin >> n >> q;

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  cout << helper(1, 0, 1, q, n) << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    run_case(i);
  }
}