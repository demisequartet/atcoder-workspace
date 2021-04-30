#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);

  for (auto&& c : a) cin >> c;
  for (auto&& c : b) cin >> c;
  for (auto&& c : c) cin >> c;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  ll ans = 0;  // a < b < c

  for (ll i = 0; i < b.size(); i++) {
    auto itc = upper_bound(c.begin(), c.end(), b[i]);

    auto ita = lower_bound(a.begin(), a.end(), b[i]);

    ll numc = n - (itc - c.begin());

    ll temp = numc * (ita - a.begin());

    ans += temp;
  }

  cout << ans << endl;
}