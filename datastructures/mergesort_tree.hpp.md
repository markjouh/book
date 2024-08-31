---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/mergesort_tree.hpp\"\n\ntemplate <class T>\n\
    struct MergesortTree {\n  int n;\n  vector<vector<T>> st;\n\n  MergesortTree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n    for (int i = 0; i < n; i++) {\n \
    \     st[i + n] = {a[i]};\n    }\n    for (int i = n - 1; i > 0; i--) {\n    \
    \  merge(begin(st[i << 1]), end(st[i << 1]), begin(st[i << 1 | 1]),\n        end(st[i\
    \ << 1 | 1]), back_inserter(st[i]));\n    }\n  }\n\n  T query(int l, int r, T\
    \ v) {\n    T ls = 0, rs = 0;\n    for (l += n, r += n + 1; l < r; l >>= 1, r\
    \ >>= 1) {\n      if (l & 1) {\n        ls += lower_bound(all(st[l]), v) - begin(st[l]);\n\
    \        l++;\n      }\n      if (r & 1) {\n        r--;\n        rs += lower_bound(all(st[r]),\
    \ v) - begin(st[r]);\n      }\n    }\n    return ls + rs;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct MergesortTree {\n  int n;\n  vector<vector<T>>\
    \ st;\n\n  MergesortTree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n    for\
    \ (int i = 0; i < n; i++) {\n      st[i + n] = {a[i]};\n    }\n    for (int i\
    \ = n - 1; i > 0; i--) {\n      merge(begin(st[i << 1]), end(st[i << 1]), begin(st[i\
    \ << 1 | 1]),\n        end(st[i << 1 | 1]), back_inserter(st[i]));\n    }\n  }\n\
    \n  T query(int l, int r, T v) {\n    T ls = 0, rs = 0;\n    for (l += n, r +=\
    \ n + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) {\n        ls += lower_bound(all(st[l]),\
    \ v) - begin(st[l]);\n        l++;\n      }\n      if (r & 1) {\n        r--;\n\
    \        rs += lower_bound(all(st[r]), v) - begin(st[r]);\n      }\n    }\n  \
    \  return ls + rs;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/mergesort_tree.hpp
  requiredBy: []
  timestamp: '2024-08-30 22:25:44-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: datastructures/mergesort_tree.hpp
layout: document
redirect_from:
- /library/datastructures/mergesort_tree.hpp
- /library/datastructures/mergesort_tree.hpp.html
title: datastructures/mergesort_tree.hpp
---