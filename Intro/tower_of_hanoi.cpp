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

  vector<pair<int, int>> moves;
  moves.emplace_back(1, 3);

  for (int i = 2; i <= n; i++) {
    vector<pair<int, int>> k;
    // 1) switch every 3, 2 in moves to place stack on pile 2
    // 2) 1 3 to place n to pile 3
    // 3) swap every 1, 2 in moves to move stack 1->n - 1 to pile 3

    for (auto v : moves) {
      int x = v.first; int y = v.second;
      x = (x == 2 ? 3 : (x == 3) ? 2 : 1);
      y = (y == 2 ? 3 : (y == 3) ? 2 : 1);
      k.emplace_back(x, y);
    }

    k.emplace_back(1, 3);

    for (auto v : moves) {
      int x = v.first, y = v.second;
      x = (x == 2 ? 1 : (x == 1) ? 2 : 3);
      y = (y == 2 ? 1 : (y == 1) ? 2 : 3);
      k.emplace_back(x, y);
    }
    moves = k;
  }

  cout << moves.size() << endl;
  for (auto v : moves) {
    cout << v.first << " " << v.second << endl;
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