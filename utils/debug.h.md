---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/custom/utils/debug.test.cpp
    title: verify/custom/utils/debug.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/debug.h\"\n\nnamespace debug_internal {\n\nusing namespace\
    \ std;\n\ntemplate <typename T>\nconcept is_core = requires(T x) {\n    cerr <<\
    \ x;\n};\n\ntemplate <typename T>\nconcept is_pair = requires(T x) {\n    x.first;\n\
    \    x.second;\n};\n\ntemplate <typename T>\nconcept is_iterable = ranges::range<T>;\n\
    \ntemplate <typename T>\nvoid print(T x) {\n    if constexpr (is_core<T>) {\n\
    \        cerr << x;\n    } else if constexpr (is_pair<T>) {\n        cerr << '(';\n\
    \        print(x.first);\n        cerr << \", \";\n        print(x.second);\n\
    \        cerr << ')';\n    } else if constexpr (is_iterable<T>) {\n        cerr\
    \ << '[';\n        bool flag = false;\n        for (auto y : x) {\n          \
    \  if (flag) {\n                cerr << \", \";\n            }\n            print(y);\n\
    \            flag = true;\n        }\n        cerr << ']';\n    } else {\n   \
    \     cerr << \"Unknown type\";\n    }\n}\n\ntemplate <typename T>\nvoid debug(string\
    \ s, T x) {\n    cerr << \"\\033[1;35m\" << s << \"\\033[0;0m = \";\n    print(x);\n\
    \    cerr << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug(string\
    \ s, T x, Args... args) {\n    int idx = 0, layer = 0;\n    while (idx < ssize(s)\
    \ && (s[idx] != ',' || layer != 0)) {\n        layer += s[idx] == '(' || s[idx]\
    \ == '{';\n        layer -= s[idx] == ')' || s[idx] == '}';\n        idx++;\n\
    \    }\n    cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m = \";\n\
    \    print(x);\n    cerr << \"\\033[1;32m | \\033[0;0m\";\n    debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n"
  code: "#pragma once\n\nnamespace debug_internal {\n\nusing namespace std;\n\ntemplate\
    \ <typename T>\nconcept is_core = requires(T x) {\n    cerr << x;\n};\n\ntemplate\
    \ <typename T>\nconcept is_pair = requires(T x) {\n    x.first;\n    x.second;\n\
    };\n\ntemplate <typename T>\nconcept is_iterable = ranges::range<T>;\n\ntemplate\
    \ <typename T>\nvoid print(T x) {\n    if constexpr (is_core<T>) {\n        cerr\
    \ << x;\n    } else if constexpr (is_pair<T>) {\n        cerr << '(';\n      \
    \  print(x.first);\n        cerr << \", \";\n        print(x.second);\n      \
    \  cerr << ')';\n    } else if constexpr (is_iterable<T>) {\n        cerr << '[';\n\
    \        bool flag = false;\n        for (auto y : x) {\n            if (flag)\
    \ {\n                cerr << \", \";\n            }\n            print(y);\n \
    \           flag = true;\n        }\n        cerr << ']';\n    } else {\n    \
    \    cerr << \"Unknown type\";\n    }\n}\n\ntemplate <typename T>\nvoid debug(string\
    \ s, T x) {\n    cerr << \"\\033[1;35m\" << s << \"\\033[0;0m = \";\n    print(x);\n\
    \    cerr << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug(string\
    \ s, T x, Args... args) {\n    int idx = 0, layer = 0;\n    while (idx < ssize(s)\
    \ && (s[idx] != ',' || layer != 0)) {\n        layer += s[idx] == '(' || s[idx]\
    \ == '{';\n        layer -= s[idx] == ')' || s[idx] == '}';\n        idx++;\n\
    \    }\n    cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m = \";\n\
    \    print(x);\n    cerr << \"\\033[1;32m | \\033[0;0m\";\n    debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/debug.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/custom/utils/debug.test.cpp
documentation_of: utils/debug.h
layout: document
redirect_from:
- /library/utils/debug.h
- /library/utils/debug.h.html
title: utils/debug.h
---