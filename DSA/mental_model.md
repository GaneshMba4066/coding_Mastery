# Engineering Mental Models: The Pragmatic Guide to Seniority

Memorizing syntax and algorithms gets you hired. Internalizing mental models makes you a trusted engineer who can own entire systems. 

This document outlines the core heuristics to apply daily. Whenever you are faced with a technical decision, run it through these models.

---

## 1. The "Blast Radius" Heuristic (Risk Management)
Before writing code, ask: *If this fails, what goes down with it?*
*   **One-Way vs. Two-Way Doors:** If a decision is easily reversible (a two-way door), move fast and build it. If a decision is permanent or highly destructive to reverse (a one-way door, like a core schema change or deeply embedded RTOS memory layout), slow down and debate it thoroughly.
*   **Fail Gracefully:** Never let a local failure crash the global system. If an AI inference pipeline times out, does it crash the app, or does it degrade gracefully to a cached default?

## 2. The Tradeoff Triangle (Performance Engineering)
Every architectural decision is a compromise between **Time**, **Space**, and **Maintainability**. You can rarely optimize all three.
*   **Trading Space for Time:** Caching results, using hash maps, or pre-computing prefix sums. Excellent for application layers where memory is cheap but latency is critical.
*   **Trading Time for Space:** Recomputing values on the fly instead of storing them. Essential when memory budgets are strictly fixed.
*   **The Maintainability Tax:** Is a highly complex, custom $O(n)$ optimization worth it if it takes your team three days to debug it? Often, a readable $O(n \log n)$ standard library approach wins in production.

## 3. Global Maximum vs. Local Minimum (System Architecture)
Engineers often get stuck optimizing the wrong bottleneck. 
*   **The Local Minimum:** Spending three days optimizing a sorting algorithm to shave off 2 milliseconds.
*   **The Global Maximum:** Realizing the database query fetching the data takes 400 milliseconds, or that the system architecture could be redesigned so the data doesn't need to be sorted at all.
*   **Rule of Thumb:** Always profile the entire system end-to-end before optimizing a single function. Fix the largest bottleneck first.

## 4. The 60-Second Explanation (Technical Communication)
If you cannot explain your code or architecture to another engineer in 60 seconds, it is either too complex, or you do not fully understand it.
*   **The Format:** 
    1. The problem we are solving.
    2. The approach we took.
    3. The primary tradeoff we accepted.
*   *Example:* "We need to filter sensor noise. We used a sliding window average. It increases memory usage slightly, but it guarantees deterministic $O(1)$ execution time per tick."

---

## The Monthly Reflection Protocol

Instead of a rigid pass/fail checklist, sit down once a month and answer these three questions honestly:

1. **What is the hardest bug I fixed this month?** 
   *(Did I fix the root cause, or just patch the symptom? How do I prevent this entire class of bugs from happening again?)*
2. **Where did I compromise readability for speed?** 
   *(Was it justified by profiling data? Did I document the "why" for the next engineer?)*
3. **What is one thing I explained to a teammate or documented clearly?**
   *(Am I hoarding knowledge, or am I acting as a force multiplier for my team?)*

> *Maturity compounds. Solve hard problems, reflect on the tradeoffs, and encode those lessons into your daily habits.*
