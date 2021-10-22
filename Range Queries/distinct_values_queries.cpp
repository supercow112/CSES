#include <bits/stdc++.h>

using namespace std;

const int MX = 4e5 + 5;

int bit[MX];
int n, q, sol[MX];
vector<pair<int, int>> query[MX];
vector<int> x(MX);
map<int, int> fst;

int qry(int i) {
  int res = 0;
  for (; i; i -= i & (-i)) {
    cout << "qry i: " << i << endl;
    res += bit[i];
  }
  return res;
}

void upd(int i, int val) {
  cout << "start update" << endl;
  for (; i <= n; i += i & (-i)) {
    cout << "upd i: " << i << endl;
    bit[i] += val;
  }
  cout << "end update" << endl;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    query[a].push_back(make_pair(b, i));
  }
  for (int i = n; i >= 1; i--) {
    int z = x[i - 1];
    if (fst.count(z)) {
      upd(fst[z], -1);
      for (int i = 0; i <= n; i++) {
        cout << "bit[" << i << "]: " << bit[i] << endl;
      }
    }
    fst[z] = i;
    upd(i, 1);
    for (int i = 0; i <= n; i++) {
      cout << "bit[" << i << "]: " << bit[i] << endl;
    }
    for (auto t : query[i]) {
      cout << "t first, second: " << t.first << " " << t.second << endl;
      sol[t.second] = qry(t.first);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << sol[i] << '\n';
  }
}