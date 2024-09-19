---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/binsearch.h\"\n\ntemplate <class T, class U>\nT\
    \ bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1)\
    \ << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i))\
    \ * i;\n    }\n    return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo,\
    \ T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n \
    \   }\n    return lo;\n}\n"
  code: "#pragma once\n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n\
    \    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return\
    \ hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo\
    \ <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n\
    \        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binsearch.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/aizu/alds1/binary_search.test.cpp
documentation_of: numeric/binsearch.h
layout: document
redirect_from:
- /library/numeric/binsearch.h
- /library/numeric/binsearch.h.html
title: numeric/binsearch.h
---