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

typedef pair<int, int> p_int;

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


  for (int i = 1; i <= n; i++) {
    int ans = 0;
    if (i >= 5) {
      ans += (i*i - 4)*4*(i - 4);
      ans += (i*i - 8)*(i - 4)*(i - 4);
      ans += 4*(4*i*i - 12);
      cout << ans << endl;
    }
  }
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