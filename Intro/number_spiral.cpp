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
  int n, m;
  cin >> n >> m;

  if (max(n, m) % 2 == 0) {
    swap(n, m);
  }

  int k = max(n, m)*max(n, m);
  int l = k - (max(n, m) - 1);

  if (n < m) {
    cout << l + (m - n) << endl;
  } else {
    cout << l - (n - m) << endl;
  }

}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    run_case();
  }

  // run_case();
}