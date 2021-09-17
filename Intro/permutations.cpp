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

  if (n <= 4 || n == 6) {
    if (n == 2 || n == 3) {
      cout << "NO SOLUTION" << endl;
    } else if (n == 1) {
      cout << 1 << endl;
    } else if (n == 6) {
      cout << "1 5 3 6 4 2" << endl;
    } else {
      cout << "2 4 1 3" << endl;
    }
    return;
  }

  for (int i = 2; i < n - 1; i++) {
    if (__gcd(i, n) == 1) {
      for (int j = 0; j < n; j++) {
        int k = (1 + i*j) % n;
        cout << (k ? k : n) << " ";
      }
      return;
    }
  }
  cout << "NO SOLUTION" << endl;
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