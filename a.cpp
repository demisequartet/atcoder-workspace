#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {0, 1, 0, 1}, dy[] = {0, 0, 1, 1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) cin >> s[i];

  vector<vector<int>> memo(h, vector<int>(w));

  int cnt = 0, ans = 0;

  for (int i = 1; i < h - 1; i++) {
    for (int j = 1; j < w - 1; j++) {
      if (s[i][j] == '.') continue;

      for (int k = 0; k < 4; k++) {
        if (s[i + dx[k]][j + dy[k]] == '#') cnt++;
      }

      if (cnt == 1 || cnt == 3) ans++;
      cnt = 0;
    }
  }

  cout << ans << endl;
}