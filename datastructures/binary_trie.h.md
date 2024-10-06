---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/binary_trie.h\"\n\ntemplate <class T>\nstruct\
    \ BinaryTrie {\n    static const int W = sizeof(T) * 8;\n    vector<array<int,\
    \ 2>> nxt;\n    vector<int> cnt;\n    T filter = 0;\n\n    BinaryTrie() : nxt(1,\
    \ {-1, -1}), cnt(1, 0) {}\n\n    void add(T x, int v = 1) {\n        x ^= filter;\n\
    \        int pos = 0;\n        for (int i = W - 1; i >= 0; i--) {\n          \
    \  bool dir = (x >> i) & 1;\n            if (nxt[pos][dir] == -1) {\n        \
    \        nxt[pos][dir] = sz(nxt);\n                nxt.push_back({-1, -1});\n\
    \                cnt.push_back(0);\n            }\n            pos = nxt[pos][dir];\n\
    \            cnt[pos] += v;\n        }\n    }\n\n    BinaryTrie &operator^=(T\
    \ x) {\n        filter ^= x;\n        return *this;\n    }\n\n    T min_xor(T\
    \ x) {\n        x ^= filter;\n        int pos = 0;\n        T res = 0;\n     \
    \   for (int i = W - 1; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n\
    \            if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] == 0) {\n         \
    \       res |= T(1) << i;\n                pos = nxt[pos][dir ^ 1];\n        \
    \    } else {\n                pos = nxt[pos][dir];\n            }\n        }\n\
    \        return res;\n    }\n\n    T max_xor(T x) {\n        static const T mask\
    \ = -1;\n        return mask ^ min_xor(x ^ mask);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct BinaryTrie {\n    static const\
    \ int W = sizeof(T) * 8;\n    vector<array<int, 2>> nxt;\n    vector<int> cnt;\n\
    \    T filter = 0;\n\n    BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}\n\n  \
    \  void add(T x, int v = 1) {\n        x ^= filter;\n        int pos = 0;\n  \
    \      for (int i = W - 1; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n\
    \            if (nxt[pos][dir] == -1) {\n                nxt[pos][dir] = sz(nxt);\n\
    \                nxt.push_back({-1, -1});\n                cnt.push_back(0);\n\
    \            }\n            pos = nxt[pos][dir];\n            cnt[pos] += v;\n\
    \        }\n    }\n\n    BinaryTrie &operator^=(T x) {\n        filter ^= x;\n\
    \        return *this;\n    }\n\n    T min_xor(T x) {\n        x ^= filter;\n\
    \        int pos = 0;\n        T res = 0;\n        for (int i = W - 1; i >= 0;\
    \ i--) {\n            bool dir = (x >> i) & 1;\n            if (nxt[pos][dir]\
    \ == -1 || cnt[nxt[pos][dir]] == 0) {\n                res |= T(1) << i;\n   \
    \             pos = nxt[pos][dir ^ 1];\n            } else {\n               \
    \ pos = nxt[pos][dir];\n            }\n        }\n        return res;\n    }\n\
    \n    T max_xor(T x) {\n        static const T mask = -1;\n        return mask\
    \ ^ min_xor(x ^ mask);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/binary_trie.h
  requiredBy: []
  timestamp: '2024-10-05 23:54:04-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/set_xor_min.test.cpp
documentation_of: datastructures/binary_trie.h
layout: document
redirect_from:
- /library/datastructures/binary_trie.h
- /library/datastructures/binary_trie.h.html
title: datastructures/binary_trie.h
---