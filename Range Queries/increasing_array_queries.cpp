#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pint pair<int, int>
#define us unordered_set

int const MOD = 1e9 + 7;
int const MAX_N = 4e5 + 10;
int const INF = 1e18;

template <class FWIt> void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  }
  cout << endl;
}

int n, q;
vector<int> bit(MAX_N, 0), x(MAX_N), sol(MAX_N), pref(MAX_N, 0),
    contrib(MAX_N, 0);
vector<vector<pair<int, int>>> bk(MAX_N);

void update(int i, int val) {
  for (; i <= n; i += (i & -i)) {
    bit[i] += val;
  }
}

int query(int j) {
  int res = 0;
  for (; j; j -= (j & -j)) {
    res += bit[j];
  }

  return res;
}

void run_case(int test_case) {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    pref[i] = pref[i - 1] + x[i];
  }

  for (int i = 1; i <= q; i++) {
    int a, b;
    cin >> a >> b;
    bk[a].push_back({b, i});
  }

  x[n + 1] = INF;
  pref[n + 1] = pref[n] + INF;
  deque<int> stk = {n + 1};

  for (int i = n; i > 0; i--) {
    while (!stk.empty() && x[i] >= x[stk.front()]) {
      update(stk.front(), -contrib[stk.front()]);
      stk.pop_front();
    }
    contrib[i] =
        (stk.front() - i - 1) * x[i] - (pref[stk.front() - 1] - pref[i]);
    stk.push_front(i);
    update(i, contrib[i]);

    for (auto j : bk[i]) {
      int pos = upper_bound(stk.begin(), stk.end(), j.first) - stk.begin() - 1;
      int res = (pos ? query(stk[pos - 1]) : 0) +
                (j.first - stk[pos]) * x[stk[pos]] -
                (pref[j.first] - pref[stk[pos]]);
      sol[j.second] = res;
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << sol[i] << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}