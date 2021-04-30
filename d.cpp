#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

vector<string> ans;
int n;

void dfs(int keta, string s) {
  if (n == keta) {
    ans.push_back(s);
    return;
  }

  char maxch = *max_element(s.begin(), s.end());
  // cout << "maxch is " << maxch << endl;
  if (keta == 0) {
    dfs(keta + 1, s + 'a');
  } else {
    // dfs(keta + 1, s + s.back());

    for (char ch = 'a'; ch <= maxch + 1; ch++) {
      dfs(keta + 1, s + ch);
    }
  }
}
int main() {
  cin >> n;

  dfs(0, "");
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}