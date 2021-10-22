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
  int nodeSum, maxPrefixSum;

  void build(Node x, Node y) {
    nodeSum = x.nodeSum + y.nodeSum;
    maxPrefixSum = max(x.maxPrefixSum, x.nodeSum + y.maxPrefixSum);
  }

  void initLeaf(int x) {
    nodeSum = x;
    maxPrefixSum = max((int)0, x);
  }
};

vector<Node> tree;
int base = 1;

void init(vector<int> &a) {
  int n = a.size();
  while (base < n) {
    base *= 2;
  }

  tree.resize(2 * base);
  for (int i = 0; i < 2 * base; i++) {
    tree[i].initLeaf(0);
  }

  for (int i = 0; i < n; i++) {
    tree[base + i].initLeaf(a[i]);
  }

  for (int i = base - 1; i > 0; i--) {
    tree[i].build(tree[2 * i], tree[2 * i + 1]);
  }
}

// Node query(int v, int tl, int tr, int l, int r) {
//   Node res;
//   if (l == tl && r == tr) {
//     res.nodeSum = tree[v].nodeSum;
//     res.maxPrefixSum = tree[v].maxPrefixSum;
//   } else if (r < tl || tr < l) {
//     res.nodeSum = 0;
//     res.maxPrefixSum = 0;
//   } else {
//     int tm = (tl + tr) / 2;
//     Node left = query(2 * v, tl, tm, l, min(r, tm));
//     Node right = query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);

//     res.nodeSum = left.nodeSum + right.nodeSum;
//     res.maxPrefixSum =
//         max(left.maxPrefixSum, left.nodeSum + right.maxPrefixSum);
//   }

//   return res;
// }

int query(int a, int b) {
  a += base;
  b += base;

  Node l = tree[a];
  Node r = tree[b];
  if (a == b) {
    return l.maxPrefixSum;
  }
  while (a + 1 < b) {
    // cout << "l, r: " << l.maxPrefixSum << " " << r.maxPrefixSum << endl;
    // cout << "a, b: " << a << " " << b << endl;
    Node left, right;
    if (a % 2 == 0)
      l.build(l, tree[a + 1]);
    if (b % 2 == 1)
      r.build(tree[b - 1], r);

    // l = left;
    // r = right;
    a /= 2;
    b /= 2;
  }

  Node res;
  res.build(l, r);
  return res.maxPrefixSum;
}

void update(int k, int u) {
  tree[base + k].initLeaf(u);
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

  init(a);
  for (int i = 0; i < q; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 1) {
      update(y - 1, z);
    } else {
      cout << query(y - 1, z - 1) << endl;
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}