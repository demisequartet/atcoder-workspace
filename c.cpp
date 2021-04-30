#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

vector<string> ans;
int n;

void dfs(string s) {
  if (s.size() > n) return;

  if (s.size() == n) ans.push_back(s);

  string temp = "()" + s;
  string temp2 = s + "()";
  string temp3 = s + s;
  string temp4 = "(" + s + ")";

  dfs(temp);
  dfs(temp2);
  dfs(temp3);
  dfs(temp4);
}

int main() {
  cin >> n;

  dfs("()");

  sort(ans.begin(), ans.end());

  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}