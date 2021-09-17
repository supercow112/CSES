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

vector<vector<char>> grid(8, vector<char> (8));
vector<bool> col(8, false), d(15, false), rd(15, false);
int dfs(int row) {
  // cout << "hm" << endl;
  if (row == 8) {
    return 1;
  }

  int count = 0;
  for (int i = 0; i < 8; i++) {
    if (!col[i] && !d[row - i + 7] && !rd[row + i] && grid[row][i] == '.') {
      d[row - i + 7] = true;
      rd[row + i] = true;
      col[i] = true;
      count += dfs(row + 1);
      d[row - i + 7] = false;
      rd[row + i] = false;
      col[i] = false;
    }
  }

  return count;
}


 
void run_case(int test_case) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> grid[i][j];
    }
  }
  
  cout << dfs(0) << endl;

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