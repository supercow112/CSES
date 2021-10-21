#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define pint pair<int, int>
#define us unordered_set

int const MOD = 1e9 + 7;
int const MAX_N = 1e12;

template<class FWIt>
void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  } cout << endl;
}

vector<int> tree;
vector<int> order;

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = order[tl];
  } else {
    int tm = (tl + tr)/2;
    build(2*v + 1, tl, tm);
    build(2*v + 2, tm + 1, tr);
    tree[v] = tree[2*v + 1] + tree[2*v + 2];
  }
}

int get_sum(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && tr == r) {
    return tree[v];
  } else {
    int tm = (tl + tr)/2;
    return get_sum(2*v + 1, tl, tm, l, min(r, tm)) + 
    get_sum(2*v + 2, tm + 1, tr, max(tm + 1, l), r);
  }
}

void update_sum(int v, int tl, int tr, int i, int x) {
  if (tl == tr && tl == i) {
    tree[v] += x - order[i];
  } else if (tl <= i && i <= tr) {
    tree[v] += x - order[i];
    int tm = (tl + tr)/2;
    update_sum(2*v + 1, tl, tm, i, x);
    update_sum(2*v + 2, tm + 1, tr, i, x);
  }
}

void run_case(int test_case) {
  int n, q;
  cin >> n >> q;
  
  order.resize(n + 1, 0);
  tree.resize(4*n);
  vector<int> values(n);

  for (int i = 0; i < n; i++) {
    cin >> values[i];
  }

  build(0, 0, n - 1);

  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int y, z, u;
      cin >> y >> z >> u;

      update_sum(0, 0, n - 1, y - 1, u);
      update_sum(0, 0, n - 1, z, -u);

    } else {
      int y;
      cin >> y;
 
      cout << get_sum(0, 0, n - 1, 0, y - 1) + values[y - 1] << endl;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}