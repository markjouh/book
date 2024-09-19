---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/tree/euler_tour.h\"\n\nstruct EulerTour {\n    vector<int>\
    \ tin, tout;\n\n    EulerTour(const vector<vector<int>> &g, int root = 0) : adj(g)\
    \ {\n        tin.resize(sz(g));\n        tout.resize(sz(g));\n        dfs(root,\
    \ -1);\n    }\n\nprivate:\n    int time = 0;\n    const vector<vector<int>> &adj;\n\
    \n    void dfs(int u, int par) {\n        tin[u] = time++;\n        for (int v\
    \ : adj[u]) {\n            if (v != par) {\n                dfs(v, u);\n     \
    \       }\n        }\n        tout[u] = time;\n    }\n};\n"
  code: "#pragma once\n\nstruct EulerTour {\n    vector<int> tin, tout;\n\n    EulerTour(const\
    \ vector<vector<int>> &g, int root = 0) : adj(g) {\n        tin.resize(sz(g));\n\
    \        tout.resize(sz(g));\n        dfs(root, -1);\n    }\n\nprivate:\n    int\
    \ time = 0;\n    const vector<vector<int>> &adj;\n\n    void dfs(int u, int par)\
    \ {\n        tin[u] = time++;\n        for (int v : adj[u]) {\n            if\
    \ (v != par) {\n                dfs(v, u);\n            }\n        }\n       \
    \ tout[u] = time;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/tree/euler_tour.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: graphs/tree/euler_tour.h
layout: document
redirect_from:
- /library/graphs/tree/euler_tour.h
- /library/graphs/tree/euler_tour.h.html
title: graphs/tree/euler_tour.h
---