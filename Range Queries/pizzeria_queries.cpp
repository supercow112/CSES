#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pint pair<int, int>
#define us unordered_set

int const MOD = 1e9 + 7;
int const MAX_N = 1e12;

template <class FWIt> void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  }
  cout << endl;
}

struct Node {
  int left, right, size;

  void build(Node l, Node r) {
    left = min(l.left, r.left + l.size);
    right = min(r.right, l.right + r.size);
    size = l.size + r.size;
  }

  void initLeaf(int x) {
    left = x;
    right = x;
    size = 1;
  }
};

vector<Node> tree;
int base = 1;

void build(vector<int> &a) {
  int n = a.size();
  while (base < n) {
    base *= 2;
  }

  tree.resize(2 * base);

  for (int i = 0; i < 2 * base; i++) {
    tree[i].initLeaf(INT_MAX);
  }

  for (int i = 0; i < n; i++) {
    tree[base + i].initLeaf(a[i]);
  }

  for (int i = base - 1; i > 0; i--) {
    tree[i].build(tree[2 * i], tree[2 * i + 1]);
  }
}

int query(int v, int tl, int tr, int i) {
  if (tl == tr && tl == i) {
    return tree[v].left;
  }

  if (tl <= i && i <= tr) {
    int l, r;
    int tm = (tl + tr) / 2;
    l = query(2 * v, tl, tm, i);
    r = query(2 * v + 1, tm + 1, tr, i);

    return min(l, r);
  } else if (i < tl) {
    return (tl - i) + tree[v].left;
  } else {
    return (i - tr) + tree[v].right;
  }
}

void update(int k, int x) {
  tree[base + k].initLeaf(x);
  int i = (base + k) / 2;
  while (i > 0) {
    tree[i].build(tree[2 * i], tree[2 * i + 1]);
    i /= 2;
  }
}

void run_case(int test_case) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  build(a);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    if (x == 1) {
      int k, x;
      cin >> k >> x;
      update(k - 1, x);
    } else {
      int k;
      cin >> k;
      cout << query(1, 0, base - 1, k - 1) << endl;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}