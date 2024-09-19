---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  - icon: ':heavy_check_mark:'
    path: strings/hashing.h
    title: strings/hashing.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define f first\n#define s second\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n    return b <\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n\
    \    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n    \
    \    cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n \
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"numeric/binsearch.h\"\
    \n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <=\
    \ hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n \
    \       hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\n\ntemplate\
    \ <class T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n#line 2 \"strings/hashing.h\"\
    \n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\n\
    const ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct Hash {\n    ll val;\n    int\
    \ len;\n\n    Hash(ll x, int y) : val(x), len(y) {}\n\n    Hash operator+(Hash\
    \ b) {\n        return Hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD,\
    \ len + b.len);\n    }\n\n    bool operator==(Hash b) {\n        return val ==\
    \ b.val && len == b.len;\n    }\n};\n\nstruct StringHash {\n    int len;\n   \
    \ vector<ll> h;\n\n    template <class T>\n    StringHash(const T &s) : len(sz(s)),\
    \ h(len + 1) {\n        for (int i = 0; i < len; i++) {\n            h[i + 1]\
    \ = (__int128_t(h[i]) * H_BASE + s[i]) % H_MOD;\n        }\n        while (sz(pow_b)\
    \ <= len) {\n            pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);\n\
    \        }\n    }\n\n    Hash get(int l, int r) {\n        r++;\n        return\
    \ Hash(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r -\
    \ l);\n    }\n\n    Hash get() {\n        return get(0, sz(h) - 1);\n    }\n};\n\
    #line 6 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\n\nint\
    \ main() {\n    string s;\n    cin >> s;\n    string rev = s;\n    reverse(all(rev));\n\
    \    StringHash a(s), b(rev);\n    const int n = sz(s);\n    vector<int> ans(2\
    \ * n - 1);\n    for (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0,\
    \ min(i, n - i - 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n\
    \ - i - 1 - d, n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int\
    \ d) {\n            return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n\
    \        }) + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout\
    \ << ans[i] << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n#include \"../../../strings/hashing.h\"\n\nint main() {\n    string s;\n   \
    \ cin >> s;\n    string rev = s;\n    reverse(all(rev));\n    StringHash a(s),\
    \ b(rev);\n    const int n = sz(s);\n    vector<int> ans(2 * n - 1);\n    for\
    \ (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0, min(i, n - i -\
    \ 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n - i - 1 - d,\
    \ n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int d) {\n     \
    \       return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n        })\
    \ + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout << ans[i]\
    \ << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - numeric/binsearch.h
  - strings/hashing.h
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---