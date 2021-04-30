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

  vector<ll> a(5);

  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  cout << ceil((double)n / *min_element(a.begin(), a.end())) + 4 << endl;
}