---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/union_find.hpp\"\n\nstruct UnionFind {\n\
    \  vector<int> a;\n\n  UnionFind(int n) : a(n, -1) {}\n\n  int size(int x) {\n\
    \    return -a[find(x)];\n  }\n\n  int find(int x) {\n    return a[x] < 0 ? x\
    \ : a[x] = find(a[x]);\n  }\n\n  bool join(int x, int y) {\n    x = find(x);\n\
    \    y = find(y);\n    if (x == y) {\n      return 0;\n    }\n    if (a[x] > a[y])\
    \ {\n      swap(x, y);\n    }\n    a[x] += a[y];\n    a[y] = x;\n    return 1;\n\
    \  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  vector<int> a;\n\n  UnionFind(int n)\
    \ : a(n, -1) {}\n\n  int size(int x) {\n    return -a[find(x)];\n  }\n\n  int\
    \ find(int x) {\n    return a[x] < 0 ? x : a[x] = find(a[x]);\n  }\n\n  bool join(int\
    \ x, int y) {\n    x = find(x);\n    y = find(y);\n    if (x == y) {\n      return\
    \ 0;\n    }\n    if (a[x] > a[y]) {\n      swap(x, y);\n    }\n    a[x] += a[y];\n\
    \    a[y] = x;\n    return 1;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/union_find.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/unionfind.test.cpp
documentation_of: datastructures/union_find.hpp
layout: document
title: Union Find
---

### Overview

The union find is an online connectivity data structure that only supports edge insertions. Each component is defined by its leader element; vertices with the same leader element are connected - otherwise, they're disconnected.

Queries have inverse Ackermann complexity, which grows so slowly, they're functionally $O(1)$.

### Usage

* `UnionFind<T>(n)`: Initializes a union find of size n. $O(n)$
* `size(x)`: Returns the size of x's component.
* `find(x)`: Returns the leader element of vertex x.
* `join(x, y)`: If x and y aren't connected, connects them and returns `true`. Otherwise, returns `false`.