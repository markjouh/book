#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <utils>
#else
#define dbg(...)
#endif

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using ll = long long;

template <class T>
bool ckmin(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}

template <class T>
bool ckmax(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}

template <class T = int>
static constexpr T inf = numeric_limits<T>::max() / 2;

void solve() {
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}