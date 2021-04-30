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
  vector<ll> b(n - 1);

  for (auto&& c : b) cin >> c;

  vector<ll> numarray;

  numarray.push_back(b[0]);

  for (ll i = 0; i < n - 2; i++) {
    numarray.push_back(min(b[i], b[i + 1]));
  }

  numarray.push_back(b.back());

  cout << accumulate(numarray.begin(), numarray.end(), 0LL) << endl;
}