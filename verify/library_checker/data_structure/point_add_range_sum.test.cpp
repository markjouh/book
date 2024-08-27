#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../boilerplate.hpp"
#include "../../../datastructures/fenwick_tree.hpp"

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    fenwick_tree<ll> ft(a);
    while (q--) {
        bool t;
        int x, y;
        cin >> t >> x >> y;
        if (t) {
            cout << ft.sum(x, y - 1) << '\n';
        } else {
            ft.add(x, y);
        }
    }
}