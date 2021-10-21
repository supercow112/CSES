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

template<class T>
T F(T a, T b) {
  return max(a, b);
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
    tree[v] = F(tree[2*v + 1], tree[2*v + 2]);
  }
}

// query to find the earliest value that is at least as p
int query(int v, int tl, int tr, int p) {
  if (tl == tr) {
    return tree[v] >= p ? tl : -1;
  } else {
    int tm = (tl + tr)/2;
    int x = tree[2*v + 1];
    int y = tree[2*v + 2];

    if (x >= p) {
      return query(2*v + 1, tl, tm, p);
    } else {
      return query(2*v + 2, tm + 1, tr, p);
    }
  }
}

void update(int v, int tl, int tr, int i, int x) {
  if (tl == tr && tl == i) {
    tree[v] = x;
    return;
  } else if (tl <= i && i <= tr) {
    int tm = (tl + tr)/2;
    update(2*v + 1, tl, tm, i, x);
    update(2*v + 2, tm + 1, tr, i, x);
    tree[v] = F(tree[2*v + 1], tree[2*v + 2]);
  }
}

void print_tree(int v, int tl, int tr) {
  cout << "v: " << v << " [" << tl << ", " << tr << "]: " << tree[v] << endl;
  int tm = (tl + tr)/2;
  if (tl == tr) return;
  print_tree(2*v + 1, tl, tm);
  print_tree(2*v + 2, tm + 1, tr);
}

void run_case(int test_case) {
  int n, m;
  cin >> n >> m;

  order.resize(n);
  tree.resize(4*n);
  vector<int> q(m);

  for (int i = 0; i < n; i++) {
    cin >> order[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> q[i];
  }

  build(0, 0, n - 1);
  for (int i = 0; i < m; i++) {
    int t = query(0, 0, n - 1, q[i]);
    cout << t + 1 << " ";
    if (t > -1) {
      update(0, 0, n - 1, t, order[t] - q[i]);
      order[t] -= q[i];
    }

  }

}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}