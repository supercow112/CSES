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

  if (n*(n + 1) % 4 != 0) {
    cout << "NO" << endl;
    return;
  } else {
    int t = n*(n + 1)/4;  

    vector<int> fh;
    unordered_set<int> fh_set;

    int cur = n;
    while (t >= cur) {
      fh_set.insert(cur);

      t -= cur;
      cur -= 1;
    }
    if (t) fh_set.insert(t);

    cout << "YES" << endl;
    cout << fh_set.size() << endl;
    for (auto v : fh_set) {
      cout << v << " ";
    } cout << endl;
    
    cout << n - fh_set.size() << endl;
    for (int i = 1; i <= n; i++) {
      if (!fh_set.count(i)) {
        cout << i << " ";
      }
    } cout << endl;
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