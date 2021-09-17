#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
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
 
void run_case() {
  string s;
  cin >> s;

  map<char, int> ls = {
    {'A', MAX_N}, 
    {'C', MAX_N}, 
    {'T', MAX_N}, 
    {'G', MAX_N}
  };

  int n = s.size();
  vector<map<char, int>> lsa(n);
  for (int i = n - 1; i >= 0; i--) {
    lsa[i] = ls;
    ls[s[i]] = i;
  }

  string res;
  // is there a faster way to search for the key with the highest value?
  int i = 0;
  while (i < n) {
    int t = 0;
    char v;
    for (auto w : lsa[i]) {
      if (w.second > t) {
        t = w.second;
        v = w.first;
      }
    }
    if (i == 0) {
      if (s[0] == v) res += v;
    }
    res += v;
    i = t;
  }

  cout << res << endl;

  // cout << "Case #" << test_case << ": " << ans << endl;
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