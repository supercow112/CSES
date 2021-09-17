#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// #define us unordered_set
// #define REP(i, a, b) for (int i = a; i <= b; i++)

// typedef pair<int, int> p_int;

int const MOD = 1e9 + 7;
int const MAX_N = 1e12;

// template<class FWIt>
// void print_array(FWIt a, FWIt b) {
//   while (a != b) {
//     cout << *a << " ";
//     a++;
//   } cout << endl;
// }

vector<string> v;
unordered_map<string, int> mp;
vector<pair<int, int>> swaps;

vector<int> bfs(int s) {
    vector<int> dist(v.size(), -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] == 8)
            continue;
        string cur = v[u];
        for (auto p : swaps) {
            int i = p.first, j = p.second;
            swap(cur[i], cur[j]);
            int x = mp[cur];
            if (dist[x] == -1) {
                dist[x] = dist[u] + 1;
                q.push(x);
            }
            swap(cur[i], cur[j]);
        }
    }
    return dist;
}
 


void run_case() {
  string s;

  for (int i = 0; i < 9; i++) {
    int x;
    cin >> x;
    s += (char) (x + '0');
  }
  // cout << s << endl;
  string goal = "123456789";
  string t = goal;
  do {
    mp[t] = v.size();
    v.push_back(t);
  } while (next_permutation(t.begin(), t.end()));

  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 2; j++) {
  //     swaps.emplace_back(3*i + j, 3*i + j + 1);
  //   }
  // }
  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 2; j++) {
  //     swaps.emplace_back(3*j + i, 3*(j + 1) + i);
  //   }
  // }

  for (int i=0; i<3; i++)
        for (int j=0; j<3; j++) {
            if (i < 2)
                swaps.emplace_back(3 * i + j, 3 * (i + 1) + j);
            if (j < 2)
                swaps.emplace_back(3 * i + j, 3 * i + j + 1);
        }

  vector<int> q = bfs(0), r = bfs(mp[s]);
  int ans = MAX_N;
  for (int i = 0; i < q.size(); i++) {
    if (q[i] != -1 && r[i] != -1) {
      ans = min(ans, q[i] + r[i]);
    }
  }

  cout << ans << endl;
}
 
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  run_case();
}
