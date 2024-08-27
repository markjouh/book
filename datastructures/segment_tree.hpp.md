---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segment_tree.hpp\"\n\ntemplate<class T, T(*op)(T,\
    \ T), T(*id)()> struct segment_tree {\n    int n;\n    vector<T> tree;\n\n   \
    \ segment_tree(int sz) : n(sz), tree(2 * n, id()) {}\n\n    segment_tree(const\
    \ vector<T> &a) : n(sz(a)), tree(2 * n) {\n        copy(begin(a), end(a), begin(tree)\
    \ + n);\n        for (int i = n - 1; i > 0; i--) {\n            tree[i] = op(tree[i\
    \ << 1], tree[i << 1 | 1]);\n        }\n    }\n\n    T query(int l, int r) {\n\
    \        T ls = id(), rs = id();\n        for (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) {\n                ls = op(ls, tree[l++]);\n\
    \            }\n            if (r & 1) {\n                rs = op(tree[--r], rs);\n\
    \            }\n        }\n        return op(ls, rs);\n    }\n\n    void set(int\
    \ p, T val) {\n        for (tree[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n \
    \           tree[p] = op(tree[p << 1], tree[p << 1 | 1]);\n        }\n    }\n\
    };\n"
  code: "#pragma once\n\ntemplate<class T, T(*op)(T, T), T(*id)()> struct segment_tree\
    \ {\n    int n;\n    vector<T> tree;\n\n    segment_tree(int sz) : n(sz), tree(2\
    \ * n, id()) {}\n\n    segment_tree(const vector<T> &a) : n(sz(a)), tree(2 * n)\
    \ {\n        copy(begin(a), end(a), begin(tree) + n);\n        for (int i = n\
    \ - 1; i > 0; i--) {\n            tree[i] = op(tree[i << 1], tree[i << 1 | 1]);\n\
    \        }\n    }\n\n    T query(int l, int r) {\n        T ls = id(), rs = id();\n\
    \        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                ls = op(ls, tree[l++]);\n            }\n           \
    \ if (r & 1) {\n                rs = op(tree[--r], rs);\n            }\n     \
    \   }\n        return op(ls, rs);\n    }\n\n    void set(int p, T val) {\n   \
    \     for (tree[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n            tree[p]\
    \ = op(tree[p << 1], tree[p << 1 | 1]);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:30:17-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rmq.test.cpp
documentation_of: datastructures/segment_tree.hpp
layout: document
redirect_from:
- /library/datastructures/segment_tree.hpp
- /library/datastructures/segment_tree.hpp.html
title: datastructures/segment_tree.hpp
---