# Drumsticks (چوب‌های درام)

A greedy solution in C++ for the Quera problem **"چوب‌های درام"**
(Assignment 2 — Heap & Greedy Algorithms).

[English](#english) | [فارسی](#فارسی)

---

## English

### Problem
A band has a leader and `k` drummers. A shop sells `n` packs of drumsticks: pack `i` has `ai`
sticks and costs `ci`. Every opened pack must be fully split so that:

1. every drummer gets the same number of sticks, and the leader gets **exactly 1 more** than a drummer;
2. nobody is left with zero sticks.

The leader has `v` tomans. Find the **maximum number of packs** he can buy, using only packs that
can be split this way.

**Input**
- Line 1: `k`, `v`, `n`
- Line 2: `a1 ... an`
- Line 3: `c1 ... cn`
- Limits: `1 ≤ n, k ≤ 100000`, `1 ≤ ai, ci, v ≤ 10^9`

**Output**
- One integer: the maximum number of packs.

### Example
```
Input:
3 10 5
5 9 10 4 14
1 10 2 1 3

Output:
1
```
Packs 1 and 2 can be split fairly (costs 1 and 10), but the budget `10` allows only one of them.

### Solution idea
If each drummer gets `x` sticks and the leader gets `x + 1`, the pack has
`k·x + x + 1 = (k + 1)·x + 1` sticks, with `x ≥ 1`. So a pack is valid exactly when:

- `a ≥ k + 2`, and
- `(a − 1) mod (k + 1) = 0`.

Then it is a simple greedy problem: keep only valid packs, sort their prices, and buy the cheapest
packs first until the money runs out.

### Complexity
- Time: `O(n log n)`
- Memory: `O(n)`

Prices can sum up to about `10^14`, so `long long` is required.

### Build & run
```bash
g++ -O2 -std=c++17 -o main main.cpp
./main < input.txt
```

---

## فارسی

### صورت مسئله
یک گروه موسیقی یک سرگروه و `k` درام‌نواز دارد. فروشگاه `n` بسته چوب درام دارد: بسته‌ی `i` شامل
`ai` چوب است و `ci` تومان قیمت دارد. هر بسته‌ای که باز می‌شود باید کامل تقسیم شود، به‌طوری که:

۱. همه‌ی درام‌نوازها تعداد برابر چوب بگیرند و سرگروه **دقیقاً ۱ چوب بیشتر** از هر درام‌نواز بگیرد؛
۲. هیچ‌کس دست‌خالی نماند.

سرگروه `v` تومان دارد. حداکثر چند بسته (از بین بسته‌هایی که تقسیم بدون دعوا دارند) می‌تواند بخرد؟

### ایده‌ی حل
اگر هر درام‌نواز `x` چوب بگیرد و سرگروه `x + 1` چوب، تعداد چوب‌های بسته
`(k + 1)·x + 1` است و `x ≥ 1`. پس بسته وقتی معتبر است که:

- `a ≥ k + 2` و
- `(a − 1)` بر `k + 1` بخش‌پذیر باشد.

بعد مسئله حریصانه است: فقط قیمت بسته‌های معتبر را نگه می‌داریم، مرتب می‌کنیم و از ارزان‌ترین
شروع به خرید می‌کنیم تا پول تمام شود.

### پیچیدگی
- زمانی: `O(n log n)`
- حافظه: `O(n)`

### کامپایل و اجرا
```bash
g++ -O2 -std=c++17 -o main main.cpp
./main < input.txt
```
