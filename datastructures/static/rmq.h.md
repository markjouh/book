---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/static/rmq.h\"\n\ntemplate <class T, auto\
    \ op>\nstruct RMQ {\n    int n, log;\n    vector<vector<T>> st;\n\n    RMQ() {}\n\
    \    RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {\n        st.resize(log);\n\
    \        st[0] = a;\n        for (int i = 1; i < log; i++) {\n            st[i].resize(n\
    \ - (1 << i) + 1);\n            for (int j = 0; j < sz(st[i]); j++) {\n      \
    \          st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n     \
    \       }\n        }\n    }\n\n    T query(int l, int r) {\n        assert(l <=\
    \ r);\n        int i = __lg(++r - l);\n        return op(st[i][l], st[i][r - (1\
    \ << i)]);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, auto op>\nstruct RMQ {\n    int n, log;\n\
    \    vector<vector<T>> st;\n\n    RMQ() {}\n    RMQ(const vector<T> &a) : n(sz(a)),\
    \ log(__lg(n) + 1) {\n        st.resize(log);\n        st[0] = a;\n        for\
    \ (int i = 1; i < log; i++) {\n            st[i].resize(n - (1 << i) + 1);\n \
    \           for (int j = 0; j < sz(st[i]); j++) {\n                st[i][j] =\
    \ op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n\
    \    }\n\n    T query(int l, int r) {\n        assert(l <= r);\n        int i\
    \ = __lg(++r - l);\n        return op(st[i][l], st[i][r - (1 << i)]);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/rmq.h
  requiredBy: []
  timestamp: '2024-09-29 00:50:10-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: datastructures/static/rmq.h
layout: document
redirect_from:
- /library/datastructures/static/rmq.h
- /library/datastructures/static/rmq.h.html
title: datastructures/static/rmq.h
---