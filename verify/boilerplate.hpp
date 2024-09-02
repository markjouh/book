#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) int(size(x))
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T>
int lg(T x) {
#if __has_builtin(__lg)
  return __lg(x);
#else
  int res = 0;
  while (x >>= 1) {
    res++;
  }
  return res;
#endif
}

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

struct InitIO {
  InitIO() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << setprecision(10) << fixed;
  }
} init_io;