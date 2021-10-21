#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define pint pair<int, int>
#define us unordered_set

int const MOD = 1e9 + 7;
int const MAX_N  = 1e9 + 5;

template<class FWIt>
void print_array(FWIt a, FWIt b) {
  while (a != b) {
    cout << *a << " ";
    a++;
  } cout << endl;
}

template<class T>
T F(T a, T b) {
  return a + b;
}

vector<int> tree;
vector<int> order;

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = 1;
  } else {
    int tm = (tl + tr)/2;
    build(2*v + 1, tl, tm);
    build(2*v + 2, tm + 1, tr);
    tree[v] = F(tree[2*v + 1], tree[2*v + 2]);
  }
}

int query(int v, int tl, int tr, int l, int r) {
  int res = 0;
  if (l <= tl && tr <= r) {
    res += tree[v];
    return;
  }
  
  if (tr < l || r < tl) return;

  int tm = (tl + tr)/2;
  res += query(2*v + 1, tl, tm, l, r);
  res += query(2*v + 2, tm + 1, tr, l, r);
}

// 
void update(int v, int tl, int tr, int i, int x) {
  if (tl == tr && tl == i) {
    tree[v]--;
    tree[i]
  } else if (tl <= i && i <= tr) {
    tree[v] += x - order[i];
    int tm = (tl + tr)/2;
    update(2*v + 1, tl, tm, i, x);
    update(2*v + 2, tm + 1, tr, i, x);
  }
}

void run_case(int test_case) {
  tree.resize(4 * MAX_N);
  order.resize(MAX_N, 0);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    order[x]++;
  }

  while (q--) {
    string x;
    int y, z;
    cin >> x >> y >> z;

    if (x == "?") {

    } else {

    }
  }



}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}