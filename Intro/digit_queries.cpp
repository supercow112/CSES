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

  map<int, int> start = {
    {0, 0}, 
    {10, 10}
  };
  int pt = 1;
  for (int i = 2; i < 18; i++) {
    pt *= 10;
    int v = start.rbegin()->first;
    start[v + 9 * pt * i] = pt*10;
  }

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    int prev = 0;
    int val = 0;
    int d = 0;
    for (auto v : start) {
      if (v.first > k) {
        break;
      }
      d += 1;
      prev = v.first;
      val = v.second;
    }

    int q = k - prev;
    string t = to_string(val + q/d);
    int ind = k - (prev + (q/d) * d);

    cout << t[ind] << endl;
  }
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}