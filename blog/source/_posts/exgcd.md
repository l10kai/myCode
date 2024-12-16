---
title: exgcd
date: 2024-12-04 13:09:35
tags: exgcd
categories:
- 算法竞赛
- 模板类
---

```cpp
// a * x + b * y = gcd(a, b) 的一组特解
pll exgcd(i64 a, i64 b) {
  if (!b)
    return {1, 0};
  pll res = exgcd(b, a % b);
  return {res.se, res.fi - a / b * res.se};
}

```
