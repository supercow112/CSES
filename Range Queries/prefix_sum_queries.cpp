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

struct Node {
  int nodeSum, maxPrefixSum;

  void build(Node x, Node y) {
    nodeSum = x.nodeSum + y.nodeSum;
    maxPrefixSum = max(x.maxPrefixSum, x.nodeSum + y.maxPrefixSum);
  }

  void initLeaf(int x) {
    nodeSum = x;
    maxPrefixSum = max((int) 0, x);
  }
};

vector<Node> tree;
int base = 1;

void init(vector<int> &a) {
  // build tree off of initial input vector a
  int n = a.size();
  while (base < n) {
    base *= 2;
  }

  tree.resize(2 * base);
  for (int i = 0; i < 2 * base; i++) {
    tree[i].initLeaf(INT_MIN);
  }

  for (int i = 0; i < n; i++) {
    tree[base + i].initLeaf(a[i]);
  }

  for (int i = base - 1; i > 0; i--) {
    tree[i].build(tree[2*i], tree[2*i + 1]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  // cout << "query tl, tr, l, r: " << tl << " " << tr << endl;
  if (l <= tl && tr <= r) {
    cout << "query tl, tr, l, r: " << tl << " " << tr << " " << l << " " << r << " " << tree[v].maxPrefixSum << endl;
    return tree[v].maxPrefixSum;
  } else if (r < tl || tr < l) {
    cout << "query tl, tr, l, r: " << tl << " " << tr << " " << l << " " << r << " " << 0 << endl;
    return 0;
  } else {
    Node left = tree[2*v];
    Node right = tree[2*v + 1];

    int tm = (tl + tr)/2;
    cout << "tm: " << tm << endl;
    int L = query(2*v, tl, tm, l, r);
    int R = query(2*v + 1, tm + 1, tr, l, r);

    cout << "query tl, tr, l, r: " << tl << " " << tr << " " << l << " " << r << " " << max(L, left.nodeSum + R) << endl; 
    return max(L, left.nodeSum + R);
  }
}
 
void update(int k, int u) {
  // update val at position k to u

  tree[base + k].initLeaf(u);
  int i = (base + k)/2;

  while (i > 0) {
    tree[i].build(tree[2*i], tree[2*i + 1]);
    i /= 2;
  }
}

void run_case(int test_case) {
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  init(a);
  cout << query(1, 0, base - 1, 0, base - 1) << endl;
  for (int i = 0; i < q; i++) {
    int x, y, z;
    cin >> x >> y >> z;

    if (x == 1) {
      update(y - 1, z);
    } else {
      cout << "huh: " << y - 1 << " " << z - 1 << endl;
      cout << query(1, 0, base - 1, y - 1, z - 1) << endl;
    }
  }


}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}