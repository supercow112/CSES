#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define debug_v(x) cout << #x << " = ["; for(auto a : x) cout << a << ", "; cout << "]" << endl;
 
using namespace std;
 
typedef long long ll;
ll INF = 1e18;
ll MOD = 1e9 + 7;
char nl = '\n';
 
int n;
int base = 1;
vector<ll> segmentTree;
 
void buildTree(vector<ll>& nums) {
  while (base < n) { base *= 2; }
  segmentTree.resize(2 * base, 0);
  for (int i = 0; i < n; i++) {
    segmentTree[i + base] = nums[i];
  }
}
 
void update(int rootId, int rootL, int rootR, int l, int r, ll val) {
  if (l <= rootL && rootR <= r) {
    segmentTree[rootId] += val;
    return;
  }
  if (r < rootL || l > rootR) { return; }
  int mid = (rootL + rootR) / 2;
  update(rootId * 2, rootL, mid, l, r, val);
  update(rootId * 2 + 1, mid + 1, rootR, l, r, val);
}
 
ll query(int queryLeafId) {
  ll res = 0;
  for (int idx = queryLeafId + base; idx > 0; idx/=2) {
    res += segmentTree[idx];
  }
  return res;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // freopen("test_input (4).txt", "r", stdin);
 
  int q; cin >> n >> q;
  vector<ll> nums(n);
 
  for (int i = 0; i < n; i++) { cin >> nums[i]; }


  buildTree(nums);
  // cout << "hm: " << query(58579 - 1) << endl;
  for (int i = 0; i < q; i++) {
    int op; cin >> op;
    if (op == 1) {
      int l, r; cin >> l >> r;
      ll toAdd; cin >> toAdd;
      update(1, 0, base - 1, l - 1, r - 1, toAdd);
    } else {
      int node; cin >> node;
      cout << query(node - 1) << nl;
    }
  }
 
  return 0;
}