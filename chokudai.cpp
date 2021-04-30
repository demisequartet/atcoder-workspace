#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

string vectostr(const vector<int>& a) {
  string ans = "";

  for (int i = 0; i < a.size(); i++) {
    ans.push_back(a[i] + '0');
  }

  return ans;
}

vector<int> strtovec(const string& a) {
  vector<int> ans;

  for (int i = 0; i < a.size(); i++) {
    ans.push_back(a[i] - '0');
  }

  return ans;
}

int main() {
  int n;
  cin >> n;
  string s;

  for (int i = 0; i < n; i++) {
    char temp;
    cin >> temp;

    s.push_back(temp);
  }

  int m;
  cin >> m;

  vector<vector<int>> p(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }

  vector<string> ans;

  for (int bit = 0; bit < (1 << m); bit++) {
    // cout << bit << endl;
    vector<int> S;
    for (int i = 0; i < m; i++) {
      if (bit & (1 << i)) {
        S.push_back(i);
      }
    }

    sort(S.begin(), S.end());

    do {
      vector<int> tikan = strtovec(s);

      for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < p[S[i]].size(); j++) {
          int index = p[S[i]][j];
          int temp = index - 1;
          int temp2 = s[j] - '0';

          // if (bit == 1) cout << temp << " ," << temp2 << endl;
          tikan[temp] = temp2;
        }
      }

      string tempans = vectostr(tikan);

      ans.push_back(tempans);

    } while (next_permutation(S.begin(), S.end()));
  }

  sort(ans.begin(), ans.end());

  for (auto it = ans[0].begin(); it != ans[0].end(); it++) {
    cout << *it << (it == ans[0].end() ? '\n' : ' ');
  }
}