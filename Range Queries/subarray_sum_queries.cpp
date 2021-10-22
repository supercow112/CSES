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
  int leftSum, midSum, rightSum, nodeSum;

  int res() { return max({leftSum, midSum, rightSum}); }

  void build(Node left, Node right) {
    leftSum = max(left.leftSum, left.nodeSum + right.leftSum);
    rightSum = max(right.rightSum, right.nodeSum + left.rightSum);
    midSum = max({left.rightSum + right.leftSum, left.midSum, right.midSum});
    nodeSum = left.nodeSum + right.nodeSum;
  }

  void initLeaf(int x) {
    leftSum = rightSum = midSum = max((int)0, x);
    nodeSum = x;
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

void update(int k, int x) {
  // update position k to value x

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

  init(a);
  for (int i = 0; i < q; i++) {
    int k, x;
    cin >> k >> x;
    update(k - 1, x);

    cout << tree[1].res() << endl;
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}