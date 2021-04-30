#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  vector<ll> temp = {a, b, c};
  sort(temp.begin(), temp.end());

  a = temp[0];
  b = temp[1];
  c = temp[2];

  // cout << a << " " << b << " " << c;

  ll ans = 99999999;

  for (int i = 0; i < 10000; i++) {
    for (int j = 0; j < 10000; j++) {
      ll remain = n - a * i - b * j;
      if (remain % c == 0) {
        ans = min(ans, i + j + (remain / c));
      }
    }
  }

  cout << ans << endl;
}