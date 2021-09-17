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
  string s;
  cin >> s;

  int n = s.size();
  map<char, int> count;
  for (int i = 0; i < n; i++) {
    count[s[i]] += 1;
  }
  if (n % 2 == 0) {
    for (auto v : count) {
      if (v.second % 2 == 1) {
        cout << "NO SOLUTION" << endl;
        return;
      }
    }

    string res;
    for (auto v : count) {
      res += string (v.second/2, v.first);
    }
    string second_half = res;
    reverse(second_half.begin(), second_half.end());
    res += second_half;

    cout << res << endl;

  } else {
    int odd_count = 0;
    char odd_value;
    for (auto v : count) {
      if (v.second % 2 == 1) {
        odd_count += 1;
        odd_value = v.first;
        if (odd_count > 1) {
          cout << "NO SOLUTION" << endl;
          return;
        }
        odd_count = v.second;
      }
    }

    string first_half;
    for (auto v : count) {
      if (v.second % 2 == 0) {
        first_half += string(v.second/2, v.first);
      }
    }

    string second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    string res = first_half + string(odd_count, odd_value) + second_half;

    cout << res << endl;

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