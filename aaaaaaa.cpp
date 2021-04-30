#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = unsigned long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

ll modPow(ll a, ll n, ll p = mod) {
  if (n == 0) return 1;  // 0乗にも対応する場合
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n - 1, p)) % p;
  long long t = modPow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
  ll n, p;
  cin >> n >> p;

  if (p == 2) {
    cout << 0 << endl;
    return 0;
  }

  if (n == 1) {
    cout << p - 1 << endl;
    return 0;
  }

  ll zizyo = modPow(p - 2, n - 1);

  ll ans = ((p - 1) % mod * zizyo % mod) % mod;

  cout << ans << endl;
}