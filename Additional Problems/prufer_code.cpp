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
 
void run_case() {
  int n;
  cin >> n;

  vector<int> a(n - 2);
  unordered_set<int> ip;
  map<int, int> c;
  for (int i = 0; i < n - 2; i++) {
    cin >> a[i];
    ip.insert(a[i]);
    c[a[i]]++;
  }

  // initial leaves
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; i++) {
    if (!ip.count(i)) {
      pq.push(i);
    }
  }

  vector<pair<int, int>> res;
  for (int i = 0; i < n - 2; i++) {
    int x = a[i];
    int y = pq.top();
    pq.pop();

    res.emplace_back(x, y);
    c[a[i]]--;
    if (c[a[i]] == 0) {
      pq.push(a[i]);
    }
  }
  int x = pq.top();
  pq.pop();
  int y = pq.top();
  pq.pop();
  res.emplace_back(x, y);

  for (auto p : res) {
    cout << p.first << " " << p.second << endl;
  }






  

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