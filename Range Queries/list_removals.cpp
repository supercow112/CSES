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
vector<int> a;

// tree contains the number of elements in the segment
int base = 1;
void init(int v, int tl, int tr) {
  tree[v] = tr - tl + 1;
  if (tl == tr) return;
  int tm = (tl + tr)/2;
  init(2*v + 1, tl, tm);
  init(2*v + 2, tm + 1, tr);
}

int query(int v, int tl, int tr, int i) {
  // want to find the ith element available in the segment tl, tr
  // base case, we are guaranteed that the ith element in contained here
  tree[v]--;
  if (tl == tr) {
    return a[tl];
  }

  int x = tree[2*v + 1];
  int y = tree[2*v + 2];

  int tm = (tl + tr)/2;
  if (x >= i) {
    return query(2*v + 1, tl, tm, i);
  } else {
    return query(2*v + 2, tm + 1, tr, i - x);
  }
}

void run_case(int test_case) {
  int n;
  cin >> n;
  a.resize(n);
  tree.resize(4*n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  init(0, 0, n - 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    cout << query(0, 0, n - 1, x) << " ";
  }
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case(0);
}