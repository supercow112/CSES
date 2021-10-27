#include <bits/stdc++.h>
using namespace std;

int bit[1001][1001];
int n;

void update(int x, int y, int val) {
  for (int i = x; i <= n; i += (i & -i)) {
    for (int j = y; j <= n; j += (j & -j)) {
      bit[i][j] += val;
    }
  }
}

int query(int x1, int y1, int x2, int y2) {
  int ans = 0;
  for (int i = x2; i; i -= (i & -i)) {
    for (int j = y2; j; j -= (j & -j)) {
      ans += bit[i][j];
    }
  }
  for (int i = x1 - 1; i; i -= (i & -i)) {
    for (int j = y2; j; j -= (j & -j)) {
      ans -= bit[i][j];
    }
  }
  for (int i = x2; i; i -= (i & -i)) {
    for (int j = y1 - 1; j; j -= (j & -j)) {
      ans -= bit[i][j];
    }
  }
  for (int i = x1 - 1; i; i -= (i & -i)) {
    for (int j = y1 - 1; j; j -= (j & -j)) {
      ans += bit[i][j];
    }
  }
  return ans;
}

int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> n >> q;

  char grid[1001][1001];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      grid[i][j] = c;
      if (c == '*') {
        update(i, j, 1);
      }
    }
  }

  while (q--) {
    int x;
    cin >> x;
    if (x == 1) {
      int y, z;
      cin >> y >> z;
      if (grid[y][z] == '.') {
        update(y, z, 1);
        grid[y][z] = '*';
      } else {
        update(y, z, -1);
        grid[y][z] = '.';
      }
    } else {
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;

      cout << query(y1, x1, y2, x2) << endl;
    }
  }

  return 0;
}