#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int m, n;  // gyou retu
  cin >> m >> n;

  vector<vector<char>> field(n, vector<char>(m));

  int sx, sy, gx, gy;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];

      if (field[i][j] == 's') {
        sx = i;
        sy = j;
      }

      if (field[i][j] == 'g') {
        gx = i;
        gy = j;
      }
    }
  }

  vector<vector<int>> dist(n, vector<int>(m, -1));

  queue<pii> q;

  q.push({sx, sy});

  dist[sx][sy] = 0;

  // m is gyou n is retu

  auto judge = [&](int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < m;
  };

  while (!q.empty()) {
    auto [nowx, nowy] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextx = nowx + dx[i];
      int nexty = nowy + dy[i];

      if (judge(nextx, nexty)) {
        if (field[nextx][nexty] == '1') continue;
        if (dist[nextx][nexty] != -1) continue;
        dist[nextx][nexty] = dist[nowx][nowy] + 1;
        q.push({nextx, nexty});
      }
    }
  }

  if (dist[gx][gy] == -1) {
    cout << "Fail" << endl;
  } else {
    cout << dist[gx][gy] << endl;
  }
}