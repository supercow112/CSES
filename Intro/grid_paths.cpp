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
bool tr(int x, int a, int b) {	
  return (a <= x && x < b ? 1 : 0);	
}	
string s;	
bool seen[7][7];	
int dix[4] = {-1, 0, 1, 0};	
int diy[4] = {0, 1, 0, -1};	
int dfs(int pos, int i, int j) {	
  if (pos == 48) {	
    return (i == 6 && j == 0);	
  }	
  if (i == 6 && j == 0) {	
    return 0;	
  }	
  if (seen[i][j]) {	
    return 0;	
  }	
  vector<bool> v(4, -1);	
  for (int k = 0; k < 4; k++) {	
    if (tr(i + dix[k], 0, 7) && tr(j + diy[k], 0, 7)) {	
      v[k] = seen[i + dix[k]][j + diy[k]];	
    }	
  }	
  if (v[0] && v[2] && !v[1] && !v[3]) {	
    return 0;	
  }	
  if (!v[0] && !v[2] && v[1] && v[3]) {	
    return 0;	
  }	
  if (tr(i - 1, 0, 7) && tr(j + 1, 0, 7) && seen[i - 1][j + 1]) {	
    if (!v[0] && !v[1]) return 0;	
  }	
  if (tr(i - 1, 0, 7) && tr(j - 1, 0, 7) && seen[i - 1][j - 1]) {	
    if (!v[0] && !v[3]) return 0;	
  }	
  if (tr(i + 1, 0, 7) && tr(j - 1, 0, 7) && seen[i + 1][j - 1]) {	
    if (!v[2] && !v[3]) return 0;	
  }	
  if (tr(i + 1, 0, 7) && tr(j + 1, 0, 7) && seen[i + 1][j + 1]) {	
    if (!v[1] && !v[2]) return 0;	
  }	
 	
  seen[i][j] = true;	
  int count = 0;	
  if ((s[pos] == 'U' || s[pos] == '?')) {	
    if (tr(i - 1, 0, 7) && tr(j, 0, 7) && !seen[i - 1][j]) {	
      count += dfs(pos + 1, i - 1, j);	
    }	
  }	
  if ((s[pos] == 'R' || s[pos] == '?')) {	
    if (tr(i, 0, 7) && tr(j + 1, 0, 7) && !seen[i][j + 1]) {	
      count += dfs(pos + 1, i, j + 1);	
    }	
  }	
  if ((s[pos] == 'D' || s[pos] == '?')) {	
    if (tr(i + 1, 0, 7) && tr(j, 0, 7) && !seen[i + 1][j]) {	
      count += dfs(pos + 1, i + 1, j);	
    }	
  }	
  if ((s[pos] == 'L' || s[pos] == '?')) {	
    if (tr(i, 0, 7) && tr(j - 1, 0, 7) && !seen[i][j - 1]) {	
      count += dfs(pos + 1, i, j - 1);	
    }	
  }	
  seen[i][j] = false;	
  return count;	
}	
 	
void run_case(int test_case) {	
  cin >> s;	
  memset(seen, false, sizeof(seen));	
  cout << dfs(0, 0, 0) << endl;	
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
