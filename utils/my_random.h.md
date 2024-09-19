---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/my_random.h\"\n\n#include <type_traits>\n#include\
    \ <random>\n\nmt19937_64 rng_engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n// Core of random data generation\ntemplate <class T>\nT my_rand(T lo, T hi)\
    \ {\n    static_assert(is_arithmetic_v<T>, \"Invalid type for my_rand()\");\n\
    \    if constexpr (is_integral_v<T>) {\n        return uniform_int_distribution<T>(lo,\
    \ hi)(rng_engine);\n    } else {\n        return uniform_real_distribution<T>(lo,\
    \ hi)(rng_engine);\n    }\n}\n\n// Default value - uniform [0, 1] for reals\n\
    template <class T>\nconstexpr T default_val() {\n    if constexpr (is_floating_point_v<T>)\
    \ {\n        return 1;\n    } else {\n        return numeric_limits<T>::max()\
    \ / 2;\n    }\n}\n\nbool rand_bool() {\n    return my_rand<int>(0, 1);\n}\n\n\
    int rand_int(int lo, int hi) {\n    return my_rand<int>(lo, hi);\n}\n\nint rand_int(int\
    \ hi) {\n    return rand_int(0, hi - 1);\n}\n\nint rand_int() {\n    return rand_int(default_val<int>());\n\
    }\n\nlong long rand_long(long long lo, long long hi) {\n    return my_rand<long\
    \ long>(lo, hi);\n}\n\nlong long rand_long(long long hi) {\n    return rand_long(0,\
    \ hi);\n}\n\nlong long rand_long() {\n    return rand_long(default_val<long long>());\n\
    }\n\ndouble rand_doub(double lo, double hi) {\n    return my_rand<double>(lo,\
    \ hi);\n}\n\ndouble rand_doub(double hi) {\n    return rand_doub(0, hi);\n}\n\n\
    double rand_doub() {\n    return rand_doub(1);\n}\n\nstring rand_str(int n, int\
    \ k) {\n    string s(n, ' ');\n    for (int i = 0; i < n; i++) {\n        s[i]\
    \ = char('a' + rand_int(k));\n    }\n    return s;\n}\n\ntemplate <class T>\n\
    vector<T> rand_vec(int n, T lo, T hi) {\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        res[i] = my_rand<T>(lo, hi);\n    }\n    return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> rand_vec(int n, T hi) {\n    return\
    \ rand_vec<T>(n, 0, hi);\n}\n\ntemplate <class T>\nvector<T> rand_vec(int n) {\n\
    \    return rand_vec<T>(n, default_val<T>());\n}\n\ntemplate <class T, size_t\
    \ N>\narray<T, N> rand_arr(T lo, T hi) {\n    array<T, N> res;\n    for (int i\
    \ = 0; i < int(N); i++) {\n        res[i] = my_rand<T>(lo, hi);\n    }\n    return\
    \ res;\n}\n\ntemplate <class T, size_t N>\narray<T, N> rand_arr(T hi) {\n    return\
    \ rand_arr<T, N>(0, hi);\n}\n\ntemplate <class T, size_t N>\narray<T, N> rand_arr()\
    \ {\n    return rand_arr<T, N>(default_val<T>());\n}\n\n// Uniformly generate\
    \ trees from random Prufer sequences\nvector<pair<int, int>> gen_tree_edges(int\
    \ n) {\n    const vector<int> prufer = rand_vec(n - 2, 0, n - 1);\n    vector<int>\
    \ deg(n, 1);\n    for (int x : prufer) {\n        deg[x]++;\n    }\n    priority_queue<int,\
    \ vector<int>, greater<>> leaves;\n    for (int i = 0; i < n; i++) {\n       \
    \ if (deg[i] == 1) {\n            leaves.push(i);\n        }\n    }\n\n    vector<pair<int,\
    \ int>> res;\n    res.reserve(n - 1);\n    for (int v : prufer) {\n        int\
    \ u = leaves.top();\n        leaves.pop();\n\n        res.push_back(minmax(u,\
    \ v));\n        deg[u]--, deg[v]--;\n\n        if (deg[v] == 1) {\n          \
    \  leaves.push(v);\n        }\n    }\n\n    int rootA = -1, rootB = -1;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (deg[i] == 1) {\n            (rootA ==\
    \ -1 ? rootA : rootB) = i;\n        }\n    }\n    res.emplace_back(rootA, rootB);\n\
    \n    return res;\n}\n\n// Generate arbitrary graphs by adding extra edges to\
    \ a spanning tree (probably not uniform, but good enough)\nvector<pair<int, int>>\
    \ gen_graph_edges(int n, int m) {\n    assert(m >= n - 1 && m <= 1ll * n * (n\
    \ - 1) / 2);\n\n    auto res = gen_tree_edges(n);\n    set<pair<int, int>> have;\n\
    \    for (auto [u, v] : res) {\n        have.emplace(u, v);\n    }\n\n    while\
    \ (ssize(res) < m) {\n        int u = rand_int(n), v = rand_int(n - 1);\n    \
    \    v += v >= u;\n        if (u > v) {\n            swap(u, v);\n        }\n\
    \        if (!have.count({u, v})) {\n            res.emplace_back(u, v);\n   \
    \         have.emplace(u, v);\n        }\n    }\n    return res;\n}\n\nvector<vector<int>>\
    \ gen_graph(int n, int m, bool dir = false) {\n    vector<vector<int>> g(n);\n\
    \    for (auto [u, v] : gen_graph_edges(n, m)) {\n        if (dir) {\n       \
    \     if (rand_bool()) {\n                swap(u, v);\n            }\n       \
    \     g[u].push_back(v);\n        } else {\n            g[u].push_back(v);\n \
    \           g[v].push_back(u);\n        }\n    }\n    return g;\n}\n\nvector<vector<pair<int,\
    \ int>>> gen_weighted_graph(int n, int m, int lo = 1, int hi = default_val<int>(),\
    \ bool dir = false) {\n    vector<vector<pair<int, int>>> g(n);\n    for (auto\
    \ [u, v] : gen_graph_edges(n, m)) {\n        const int w = rand_int(lo, hi);\n\
    \        if (dir) {\n            if (rand_bool()) {\n                swap(u, v);\n\
    \            }\n            g[u].emplace_back(v, w);\n        } else {\n     \
    \       g[u].emplace_back(v, w);\n            g[v].emplace_back(u, w);\n     \
    \   }\n    }\n    return g;\n}\n"
  code: "#pragma once\n\n#include <type_traits>\n#include <random>\n\nmt19937_64 rng_engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n// Core of random data generation\ntemplate <class T>\nT my_rand(T lo, T hi)\
    \ {\n    static_assert(is_arithmetic_v<T>, \"Invalid type for my_rand()\");\n\
    \    if constexpr (is_integral_v<T>) {\n        return uniform_int_distribution<T>(lo,\
    \ hi)(rng_engine);\n    } else {\n        return uniform_real_distribution<T>(lo,\
    \ hi)(rng_engine);\n    }\n}\n\n// Default value - uniform [0, 1] for reals\n\
    template <class T>\nconstexpr T default_val() {\n    if constexpr (is_floating_point_v<T>)\
    \ {\n        return 1;\n    } else {\n        return numeric_limits<T>::max()\
    \ / 2;\n    }\n}\n\nbool rand_bool() {\n    return my_rand<int>(0, 1);\n}\n\n\
    int rand_int(int lo, int hi) {\n    return my_rand<int>(lo, hi);\n}\n\nint rand_int(int\
    \ hi) {\n    return rand_int(0, hi - 1);\n}\n\nint rand_int() {\n    return rand_int(default_val<int>());\n\
    }\n\nlong long rand_long(long long lo, long long hi) {\n    return my_rand<long\
    \ long>(lo, hi);\n}\n\nlong long rand_long(long long hi) {\n    return rand_long(0,\
    \ hi);\n}\n\nlong long rand_long() {\n    return rand_long(default_val<long long>());\n\
    }\n\ndouble rand_doub(double lo, double hi) {\n    return my_rand<double>(lo,\
    \ hi);\n}\n\ndouble rand_doub(double hi) {\n    return rand_doub(0, hi);\n}\n\n\
    double rand_doub() {\n    return rand_doub(1);\n}\n\nstring rand_str(int n, int\
    \ k) {\n    string s(n, ' ');\n    for (int i = 0; i < n; i++) {\n        s[i]\
    \ = char('a' + rand_int(k));\n    }\n    return s;\n}\n\ntemplate <class T>\n\
    vector<T> rand_vec(int n, T lo, T hi) {\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        res[i] = my_rand<T>(lo, hi);\n    }\n    return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> rand_vec(int n, T hi) {\n    return\
    \ rand_vec<T>(n, 0, hi);\n}\n\ntemplate <class T>\nvector<T> rand_vec(int n) {\n\
    \    return rand_vec<T>(n, default_val<T>());\n}\n\ntemplate <class T, size_t\
    \ N>\narray<T, N> rand_arr(T lo, T hi) {\n    array<T, N> res;\n    for (int i\
    \ = 0; i < int(N); i++) {\n        res[i] = my_rand<T>(lo, hi);\n    }\n    return\
    \ res;\n}\n\ntemplate <class T, size_t N>\narray<T, N> rand_arr(T hi) {\n    return\
    \ rand_arr<T, N>(0, hi);\n}\n\ntemplate <class T, size_t N>\narray<T, N> rand_arr()\
    \ {\n    return rand_arr<T, N>(default_val<T>());\n}\n\n// Uniformly generate\
    \ trees from random Prufer sequences\nvector<pair<int, int>> gen_tree_edges(int\
    \ n) {\n    const vector<int> prufer = rand_vec(n - 2, 0, n - 1);\n    vector<int>\
    \ deg(n, 1);\n    for (int x : prufer) {\n        deg[x]++;\n    }\n    priority_queue<int,\
    \ vector<int>, greater<>> leaves;\n    for (int i = 0; i < n; i++) {\n       \
    \ if (deg[i] == 1) {\n            leaves.push(i);\n        }\n    }\n\n    vector<pair<int,\
    \ int>> res;\n    res.reserve(n - 1);\n    for (int v : prufer) {\n        int\
    \ u = leaves.top();\n        leaves.pop();\n\n        res.push_back(minmax(u,\
    \ v));\n        deg[u]--, deg[v]--;\n\n        if (deg[v] == 1) {\n          \
    \  leaves.push(v);\n        }\n    }\n\n    int rootA = -1, rootB = -1;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (deg[i] == 1) {\n            (rootA ==\
    \ -1 ? rootA : rootB) = i;\n        }\n    }\n    res.emplace_back(rootA, rootB);\n\
    \n    return res;\n}\n\n// Generate arbitrary graphs by adding extra edges to\
    \ a spanning tree (probably not uniform, but good enough)\nvector<pair<int, int>>\
    \ gen_graph_edges(int n, int m) {\n    assert(m >= n - 1 && m <= 1ll * n * (n\
    \ - 1) / 2);\n\n    auto res = gen_tree_edges(n);\n    set<pair<int, int>> have;\n\
    \    for (auto [u, v] : res) {\n        have.emplace(u, v);\n    }\n\n    while\
    \ (ssize(res) < m) {\n        int u = rand_int(n), v = rand_int(n - 1);\n    \
    \    v += v >= u;\n        if (u > v) {\n            swap(u, v);\n        }\n\
    \        if (!have.count({u, v})) {\n            res.emplace_back(u, v);\n   \
    \         have.emplace(u, v);\n        }\n    }\n    return res;\n}\n\nvector<vector<int>>\
    \ gen_graph(int n, int m, bool dir = false) {\n    vector<vector<int>> g(n);\n\
    \    for (auto [u, v] : gen_graph_edges(n, m)) {\n        if (dir) {\n       \
    \     if (rand_bool()) {\n                swap(u, v);\n            }\n       \
    \     g[u].push_back(v);\n        } else {\n            g[u].push_back(v);\n \
    \           g[v].push_back(u);\n        }\n    }\n    return g;\n}\n\nvector<vector<pair<int,\
    \ int>>> gen_weighted_graph(int n, int m, int lo = 1, int hi = default_val<int>(),\
    \ bool dir = false) {\n    vector<vector<pair<int, int>>> g(n);\n    for (auto\
    \ [u, v] : gen_graph_edges(n, m)) {\n        const int w = rand_int(lo, hi);\n\
    \        if (dir) {\n            if (rand_bool()) {\n                swap(u, v);\n\
    \            }\n            g[u].emplace_back(v, w);\n        } else {\n     \
    \       g[u].emplace_back(v, w);\n            g[v].emplace_back(u, w);\n     \
    \   }\n    }\n    return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/my_random.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/my_random.h
layout: document
redirect_from:
- /library/utils/my_random.h
- /library/utils/my_random.h.html
title: utils/my_random.h
---