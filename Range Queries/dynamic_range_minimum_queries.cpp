#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define pint pair<int, int>
#define us unordered_set

int const MOD = 1e9 + 7;
int const MAX_N = 1e12;

vector<int> tree;
vector<int> order;

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = order[tl];
  } else {
    int tm = (tl + tr)/2;
    build(2*v + 1, tl, tm);
    build(2*v + 2, tm + 1, tr);
    tree[v] = min(tree[2*v + 1], tree[2*v + 2]);
  }
}

int get_min(int v, int tl, int tr, int l, int r) {
  if (l > r) return MAX_N;
  if (l == tl && tr == r) {
    return tree[v];
  } else {
    int tm = (tl + tr)/2;
    return min(get_min(2*v + 1, tl, tm, l, min(r, tm)), 
    get_min(2*v + 2, tm + 1, tr, max(tm + 1, l), r));
  }
}

void update_min(int v, int tl, int tr, int i, int x) {
  if (tl == tr && tl == i) {
    tree[v] = x;
  } else if (tl <= i && i <= tr) {
    int tm = (tl + tr)/2;

    if (x > tree[v]) {
      int e, f;
      e = get_min(v, tl, tr, tl, i - 1);
      f = get_min(v, tl, tr, i + 1, tr);
      tree[v] = min({e, f, x});
    } else {
      tree[v] = x;
    }

    update_min(2*v + 1, tl, tm, i, x);
    update_min(2*v + 2, tm + 1, tr, i, x);
  }
}
 
void run_case(int test_case) {
  int n, q;
  cin >> n >> q;

  order.resize(n);
  tree.resize(4*n);

  for (int i = 0; i < n; i++) {
    cin >> order[i];
  }

  build(0, 0, n - 1);

  while (q--) {
    int x, y, z;
    cin >> x >> y >> z;
    
    if (x == 1) {
      y--;
      update_min(0, 0, n - 1, y, z);
      order[y] = z;
    } else {
      y--; z--;
      cout << get_min(0, 0, n - 1, y, z) << endl;
    }
  }
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}
