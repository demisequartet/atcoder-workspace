#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
using ll = long long;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

struct city {
  int pre;
  int year;
  int index;
  char disting[999];
};

void debug(vector<city> &con) {
  for (auto c : con) {
    cout << c.pre << " " << c.year << " " << c.index << endl;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<city> p(m);

  for (int i = 0; i < m; i++) {
    cin >> p[i].pre >> p[i].year;
    p[i].index = i;
  }

  auto comp = [](city &a, city &b) {
    if (a.pre == b.pre) {
      return a.year < b.year;
    } else {
      return a.pre < b.pre;
    }
  };

  sort(p.begin(), p.end(), comp);

  // debug(p);

  int now_pre = 0;
  int cnt = 0;
  for (int i = 0; i < p.size(); i++) {
    if (i == 0) {
      now_pre = p[i].pre;
      cnt++;
      // printf("%06d%06d\n", p[i].pre, cnt);
      sprintf(p[i].disting, "%06d%06d\n", p[i].pre, cnt);
    } else {
      if (now_pre == p[i].pre) {
        cnt++;
        // printf("%06d%06d\n", p[i].pre, cnt);
        sprintf(p[i].disting, "%06d%06d\n", p[i].pre, cnt);

      } else {
        cnt = 1;
        // printf("%06d%06d\n", p[i].pre, cnt);
        sprintf(p[i].disting, "%06d%06d\n", p[i].pre, cnt);

        now_pre = p[i].pre;
      }
    }
  }

  auto comp2 = [](city &a, city &b) { return a.index < b.index; };

  sort(p.begin(), p.end(), comp2);

  for (int i = 0; i < p.size(); i++) {
    cout << p[i].disting;
  }
}